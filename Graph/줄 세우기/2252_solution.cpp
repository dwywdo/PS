#include <iostream>
#include <queue>
using namespace std;
int indegrees[32001];
vector<int> links[32001];
vector<int> order;
int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int from, to;
        cin >> from; cin >> to;
        links[from].push_back(to);
        indegrees[to]++;
    }
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        cout << node << ' ';
        for(int i=0; i<links[node].size(); i++){
            int next = links[node][i];
            indegrees[next]-=1;
            if(indegrees[next] == 0){
                q.push(next);
            }
        }
    }
    cout << endl;
    return 0;
}
