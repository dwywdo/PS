#include <iostream>
#include <deque>
using namespace std;
int main() {
  deque<int> deque;

  deque.push_back(3);
  deque.push_front(5);
  deque.push_front(1);
  deque.push_back(2);
  while(!deque.empty()) {
    cout << deque.front() << endl;
    deque.pop_front();
  }

  return 0;
}