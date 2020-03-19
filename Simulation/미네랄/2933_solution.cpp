#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visited[100][100];
char cave[100][100];
int R, C, N;
vector<int> heights;
vector<pair<int, int>> cluster;
void dfs(int y, int x){
    if(visited[y][x]) return;
    if(cave[y][x] == '.') return;
    visited[y][x] = true;
    cluster.push_back(make_pair(y, x));
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny>=0 && ny<R && nx>=0 && nx<C){
            dfs(ny, nx);
        }
    }
    return;
}
int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> cave[i][j];
        }
    }
    cin >> N;
    vector<int> heights(N, 0);
    for(int i=0; i<N; i++){
        cin >> heights[i];
    }
    for(int i=0; i<N; i++){
        int height = heights[i];
        int hindex = R - height;
        if(i%2 == 0){
            // 왼쪽에서 오른쪽
            int y = hindex; int x = 0;
            while(x < C && cave[y][x] != 'x') x++;
            cave[y][x] = '.';
        }
        else{
            // 오른쪽에서 왼쪽
            int y = hindex; int x = C-1;
            while(x >= 0 && cave[y][x] != 'x') x--;
            cave[y][x] = '.';
        }
        memset(visited, false, sizeof(visited));
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(visited[i][j]) continue;
                if(cave[i][j] == '.') continue;
                cluster.clear();
                dfs(i, j);
                vector<int > low(C, -1);
                for(auto &p : cluster){
                    low[p.second] = max(low[p.second], p.first);
                    cave[p.first][p.second] = '.';
                }
                int howmany = R;
                for(int i, j=0; j<C; j++){
                    if(low[j] == -1) continue;
                    for(i=low[j]; i<R && cave[i][j] =='.'; i++);
                    howmany = min(howmany, i-low[j]-1);
                }
                for(auto &p : cluster){
                    p.first += howmany;
                    cave[p.first][p.second] = 'x';
                    visited[p.first][p.second] = true;
                }
                int temp =0;
            }
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            printf("%c", cave[i][j]);
        }
        printf("\n");
    }
    return 0;
}