#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int N; int K;
bool visited[100001];
int from[100001];
int main(){
    stack<int> route;
    cin >> N >> K;
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    visited[N] = true; from[N] = N;
    while(!q.empty()){
        int loc = q.front().first;
        int time = q.front().second;
        q.pop();
        if(loc == K){
            cout << time << endl;
            while(1){
                route.push(loc);
                if(loc == from[loc]) break;
                else loc = from[loc];
            }
            while(!route.empty()){
                cout << route.top() << " ";
                route.pop();
            }
            return 0;
        }
        int next_locs[3] = {loc - 1, loc + 1, loc * 2};
        for(int i=0; i<3; i++){
            int next_loc = next_locs[i];
            if(next_loc >= 0 && next_loc <= 100000){
                if(visited[next_loc]) continue;
                visited[next_loc] = true;
                from[next_loc] = loc;
                q.push(make_pair(next_loc, time + 1));
            }
        }
    }
    return 0;
}