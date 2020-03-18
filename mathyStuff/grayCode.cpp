//Finding gray code
int g (int n) {
    return n ^ (n >> 1);
}

//finding inverse gray code
int rev_g (int g) {
  int n = 0;
  for (; g; g >>= 1)
    n ^= g;
  return n;
}

