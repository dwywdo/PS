#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int map[1000][1000];
int d[1000][1000][2];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    int N = 0; int M = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string row = "";
        cin >> row;
        for(int j=0; j<M; j++){
            map[i][j] = row[j] - '0';
        }
    }
    d[0][0][0] = 1;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int c = get<2>(q.front());
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i]; int nx = x + dx[i];
            if(nx>=0 && nx<M && ny>=0 && ny<N){
                // 다음 위치가 벽이 아닌 경우
                // 벽을 부쉈다면 벽을 부순 상태에 더해주고 방문
                if(map[ny][nx] == 0 && d[ny][nx][c] == 0){
                    d[ny][nx][c] = d[y][x][c] + 1;
                    q.push(make_tuple(ny, nx, c));
                }
                // 다음 위치가 벽이면서, 여태까지 벽을 부순 적이 없을 경우
                if(c == 0 && map[ny][nx] == 1 && d[ny][nx][c+1] == 0){
                    d[ny][nx][c+1] = d[y][x][c] + 1;
                    q.push(make_tuple(ny, nx, c+1));
                }
            }
        }
    }
    // 둘 다 0인 경우 방문할 수 없음
    if(d[N-1][M-1][0] == 0 && d[N-1][M-1][1] == 0){
        cout << -1 << endl;
        return 0;
    }
    // 둘 다 0이 아닌 경우 최솟값 출력
    if(d[N-1][M-1][0] != 0 && d[N-1][M-1][1] != 0){
        cout << min(d[N-1][M-1][0], d[N-1][M-1][1]) << endl;
        return 0;
    }
    if(d[N-1][M-1][1] != 0){
        cout << d[N-1][M-1][1] << endl;
    }
    if(d[N-1][M-1][0] != 0){
        cout << d[N-1][M-1][0] << endl;
    }
    return 0;
}