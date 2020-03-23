#include <iostream>
#include <map>
#include <vector>
using namespace std;
int dy[4] = {-1, 0, 1, 0}; // 위 오른쪽 아래 왼쪽 (시계방향 순)
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> board(100, vector<int>(100));
map<int, vector<pair<int, int>>> worms;
int next_d(int btype, int d){
    if(btype == 1){
        if(d == 0) return 2;
        if(d == 1) return 3;
        if(d == 2) return 1;
        if(d == 3) return 0;
    }
    else if(btype == 2){
        if(d == 0) return 1;
        if(d == 1) return 3;
        if(d == 2) return 0;
        if(d == 3) return 2;
        
    }
    else if(btype == 3){
        if(d == 0) return 3;
        if(d == 1) return 2;
        if(d == 2) return 0;
        if(d == 3) return 1;

    }
    else if(btype == 4){
        if(d == 0) return 2;
        if(d == 1) return 0;
        if(d == 2) return 3;
        if(d == 3) return 1;
        
    }
    else if(btype == 5){
        if(d == 0) return 2;
        if(d == 1) return 3;
        if(d == 2) return 0;
        if(d == 3) return 1;
    }
    else {
        return -1;
    }
    return 0;
}
typedef struct pinball{
    int y = 0; 
    int x = 0;
    int d = 0;
}PINBALL;
int T, N;
int go(int y, int x, int start_d){
    PINBALL ball;
    ball.y = y; ball.x = x; ball.d = start_d;
    int start_y = y; int start_x = x;
    int score = 0;
    int t = 0;
    while(1){
        if(t != 0 && start_y == ball.y && start_x == ball.x) break;
        t++;
        // 현재 밖으로 나와있으면
        if(!(ball.y>=0 && ball.y<N && ball.x>=0 && ball.x<N)) {
            score++;
            ball.d = next_d(5, ball.d);
            ball.y = ball.y + dy[ball.d]; ball.x = ball.x + dx[ball.d];
        }
        // 현재 위치가 빈 공간이면
        else if(board[ball.y][ball.x] == 0){
            ball.y = ball.y + dy[ball.d]; ball.x = ball.x + dx[ball.d];
            if(ball.y == start_y && ball.x == start_x) break;
        }
        // 현재 위치가 블록에 있으면
        else if(1 <= board[ball.y][ball.x] && board[ball.y][ball.x] <= 5){
            score++;
            ball.d = next_d(board[ball.y][ball.x], ball.d);
            ball.y = ball.y + dy[ball.d]; ball.x = ball.x + dx[ball.d];
            if(ball.y == start_y && ball.x == start_x) break;
        }
        // 현재 위치가 웜홀에 있으면
        else if(6 <= board[ball.y][ball.x] && board[ball.y][ball.x] <= 10){
            int ny = 0; int nx =0;
            for(auto &p : worms[board[ball.y][ball.x]]){
                if(p.first == ball.y && p.second == ball.x) continue;
                else{
                    ny = p.first; nx = p.second;
                }
            }
            ball.y = ny + dy[ball.d]; ball.x = nx + dx[ball.d];
        }
        else if(board[ball.y][ball.x] == -1) break;
    }
    return score;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N;
        int answer = 0;
        map<int, vector<pair<int, int>>> wormholes;
        vector<vector<int>> input(N, vector<int>(N));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> input[i][j];
                if(6<=input[i][j] && input[i][j]<=10){
                    if(wormholes.count(input[i][j]) == 0){
                        vector<pair<int, int>> list;
                        list.push_back(make_pair(i, j));
                        wormholes[input[i][j]] = list;
                    }
                    else wormholes[input[i][j]].push_back(make_pair(i, j));
                }
            }
        }
        board = input; worms = wormholes;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(board[i][j] != 0) continue;
                for(int d=0; d<4; d++){
                    int score = go(i, j, d);
                    if(answer < score) answer = score;           
                }
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}