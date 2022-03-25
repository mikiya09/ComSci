

# Node.js 

    [concept!] node.js free javascript from the browser, create ways(API?) allowing js interact with computer directly (like server)
      - think of C++, it will manipulate memory directly through pointers; 
      - javacripts is high-level language, cannot interact with low level things directly; use c++ and pointers to understand node.js
      - this low level technology


# Server
    [updating...]

    [!]: port: 3000 (channel?)

    [!]: resquest <- back & forth -> send

    [!] why server?
      >> one way of running and rendering html & css & js is on the FrontEnd, browser itself
      >> the other way is by sending all the code, and running on the somewhere that has large memory or capacity, and then send only the outcome back
      >> so that free browser to do more complex things

# Express
    
    [!]: extention or add-on of Node, done something specific = server stuff

    [+]: work need to be done inside nvm
    >> cd "some directory"
    >> npm init
    : fill in the informtaion, enter means set default] -> a package.json file will be added 

    [+]: install -> seems to do that for every new folder
    >> npm install express

    [+]: automatically update .js file, so that won't need to stop and restart server again every time
    >> npm install -g nodemon
    >> nodemon server.js

    [+]: allow we to parse the data sent through post method to properties and variables
    >> npm install body-parser

    
# ex).

    [1] get is a method: automatically combine with a resquest sent and a response sending back --> so there is two behavior hidden: send request & receive message
    [1] first parameter "/" means the path, where the server is looking responding
    [1] function that react to req and res
    [1] response here is not the somethings user received, is something computer receive
    
    [2] __dirname is a method print out the path where "__dirname" currently at
    [2] so this is saying sending index.html file at this location back to user connect to our server

    [3] when sending data to server through html, you will need to include: <form action="/" method="post">
    [3] method is how you will interact with server
    [3] action is where you will interact with server
    [3] if not .post method capturing data sending through html, meaning there is not such function inside server, and that is user's wrong operation, and result in 404

    [4] print out the data sending from other place to out server

    ====================== ex =========================
    >> const express = require("express");                    --- loading express package
    >> const bodyParser = require("body-parser");             --- loading parser package

    >> const app = express();                                 --- creating express object for interacting with server
    >> app.use(bodyParser.urlencoded({extended: true}));      --- parser object that can parser the data(into var, etc) received by the server

    >> app.get("/", function(req, res) {                      --- 1
          res.sendFile(__dirname + "/index.html");            --- 2
        });

    >> app.post("/", function(req, res) {                     --- 3
        console.log(req.body);                                --- 4

        var first_num = Number(req.body.n1);                  --- store parer variable for calculation 
        var second_num = Number(req.body.n2);

        var result = first_num + second_num;                  --- perform calculation

          res.send("The result is " + result);                --- send response back 

        });

    >> app.listen(3000, function() {                          --- listen method print out something when successfully reach to server
        console.log("server is running on port 3000.")
        })



# HTML

    <body>
      <h1>Reach</h1>
      <form action="/" method="post">
        <input type="text" name="n1" placeholder="First Number">
        <input type="text" name="n2" placeholder="Second Number">
        <button type="submit" name="submit">Calculate</butoon>
      </form>
    </body>










