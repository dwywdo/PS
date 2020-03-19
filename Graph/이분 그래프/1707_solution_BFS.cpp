#include <iostream>
#include <vector>
#include <queue>
#define NOCOLOR 0
#define RED 1
#define BLUE 2
using namespace std;

int color[20001];

int T; int V; int E;
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        for(int i=1; i<=V; i++) color[i] = NOCOLOR;
        vector<int> list[20001];
        cin >> V >> E;
        for(int e=0; e<E; e++){
            int from; int to;
            cin >> from >> to;
            list[from].push_back(to);
            list[to].push_back(from);
        }

        for(int v=1; v<=V; v++){
            if(color[v] != NOCOLOR) continue;
            queue<int> q; q.push(v);
            color[v] = RED;
            while(!q.empty()){
                int from = q.front(); q.pop();
                for(int i=0; i<list[from].size(); i++){
                    int to = list[from][i];
                    if(color[to] != NOCOLOR) continue;

                    if(color[from] == RED) color[to] = BLUE;
                    if(color[from] == BLUE) color[to] = RED;
                    q.push(to);
                }
            }
        }        
        bool isBipartite = true;
        for(int i=1; i<=V; i++){
            for(int j=0; j<list[i].size(); j++){
                int from = i;
                int to = list[i][j];
                if(color[from] == color[to]){
                    isBipartite = false;
                    break;
                }
            }
            if(isBipartite == false) break;
        }
        if(isBipartite) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}