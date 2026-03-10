#pragma once
#include <algorithm>
#include <stdexcept>
#include <vector>
template <typename T>
typename T::iterator easyfind(T &container, const int tofind) {

  typename T::iterator where =
      std::find(container.begin(), container.end(), tofind);
  if (where == container.end())
    throw std::out_of_range("Not Found");
  return (where);
}
