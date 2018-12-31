#ifndef LINKED_LIST_JMB_H_
#define LINKED_LIST_JMB_H_

#include <cstddef>
#include <string>

namespace jmb {
class LinkedList {
  public:
    LinkedList() = default;
    bool empty() const;
    int size() const;

  private:
    struct Node {
      std::string data_;
      Node* next_{};
    };
    Node* head_{};
    std::size_t size_{};
};
}

#endif
