#include "vektor.h"
#include <cassert>
#include <iostream>
#include <string>

std::string generate(const int n) {
  return n > 1 ? generate(n - 1) + std::to_string(n - 1) : "0";
}

void strings(const int n) {

  // Iterative
  std::string iterative;
  for (int i = 0; i < n; ++i)
    iterative += std::to_string(i);

  // Recursive
  const std::string recursive = generate(n);

  for (const auto &y : {iterative, recursive})
    std::cout << y << '\n';

  assert(iterative == recursive);
}

vek::vektor<double> generate_vector(const int n) {
  return n > 0 ? generate_vector(n - 1) + n : 0;
}

void vectors(const int n) {

  // Iterative
  std::vector<double> iterative;
  for (int i = 0; i < n; ++i)
    iterative.push_back(i + 1);

  // Recursive
  vek::vektor<double> recursive = generate_vector(n);

  for (const auto &y : {iterative, std::vector<double>(recursive)})
    for (const auto &x : y)
      std::cout << x << '\n';

  assert(iterative == recursive);
}

int main() {

  const int n = 10;
  strings(n);
  vectors(n);
}
