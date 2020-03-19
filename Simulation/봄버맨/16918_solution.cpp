#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int board[200][200];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int R, C, T;
int main(){
    cin >> R >> C >> T;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char c; cin >> c;
            if(c == 'O') board[i][j] = 0;
            else if(c == '.') board[i][j] = -1;
        }
    }
    // 아무것도 하지 않는 것 처리
    int t = 1;
    for(int t = 1; t<T; t++){
        if(t%2 == 1){
            for(int i=0; i<R; i++){
                for(int j=0; j<C; j++){
                    if(board[i][j] == -1) board[i][j] = t+1;
                }
            }
        }
        else if(t%2 == 0){
            vector<pair<int, int>> explosions;
            for(int i=0; i<R; i++){
                for(int j=0; j<C; j++){
                    if(board[i][j] == t-2){
                        explosions.push_back(make_pair(i, j));
                        for(int k=0; k<4; k++){
                            int ny = i+dy[k]; int nx = j+dx[k];
                            if(ny>=0 && ny<R && nx>=0 && nx<C){
                                explosions.push_back(make_pair(ny, nx));
                            }
                        }
                    }
                }
            }
            for(auto &p : explosions){
                board[p.first][p.second] = -1;
            }
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            int c = board[i][j] != -1 ? 'O' : '.';
            printf("%c", c);
        }
        cout <<'\n';
    }

    return 0;
}