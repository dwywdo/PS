#include <iostream>
using namespace std;
int N = 0; int M = 0;
char map[50][50];
int d[50][50];
bool visited[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
string answer = "No";
void DFS(int y, int x, int distance){
    visited[y][x] = true;
    d[y][x] = distance;
    char color = map[y][x];
    for(int i=0; i<4; i++){
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny>=0 && ny<N && nx>=0 && nx<M){
            if(!visited[ny][nx] && map[ny][nx] == color){
                DFS(ny, nx, distance + 1);
            }
            else if(visited[ny][nx] && distance - d[ny][nx] >= 3){
                answer = "Yes";
                return;
            }
        }
    }
    return;
}
int main(){
    cin >> N;
    cin >> M;
    string row;
    for(int i=0; i<N; i++){
        cin >> row;
        for(int j=0; j<row.size(); j++){
            map[i][j] = row[j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(visited[i][j]) continue;
            DFS(i, j, 0);
        }
    }
    cout << answer << endl;
    return 0;
}