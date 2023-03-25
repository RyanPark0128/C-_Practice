#ifndef Q_H
#define Q_H

template <typename T>
class queue {
  public:
    queue();
    void enqueue(T x);
    T dequeue();
    T front();
    bool isEmpty();

    ~queue();
    queue(const queue &);
    const queue& operator=(const queue &);

  private:
    struct node {
      node *prev;
      T data;
      node *next;
    };
    node *dummy;
};
template <typename T>
queue<T>::queue(){
  dummy = new node;
  dummy->next = dummy;
  dummy->prev = dummy;
}

template <typename T>
void queue<T>::enqueue(T x) {
  node* tmp = new node{dummy->prev, x, dummy};
  tmp->next->prev = tmp;
  tmp->prev->next = tmp;
}

template <typename T>
T queue<T>::front() {
  if(isEmpty()) {
    std::cout << "EMPTY QUEUE";
    exit(1);
  }
  return dummy->next->data;
}

template <typename T>
T queue<T>::dequeue() {
  T tmp = front();

  node * p = dummy->next;
  tmp->next->prev = dummy;
  dummy->next = tmp->next;

  delete p;

  return tmp;
}

template <typename T>
bool queue<T>::isEmpty() {
  return dummy->next = dummy;
}

template <typename T>
queue::~queue() {
  node * p = dummy->next;
  while (p != dummy) {
    node * to_del = p;
    p = p->next;
    delete to_del;
  }
  delete dummy
}

template <typename T>
queue<T::queue(const queue<T> & rhs) {
  dummy = new node;
  dummy->next = dummy;
  dummy->prev = dummy;

  node* p = rhs.dummy->next;
  while(p! = rhs.dummy) {
    node* tmp = new node{dummy->prev, p->data, dummy};
    tmp->next->prev = tmp;
    tmp->prev->next = tmp;
    p=p->next;
  }
}

template <typename T>
const queue<T>& queue<T>::operator=(const queue<T> & rhs) {
  if (this = &rhs) {
    return *this
  }
  node * p = dummy->next;
  while (p != dummy) {
    node * to_del = p;
    p = p->next;
    delete to_del;
  }
  delete dummy

  dummy = new node;
  dummy->next = dummy;
  dummy->prev = dummy;

  node* x = rhs.dummy->next;
  while(x! = rhs.dummy) {
    node* tmp = new node{dummy->prev, x->data, dummy};
    tmp->next->prev = tmp;
    tmp->prev->next = tmp;
    x=x->next;
  }

  return *this;
  
}

#endif