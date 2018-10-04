#include "vektor.h"
#include "parallel.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {

  // Create some test data
  std::vector<double> a(1e4 + 13);
  std::iota(a.begin(), a.end(), 1.1);

  // Create copies to work with
  auto b = a;
  auto c = a;

  // The worker routine
  const auto do_things = [](auto &i) { i = std::sqrt(i + 1.0 / 1000000); };

  // Serial application
  std::for_each(b.begin(), b.end(), do_things);

  // Parallel application
  parallel::for_each(c.begin(), c.end(), do_things);

  assert(b == c);
}
