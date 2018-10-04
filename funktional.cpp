#include "parallel.h"
#include "vektor.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {

  const std::vector<double> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  const vek::vektor b(a);
  const vek::vektor c = b;
  const auto d = vek::vektor(.1) + 1.1;
  const auto e = vek::vektor(.1) + 2.0 + vek::vektor(101.0) + 1.1;
  const auto f = 2.0 + vek::vektor(101.0) + 1.1;
  const vek::vektor g = 3.0;
  const vek::vektor h = 3.0 + 4.0;
  const vek::vektor i = 3.0 + 4.0 + vek::vektor(.2);

  assert(b.size() == 10);
  assert(c.size() == 10);
  assert(d.size() == 2);
  assert(e.size() == 4);
  assert(f.size() == 3);
  assert(g.size() == 1);
  assert(h.size() == 1);
  assert(h.back() > 4.0);
  assert(i.size() == 2);
  assert(i.front() > 3.0);

  const auto a_sum = std::accumulate(a.cbegin(), a.cend(), 0.0);

  assert(a_sum < std::accumulate(b.cbegin(), c.cend(), 1.0));
  assert(a_sum < std::accumulate(c.cbegin(), c.cend(), 1.0));
  assert(std::accumulate(i.cbegin(), i.cend(), 0.0) > 7.0);
}
