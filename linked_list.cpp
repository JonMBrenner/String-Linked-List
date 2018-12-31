#include "linked_list.h"

bool jmb::LinkedList::empty() const {
  return !size_ && !head_;
}

int jmb::LinkedList::size() const {
  return size_;
}
