#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
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
int Span::shortestSpan() {
  int shortest = -1;
  if (this->v.size() <= 1)
    throw(std::length_error("invalid shortest span call"));
  std::sort(this->v.begin(), this->v.end());
  std::vector<int>::iterator it = this->v.begin();
  while (it + 1 != this->v.end()) {
    if (shortest == -1 || *(it + 1) - *it < shortest)
      shortest = *(it + 1) - *it;
    it++;
  }
  return (shortest);
}
int Span::longestSpan() {
  int longest = -1;
  if (this->v.size() <= 1)
    throw(std::length_error("invalid longest span call"));
  std::sort(this->v.rbegin(), this->v.rend());
  std::vector<int>::iterator it = this->v.begin();
  while (it + 1 != this->v.end()) {
    if (longest == -1 || *it - *(it + 1) > longest)
      longest = *it - *(it + 1);
    it++;
  }
