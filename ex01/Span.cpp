#include "Span.hpp"
#include <algorithm>
// #include <iostream>
Span::Span() : maxsize(67) {}

Span::Span(unsigned int N) : maxsize(N) {}

Span::Span(const Span &other) { this->v = other.v; }

Span &Span::operator=(const Span &obj) {
  if (this == &obj)
    return (*this);
  this->maxsize = obj.maxsize;
  this->v.assign(obj.v.begin(), obj.v.end());
  return (*this);
}

Span::~Span() {}

/*                                         */

void Span::addNumber(int number) {
  if (this->v.size() >= this->maxsize)
    throw(std::length_error("Max size exceeded"));
  this->v.push_back(number);
}

unsigned int Span::shortestSpan() {
  long shortest = -1;
  if (this->v.size() <= 1)
    throw(std::length_error("invalid shortest span call"));
  std::sort(this->v.begin(), this->v.end());
  std::vector<int>::iterator it = this->v.begin();
  while (it + 1 != this->v.end()) {
    if (shortest == -1 || absDiff(*(it + 1), *it) < shortest)
      shortest = absDiff(*(it + 1), *it);
    it++;
  }
  return (static_cast<unsigned int>(shortest));
}
unsigned int Span::longestSpan() {
  if (this->v.size() <= 1)
    throw(std::length_error("invalid longest span call"));
  std::sort(this->v.begin(), this->v.end());
  return (static_cast<unsigned int>(absDiff(this->v.back(), this->v.front())));
}

int Span::absDiff(int a, int b) {
  if (a < b)
    return (b - a);
  else
    return (a - b);
}
/*                                              */

std::vector<int> vectorGenerator(int amount) {
  std::vector<int> v;
  srand(0);
  for (int i = 0; i < amount; i++) {
    v.push_back(random());
    // std::cout << v[i] << std::endl;
  }
  return (v);
}
