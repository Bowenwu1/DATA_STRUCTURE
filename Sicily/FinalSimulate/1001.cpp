#include <iostream>
#include <string>
 template <typename E>

class LinkedList
{
private:
 
  // inner class: linked-list node
  class Node
  {
  public:
    E data;
    Node * next;
  };
 
  Node * first;
 
public:
  LinkedList() {
    first = 0;
  }
 LinkedList(const LinkedList<E> & that);
 LinkedList<E> & operator=(const LinkedList<E> & that);
  ~LinkedList() {
    while (first != 0) {
      removeFirst();
    }
  }
 void removeFirst();
 void addFirst(E data);
  E getFirst() {
    return first->data;
  }
 
  bool isEmpty() {
    return first == 0;
  }
};
/***************************************/
template <typename E>
void LinkedList<E>::removeFirst() {
    if (first) {
        Node * node = first;
        first = node->next;
        delete node;
    }
}
template <typename T>
void LinkedList<T>::addFirst(T data) {
    Node* temp = first;
    first = new Node();
    first->data = data;
    first->next = temp;
}
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & that) {
	first = 0;
    *this = that;
}

template<typename T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & that) {
     while (first != 0) {
      this->removeFirst();
    }
    if (that.first != 0) {
        first = new Node();
        first->data = that.first->data;
        Node* thisTemp = first;
        Node* thatTemp = that.first->next;
        while (thatTemp) {
            thisTemp->next = new Node();
            thisTemp = thisTemp->next;
            thisTemp->data = thatTemp->data;
            thisTemp->next = 0;
            thatTemp = thatTemp->next;
        }
    }
    return *this;
}
/*************************************/
using namespace std;
int main() {
    LinkedList<int> test;
    for (int i = 0; i < 10; ++i) {
        test.addFirst(i);
    }
    LinkedList<int> ttt(test);
    while (!ttt.isEmpty()) {
        cout << ttt.getFirst() << " ";
        ttt.removeFirst();
    }
}
