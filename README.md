This is a ESP8266[NodeMCU] Based kodi media server remote which takes input from and IR remote and send http POST request to control anything to kodi

Remote work using Kodi's jsonrpc API so you can customise the code according to it

**Installation**

1. Make you setup the Arduino IDE to upload code to ESP [you can checkout many guides on internet]
2. Add the IRRemoteESP8266 Library from the library manager in the IDE
3. Upload the IRRecvDump V2 code from library examples 
4. Connect IR Receiver on GPIO14 [D5]
4. After uploading the code open serial monitor and decode your IR remote with the keys you want to use and Note them down
5. After that upload my ESPKodiRemote Code , you have to change some things to make it work for you
 (i). Add your wifi credentials
 (ii). The Local IP of your Kodi Device.
 (iii). The Hex codes of IR remote in Switch Statement of code [i will add comments in code to make it easier]
6. You are now good to go :)



**I am not a pro coder , you may find the code bit inefficient feel free to improve it**
