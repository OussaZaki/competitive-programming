/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/quadrant Quadrant}
 * @author Oussama Zaki <zaki.oussama@gmail.com>
 */

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const input = [];
rl.on("line", line => {
  input.push(parseInt(line));
});

rl.on("close", () => {
  console.log(wichQuadrant(input[0], input[1]));
});

const wichQuadrant = (x, y) => {
  if (x > 0) {
    return y > 0 ? 1 : 4;
  } else {
    return y > 0 ? 2 : 3;
  }
};
