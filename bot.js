const TelegramBot = require('node-telegram-bot-api');

const bot = new TelegramBot('youre_bot_token', {polling: true});


module.exports = bot;