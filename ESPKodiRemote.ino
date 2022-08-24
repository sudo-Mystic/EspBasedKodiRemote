/*
Upload by Mystic
https://github.com/sudo-Mystic/EspBasedKodiRemote.git
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const char* ssid = "WifiName"; //your wifi ssid
const char* password = "WifiPassword"; //your wifi password

const char* serverName = "http://192.168.xx.xx:8080/jsonrpc"; //Add your Kodi device's local IP
const uint16_t kRecvPin = 14; //Pin on which IR Receiver is connected
unsigned long key_value = 0;
IRrecv irrecv(kRecvPin);
decode_results results;
int httpResponseCode;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  
  Serial.println("Starting IR Receiver...");// Start the receiver
  irrecv.enableIRIn();  // Start the receiver
  Serial.print("IR Receiver is now running and waiting for IR message on Pin ");
 
}

void loop() {

    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      
      http.begin(client, serverName);
      http.addHeader("Content-Type", "application/json");
     
     if (irrecv.decode(&results)) {
       serialPrintUint64(results.value, HEX);
       Serial.println("");
      // Change below hex value according to your remote
       switch(results.value){
          case 0x6F9FA05:
          Serial.println("Up");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"Input.Up\",\"id\":1}");
          break;
          case 0x6F92AD5:
          Serial.println("Down");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"Input.Down\",\"id\":1}");
          break;
          case 0x6F91AE5:
          Serial.println("Right");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"Input.Right\",\"id\":1}");
          break;
          case 0x6F99A65:
          Serial.println("Left");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"Input.Left\",\"id\":1}");
          break;
          case 0x6F906F9:
          Serial.println("Ok");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"Input.Select\",\"id\":1}");
          break ;  
          case 0x6F9708F:
          Serial.println("Back");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"Input.Back\",\"id\":1}");
          break ;               
          case 0x6F958A7:
          Serial.println("Volume Up");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"Input.ExecuteAction\",\"params\":{\"action\":\"volumeup\"},\"id\":1}");
          break ;  
          case 0x6F97887:
          Serial.println("Volume Down");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"Input.ExecuteAction\",\"params\":{\"action\":\"volumedown\"},\"id\":1}");
          break ;
          case 0x6F908F7:
          Serial.println("Mute");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"Input.ExecuteAction\",\"params\":{\"action\":\"mute\"},\"id\":1}");
          break ;  
          case 0x6F948B7:
          Serial.println("Shutdown");
          httpResponseCode = http.POST("{\"jsonrpc\":\"2.0\",\"method\":\"System.Shutdown\",\"id\":1}");
          break ;  
        
         
    }
      key_value = results.value;
      digitalWrite(LED_BUILTIN, LOW);
      irrecv.resume();  // Receive the next value
      delay(100);
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      digitalWrite(LED_BUILTIN, HIGH);
     }
      // Free resources
      http.end();
    }
    else{
      Serial.println("Wifi Not Connected...");
      }
  }
