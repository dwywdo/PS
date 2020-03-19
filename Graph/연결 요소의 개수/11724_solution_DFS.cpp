#include <iostream>
#include <vector>
using namespace std;
vector<int> list[1001];
bool visited[1001];
int N; int M;
void dfs(int node){
    visited[node] = true;
    for(int i=0; i<list[node].size(); i++){
        int next = list[node][i];
        if(visited[next]) continue;
        dfs(next);
    }
}
int main(){
    cin >> N; cin >> M;
    int cnt = 0;
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    for(int i=1; i<=N; i++){
        if(visited[i]) continue;
        cnt++;
        dfs(i);
    }
    cout << cnt << endl;
    return 0;
}