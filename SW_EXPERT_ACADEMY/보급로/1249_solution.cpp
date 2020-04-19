#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 100
int T = 0;
int map[MAXN][MAXN];
int dist[MAXN][MAXN];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        int N = 0; cin >> N;
        memset(map, 0, sizeof(map));
        memset(dist, -1, sizeof(dist));
        for(int i=0; i<N; i++){
            string row = ""; cin >> row;
            for(int j=0; j<N; j++){
                map[i][j] = row[j] - '0';
            }
        }
        dist[0][0] = 0;
        queue<pair<int, int>> q; q.push(make_pair(0, 0));
        while(!q.empty()){
            int y = q.front().first; int x = q.front().second; q.pop();
            for(int k=0; k<4; k++){
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
                if(dist[ny][nx] == -1){
                    dist[ny][nx] = dist[y][x] + map[ny][nx];
                    q.push(make_pair(ny, nx));
                }
                else{
                    if(map[ny][nx] + dist[y][x] < dist[ny][nx]){
                        dist[ny][nx] = dist[y][x] + map[ny][nx];
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
        cout << "#" << test_case << " " << dist[N-1][N-1] << "\n";
    }
    return 0;
}