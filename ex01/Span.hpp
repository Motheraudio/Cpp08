#pragma once

#include <stdexcept>
#include <vector>
class Span {
public:
  Span();
  Span(unsigned int N);
  Span(const Span &obj);
  ~Span();
  Span &operator=(const Span &obj);
  void addNumber(int number);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  template <typename U> void addRange(U r1, U r2) {
    while (r1 != r2) {
      if (this->v.size() >= this->maxsize)
        throw(std::length_error("Max size exceeded"));
      this->v.push_back(*r1);
      r1++;
    }
  }

private:
  std::vector<int> v;
  int absDiff(int a, int b);
  unsigned int maxsize;
};

std::vector<int> vectorGenerator(int amount);
