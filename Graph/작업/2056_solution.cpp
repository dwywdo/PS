#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int costs[10001];
int d[10001];
int indegrees[10001];
int N;
vector<int> links[10001];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        int count; int next;
        cin >> costs[i];
        cin >> count;
        if(count!=0){
            for(int j=0; j<count; j++){
                cin >> next;
                links[next].push_back(i);
                indegrees[i]+=1;
            }
        }
    }
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(indegrees[i] == 0){
            q.push(i);
            d[i] = costs[i];
        }
    }

    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0; i<links[x].size(); i++){
            int next = links[x][i];
            indegrees[next]-=1;
            if(d[next] < d[x] + costs[next]){
                d[next] = d[x] + costs[next];
            }
            if(indegrees[next] == 0) q.push(next);
        }
    }
    int answer = 0;
    for(int i=1; i<=N; i++){
        if(answer < d[i]){
            answer = d[i];
        }
    }
    cout << answer << endl;
    return 0;
}
