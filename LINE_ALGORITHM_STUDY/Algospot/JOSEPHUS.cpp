#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int C = 0;
int N = 0;
int K = 0;
int main() {
  // freopen("input.txt", "r", stdin);
  cin >> C;
  for (int i=0; i<C; i++) {
    cin >> N >> K;
    queue<int> queue;
    for (int n=1; n<=N; n++) queue.push(n);
    while(queue.size() > 2) {
      queue.pop();
      for (int k=0; k<K-1; k++) {
        int num = queue.front();
        queue.pop();
        queue.push(num);
      }
    }
    vector<int> sortedQueue;
    while(!queue.empty()) {
      sortedQueue.push_back(queue.front());
      queue.pop();
    }
    sort(sortedQueue.begin(), sortedQueue.end());
    for(auto it = sortedQueue.begin(); it < sortedQueue.end(); it++) cout << *it << " ";
    cout << endl;
  }
  return 0;
}
