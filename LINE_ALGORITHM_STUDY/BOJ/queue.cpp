#include <iostream>
#include <queue>
using namespace std; 
int main() {
  queue<string> queue;
  queue.push("first");
  queue.push("second");
  queue.push("thrid");
  queue.pop();
  while(!queue.empty()) {
    cout << queue.front() << endl;
    queue.pop();
  }
  return 0;
}