# Where is my light

This project consists of a Node.js server and an ESP8266 client that work together to notify a user via Telegram when a light is turned on.
## Installation
```bash
npm install express node-telegram-bot-api
```
Also install `ESP8266WiFi.h` and `ESP8266HTTPClient.h` in your ArduinoIDE

## Usage

Replace these lines according to your server, router and .js files  configuration.

```
http.begin(client, "http://0.0.0.0:3001/light?&token=your_token");
http.begin(client, "http://0.0.0.0:3001/ping"); 
const bot = new TelegramBot('youre_bot_token', {polling: true});
const validToken = 'token';
```

Configure `systemd` to automatically start the `index.js` server.
```bash
nano /etc/systemd/system/example.service
```
