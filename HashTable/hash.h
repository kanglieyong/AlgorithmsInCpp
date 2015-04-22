int hash1(const string& key, int tableSize)
{
  int hashVal = 0;

  for (int i = 0; i < key.length(); i++) {
    hashVal += key[i];
  }

  return hashVal % tableSize;
}

int hash2(const string& key, int tableSize)
{
  return (key[0] + 27 * key[1] + 729 * key[2]) % tableSize;
}

int hash3(const string& key, int tableSize)
{
  int hashVal = 0;

  for (int i = 0; i < key.length(); i++) hashVal = 37 * hashVal + key[i];

  hashVal %= tableSize;
  if (hashVal < 0) hashVal += tableSize;

  return hashVal;
}
