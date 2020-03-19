#include <iostream>
using namespace std;
char map[20][20];
bool check[256];
int R, C;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = 0;
void go(int y, int x, int length){
    if(length > answer) answer = length;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny>=0 && ny<R && nx>=0 && nx<C){
            char n_alphabet = map[ny][nx];
            if(!check[n_alphabet]){
                check[n_alphabet] = true;
                go(ny, nx, length + 1);
                check[n_alphabet] = false;
            }
        }
    }
    return;
}
int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        string row = "";
        cin >> row;
        for(int j=0; j<C; j++){
            map[i][j] = row[j];
        }
    }
    check[map[0][0]] = true;
    go(0, 0, 1);
    cout << answer << endl;
    return 0;
}
// 리턴값을 이용한 구현
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int go(vector<string> &board, vector<bool> &check, int x, int y) {
    int ans = 0;
    for (int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
            if (check[board[nx][ny]-'A'] == false) {
                check[board[nx][ny]-'A'] = true;
                int next = go(board, check, nx, ny);
                if (ans < next) {
                    ans = next;
                }
                check[board[nx][ny]-'A'] = false;
            }
        }
    }
    return ans + 1;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i=0; i<n; i++) {
        cin >> board[i];
    }
    vector<bool> check(26);
    check[board[0][0]-'A'] = true;
    cout << go(board, check, 0, 0) << '\n';
    return 0;
}
*/