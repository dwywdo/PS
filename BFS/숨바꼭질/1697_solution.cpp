#include <iostream>
#include <queue>
using namespace std;
bool visited[100001];
int N = 0;
int K = 0;
int main(){
    cin >> N >> K;
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    visited[N] = true;
    while(!q.empty()){
        int loc = q.front().first;
        int time = q.front().second;
        q.pop();
        if(loc == K){
            cout << time << endl;
            return 0;
        }
        int right_loc = loc + 1;
        int left_loc = loc - 1;
        int tel_loc = loc * 2;
        int next_loc[3] = {left_loc, right_loc, tel_loc};
        for(int i=0; i<3; i++){
            int next = next_loc[i];
            if(next >= 0 && next <= 100000){
                if(visited[next]) continue;
                visited[next] = true;
                q.push(make_pair(next, time + 1));
            }
        }
    }
    return 0;
}

