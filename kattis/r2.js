/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/r2 R2}
 * @author Oussama Zaki <zaki.oussama@gmail.com>
 */

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];
rl.on("line", line => {
  input.push(...line.split(" ").map(x => parseInt(x)));
});

rl.on("close", () => {
  console.log(r2(input[0], input[1]));
});

const r2 = (r1, s) => {
  return 2 * s - r1;
};
