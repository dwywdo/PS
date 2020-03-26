#include <iostream>
#include <queue>
#include <cstring>
#define MAXN 50
#define MAXM 50
using namespace std;
int map[MAXN][MAXM];
int T = 0;
int N, M, R, C, L;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int tunnels[8][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1}
};
bool connectCheck(int to_y, int to_x, int dir){
    if(dir==0 && tunnels[map[to_y][to_x]][2] == 1) return true;
    if(dir==1 && tunnels[map[to_y][to_x]][3] == 1) return true;
    if(dir==2 && tunnels[map[to_y][to_x]][0] == 1) return true;
    if(dir==3 && tunnels[map[to_y][to_x]][1] == 1) return true;
    return false;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N >> M >> R >> C >> L;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> map[i][j];
            }
        }
        int dist[MAXN][MAXM]; memset(dist, 0, sizeof(dist));
        dist[R][C] = 1; int cnt = 1;
        queue<pair<int, int>> q; q.push(make_pair(R, C));
        while(!q.empty()){
            int y = q.front().first; int x = q.front().second; q.pop();
            int tunnel = map[y][x];
            for(int i=0; i<4; i++){
                if(tunnels[tunnel][i] == 1){
                    int ny = y + dy[i]; int nx = x + dx[i];
                    if(dist[ny][nx] != 0) continue;
                    if(dist[y][x] + 1 > L) continue;
                    if(map[ny][nx] == 0) continue;
                    if(!connectCheck(ny, nx, i)) continue;
                    if(ny>=0 && ny<N && nx>=0 && nx<M){
                        dist[ny][nx] = dist[y][x] + 1; cnt++;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
        cout << "#" << test_case << " " << cnt << "\n";
    }
    return 0;
}

