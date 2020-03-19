// 인접 리스트를 이용해 구현한 소스
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int V;
vector<int> list[1001];
bool visited[1001];
void BFS(){
    queue<int> q;
    q.push(V);
    visited[V] = true;
    while(!q.empty()){
        int v = q.front();
        cout << v << " ";
        q.pop();
        for(int i=0; i<list[v].size(); i++){
            int v2 = list[v][i];
            if(!visited[v2]){
                visited[v2] = true;
                q.push(v2);
            }
        }
    }
    cout << endl;
}
void DFS(int v){
    cout << v << " ";
    visited[v] = true;
    for(int i=0; i<list[v].size(); i++){
        int v2 = list[v][i];
        if(!visited[v2]){
            DFS(v2);
        }
    }
}
int main(){
    cin >> N;
    cin >> M;
    cin >> V;
    for(int i=0; i<M; i++){
        int n1; int n2;
        cin >> n1;
        cin >> n2;
        list[n1].push_back(n2);
        list[n2].push_back(n1);
    }
    for(int i=1; i<=N; i++){
        sort(list[i].begin(), list[i].end());
    }
    DFS(V);
    for(int i=0; i<=N; i++){
        visited[i] = false;
    }
    cout << endl;
    BFS();
    return 0;
}