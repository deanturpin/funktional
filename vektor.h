#ifndef VEKTOR_H
#define VEKTOR_H

#include <type_traits>
#include <vector>

namespace vek {

// VEKTOR - a concatenating vector
template <typename T = double> struct vektor : public std::vector<T> {

  // A constructor with a value pushes the value onto the empty vector
  vektor(const T &a) { this->push_back(a); }

  // std::vector has non-virtual destructors so we can't do this
  // virtual ~vektor() = default;

  // Nor can we add members that might not be destroyed properly
  // int blah;

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

// IOTA
template <typename T = double> vek::vektor<T> iota(const int n) {
  return n <= 0 ? vek::vektor<T>() : iota(n - 1) + n;
}

// Assertive
static_assert(std::is_standard_layout<vektor<double>>::value);
static_assert(std::is_constructible<vektor<double>>::value);
static_assert(std::is_default_constructible<vektor<double>>::value);
static_assert(std::is_copy_constructible<vektor<double>>::value);
static_assert(std::is_move_constructible<vektor<double>>::value);
static_assert(std::is_assignable<vektor<double>, std::vector<double>>::value);
static_assert(std::is_assignable<std::vector<double>, vektor<double>>::value);
static_assert(std::is_move_assignable<vektor<double>>::value);
static_assert(std::is_destructible<vektor<double>>::value);
static_assert(!std::has_virtual_destructor<vektor<double>>::value);

} // namespace vek

#endif
