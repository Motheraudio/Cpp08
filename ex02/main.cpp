#include "MutantStack.hpp"
#include <iostream>
#include <list>
int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  std::cout << "top: " << mstack.top() << std::endl;
  MutantStack<int>::iterator it = mstack.begin();
  std::cout << "begin: " << *(mstack.begin()) << std::endl;
  // why begin and top are different?
  //  top() -> returns the last element (back of deque) = most recently pushed
  //  begin() -> returns iterator to the first element (front of deque) = oldest
  //  pushed
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  std::cout << "-----------------" << std::endl;
  std::list<int> mlist;
  mlist.push_front(5);
  mlist.push_front(17);
  std::cout << *mlist.begin() << std::endl;
  mlist.pop_front();
  std::cout << mlist.size() << std::endl;
  mlist.push_back(3);
  mlist.push_back(5);
  mlist.push_back(737);
  //[...]
  mlist.push_back(0);
  std::list<int>::iterator itl = mlist.begin();
  std::list<int>::iterator itel = mlist.end();
  ++itl;
  --itl;
  while (itl != itel) {
    std::cout << *itl << std::endl;
    ++itl;
  }
  std::cout << "xxxxxxxxx" << std::endl;
  MutantStack<int>::reverse_iterator itr = mstack.rbegin();
  std::cout << *(itr + 1) << std::endl;
  MutantStack<int>::reverse_iterator itr2 = mstack.rend();
  std::cout << *(itr2 - 1) << std::endl;
  MutantStack<int>::const_iterator itc = mstack.begin();
  MutantStack<int>::const_reverse_iterator itcr = mstack.rbegin();
  // *itc += 1;  // cant modify the value when dereferencing due to const
  // *itcr -= 1;  // cant modify the value when dereferencing due to const
  std::cout << *itc << std::endl << *(itcr - 1) << std::endl;
  return 0;
}
