/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/planina Planina}
 * @author Oussama Zaki <zaki.oussama@gmail.com>
 */

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];
rl.on("line", line => {
  input.push(parseInt(line));
});

rl.on("close", () => {
  console.log(numberOfDots(input[0]));
});

const numberOfDots = i => {
  return Math.pow(Math.pow(2, i) + 1, 2);
};
