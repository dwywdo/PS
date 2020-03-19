#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> links[3001];
int dist[3001];
int visited[3001];
int N;
int DFS(int node, int previousNode){
    if(visited[node] == 1) return node;
    
    visited[node] = 1;

    for(int i=0; i<links[node].size(); i++){
        int next = links[node][i];
        if(next == previousNode) continue;
        int result = DFS(next, node);
        if(result == -2) return -2;
        if(result >=  0){
            visited[node] = 2;
            if(node == result) return -2;
            else return result;
        }
    }
    return -1;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int from = 0; int to = 0;
        cin >> from >> to;
        links[from].push_back(to);
        links[to].push_back(from);
    }
    DFS(1, -1);
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(visited[i] == 2){
            dist[i] = 0;
            q.push(i);
        }
        else{
            dist[i] = -1;
        }
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int i=0; i<links[node].size(); i++){
            int next = links[node][i];
            if(dist[next] == -1){
                q.push(next);
                dist[next] = dist[node] + 1;
            }
        }
    }
    for(int i=1; i<=N; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}