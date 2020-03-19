#include <iostream>
#include <queue>
using namespace std;
bool visited[1000001];
int d[1000001];
int MAX = 1000000;
int main(){
    int N, M;
    cin >> N >> M;
    visited[N] = true; d[N] = 0;
    queue<int> q;
    queue<int> nq;
    q.push(N);
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(now*2 < MAX){
            if(!visited[now*2]){
                q.push(now*2);
                visited[now*2] = true;
                d[now*2] = d[now];
            }
        }
        if(now-1 >= 0){
            if(!visited[now-1]){
                nq.push(now-1);
                visited[now-1] = true;
                d[now-1] = d[now] + 1;
            }
        }
        if(now+1 <= MAX){
            if(!visited[now+1]){
                nq.push(now+1);
                visited[now+1] = true;
                d[now+1] = d[now] + 1;
            }
        }
        if(q.empty()){
            q = nq;
            nq = queue<int>();
        }
    }
    cout << d[M] << endl;
    return 0;
}