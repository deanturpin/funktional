#ifndef PARALLEL_H
#define PARALLEL_H

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

namespace parallel {

const auto thread_count = std::thread::hardware_concurrency();

template <typename Iterator, typename Functor>
void for_each(Iterator begin, Iterator end, Functor func) {

  const auto calculations = std::distance(begin, end);
  const unsigned long calculations_per_thread =
      std::ceil(1.0 * calculations / thread_count);

  struct worker_t {
    Iterator a{};
    Iterator b{};
  };

  std::vector<worker_t> workers;

  const std::function<void(Iterator, Iterator, int)> populate =
      [&workers, &begin, &end, &calculations_per_thread,
       &populate](const Iterator a, const Iterator b, const int n) {
        if (n == 0)
          return;

        workers.push_back({a, b});

        populate(a, b, n - 1);
      };

  populate(begin, std::min(std::next(begin, calculations_per_thread), end),
           thread_count);

  std::cout << workers.size() << " workers\n";

  // Partition data for each thread
  std::vector<std::thread> threads;
  for (unsigned int i = 0; i < thread_count; ++i) {

    // Initialise iterators
    thread_local auto front = begin;
    thread_local auto back =
        std::min(std::next(front, calculations_per_thread), end);

    // Process each partition
    threads.push_back(std::thread(
        [&func](auto f, auto b) { std::for_each(f, b, func); }, front, back));

    front = back;
    back = std::min(std::next(front, calculations_per_thread), end);
  }

  // Wait for all threads to finish
  for (auto &thr : threads)
    if (thr.joinable())
      thr.join();
}
} // namespace parallel

#endif
