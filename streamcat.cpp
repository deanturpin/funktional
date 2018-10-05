#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int z() { return 0; }

int main() {

  // const auto a = std::string{} + "1 " + "2 " + "3 " + "4 ";
  // std::cout << a << '\n';
  // std::stringstream b(a);
  // std::vector<int> c {std::istream_iterator<int>(b), {}};

  // const std::vector<int> d (1.1);
  // const std::vector<int> e {1.1};

  int x();
  int y{};

  std::cout << x() << " x\n";
  std::cout << y << " y\n";
  std::cout << z << " y\n";
}

int x() { return 2; }
