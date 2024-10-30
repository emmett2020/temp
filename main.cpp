#include <iostream>
#include <string.h>

int Print() {
  int n = 1;
  if (n == 1) {
    ++n;
  } else {
    --n;
  }
  std::cout << "Hello world\n";
  int n2 = 1.1;

  return n;
}

int main() {

  Print();
  return 0;
}
