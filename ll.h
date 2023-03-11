#ifndef LL_H
#define LL_H
#include <iostream>

class ll {
  public:
    ll();
    void insert(int x);
    void remove(int x);
    friend std::ostream & operator <<(std::ostream & out, const ll & rhs);

    ~ll() {
      delete_list();
    }

    ll(const ll& rhs) {
      head = copy(rhs.head);
      std::cout << "Copy" << std::endl;
    }

    const ll & operator=(const ll& rhs) {
      if (this == &rhs) {
        return *this;
      }
      delete_list();
      head = copy(rhs.head);
      std::cout << "Assignment" <<std::endl;
      return *this;
    }
  private:
    struct node{
      int data;
      node* next;
    };
    node* head;
    node * insert(int x, node* p);
    node * remove(int x, node* p);
    node * copy(node*p) {
      if(!p) {
        return p;
      }
      return new node{p->data, copy(p->next)};
    }
    void delete_list() {
      while(head) {
        node* tmp = head;
        head = head->next;
        delete tmp;
      }
      std::cout << "deleted" << std::endl;
    }
};

ll::ll() {
  head = nullptr;
}

void ll::insert(int x) {
  head = insert(x, head);
}

ll::node* ll::insert(int x, ll::node* p) {
  if(!p || p->data > x) {
    return new node{x, p};
  }
  p->next = insert(x,p->next);
  return p;
}

std::ostream & operator <<(std::ostream & out, const ll & rhs) {
  //because its friend function when i want to use node struc, need to define it with ll:
  ll::node * p = rhs.head;
  while(p){
    out << p->data << " ";
    p = p->next;
  }
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