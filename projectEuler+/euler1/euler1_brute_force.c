long long euler1(long long N) {
  long long i, sum = 0;
  for (i = 3; i < N; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  return sum;
}
