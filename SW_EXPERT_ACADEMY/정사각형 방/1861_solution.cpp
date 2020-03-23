#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int T, N;
int map[1001][1001];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N;
        memset(map, 0, sizeof(map));
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];
            }
        }
        int answerRoom = N*N + 1;
        int answerCount = 0;
        bool visited[1001][1001];
        memset(visited, false, sizeof(visited));
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(visited[i][j]) continue;
                int room = map[i][j]; int cnt = 1;
                queue<pair<int, int>> q;
                visited[i][j] = true;
                q.push(make_pair(i, j));
                while(!q.empty()){
                    int y = q.front().first; int x = q.front().second; q.pop();
                    for(int k=0; k<4; k++){
                        int ny = y + dy[k]; int nx = x + dx[k];
                        if(ny>=1 && ny<=N && nx>=1 && nx<=N){
                            if(map[ny][nx] - map[y][x] == 1){
                                q.push(make_pair(ny, nx)); cnt++;
                                visited[ny][nx] = true;
                            }
                            else{
                                continue;
                            }
                        }
                    }
                }
                if(cnt > answerCount){
                    answerRoom = room; answerCount = cnt;
                }
                if(cnt == answerCount){
                    if(room < answerRoom) answerRoom = room;
                }
            }
        }
        cout << "#" << test_case << " " << answerRoom << " " << answerCount << "\n"; 
    }
    return 0;
}