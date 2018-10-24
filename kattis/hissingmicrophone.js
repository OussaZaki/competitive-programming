/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/hissingmicrophone Hissing microphone}
 * @author Oussama Zaki <zaki.oussama@gmail.com>
 */

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input;
rl.on("line", line => {
  input = line;
});

rl.on("close", () => {
  console.log(hasHiss(input));
});

const hasHiss = word => {
  const doubleS = /ss/;
  return doubleS.test(word) ? "hiss" : "no hiss";
};
