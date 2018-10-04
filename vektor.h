#ifndef VEKTOR_H
#define VEKTOR_H

#include <vector>

namespace vek {

// VEKTOR - a concatenating vector
template <typename T = double> struct vektor : public std::vector<T> {

  // A constructor with a value pushes the value onto the empty vector
  vektor(const T &a) { this->push_back(a); }

  // Construct with a std::vector
  vektor(const std::vector<T> &a) {
    this->reserve(a.size());
    for (const auto &x : a)
      this->push_back(x);
  }

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

#endif
