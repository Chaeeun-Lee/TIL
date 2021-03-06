let http = require("http");
let fs = require("fs");
let url = require("url");

http
  .createServer((req, res) => {
    let pathname = url.parse(req.url).pathname;

    console.log(`Request for ${pathname} received.`);

    if (pathname == "/") {
      pathname = "/index.html";
    }

    fs.readFile(pathname.substr(1), (err, data) => {
      if (err) {
        console.log(err);
        res.writeHead(404, { "Content-Type": "text/html" });
      } else {
        res.writeHead(200, { "Content-Type": "text/html" });
        res.write(data.toString());
      }

      res.end();
    });
  })
  .listen(8081);

console.log("Server running at http://127.0.0.1:8081/");
