#include <iostream>

struct node {
  int data;
  node * next;
};

// two ways, 1) manipulate pointers 2) change values to be in order
node* sel_sort(node * p) {

  for (node * i =p; i; i= i->next) {
    node * min = i;
    for (node * j= i->next; j; j= j->next) {
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



int main() {
  node * h = new node{4,new node{0,new node{7,new node{12,new node{2,new node{9,new node}}}}}};
  h = sel_sort(h);
  for (node * temp =h; temp; temp= temp->next) {
    std::cout << temp->data << " ";
  }
  return 0;
}