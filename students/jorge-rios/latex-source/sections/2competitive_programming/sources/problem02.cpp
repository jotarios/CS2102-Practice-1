#include <iostream>

int main() {
  std::string line;
  while (getline(std::cin, line)) {
    for (auto &l : line) {
      std::cout << char(l - 7);
    }

    std::cout << std::endl;
  }

  return 0;
}
