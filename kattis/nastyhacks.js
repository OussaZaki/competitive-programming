/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/nastyhacks Nasty hacks}
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
  const n = input[0];
  for (let i = 0; i < n; i++) {
    const r = input[3 * i + 1],
      e = input[3 * i + 2],
      c = input[3 * i + 3];
    console.log(worthAdvertising(r, e, c));
  }
});

const worthAdvertising = (r, e, c) => {
  const value = e - c - r;
  return value < 0
    ? "do not advertise"
    : value == 0
      ? "does not matter"
      : "advertise";
};
