#include "Span.hpp"
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
unsigned int Span::shortestSpan() {
  if (this->v.size() <= 1)
    throw(std::length_error("invalid shortest span call"));
}
unsigned int Span::longestSpan() {}
