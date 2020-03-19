#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int map[101][101]; bool visited[101][101];
int d[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int N; int M;
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d", &map[i][j]);
            visited[i][j] = false;
        }
    }
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(1, 1, 1));
    visited[1][1] = true; d[1][1] = 1;
    while(!q.empty()){
        tuple<int, int, int> point = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = get<0>(point) + dy[i];
            int nx = get<1>(point) + dx[i];
            int cnt = get<2>(point) + 1;
            if(ny>=1 && ny<=N && nx>=1 && nx<=M && map[ny][nx] == 1 && !visited[ny][nx]){
                visited[ny][nx] = true; d[ny][nx] = cnt;
                q.push(make_tuple(ny, nx, cnt));
            }
        }
    }
    cout << d[N][M] << endl;
    return 0;
}
