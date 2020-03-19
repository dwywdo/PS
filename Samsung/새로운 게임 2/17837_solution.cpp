#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define WHITE 0
#define RED 1
#define BLUE 2
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
int N, K; 
vector<int> horses[13][13]; // 말의 번호, 이동 방향
int board[13][13];
vector<pair<int, int>> loc(11); // y, x값
vector<int> dir(11);
int rd(int d){
    if(d==RIGHT) return LEFT;
    else if(d==LEFT) return RIGHT;
    else if(d==UP) return DOWN;
    else if(d==DOWN) return UP;
    else return 0;
}
int main(){
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }
    for(int i=1; i<=K; i++){
        int r, c, d;
        cin >> r >> c >> d;
        horses[r][c].push_back(i);
        dir[i] = d;
        loc[i] = make_pair(r, c);
    }
    int turn = 1; bool possible = true;
    while(1){
        if(turn >= 1001){
            possible = false; break;
        }
        bool end = false;
        for(int i=1; i<=K; i++){
            int y = loc[i].first; int x = loc[i].second; int d = dir[i];
            int ny = y + dy[d]; int nx = x + dx[d];
            if(nx>=1 && nx<=N && ny>=1 && ny<=N){
                vector<int> targets(find(horses[y][x].begin(), horses[y][x].end(), i), horses[y][x].end());
                if(board[ny][nx] == WHITE){
                    horses[y][x].erase(find(horses[y][x].begin(), horses[y][x].end(), i), horses[y][x].end());
                    for(int t=0; t<targets.size(); t++){
                        horses[ny][nx].push_back(targets[t]);
                        loc[targets[t]] = make_pair(ny, nx); 
                    }
                }
                else if(board[ny][nx] == RED){
                    horses[y][x].erase(find(horses[y][x].begin(), horses[y][x].end(), i), horses[y][x].end());
                    for(int t=targets.size()-1; t>=0; t--){
                        horses[ny][nx].push_back(targets[t]);
                        loc[targets[t]] = make_pair(ny, nx);
                    }
                }
                else if(board[ny][nx] == BLUE){
                    int nd = rd(d); ny = y + dy[nd]; nx = x + dx[nd];
                    if(nx>=1 && nx<=N && ny>=1 && ny<=N){
                        if(board[ny][nx] == WHITE){
                            dir[i] = nd;
                            horses[y][x].erase(find(horses[y][x].begin(), horses[y][x].end(), i), horses[y][x].end());
                            for(int t=0; t<targets.size(); t++){
                                horses[ny][nx].push_back(targets[t]);
                                loc[targets[t]] = make_pair(ny, nx); 
                            }
                        }
                        else if(board[ny][nx] == RED){
                            dir[i] = nd;
                            horses[y][x].erase(find(horses[y][x].begin(), horses[y][x].end(), i), horses[y][x].end());
                            for(int t=targets.size()-1; t>=0; t--){
                                horses[ny][nx].push_back(targets[t]);
                                loc[targets[t]] = make_pair(ny, nx);
                            }
                        }
                        else if(board[ny][nx] == BLUE){
                            dir[i] = nd;
                        }
                    }
                    else{
                        dir[i] = nd;
                    }
                }
            }
            else{
                vector<int> targets(find(horses[y][x].begin(), horses[y][x].end(), i), horses[y][x].end());
                int nd = rd(d); ny = y + dy[nd]; nx = x + dx[nd];
                if(nx>=1 && nx<=N && ny>=1 && ny<=N){
                    if(board[ny][nx] == WHITE){
                        dir[i] = nd;
                        horses[y][x].erase(find(horses[y][x].begin(), horses[y][x].end(), i), horses[y][x].end());
                        for(int t=0; t<targets.size(); t++){
                            horses[ny][nx].push_back(targets[t]);
                            loc[targets[t]] = make_pair(ny, nx); 
                        }
                    }
                    else if(board[ny][nx] == RED){
                        dir[i] = nd;
                        horses[y][x].erase(find(horses[y][x].begin(), horses[y][x].end(), i), horses[y][x].end());
                        for(int t=targets.size()-1; t>=0; t--){
                            horses[ny][nx].push_back(targets[t]);
                            loc[targets[t]] = make_pair(ny, nx);
                        }
                    }
                    else if(board[ny][nx] == BLUE){
                        dir[i] = nd;
                    }
                }
                else{
                    dir[i] = nd;
                }
            }
            if(horses[ny][nx].size() >= 4){
                end = true; possible = true; break;
            }
        }
        if(end) break;

        turn++;
    }
    if(possible) cout << turn << '\n';
    else cout << -1 << '\n';
    return 0;
}