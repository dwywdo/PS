#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 200
int hmove_dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hmove_dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int mmove_dy[4] = {-1, 1, 0, 0};
int mmove_dx[4] = {0, 0, -1, 1};
int K, W, H;
int map[MAXN][MAXN];
typedef struct NODE{
    int y = 0;
    int x = 0;
    int k = 0;
}NODE;
int BFS(){
    int dist[MAXN][MAXN][MAXN]; memset(dist, -1, sizeof(dist));
    dist[0][0][0] = 0;
    NODE start; start.y = 0; start.x = 0; start.k = 0;
    queue<NODE> q; q.push(start);
    while(!q.empty()){
        int y = q.front().y; int x = q.front().x; int k = q.front().k; q.pop();
        for(int z=0; z<4; z++){
            int ny = y + mmove_dy[z]; int nx = x + mmove_dx[z];
            if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
            if(dist[ny][nx][k] != -1) continue;
            if(map[ny][nx] == 1) continue;
            dist[ny][nx][k] = dist[y][x][k] + 1;
            NODE next; next.y = ny; next.x = nx; next.k = k;
            q.push(next);
        }
        if(k<K){
            for(int z=0; z<8; z++){
                int ny = y + hmove_dy[z]; int nx = x + hmove_dx[z];
                if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
                if(dist[ny][nx][k+1] != -1) continue;
                if(map[ny][nx] == 1) continue;
                dist[ny][nx][k+1] = dist[y][x][k] + 1;
                NODE next; next.y = ny; next.x = nx; next.k = k + 1;
                q.push(next);
            }
        }
    }
    int min = 987654321;
    for(int i=0; i<MAXN; i++){
        if(dist[H-1][W-1][i] < min && dist[H-1][W-1][i] != -1) min = dist[H-1][W-1][i];
    }
    return min;
}
int main(){
    cin >> K >> W >> H;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> map[i][j];
        }
    }
    int answer = BFS();
    if(answer == 987654321) cout << -1 << "\n";
    else cout << answer << "\n";
    return 0;
}