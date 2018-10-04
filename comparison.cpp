#include "vektor.h"
#include <cassert>
#include <iostream>
#include <string>

namespace strings {

template <typename T> T generationX(const int n) {
  return n > 1 ? generationX<T>(n - 1) + "X" : "X";
}

void comparison(const int n) {

  // Iterative
  std::string iterative;
  for (int i = 0; i < n; ++i)
    iterative += "X";

  // Recursive
  const auto recursive = generationX<std::string>(n);

  assert(iterative == recursive);
}
} // namespace strings

namespace vectors {

vek::vektor<std::string> generationX(const int n) {
  return n > 1 ? generationX(n - 1) + vek::vektor<std::string>("X")
               : vek::vektor<std::string>("X");
}

void comparison(const int n) {

  // Iterative
  std::vector<std::string> iterative;
  for (int i = 0; i < n; ++i)
    iterative.push_back("X");

  // Recursive
  const auto recursive = generationX(n);

  assert(iterative == recursive);
}

} // namespace vectors
int main() {

  const int n = 10;
  strings::comparison(n);
  vectors::comparison(n);
}
