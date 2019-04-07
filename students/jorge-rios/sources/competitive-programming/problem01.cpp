#include <iostream>

unsigned int stop(int n) {
  unsigned int saltos = 0;

  while (n != 1) {
    if (n % 2 == 1) {
      n = 3 * n + 1;
      n = n / 2;
      saltos++;
    } else {
      n = n / 2;
    }

    saltos++;
  }

  return ++saltos;
}

int main() {
  int a, b;
  int aToPrint = 0;
  int tmp = 0;
  while (std::cin >> a >> b) {
    aToPrint = a;
    tmp = b;
    int max = 0;
    unsigned int result = 0;

    if (a > b) {
      b = a;
      a = tmp;
    }

    for (int j = a; j <= b; ++j) {
      result = stop(j);
      if (result > max) {
        max = result;
      }
    }

    std::cout << aToPrint << " " << tmp << " " << max << std::endl;
  }
  return 0;
}
