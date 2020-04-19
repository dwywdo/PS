#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct edge{
    int src = 0;
    int dst = 0;
    double cost = 0;
}EDGE;
bool compare(const EDGE& a, const EDGE &b){
    return a.cost < b.cost;
}
vector<int> set;
int getParent(int x){
    if(set[x] == x) return x;
    else{
        return getParent(set[x]);
    }
}
void makesamegroup(int a, int b){
    int p1 = getParent(a);
    int p2 = getParent(b);
    if(p1 < p2) set[p2] = p1;
    else set[p1] = p2;
    return; 
}
bool issamegroup(int a, int b){
    int p1 = getParent(a);
    int p2 = getParent(b);
    return p1 == p2;
}
int main(){
    int T = 0; cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        int N = 0; cin >> N;
        vector<pair<long long, long long>> nodes; 
        for(int i=0; i<N; i++){
            long long x = 0;cin >> x;
            nodes.push_back(make_pair(x, 0));
        }
        for(int i=0; i<N; i++){
            long long y = 0; cin >> y;
            nodes[i].second = y;
        }
        double E = 0; cin >> E;
        vector<EDGE> edges;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(i==j) continue;
                double cost = 0;
                long long x1 = nodes[i].first; long long y1 = nodes[i].second;
                long long x2 = nodes[j].first; long long y2 = nodes[j].second;
                cost = E * ((long long)pow((x1-x2), 2) + (long long)pow((y1-y2), 2));
                edges.push_back({i, j, cost}); 
            }
        }
        sort(edges.begin(), edges.end(), compare);
        set.clear();
        for(int i=0; i<N; i++) set.push_back(i);
        int temp = 0;
        double totalcost = 0;
        for(int i=0; i<edges.size(); i++){
            EDGE e = edges[i];
            int a = e.src; int b = e.dst;
            if(!issamegroup(a, b)){
                totalcost += e.cost;
                makesamegroup(a, b);
            }
        }
        printf("#%d %.0f\n", test_case, round(totalcost));
    }
    return 0;
}