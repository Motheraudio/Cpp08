#pragma once

#include <vector>
class Span {
public:
  Span();
  Span(unsigned int N);
  Span(const Span &obj);
  ~Span();
  Span &operator=(const Span &obj);
  void addNumber(int number);
  int shortestSpan();

private:
  int longestSpan();
  std::vector<int> v;
  unsigned int maxsize;
};
