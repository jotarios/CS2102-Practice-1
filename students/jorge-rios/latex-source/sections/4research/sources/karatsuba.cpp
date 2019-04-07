#include <iostream>
#include <cmath>
#include <assert.h>
#include <iomanip>

#define number long double
#define maxDigits unsigned long

class Multiplication {
  number numberOne;
  number numberTwo;
  number base = 2;

 public:
  Multiplication(number a, number b) {
    this->numberOne = a;
    this->numberTwo = b;
  }

  number getNumberOne() const {
    return numberOne;
  }

  number getNumberTwo() const {
    return numberTwo;
  }

  void setBase(int newBase) {
    this->base = newBase;
  }

  maxDigits maxNumberOfDigits(number first, number second) {
    auto a = (int) first;
    auto b = (int) second;

    if (a > b) {
      return std::to_string(a).length();
    }

    return std::to_string(b).length();
  }

  number karatsuba(number first, number second) {
    if (first <= 9 && second <= 9) {
      return first * second;
    }

    maxDigits digits = maxNumberOfDigits(first, second);
    auto m = std::ceil(digits / 2);

    auto exp = std::pow(this->base, m);

    auto x1 = std::floor(first / exp);
    auto x2 = std::fmod(first, exp);

    auto y1 = std::floor(second / exp);
    auto y2 = std::fmod(second, exp);

    number z2 = karatsuba(x1, y1);
    number z0 = karatsuba(x2, y2);
    number z1 = karatsuba(x1 + x2, y1 + y2) - z2 - z0;

    return z2 * std::pow(this->base, m * 2) + z1 * (exp) + z0;
  }
};

int main() {
  auto calculator = new Multiplication(3456, 8750);
  number result = calculator->karatsuba(calculator->getNumberOne(),
                                        calculator->getNumberTwo());

  std::cout << std::setprecision(68);
  std::cout << result;

  return 0;
}
