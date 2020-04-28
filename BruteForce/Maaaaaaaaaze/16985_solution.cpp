#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 5
typedef struct loc{
    int z = 0;
    int y = 0;
    int x = 0;
}LOC;
int dz[6] = {-1, 0, 0, 0, 0, 1};
int dy[6] = {0, -1, 1, 0, 0, 0};
int dx[6] = {0, 0, 0, -1, 1, 0};
int maze[MAXN][MAXN][MAXN];
int answer = 987654321;
bool rangeCheck(int z, int y, int x){
    if(z>=0 && z<MAXN && y>=0 && y<MAXN && x>=0 && x<MAXN) return true;
    else return false;
}
int BFS(int maze[MAXN][MAXN][MAXN]){
    if(maze[0][0][0] != 1) return -1;
    int dist[MAXN][MAXN][MAXN];
    memset(dist, -1, sizeof(dist));

    queue<LOC> q;
    LOC startNode; startNode.z = 0; startNode.y = 0; startNode.x = 0; q.push(startNode);
    dist[0][0][0] = 0;
    while(!q.empty()){
        int z = q.front().z; int y = q.front().y; int x = q.front().x; q.pop();
        for(int k=0; k<6; k++){
            int nz = z + dz[k]; int ny = y + dy[k]; int nx = x + dx[k];
            if(!rangeCheck(nz, ny, nx)) continue;
            if(maze[nz][ny][nx] == 0) continue;
            if(dist[nz][ny][nx] != -1) continue;
            dist[nz][ny][nx] = dist[z][y][x] + 1;
            LOC nextNode; nextNode.z = nz; nextNode.y = ny; nextNode.x = nx;
            q.push(nextNode);
        }
    }
    
    if(dist[MAXN-1][MAXN-1][MAXN-1] == -1) return -1;
    
    return dist[MAXN-1][MAXN-1][MAXN-1];
}
void do_rotate(int board[][MAXN], int rotcount){
    for(int r=0; r<rotcount; r++){
        int tmp[MAXN][MAXN];
        for(int a=0; a<MAXN; a++){
            for(int b=0; b<MAXN; b++){
                tmp[a][b] = board[a][b];
            }
        }
        for(int a=0; a<MAXN; a++){
            for(int b=0; b<MAXN; b++){
                board[a][b] = tmp[MAXN - 1 - b][a];
            }
        }
    }
}
void go(vector<int> &rotation){
    int tmp_maze[MAXN][MAXN][MAXN];
    vector<int> d; d.push_back(0); d.push_back(1); d.push_back(2); d.push_back(3); d.push_back(4);
    sort(d.begin(), d.end());
    do{
        for(int i=0; i<d.size(); i++){
            int z_idx = d[i];
            for(int j=0; j<MAXN; j++){
                for(int k=0; k<MAXN; k++){
                    tmp_maze[z_idx][j][k] = maze[i][j][k];
                }
            }
            int rotcount = rotation[i];
            do_rotate(tmp_maze[z_idx], rotcount);
        }

        for(int i=0; i<4; i++){
            int time = BFS(tmp_maze);
            if(time != -1){
                if(time < answer) answer = time;
            }
            for(int r=0; r<5; r++){
                do_rotate(tmp_maze[r], 1);
            }
        }

    }while(next_permutation(d.begin(), d.end()));

    


}
void choose(int cnt, vector<int> &rotation){
    if(cnt == 5){
        go(rotation);
        return ;
    }
    for(int i=0; i<4; i++){
        rotation.push_back(i);
        choose(cnt + 1, rotation);
        rotation.pop_back();
    }
}
int main(){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            for(int k=0; k<MAXN; k++){
                cin >> maze[i][j][k];
            }
        }
    }
    vector<int> rotation;
    choose(0, rotation);
    if(answer == 987654321){
        cout << -1 << "\n";
    }
    else{
        cout << answer << "\n";
    }
    return 0;
}