#include <iostream>
#include <vector>
using namespace std;
int N, M;
struct edge{
    int to = 0;
    int cost = 0;
};
bool connected[1001];
int minWeight[1001];
int parent[1001];
vector<edge> selected;
vector<edge> edges[1001];
int main(){
    cin >> N >> M;
    int totalCost = 0;
    for(int i=0; i<=N; i++){
        minWeight[i] = 987654321;
        parent[i] = -1; 
    }
    for(int i=0; i<M; i++){
        int from = 0; int to = 0; int cost = 0;
        cin >> from >> to >> cost;
        edges[from].push_back(edge({to, cost}));
        edges[to].push_back(edge({from, cost}));
    }
    connected[1] = true;
    minWeight[1] = 0; parent[1] = 1;
    for(int i=0; i<edges[1].size(); i++){
        int to = edges[1][i].to; int cost = edges[1][i].cost;
        if(minWeight[to] > cost){
            minWeight[to] = cost; parent[to] = 1;
        }
    }
    for(int i=0; i<N-1; i++){
        int nextV = 0;
        for(int v=1; v<=N; v++){
            if(!connected[v] && minWeight[nextV] > minWeight[v]) nextV = v;
        }
        selected.push_back(edge({parent[nextV], nextV}));
        totalCost += minWeight[nextV];
        connected[nextV] = true;
        for(int j=0; j<edges[nextV].size(); j++){
            int to = edges[nextV][j].to;
            int cost = edges[nextV][j].cost;
            if(!connected[to] && minWeight[to] > cost){
                parent[to] = nextV; minWeight[to] = cost;
            }
        }
    }
    cout << totalCost << endl;
    return 0;
}