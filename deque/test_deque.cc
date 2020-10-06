#include <iostream>

#include "deque.h"

using namespace std;

int main() {
  try {
    data_structure::Deque<int> deq;
    deq.AddFirst(10);
    deq.AddFirst(20);
    deq.AddFirst(30);
    deq.AddLast(100);
    while (!deq.IsEmpty()) {
      int val = deq.RemoveFirst();
      cout << val << endl;
    }

    cout << "-----\n";

    deq.AddLast(1);
    deq.AddLast(2);
    deq.AddLast(3);
    deq.AddFirst(110);
    cout << "size: " << deq.Size() << "\n";

    while (!deq.IsEmpty()) {
      int last = deq.RemoveLast();
      int first = deq.RemoveFirst();
      cout << "last: " << last << endl;
      cout << "first: " << first << endl;
    }
  } catch (const exception &ex) {
    cerr << ex.what() << endl;
  }
}