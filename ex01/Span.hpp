#pragma once

#include <vector>
class Span {
public:
  Span();
  Span(unsigned int N);
  Span(const Span &obj);
  ~Span();
  Span &operator=(const Span &obj);

private:
  void addNumber(int number);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  std::vector<int> v;
  unsigned int maxsize;
};
