# competitive-programming

My solutions for different programming problems, from different platforms:

- [Kattis 🐱](https://open.kattis.com)
- [Leetcode 🎗](https://leetcode.com)
- [hackerrank ☘️](https://hackerrank.com)
- [Moocs 🎓](https://www.edx.org)
- [AdventOfCode 🎄](https://adventofcode.com)
- [Google Code Jam 🍓](https://codingcompetitions.withgoogle.com/codejam)

## Milestones

### 2020 Goals 🙈

- [ ] top 100 in Kattis.
- [ ] 1 star in Leetcode.
- [ ] 10 ProjectEuler problems from Hackerrank.
- [ ] Finish [Algorithms and Data Structures](https://www.edx.org/micromasters/ucsandiegox-algorithms-and-data-structures) Micro Masters.

## How to run

### Javascript (Node 8)

JavaScript solutions are run in node `v8.11.4`.
Generally, reading is done from [process.stdin](https://nodejs.org/api/process.html#process_process_stdin) (standard input), using the [readline](https://nodejs.org/api/readline.html) interface. Inputs are read at once, sometimes parsed on the go.

```js
// importing and instantiating the readline interface
const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];

// Reading multiple lines, each line include space-split integers
rl.on("line", line => {
  input.push(...line.split(" ").map(x => parseInt(x)));
});
```

Then solution is run once the input stream is closed.

```js
// when there's no more data to process, we run the solution
rl.on("close", () => {
  console.log(solution(input))
});
```

Run a given solution locally using the command below, solution will run on interactive mode, where you can provide inputs on the go, then hit `ctrl + C` to close the input stream.

```bash
node ./kattis/solution.js
```

### C++

I'm using standard input/output `stdin/stdout` to read/write for my c++ implementations.
To run any solution, you can use the command below. Then provide data on your own.

*You can use your preferred c++ compiler, I'm using **g++***

```bash
g++ pathToSolution/solution.cpp -o solution.out && ./solution.out
```

## Ressources

### Editorials

- [Medium](https://medium.com/@TheZaki)