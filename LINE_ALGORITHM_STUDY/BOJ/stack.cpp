#include <iostream>
#include <stack>
using namespace std; 
int main() {
  stack<string> stack;
  stack.push("first");
  stack.push("second");
  stack.push("thrid");
  while(!stack.empty()) {
    cout << stack.top() << endl;
    stack.pop();
  }
  return 0;
}