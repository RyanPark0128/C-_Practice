#include <iostream>


struct node {
  int data;
  node* next;
};

node * insert(int x, node * p) {
  if (!p) {
    return new node{x,p};
  }

  p->next = insert(x,p->next);
  return p;
}

node * remove(int x, node *p) {
  if (!p) {
    return p;
  }

  if (p->data == x) {
    node * tmp = p;
    p = p->next;
    delete tmp;
    return remove(x,p);
  }

  p->next = remove(x,p->next);
  return p;
}

void print(node * p) {
  node * tmp = p;
  while (tmp) {
    std::cout << tmp->data << " ";
    tmp = tmp->next;
  }
  std::cout << std::endl;
}

node * sort(node * p) {
  for (node * i=p; i; i=i->next) {
    node * min = i;
    for (node * j=i->next; j; j=j->next) {
      if (min->data > j->data) {
        min = j;
      }
    }

    int tmp = min->data;
    min->data = i->data;
    i->data = tmp;
  }

  return p;
}

node* partition(node *p) {
  if (!p) {
    return p;
  }
  for (node * i=p; i; i=i->next) {
    node * max = i;
    for (node * j=i->next; j; j=j->next) {
      if (max->data < j->data) {
        max = j;
      }
    }

    int tmp = i->data;
    i->data = max->data;
    max->data = tmp;
  }
  return p;
}

int main () {
  node * head = new node{7, nullptr};
  head = insert(10, head);
  head = insert(5, head);
  head = insert(3, head);
  head = insert(2, head);
  head = insert(20, head);
  head = insert(17, head);
  head = insert(4, head);
  head = remove(5, head);
  head = partition(head);
  print(head);

  return 0;
}

