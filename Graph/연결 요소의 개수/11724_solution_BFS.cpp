#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N; int M;
vector<int> list[1001];
bool visited[1001];
int main(){
    cin >> N;
    cin >> M;
    int cnt = 0;
    for(int i=0; i<M; i++){
        int u; int v; 
        cin >> u >> v;
        list[u].push_back(v); // 방향이 없는 그래프: 양방향 그래프
        list[v].push_back(u);
    }
    for(int i=1; i<=N; i++){
        if(visited[i]) continue;
        queue<int> q;
        cnt++;
        visited[i] = true;
        q.push(i);
        while(!q.empty()){
            int from = q.front(); q.pop();
            for(int k=0; k<list[from].size(); k++){
                int to = list[from][k];
                if(!visited[to]){
                    visited[to] = true;
                    q.push(to);
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}