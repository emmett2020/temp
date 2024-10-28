#include <iostream>

int Print() {
  int n = 1;
  if (n == 1) {
    ++n;
  } else {
    --n;
  }
  std::cout << "Hello world\n";
  return n;
}

int main() {
  Print();
  return 0;
}
