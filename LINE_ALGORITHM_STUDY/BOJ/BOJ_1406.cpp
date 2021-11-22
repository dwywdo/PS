#include <iostream>
#include <string>
#include <list>
using namespace std;
string str;
int M = 0;

int main() {
  cin >> str;
  cin >> M;
  list<char> page(str.begin(), str.end());
  auto cursor = page.end();
  for (int i=0; i<M; i++) {
    char inst; cin >> inst;
    if (inst == 'L') {
      if (cursor != page.begin()) cursor--;
    } else if (inst == 'D') {
      if (cursor != page.end()) cursor++;
    } else if (inst == 'B') {
      if (cursor != page.begin()) {
        cursor = page.erase(--cursor);
      }
    } else if (inst = 'P') {
      char input; cin >> input;
      page.insert(cursor, input);
    }
  }
  for (auto it = page.begin(); it != page.end(); it++) {
    cout << *it;
  }
  return 0;
}