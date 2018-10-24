/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/autori Autori}
 * @author Oussama Zaki <zaki.oussama@gmail.com>
 */

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let name = "";
rl.on("line", line => {
  name = line;
});

rl.on("close", () => {
  console.log(shortName(name));
});

const shortName = name => {
  return name
    .split("")
    .reverse()
    .filter(c => c !== "-" && c == c.toUpperCase())
    .reduce((c, result) => result + c, "");
};
