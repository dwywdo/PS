#include <iostream>
#include <queue>
using namespace std;
int N; int M;
int map[8][8];
int copymap[8][8];
bool visited[8][8];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = 0;
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    int mapsize = M*N;
    for(int p1 = 0; p1<mapsize; p1++){
        for(int p2 = p1+1; p2<mapsize; p2++){
            for(int p3 = p2+1; p3<mapsize; p3++){
                int p1_x = p1 % M; int p1_y = p1 / M;
                int p2_x = p2 % M; int p2_y = p2 / M;
                int p3_x = p3 % M; int p3_y = p3 / M;
                if(map[p1_y][p1_x] != 0) continue;
                if(map[p2_y][p2_x] != 0) continue;
                if(map[p3_y][p3_x] != 0) continue;
                for(int i=0; i<N; i++){
                    for(int j=0; j<M; j++){
                        copymap[i][j] = map[i][j];
                        visited[i][j] = false;
                    }
                }
                copymap[p1_y][p1_x] = 1; copymap[p2_y][p2_x] = 1; copymap[p3_y][p3_x] = 1;
                for(int i=0; i<N; i++){
                    for(int j=0; j<M; j++){
                        if(copymap[i][j]!=2) continue;
                        queue<pair<int, int>> q;
                        visited[i][j] = true;
                        q.push(make_pair(i, j));
                        while(!q.empty()){
                            int y = q.front().first; int x = q.front().second;
                            q.pop();
                            for(int k=0; k<4; k++){
                                int ny = y + dy[k]; int nx = x + dx[k];
                                if(nx>=0 && nx<M && ny>=0 && ny<N && !visited[ny][nx] && copymap[ny][nx] == 0){
                                    visited[ny][nx] = true;
                                    copymap[ny][nx] = 2;
                                    q.push(make_pair(ny, nx));
                                }
                            }
                        }
                        
                    }
                }
                int safeCount = 0;
                for(int i=0; i<N; i++){
                    for(int j=0; j<M; j++){
                        if(copymap[i][j] == 0) safeCount++;
                    }
                }
                answer = safeCount > answer ? safeCount : answer;
            }
        }
    }
    cout << answer;
    return 0;
}