// DFS를 재귀를 사용하지 않고 구현하는 방법
// 스택을 사용하되, 아직 어느 길부터 가지 않았는지를 스택에 저장해둔다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N, M, V;
vector<int> list[1001];
bool visited[1001];
void DFS(int node){
    stack<pair<int, int> > nstack;
    visited[node] = true;
    nstack.push(make_pair(node, 0));
    cout << node << " ";
    while(!nstack.empty()){
        int node = nstack.top().first;
        int start = nstack.top().second;
        nstack.pop();
        for(int i=start; i<list[node].size(); i++){
            int next = list[node][i];
            if(!visited[next]){
                cout << next << " ";
                visited[next] = true;
                nstack.push(make_pair(node, i+1));
                nstack.push(make_pair(next, 0));
                break;
            }
        }
    }
}
int main(){
    cin >> N >> M >> V;
    for(int i=0; i<M; i++){
        int v1, v2;
        cin >> v1 >> v2;
        list[v1].push_back(v2);
        list[v2].push_back(v1);
    }
    for(int i=1; i<=N; i++){
        sort(list[i].begin(), list[i].end());
    }
    DFS(V);
    return 0;
}