// 유니온-파인드 + 크루스칼 알고리즘 구현
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V, E;
int parent[10001];
vector<pair<int, pair<int, int>>> edges;
int find(int node){
    if(parent[node] == node) return node;
    else return (parent[node] = find(parent[node]));
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u==v) return;
    parent[u] = v;
    return;
}
int main(){
    cin >> V >> E;
    for(int i=1; i<=V; i++) parent[i] = i;
    for(int i=0; i<E; i++){
        int from=0; int to=0; int cost=0;
        cin >> from >> to >> cost;
        edges.push_back(make_pair(cost, make_pair(from, to)));
    }
    sort(edges.begin(), edges.end());
    int answer = 0;
    for(int i=0; i<E; i++){
        int cost = edges[i].first;
        int from = edges[i].second.first;
        int to = edges[i].second.second;
        int from_p = find(from);
        int to_p = find(to);
        if(from_p != to_p){
            merge(from, to);
            answer += cost;
        }
    }
    cout << answer << endl;
    return 0;
}