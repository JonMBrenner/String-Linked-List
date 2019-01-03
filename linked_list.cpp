#include "linked_list.h"

jmb::LinkedList::LinkedList(const LinkedList& other)
  : head_{new Node{other.head_->data_,other.head_->next_}}, size_{other.size_} {
  Node* cur = head_;
  Node* cur_other = other.head_;
  for (std::size_t i = 1; i < size_; ++i) {
    cur_other = cur_other->next_;
    cur->next_ = new Node{cur_other->data_, cur_other->next_};
    cur = cur->next_;
  }
}

jmb::LinkedList& jmb::LinkedList::operator=(const LinkedList& other) {
  if (this == &other) {
    return *this;
  }
  this->~LinkedList();
  size_ = other.size_;
  head_ = new Node{other.head_->data_, other.head_->next_};
  Node* cur = head_;
  Node* cur_other = other.head_;
  for (std::size_t i = 1; i < size_; ++i) {
    cur_other = cur_other->next_;
    cur->next_ = new Node{cur_other->data_, cur_other->next_};
    cur = cur->next_;
  }
  return *this;
}

jmb::LinkedList::~LinkedList() {
  Node* cur = head_;
  Node* next;
  for (std::size_t i = 0; i < size_; ++i) {
    next = cur->next_;
    delete cur;
    cur = next;
  }
}

bool jmb::LinkedList::empty() const {
  return !size_ && !head_;
}

int jmb::LinkedList::size() const {
  return size_;
}

void jmb::LinkedList::append_front(std::string data) {
  head_ = new Node{data, head_};
  ++size_;
}

void jmb::LinkedList::append_back(std::string data) {
  if (this->empty()) {
    head_ = new Node{data, nullptr};
  } else {
    Node* cur = head_;
    for (std::size_t i = 0; i < size_ - 1; ++i) {
      cur = cur->next_;
    }
    cur->next_ = new Node{data, nullptr};
  }
  ++size_;
}

void jmb::LinkedList::remove(std::size_t index) {
  //TODO: raise error for out of bound index
  Node* remove;
  if (index == 0) {
    remove = head_;
    head_ = head_->next_;
  } else {
    Node* cur = head_;
    for (std::size_t i = 0; i < index-1; ++i) {
      cur = cur->next_;
    }
    remove = cur->next_;
    cur->next_ = cur->next_->next_;
  }
  delete remove;
  --size_;
}

std::string& jmb::LinkedList::operator[](std::size_t index) {
  //TODO: raise error for out of bound index
  Node* cur = head_;
  for (std::size_t i = 0; i < index; ++i) {
    cur = cur->next_;
  }
  return cur->data_;
}

const std::string& jmb::LinkedList::operator[](std::size_t index) const {
  //TODO: raise error for out of bound index
  Node* cur = head_;
  for (std::size_t i = 0; i < index; ++i) {
    cur = cur->next_;
  }
  return cur->data_;
}

bool jmb::LinkedList::operator==(const LinkedList& other) const {
  if (size_ != other.size_) {
    return false;
  }
  Node* cur = head_;
  Node* cur_other = other.head_;
  for (std::size_t i = 0; i < size_; ++i) {
    if (cur->data_ != cur_other->data_) {
      return false;
    }
    cur = cur->next_;
    cur_other = cur_other->next_;
  }
  return true;
}

bool jmb::LinkedList::operator!=(const LinkedList& other) const {
  return !(*this == other);
}
