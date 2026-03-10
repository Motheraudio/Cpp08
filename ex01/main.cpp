#include "Span.hpp"
#include <iostream>
int main() {
  Span sp(10);
  std::vector<int> hehe = vectorGenerator(10);
  sp.addRange(hehe.begin(), hehe.end());
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  Span sp2(sp);
  std::cout << sp2.shortestSpan() << std::endl;
  std::cout << sp2.longestSpan() << std::endl;
  Span sp3(88);
  sp3 = sp;
  std::cout << sp3.shortestSpan() << std::endl;
  std::cout << sp3.longestSpan() << std::endl;
  try {
    sp3.addNumber(63);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  Span sp4(10);
  sp4.addNumber(1);
  try {
    std::cout << sp4.shortestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  Span sp5(10);
  try {
    std::cout << sp5.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
