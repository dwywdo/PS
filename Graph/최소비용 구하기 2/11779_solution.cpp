#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
vector<pair<int, int>> edges[1001];
vector<bool> check(1001, false);
vector<int> dist(1001, 987654321);
vector<int> from(1001, 0);
int N, M;
int start = 0; int dst = 0;
int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int from=0; int to=0; int cost=0;
        cin >> from >> to >> cost;
        edges[from].push_back(make_pair(cost, to));
    }
    cin >> start >> dst;
    check[start] = true; dist[start] = 0; from[start] = -1;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0, start));
    while(!pq.empty()){
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<edges[here].size(); i++){
            int there = edges[here][i].second;
            int nextCost = edges[here][i].first;
            int nextDist = cost + nextCost;
            if(dist[there] > nextDist){
                dist[there] = nextDist;
                from[there] = here;
                pq.push(make_pair(nextDist, there));
            }
        }
    }
    cout << dist[dst] << endl;
    stack<int> st;
    int x = dst;
    while(x != -1){
        st.push(x);
        x = from[x];
    }
    cout << st.size() << endl;
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
    return 0;
}