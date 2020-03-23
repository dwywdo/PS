#include <iostream>
#include <vector>
using namespace std;
#define B 1
#define W 2
int T, N, M;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N >> M;
        vector<vector<int>> board(N, vector<int>(N, 0));
        int lastindex = N-1;
        board[lastindex/2][lastindex/2] = W; board[lastindex/2][lastindex/2+1] = B; board[lastindex/2+1][lastindex/2] = B; board[lastindex/2+1][lastindex/2+1] = W;
        for(int i=0; i<M; i++){
            int y; int x; int color;
            cin >> x >> y >> color;
            board[y-1][x-1] = color;
            int cy = y - 1; int cx = x - 1;
            for(int k=0; k<8; k++){
                int ny = cy + dy[k];
                int nx = cx + dx[k];
                if(!(ny >= 0 && ny < N && nx >= 0 && nx < N)) continue;
                if(board[ny][nx] == 0) continue;
                if(board[ny][nx] == color) continue;
                if(board[ny][nx] == 3 - color) {
                    vector<pair<int, int>> targets;
                    bool check = false;
                    while(board[ny][nx] == 3 - color){
                        targets.push_back(make_pair(ny, nx));
                        ny = ny + dy[k]; nx = nx + dx[k];
                        if(!(ny >= 0 && ny < N && nx >= 0 && nx < N)) break;
                        if(board[ny][nx] == color){
                            check = true; break;
                        }
                        if(board[ny][nx] == 0){
                            check = false; break;
                        }
                    }
                    if(check){
                        for(auto &p : targets){
                            board[p.first][p.second] = color;
                        }
                    }
                }
            }
        }
        int bcount = 0; int wcount = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(board[i][j] == B) bcount++;
                if(board[i][j] == W) wcount++;
            }
        }
        cout << "#" << test_case << " " << bcount << " " << wcount << '\n';
    }
    return 0;
}