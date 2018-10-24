/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/kornislav Kornislav}
 * @author Oussama Zaki <zaki.oussama@gmail.com>
 */

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const input = [];
rl.on("line", line => {
  input.push(...line.split(" ").map(x => parseInt(x)));
});

rl.on("close", () => {
  input.sort();
  console.log(largestArea(input[0], input[2]));
});

const largestArea = (width, height) => {
  return width * height;
};
