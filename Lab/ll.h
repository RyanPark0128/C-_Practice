#ifndef LL_H
#define LL_H
#include <iostream>
// template <typename T>
class ll {
  public:
    ll();
    void insert(int x);
    void remove(int x);
    ll merge(const ll & rhs);
    friend std::ostream & operator <<(std::ostream & out, const ll & rhs);
    ~ll();
    ll(const ll& rhs);
    const ll & operator=(const ll& rhs);
  private:
    struct node{
      int data;
      node* next;
    };
    node* head;
    node * insert(int x, node* p);
    node * remove(int x, node* p);
    node * copy(node*p);
    node* merge(node* p1, node* p2);
    void delete_list();
};

ll ll::merge(const ll & rhs) {
  // ll temp;
  // node* p1 = this->head;
  // node* p2 = rhs.head;
  // node* p3 = temp.head;
  // while(p1 || p2) {
  //   if (!p1) {
  //     // std::cout << p2->data << std::endl;
  //     temp.head = new node{p2->data, nullptr};
  //     temp.head = temp.head->next;
  //     p2 = p2->next;
  //   } else if (!p2) {
  //     // std::cout << p1->data << std::endl;
  //     p1 = p1->next;
  //   } else if (p1->data >= p2->data) {
  //     // std::cout << p2->data << std::endl;
  //     p2 = p2->next;
  //   } else if (p2->data > p1->data) {
  //     // std::cout << p1->data << std::endl;
  //     p1 = p1->next;
  //   }
  // }
  // temp.head = p3;
  // return temp;
  ll temp;
  temp.head = merge(this->head,rhs.head);
  return temp;
}


ll::node* ll::merge(node* p1, node* p2) {
  if (!p1 || !p2) {
    return p1;
  }

  if (!p1) {
    return new ll::node{p2->data, merge(p1,p2->next)};
  } else if (!p2) {
    return new ll::node{p1->data, merge(p1->next,p2)};
  } else if (p1->data >= p2->data) {
    return new ll::node{p2->data, merge(p1,p2->next)};
  } else if (p2->data > p1->data) {
    return new ll::node{p1->data, merge(p1->next,p2)};
  }
  // return ll::node()


  //   if(!p) {
  //   return p;
  // }
  // return new ll::node{p->data, copy(p->next)};
}

ll::ll() {
  head = nullptr;
}

ll::~ll() {
  delete_list();
}
ll::ll(const ll& rhs) {
  head = copy(rhs.head);
  // std::cout << "Copy" << std::endl;
}

void ll::insert(int x) {
  head = insert(x, head);
}

const ll & ll::operator=(const ll& rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete_list();
  head = copy(rhs.head);
  // std::cout << "Assignment" <<std::endl;
  return *this;
}

ll::node* ll::insert(int x, ll::node* p) {
  if(!p || p->data > x) {
    return new node{x, p};
  }
  p->next = insert(x,p->next);
  return p;
}

ll::node * ll::copy(ll::node*p) {
  if(!p) {
    return p;
  }
  return new ll::node{p->data, copy(p->next)};
}

void ll::delete_list() {
  while(head) {
    node* tmp = head;
    head = head->next;
    delete tmp;
  }
  // std::cout << "deleted" << std::endl;
}

std::ostream & operator <<(std::ostream & out, const ll & rhs) {
  //because its friend function when i want to use node struc, need to define it with ll:
  ll::node * p = rhs.head;
  while(p){
    out << p->data << "->";
    p = p->next;
  }
  out << "nullptr";
  return out;
}

void ll::remove(int x) {
  head = remove(x,head);
}

ll::node* ll::remove(int x, node* p) {
  if (!p) {
    return p;
  }
  if (p->data == x) {
    node * tmp = p;
    p = p->next;
    delete tmp;
    return remove(x,p);
  }
  p->next =remove(x,p->next);
  return p;
}

#endif