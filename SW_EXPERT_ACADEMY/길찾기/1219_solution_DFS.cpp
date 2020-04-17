#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
bool visited[100];
vector<int> links[100];
void DFS(int node){
    if(visited[node]) return;
    visited[node] = true;
    for(int i=0; i<links[node].size(); i++){
        int togo = links[node][i];
        DFS(togo);
    }
    return;
}
int main(){
    int T = 10;
    for(int test_case=1; test_case<=T; test_case++){
        int tc = 0; int cnt = 0;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<100; i++) links[i].clear();
        cin >> tc >> cnt;
        for(int i=0; i<cnt; i++){
            int src = 0; int dst = 0;
            cin >> src >> dst;
            links[src].push_back(dst);
        }
        DFS(0);
        int answer = 0;
        if(visited[99]) answer = 1;
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}