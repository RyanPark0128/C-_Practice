#include <iostream>


struct node{
  int data;
  node* next;
};
void print (node * p) {
    for (;p;p=p->next) {
      std::cout << p->data << " ";
    }
    std::cout << std::endl;
  }


node * r_append(int x, node *p) {
  if (!p) {
    return new node{x,nullptr};
  }
  p->next = r_append(x,p->next);
  return p;
}
node* append(int x, node* p) {
    node *h = p;
    if (!p) {
      return new node{x,p};
    }
    while (p->next) {
        p= p->next;
    }
    p->next = new node {x,nullptr};
    return h;

    }

node * insert(int x, node * p) {
  if (!p || p->data > x) {
    return new node{x,p};
  }
  p->next = insert(x, p->next);
  return p;
}

int main() {
  node * h = new node{1,new node{2,new node{4,new node{7,new node{10,nullptr}}}}};
  print(h);
  h = append(17,h);
  print(h);

  return 0;
}