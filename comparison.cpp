#include "vektor.h"
#include <cassert>
#include <iostream>
#include <string>

std::string generate(const int n) {
  return n > 1 ? generate(n - 1) + std::to_string(n - 1) : "0";
}

int main() {

  const int n = 10;

  // Iterative approach
  std::string a;
  for (int i = 0; i < n; ++i)
    a += std::to_string(i);

  // Functional approach using recursion
  const std::string b = generate(n);

  for (const auto &x : {a, b})
    std::cout << x << '\n';

  assert(a == b);
}
