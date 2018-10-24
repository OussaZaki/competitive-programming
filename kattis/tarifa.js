/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/tarifa Tarifa}
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
  console.log(fitMatches(input));
});

const fitMatches = input => {
  const X = input[0],
    N = input[1];
  let sum = 0;
  for (let i = 2; i < input.length; i++) {
    sum += input[i];
  }
  return X * N - sum + X;
};
