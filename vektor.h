#ifndef VEKTOR_H
#define VEKTOR_H

#include <vector>

// VEKTOR - a concatenating vector
template <typename T> struct vektor : public std::vector<T> {

  // A constructor with a value pushes the value onto the empty vector
  explicit vektor(const T &a) { this->push_back(a); }

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

#endif
