#include <iostream>
#include <stack>
using namespace std;
int C = 0;
int main() {
  // freopen("input.txt", "r", stdin);
  cin >> C;
  for (int c=0; c<C; c++) {
    string str; cin >> str;
    stack<char> stack;
    string answer = "YES";
    for (int i=0; i<str.length(); i++) {
      if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
        stack.push(str[i]);
      }
      else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
        if(stack.empty()) { 
          answer = "NO";
          break;
        }
        char top = stack.top();
        if (str[i] == ')') {
          if(top != '(') {
            answer = "NO";
            break;
          } else stack.pop();
        }
        if (str[i] == '}') {
          if(top != '{') {
            answer = "NO";
            break;
          } else stack.pop();
        }
        if (str[i] == ']') {
          if(top != '[') {
            answer = "NO";
            break;
          } else stack.pop();
        }
      }
    }
    if (answer == "NO") cout << answer << endl;
    else {
      answer = stack.empty() ? "YES" : "NO";
      cout << answer << endl;
    }
  }
  return 0;
}