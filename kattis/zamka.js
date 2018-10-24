/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/zamka Zamka}
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
  console.log(minSummable(input[0], input[1], input[2]));
  console.log(maxSummable(input[0], input[1], input[2]));
});

const minSummable = (L, D, X) => {
  for (let index = L; index <= D; index++) {
    if (checksum(index) === X) {
      return index;
    }
  }
};

const maxSummable = (L, D, X) => {
  for (let index = D; index >= L; index--) {
    if (checksum(index) === X) {
      return index;
    }
  }
};

const checksum = x => {
  let s = 0;
  while (x !== 0) {
    s += x % 10;
    x = Math.floor(x / 10);
  }
  return s;
};
