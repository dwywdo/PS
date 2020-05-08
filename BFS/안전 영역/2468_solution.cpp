#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 100
int map[MAXN][MAXN];
int N = 0;
int answer = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int BFS(int height){
    bool visited[MAXN][MAXN];
    memset(visited, false, sizeof(visited));
    int areaCnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]) continue;
            if(map[i][j] <= height) continue;
            queue<pair<int, int>> q;
            areaCnt++;
            visited[i][j] = true;
            q.push(make_pair(i, j));
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if(visited[ny][nx]) continue;
                    if(map[ny][nx] <= height) continue;
                    if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    return areaCnt;
}
int main(){
    cin >> N;
    int maxheight = 0;
    int minheight = 100;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(maxheight < map[i][j]) maxheight = map[i][j];
            if(minheight > map[i][j]) minheight = map[i][j];
        }
    }
    int temp = 0;
    for(int height=0; height<=maxheight; height++){
        int cnt = BFS(height);
        if(answer < cnt) answer = cnt;
    }
    cout << answer << "\n";
    return 0;
}