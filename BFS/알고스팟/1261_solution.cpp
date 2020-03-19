#include <iostream>
#include <queue>
using namespace std;
int M, N;
int map[100][100];
int dist[100][100];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    cin >> M >> N;
    for(int i=0; i<N; i++){
        string row = "";
        cin >> row;
        for(int j=0; j<M; j++){
           map[i][j] = row[j] - '0'; 
           dist[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    queue<pair<int, int>> nq;
    q.push(make_pair(0, 0)); dist[0][0] = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i]; int nx = x + dx[i];
            if(ny>=0 && ny<N && nx>=0 && nx<M){
                if(dist[ny][nx] == -1){
                    if(map[ny][nx] == 0){
                        dist[ny][nx] = dist[y][x];
                        q.push(make_pair(ny, nx));
                    }
                    else if(map[ny][nx] == 1){
                        nq.push(make_pair(ny, nx));
                        dist[ny][nx] = dist[y][x] + 1;
                    }
                }
            }
        }
        if(q.empty()){
            q = nq;
            nq = queue<pair<int,int>>();
        }
    }
    cout << dist[N-1][M-1] << endl;
    return 0;
}