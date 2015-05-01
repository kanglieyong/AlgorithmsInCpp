bool isPrime(int num)
{
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

int nextPrime(int thePrime)
{
  int num = (thePrime % 2 == 1) ? thePrime + 2 : thePrime + 1;
  for ( ; num < thePrime * thePrime; num += 2) {
    if (isPrime(num)) return num;
  }
  return thePrime * thePrime;
}
