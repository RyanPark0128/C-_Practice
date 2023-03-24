#include <iostream>
#include "ddq.h"

// removing node from double linked list
// p->prev->next = p->next;
// p->next->prev = p->prev;


// inserting a node to double linked list
// n->next = p->next;
// n->prev = p;
// p->next->prev =n;
// p->next = n;

//or 

// node * n = new node{p,x,p->next}
// p->next->prev = n;
// p->next = n;


//circle doubly linked list with dummy node to connect head and tail. No nullptr. Access to head and tail.

// void print(node * d) {
//   node * p = d->next;
//   while (p != d) {
//     std::cout << p.data << " ";
//     p = p->next;
//   }
//   std::cout << std::endl;
// }


struct node {
    node * prev;
    int data;
    node * next;
};

int main() {

  node * head = new node{nullptr, 4, nullptr};

  return 0;
}