#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int board[8][8];
int check[8][8][9];
int dy[9] = {-1, 1, 0, 0, -1, 1, 1, -1, 0};
int dx[9] = {0, 0, -1, 1, 1, 1, -1, -1, 0};
// 벽이 [y][x]에 존재했다면, 1초 뒤에는 [y+1][x]로 이동한다.
// 벽이 [y][x]에 존재했다면, t초 뒤에는 [y+t][x]로 이동한다.
// t가 8초가 되면, 모든 벽이 사라진다.
int main(){
    for(int i=0; i<8; i++){
        string row = "";
        cin >> row;
        for(int j=0; j<8; j++){
            board[i][j] = row[j];
        }
    }
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(7, 0, 0));
    check[7][0][0] = true; bool ans = false;
    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();
        if(y == 0 && x == 7) ans = true;
        if(y-t>=0 && board[y-t][x] == '#') continue;
        for(int i=0; i<9; i++){
            int ny = y + dy[i]; int nx = x + dx[i]; int nt = min(t+1, 8);
            // 새로운 좌표가 체스판 영역의 밖인 경우
            if (0 <= nx && nx < 8 && 0 <= ny && ny < 8){
                // 범위 검사를 위함.. ny-t가 0보다 작고 벽이 있었다면 이미 사라진 벽임
                if(ny-t >= 0 && board[ny-t][nx] == '#') continue;
                // 다음에 어차피 벽이 내려온다면 그 상태로는 가지 않음
                // 29번째 줄로 처리 가능. 일단 방문하고 벽이 내려왔으면 더이상 추가 방문 하지 않는 방식으로
                //if(ny-t-1 >= 0 && board[ny-t-1][nx] == '#') continue;
                if(check[ny][nx][nt] == false){
                    check[ny][nx][nt] = true;
                    q.push(make_tuple(ny, nx, nt));
                }
            }
        }
    }
    if(ans) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}