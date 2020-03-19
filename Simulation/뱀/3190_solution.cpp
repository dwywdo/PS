#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, char>> insts;
deque<pair<int, int>> snake;
int N, K;
int board[100][100];
int L;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
// 2: snake
// 1: apple
// 0: empty
int main(){
    cin >> N >> K;
    for(int i=0; i<K; i++){
        int y = 0; int x = 0;
        cin >> y >> x;
        board[y-1][x-1] = 1;
    }
    cin >> L;
    for(int i=0; i<L; i++){
        int t = 0; char c = '0';
        cin >> t >> c;
        insts.push_back(make_pair(t, c));
    }
    snake.push_back(make_pair(0, 0));
    board[0][0] = 2;
    int d = 0;
    int time = 0;
    while(1){
        time++;
        int head_y = snake.front().first; int head_x = snake.front().second;
        int ny = head_y + dy[d]; int nx = head_x + dx[d];
        if(ny>=0 && ny<N && nx>=0 && nx<N){
            // 뱀 머리에 부딪힌 경우
            if(board[ny][nx] == 2) break;
            if(board[ny][nx] == 1) {
                board[ny][nx] = 2; snake.push_front(make_pair(ny, nx));
            }
            else if(board[ny][nx] == 0){
                board[ny][nx] = 2;
                snake.push_front(make_pair(ny, nx));
                int by = snake.back().first; int bx = snake.back().second;
                board[by][bx] = 0; 
                snake.pop_back();
            }
        }
        // 맵 밖으로 나가는 경우
        else{
            break;
        }
        for(auto it=insts.begin(); it<insts.end(); it++){
            int t = (*it).first; int c = (*it).second;
            if(t<=time){
                // L 왼쪽
                if(c=='L') d = (d+3)%4;
                // D 오른쪽
                else if(c=='D') d = (d+1)%4;
                insts.erase(it);
                break;
            }
        }
    }
    cout << time << '\n';
    return 0;
}
