#include <iostream>
#include <vector>


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
//mine
node * vect2ll(std::vector<int> & v) {
  node *h = new node{v[0], nullptr};
  node *p = h;
  for (int i=1; i< v.size(); i++) {
    p->next = new node{v[i], nullptr};
    p = p->next;
  }

  return h;
}

//Ryan's with loop
node * vect2ll(std::vector<int> & v) {
  node* h = nullptr;
  for (int i= v.size()-1; i >= 0; i--) {
    h = new node{v[i],h};
  }
  return h;
}

//#2 recursive
node * vect2ll(std::vector<int> & v, int i=0) {
  if (i == v.size()) {
    return nullptr;
  }

  return new node{v[i], vect2ll(v,i+1)};
}



int main() {
  node * h = new node{1,new node{2,new node{4,new node{7,new node{10,nullptr}}}}};
  // print(h);
  // h = append(17,h);
  // print(h);
  // h = insert(6,h);
  std::vector<int> v = {5,12,16,22,90,101};
  node* p = vect2ll(v);
  print(p);
  return 0;
}