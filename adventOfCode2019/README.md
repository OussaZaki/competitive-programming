# Advent of code solutions

I solved the y.2018 using c++.

I wrote my own **makefile** to autogenerate a daily solution template (cpp), and fetch my daily input files.
In order to use the same setup as me, make sure to export your session cookie as an environment variable.

```bash
export AOC_COOKIE="<your_session_cookie>"
```

You can retrieve your session cookie from the browser after you successfully logged in to AoC.

- to autogenerate day 7, run:

```bash
make -s init day=7
```

- to compile and run your solution, run:

```bash
make run day=7
```

- to clean all output files, run:

```bash
make clean
```

## Execution time

You can track execution time of each function or the whole program by using `START_TIMING` and `END_TIMING`. See below example:

```c++
int main()
{
  // Time the whole program
  START_TIMING
  vector<Claim*> claims = get_inputs();
  cout << day3_part1(claims) << endl;
  cout << day3_part2(claims) << endl;
  END_TIMING
}
```

```c++
int main()
{
  vector<Claim*> claims = get_inputs();
  cout << day3_part1(claims) << endl;
  // Time the part2 only
  START_TIMING
  cout << day3_part2(claims) << endl;
  END_TIMING
}
```

## Ressources

### Editorials [WIP]
