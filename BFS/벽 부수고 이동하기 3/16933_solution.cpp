#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int map[1000][1000];
int dist[1000][1000][11][2]; // 0: 낮, 1: 밤
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int N; int M; int K;
int main(){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        string row = "";
        cin >> row;
        for(int j=0; j<M; j++){
            map[i][j] = row[j] - '0';
        }
    }
    queue<tuple<int, int, int, int>> q;
    dist[0][0][0][0] = 1;
    q.push(make_tuple(0, 0, 0, 0));
    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int k = get<2>(q.front());
        int t = get<3>(q.front());
        q.pop();
        // 다음 위치로 이동하는 경우와, 머무는 크게 두 가지 경우로 나눈다.
        for(int i=0; i<4; i++){
            int ny = y + dy[i]; int nx = x + dx[i];
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            // t=0 : 낮, t=1 : 밤
            // 다음 위치가 벽이 아니고, 낮->밤, 밤->낮에 해당하는 상태에 방문한 적이 없으면
            if(map[ny][nx] == 0 && dist[ny][nx][k][1-t] == 0){
                dist[ny][nx][k][1-t] = dist[y][x][k][t] + 1;
                q.push(make_tuple(ny, nx, k, 1-t));
            }
            // 현재 낮이고, 다음 위치가 벽이며, 벽을 부순 횟수가 제한 안에 있고, 낮->밤, 밤->낮에 해당하는 상태에 방문한 적이 없으면
            if(t == 0 && map[ny][nx] == 1 && k+1 <= K && dist[ny][nx][k+1][1-t] == 0){
                dist[ny][nx][k+1][1-t] = dist[y][x][k][t] + 1;
                q.push(make_tuple(ny, nx, k+1, 1-t));
            }
        }
        // 현재 위치에 머무는 경우를 말함. 낮->밤, 밤->낮에 해당하는 상태에 방문한 적이 없으면
        if(dist[y][x][k][1-t] == 0){
            dist[y][x][k][1-t] = dist[y][x][k][t] + 1;
            q.push(make_tuple(y, x, k, 1-t));
        }
    }
    int ans = -1;
    for (int j=0; j<2; j++) {
        for (int i=0; i<=K; i++) {
            if (dist[N-1][M-1][i][j] == 0) continue;
            if (ans == -1) {
                ans = dist[N-1][M-1][i][j];
            } else if (ans > dist[N-1][M-1][i][j]) {
                ans = dist[N-1][M-1][i][j];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}