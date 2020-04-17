#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int dist[101];
int main (){
    int T = 10;
    for(int test_case=1; test_case<=T; test_case++){
        int len = 0; int start = 0;
        vector<int> links[101];
        memset(dist, -1, sizeof(dist));
        cin >> len >> start;
        int answerperson = 0;
        int answertime = 0;
        for(int i=0; i<len/2; i++){
            int from = 0; int to = 0;
            cin >> from >> to;
            links[from].push_back(to);
        }
        queue<int> q;
        dist[start] = 0; q.push(start);
        while(!q.empty()){
            int here = q.front(); q.pop();
            for(int i=0; i<links[here].size(); i++){
                int to = links[here][i];
                if(dist[to] != -1) continue;
                dist[to] = dist[here] + 1;
                if(dist[to] > answertime){
                    answerperson = to; answertime = dist[to];
                }
                else if(dist[to] == answertime){
                    if(answerperson < to) answerperson = to;
                }
                q.push(to);
            }
        }
        cout << "#" << test_case << " " << answerperson << "\n";
    }
    return 0;
}