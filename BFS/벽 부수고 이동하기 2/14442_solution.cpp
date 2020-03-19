#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, M, K;
int map[1000][1000];
int dist[1000][1000][11];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        string row = "";
        cin >> row;
        for(int j=0; j<M; j++){
            map[i][j] = row[j] - '0';
        }
    }

    queue<tuple<int, int, int>> q;
    dist[0][0][0] = 1;
    q.push(make_tuple(0, 0, 0));
    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int k = get<2>(q.front());
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i]; int nx = x + dx[i];
            if(ny>=0 && ny<N && nx>=0 && nx<M){
                if(map[ny][nx] == 0 && dist[ny][nx][k] == 0){
                    dist[ny][nx][k] = dist[y][x][k] + 1;
                    q.push(make_tuple(ny, nx, k));
                }
                if(map[ny][nx] == 1 && dist[ny][nx][k+1] == 0 && k+1 <= K){
                    dist[ny][nx][k+1] = dist[y][x][k] + 1;
                    q.push(make_tuple(ny, nx, k+1));
                }
            }
        }
    }
    int ans = -1;
    for(int k=0; k<=K; k++){
        if(dist[N-1][M-1][k] == 0) continue;
        if(ans == -1){
            ans = dist[N-1][M-1][k];
        }
        else if(ans > dist[N-1][M-1][k]){
            ans = dist[N-1][M-1][k];
        }
    }
    cout << ans << endl;
    return 0;
}
