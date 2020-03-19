#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
typedef struct Edge{
    int to = 0;
    int cost = 0;
    bool operator < (const Edge &other) const{
        return cost > other.cost;
    }
}EDGE;
vector<EDGE> edges[1001];
bool connected[1001];
int main(){
    cin >> N; cin >> M;
    int answer = 0;
    for(int i=0; i<M; i++){
        int from = 0; int to = 0; int cost = 0;
        cin >> from >> to >> cost;
        edges[from].push_back(EDGE({to, cost}));
        edges[to].push_back(EDGE({from, cost}));
    }
    priority_queue<EDGE> pq;
    connected[1] = true;
    for(int i=0; i<edges[1].size(); i++){
        pq.push(edges[1][i]);
    }
    while(!pq.empty()){
        int to = pq.top().to;
        int cost = pq.top().cost;
        pq.pop();
        if(connected[to]) continue;
        connected[to] = true;
        answer += cost;
        for(int i=0; i<edges[to].size(); i++){
            if(connected[edges[to][i].to]) continue;
            pq.push(edges[to][i]);
        }
    }
    cout << answer << endl;
    return 0;
}