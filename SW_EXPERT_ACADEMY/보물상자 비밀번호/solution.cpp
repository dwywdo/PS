#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int T;
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        int N, K; cin >> N >> K;
        string s; cin >> s;
        priority_queue<int> pq;
        set<string> check;
        for(int i=0; i<N-1; i++){
            string num; 
            for(int j=0; j<N; j+=(N/4)){
                num = s.substr(j, N/4);
                if(check.count(num) == 0){
                    check.insert(num);
                }
                else continue;
                int num_int = stoi(num, 0, 16);
                pq.push(num_int);
            }
            rotate(s.begin(), s.begin() + 1, s.end());
        }
        for(int i=0; i<K-1; i++){
            pq.pop();
        }
        int answer = pq.top();
        printf("#%d %d\n", t+1, answer);
    }
    return 0;
}