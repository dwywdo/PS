#include <iostream>
#include <queue>
using namespace std;
int N; int M;
int map[1000][1000];
bool visited[1000][1000];
int d[1000][1000];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    cin >> M >> N;
    queue<pair<int, int> > q;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            visited[i][j] = false;
            if(map[i][j] == 1){
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        pair<int, int> point = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = point.first + dy[i];
            int nx = point.second + dx[i];
            if(ny>=0 && ny<N && nx>=0 && nx<M && map[ny][nx] == 0 && !visited[ny][nx]){
                d[ny][nx] = d[point.first][point.second] + 1;
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
    int answer = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(answer < d[i][j]) answer = d[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0 && d[i][j] == 0) answer = -1;
        }
    }
    cout << answer << endl;
    return 0;
}