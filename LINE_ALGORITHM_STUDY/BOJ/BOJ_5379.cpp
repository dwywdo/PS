#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int caseCount = 0;
vector<string> password_list;
int main() {
  cin >> caseCount;
  for (int i=0; i<caseCount; i++) {
    string str; cin >> str;
    stack<char> rst;
    stack<char> tmp;
    for (auto it = str.begin(); it != str.end(); it++){ 
      if (*it == '<') {
        if (!rst.empty()) { 
          tmp.push(rst.top());
          rst.pop();
        }
      } else if (*it == '>') {
        if(!tmp.empty()) {
          rst.push(tmp.top());
          tmp.pop();
        }
      } else if (*it == '-') {
        if (!rst.empty()) {
          rst.pop();
        }
      } else {
        rst.push(*it);
      }
    }
    while(!tmp.empty()) {
      rst.push(tmp.top());
      tmp.pop();
    }

    string answer;
    while(!rst.empty()) {
      answer += rst.top();
      rst.pop();
    }
    reverse(answer.begin(), answer.end());
    cout << answer << endl;
  }
  return 0;
}