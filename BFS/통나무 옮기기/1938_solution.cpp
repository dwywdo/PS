#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 50
int N;
char map[MAXN][MAXN];
// 통나물의 배열 정보가 첫 인덱스; 0 : 세로, 1 : 가로
char status[2][3][3] = {
    {
        {'0', '0', '0'}, 
        {'1', '1', '1'}, 
        {'0', '0', '0'}
    },
    {
        {'0', '1', '0'}, 
        {'0', '1', '0'}, 
        {'0', '1', '0'}
    }
};
typedef struct node{
    int y = 0;
    int x = 0;
    int stat = 0;
}NODE;
int start_stat = 0; int start_y = 0; int start_x = 0;
int dest_stat = 0; int dest_y = 0; int dest_x = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool rotateCheck(int y, int x){
    bool rotatePossible = true;
    for(int i=y-1; i<=y+1; i++){
        for(int j=x-1; j<=x+1; j++){
            if(map[i][j] == '1'){
                rotatePossible = false; break;
            }
        }
        if(!rotatePossible) break;
    }
    return rotatePossible;
}
bool check(int y, int x, int stat){
    int c_stat[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            c_stat[i][j] = status[stat][i][j];
        }
    }
    bool possible = true;
    // i, j : 상대적인 통나무의 위치. 중심점은 1, 1에 위치
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int ky = y+i-1; // ky, kx : 맵에서의 위치
            int kx = x+j-1;
            if(c_stat[i][j] == '1'){
                if(kx<0 || kx>=N || ky<0 || ky>=N || map[ky][kx] == '1'){
                    possible = false;
                }
            }
        }
    }
    return possible;
}
int BFS(){
    int dist[MAXN][MAXN][2];
    memset(dist, -1, sizeof(dist));
    dist[start_y][start_x][start_stat] = 0;
    queue<NODE> q;
    NODE start; start.y = start_y; start.x = start_x; start.stat = start_stat;
    q.push(start);
    while(!q.empty()){
        int y = q.front().y; int x = q.front().x; int stat = q.front().stat; q.pop();
        for(int k=0; k<4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(dist[ny][nx][stat] != -1) continue;
            if(!check(ny, nx, stat)) continue;
            dist[ny][nx][stat] = dist[y][x][stat] + 1;
            NODE next; next.y = ny, next.x = nx; next.stat = stat;
            q.push(next);
        }
        int nstat = 1 - stat;
        if(dist[y][x][nstat] == -1 && check(y, x, nstat) && rotateCheck(y, x)){
            dist[y][x][nstat] = dist[y][x][stat] + 1;
            NODE next; next.y = y; next.x = x; next.stat = nstat;
            q.push(next);
        } 
    }
    return dist[dest_y][dest_x][dest_stat];
}
int main(){
    cin >> N;
    vector<pair<int, int>> start;
    vector<pair<int, int>> dest;
    for(int i=0; i<N; i++){
        string row; cin >> row;
        for(int j=0; j<N; j++){
            map[i][j] = row[j];
            if(map[i][j] == 'B') start.push_back(make_pair(i, j));
            if(map[i][j] == 'E') dest.push_back(make_pair(i, j));
        }
    }
    if(start[1].first - start[0].first != 0) start_stat = 1;
    start_y = start[1].first; start_x = start[1].second;
    if(dest[1].first - dest[0].first != 0) dest_stat = 1;
    dest_y = dest[1].first; dest_x = dest[1].second;
    int answer = BFS();
    if(answer == -1) cout << 0 << "\n";
    else cout << answer << "\n";
    return 0;
}