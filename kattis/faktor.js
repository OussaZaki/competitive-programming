/**
 * Javascript(Node8) solution for {@link https://open.kattis.com/problems/faktor Faktor}
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
  console.log(minScientistCount(input[0], input[1]));
});

const minScientistCount = (articleCount, faktor) => {
  return (faktor - 1) * articleCount + 1;
};
