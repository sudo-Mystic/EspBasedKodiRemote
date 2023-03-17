# ESP8266 Kodi IR Remote 🎮📺

ESP8266 Kodi IR Remote

🚀 This is an ESP8266 (NodeMCU) based Kodi media server remote that takes input from an IR remote and sends HTTP POST requests to control Kodi. You can customize the code using Kodi's JSON-RPC API.

## Installation

1. Make sure you have set up the Arduino IDE to upload code to the ESP8266. You can find many guides on the internet to help you with this. 👨‍💻
2. Add the IRRemoteESP8266 library from the Library Manager in the IDE. 📚
3. Upload the IRRecvDump V2 code from the library examples. 🚀
4. Connect the IR receiver to GPIO14 (D5). 🔌
5. After uploading the code, open the serial monitor and decode your IR remote with the keys you want to use. Note them down. 🧐
6. Upload the ESPKodiRemote code. You will need to make some changes to make it work for you:
    * Add your WiFi credentials.
    * The local IP of your Kodi device.
    * The hex codes of the IR remote in the Switch Statement of the code. (I will add comments in the code to make it easier for you.) 👨‍💻

You are now good to go! 😎

## Features

* Control Kodi with an IR remote. 🎮
* Uses Kodi's JSON-RPC API to customize the remote control behavior. 🛠️
* Easy to set up and customize. 🚀

## Troubleshooting

If you encounter any issues while setting up or using the remote control, please check the following:

* Make sure the IR receiver is connected to the correct GPIO pin (GPIO14/D5).
* Check that you have entered the correct WiFi credentials and local IP address of your Kodi device.
* Ensure that you have added the correct hex codes for the keys of your IR remote in the Switch Statement of the code. 🧐

If you are still experiencing issues, please feel free to contact me at mrmysticuniverse@gmail.com.

## Contributing

If you would like to contribute to the project, please follow these steps:

1. Fork the repository.
2. Create a new branch.
3. Make your changes and commit them.
4. Push your changes to your fork.
5. Submit a pull request. 🤝

## Contact

If you have any questions or feedback about the project, please feel free to contact me at mrmysticuniverse@gmail.com. 📧
