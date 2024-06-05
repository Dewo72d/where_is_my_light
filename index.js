const bot = require("./bot.js");
const express = require("express")


const yourChatId = 'chatid';


const app = express();
const port = 3001;
const validToken = 'token';

app.post('/light', (req, res) => {
    const { token } = req.query;

    if (token !== validToken) {
        return res.sendStatus(200)
    }
    bot.sendMessage(yourChatId, "LIGHT, U CAN BACK TO HOME")

    return res.sendStatus(200)

});


app.get("/ping", (req,res) =>{
    console.log("PING >> ");
    return res.sendStatus(200)
})

app.listen(port,"0.0.0.0", () => {
    console.log(`http://localhost:${port}`);
});