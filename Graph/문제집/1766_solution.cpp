#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N=0; int M=0;
int indegrees[32001];
vector<int> links[32001];
int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int from = 0; int to = 0;
        cin >> from >> to;
        links[from].push_back(to);
        indegrees[to]++;
    }
    for(int i=1; i<=N; i++) sort(links[i].begin(), links[i].end());
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1; i<=N; i++){
        if(indegrees[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.top(); q.pop();
        cout << node << " ";
        for(int i=0; i<links[node].size(); i++){
            int next = links[node][i];
            indegrees[next]-=1;
            if(indegrees[next] == 0) q.push(next);
        }
    }
    cout << '\n';
    return 0;
}
