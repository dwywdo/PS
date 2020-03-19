#include <iostream>
#include <queue>
int map[101];
int d[101];
using namespace std;
int N; int M;
int main(){
    cin >> N >> M;
    for(int i=0; i<=100; i++) {
        d[i] = -1;
        map[i] = i;
    }
    for(int i=0; i<N+M; i++){
        int start = 0; int end = 0;
        cin >> start >> end;
        map[start] = end;
    }
    queue<int> q;
    q.push(1); d[1] = 0;
    while(!q.empty()){
        int loc = q.front(); q.pop();
        for(int i=1; i<=6; i++){
            int next_loc = loc+i;
            if(next_loc > 100) continue;
            next_loc = map[next_loc];
            if(d[next_loc] == -1){
                d[next_loc] = d[loc] + 1;
                q.push(next_loc);
            }
        }
    }
    cout << d[100] << endl;
}