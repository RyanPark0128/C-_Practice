#ifndef Q_H
#define Q_H
#include <iostream>

class queue {
  public:
    queue();
    int dequeue();
    void enqueue(int x);
    int front();
    bool is_empty();
  private:
    struct node {
      int data;
      node * next;
    };
    node *head, *tail;
}

queue::queue() {
  head = tail = nullptr;
}

int queue::dequeue() {
  if (is_empty()) {
    std::cout << "EMPTY QUEUE";
    exit(1);
  }
  int ret = head->data;
  node * to_del = head;
  head = head->next;
  delete to_del;
  if (!head) {
    tail = head;
  }

  return ret;
}

void queue::enqueue(int x) {
  if (is_empty()) {
    head = new node{x,nullptr};
    tail = head;
  } else {
    tail->next = new node{x,nullptr};
    tail = tail->next;
  }
}

int queue::front() {
  if (is_empty()) {
    std::cout << "EMPTY QUEUE";
    exit(1);
  }
  return head->data;
}

bool queue::is_empty() {
  return !head && !tail;
}
