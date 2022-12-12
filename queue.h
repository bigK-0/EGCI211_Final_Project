//#ifndef queue_h
//#define  queue_h
#include "data.h"

class Queue {
private:
  dataPtr headPtr, tailPtr;
  int size;

public:
  void enqueue(dataPtr);
  string dequeue();
  void print_all();
  int getSize() { return size; }
  Queue();
  ~Queue(); // dequeue all
};

Queue::Queue() {
  size = 0;
  headPtr = NULL;
  tailPtr = NULL;
}

Queue::~Queue() {}
  
void Queue::enqueue(dataPtr d) {
  dataPtr new_node = d;
  if (new_node != NULL) {
    if (size == 0)
      headPtr = new_node;
    else
      tailPtr->set_next(new_node);
    tailPtr = new_node;
    size++;
  }
}

string Queue::dequeue() {
  if (size > 0) {
    string name = headPtr->get_name();
    if (headPtr->get_next() != NULL)
      headPtr = headPtr->get_next();
    size--;
    print_all();
    return name;
  } else {
    cout << "The queue is empty." << endl;
    return "Nothing";
  }
}

void Queue::print_all() {
  dataPtr current = headPtr;
  if (size > 0) {
    for (int i = 1; i < size; i++) {
      current->print();
      cout << " -> ";
      current = current->get_next();
    }
    if (current != NULL)
      current->print();
    else
      cout << "NULL";
  } else
    cout << "NULL";
  cout << endl;
}

//#endif