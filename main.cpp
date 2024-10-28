#include <iostream>

int Print() {
  int n = 1;
  if (n == 1) {
    ++n;
  } else {
    --n;
  }
  return n;
  std::cout << "Hello world\n";
}

int main() {
  Print();
  return 0;
}
