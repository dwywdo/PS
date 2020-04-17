#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int T = 10;
    for(int test_case=1; test_case<=T; test_case++){
        int tc = 0; int cnt = 0;
        vector<int> links[100];
        bool visited[100] = {false, };
        cin >> tc >> cnt;
        for(int i=0; i<cnt; i++){
            int src = 0; int dst = 0;
            cin >> src >> dst;
            links[src].push_back(dst);
        }
        queue<int> q;
        q.push(0), visited[0] = true;
        while(!q.empty()){
            int here = q.front(); q.pop();
            for(int i=0; i<links[here].size(); i++){
                int togo = links[here][i];
                if(visited[togo]) continue;
                visited[togo] = true;
                q.push(togo);
            }
        }
        int answer = 0;
        if(visited[99]) answer = 1;
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}