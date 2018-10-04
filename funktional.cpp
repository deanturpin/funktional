// #include "vektor.h"
#include "parallel.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

namespace vek {

// VEKTOR - a concatenating vector
template <typename T = double> struct vektor : public std::vector<T> {

  // A constructor with a value pushes the value onto the empty vector
  vektor(const T &a) { this->push_back(a); }

  // Ensure the default constuctor is valid
  vektor() = default;

  // Declare the concatenation operator overloads
  friend vektor operator+(vektor<T> &a, const T &b) {
    a.reserve(a.size() + 1);
    return a.push_back(b);
  }

  friend vektor operator+(vektor<T> &a, const vektor<T> &b) {
    a.reserve(a.size() + b.size());
    for (const auto &c : b)
      a.emplace_back(c);
    return a;
  }

  friend vektor operator+(vektor<T> &&a, const vektor<T> &b) {
    for (const auto &c : b)
      a.push_back(c);
    return a;
  }
};

} // namespace vek

int main() {

  const std::vector<double> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  const auto b(a);
  const auto c = b;
  const auto d = vek::vektor(.1) + 1.1;
  const auto e = vek::vektor(.1) + 2.0 + vek::vektor(101.0) + 1.1;
  const auto f = 2.0 + vek::vektor(101.0) + 1.1;

  assert(b.size() == 10);
  assert(c.size() == 10);
  assert(d.size() == 2);
  assert(e.size() == 4);
  assert(f.size() == 3);
}
