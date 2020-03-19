#include <iostream>
#include <queue>
using namespace std;
vector<int> links[32001];
bool check[32001];
void go(int node){
    check[node] = true;
    for(int &next : links[node]){
        if(check[next] == false){
            go(next);
        }
    }
    cout << node << ' ';
    return;
}
int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int from, to;
        cin >> from; cin >> to;
        links[to].push_back(from);
    }
    for(int i=1; i<=N; i++){
        if(!check[i]) go(i);
    }
    cout << '\n';
    return 0;
}
