#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int T = 0;
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        int N = 0;
        cin >> N;
        if(N == 1){
            cout << 1 << '\n';
            continue;
        }
        queue<int> q; q.push(1);
        vector<int> from(N, -1);
        vector<int> dist(N, -1); dist[1] = 0;
        vector<int> how(N, -1); how[1] = 1;
        while(!q.empty()){
            int num = q.front(); q.pop();
            int next[2];
            next[0] = (num*10)%N;
            next[1] = (next[0]+1)%N;
            for(int i=0; i<2; i++){
                int next_num = next[i];
                if(dist[next_num] != -1) continue;
                dist[next_num] = dist[num] + 1;
                from[next_num] = num;
                how[next_num] = i;
                q.push(next_num);
            }
        }
        if(dist[0] == -1){
            cout << "BRAK" << '\n';
        }
        else{
            string ans = "";
            for(int i=0; i!=-1; i=from[i]){
                ans += to_string(how[i]);
            }
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
        }
    }
    return 0;
}