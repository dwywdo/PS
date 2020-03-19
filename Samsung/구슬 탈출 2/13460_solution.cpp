#include <iostream>
#include <queue>
using namespace std;
typedef struct state{
    int r_y = 0;
    int r_x =0;
    int b_y = 0;
    int b_x = 0;
}STATE;
char board[10][10];
int N, M;
int d[10][10][10][10];
bool check[10][10][10][10];
int o_y = 0; int o_x = 0;
// 왼 오 위 아래
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int answer = 987654321;
int main(){
    cin >> N >> M;
    STATE is;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R') {is.r_y = i; is.r_x = j;}
            if(board[i][j] == 'B') {is.b_y = i; is.b_x = j;}
            if(board[i][j] == 'O') {o_y = i; o_x = j;}
        }
    }
    queue<STATE> q;
    check[is.r_y][is.r_x][is.b_y][is.b_x] = true; d[is.r_y][is.r_x][is.b_y][is.b_x] = 0; 
    q.push(is);
    while(!q.empty()){
        STATE s = q.front(); q.pop();
        for(int k=0; k<4; k++){
            STATE ns = s;
            bool red_ok = false;
            bool blue_ok = false;
            while(1){
                if(board[ns.r_y + dy[k]][ns.r_x + dx[k]] == '#') break;
                else {
                    ns.r_y = ns.r_y + dy[k]; ns.r_x = ns.r_x + dx[k];
                    if(board[ns.r_y][ns.r_x] == 'O'){
                        red_ok = true; break;
                    }
                }
            }
            while(1){
                if(board[ns.b_y + dy[k]][ns.b_x + dx[k]] == '#') break;
                else {
                    ns.b_y = ns.b_y + dy[k]; ns.b_x = ns.b_x + dx[k];
                    if(board[ns.b_y][ns.b_x] == 'O'){
                        blue_ok = true; break;
                    }
                }
            }
            if(red_ok == true && blue_ok == false){
                if(!check[ns.r_y][ns.r_x][ns.b_y][ns.b_x]){
                    check[ns.r_y][ns.r_x][ns.b_y][ns.b_x] = true;
                    d[ns.r_y][ns.r_x][ns.b_y][ns.b_x] = d[s.r_y][s.r_x][s.b_y][s.b_x] + 1;
                    continue;
                }
            }
            if(red_ok == true && blue_ok == true) continue;
            if(red_ok == false && blue_ok == true) continue;

            if(ns.r_y == ns.b_y && ns.r_x == ns.b_x){
                if(ns.r_y == o_y && ns.r_x == o_x) continue;
                if(k==0){ // 왼
                    if(s.r_x < s.b_x) ns.b_x++;
                    else if(s.r_x > s.b_x) ns.r_x++;
                }
                else if(k==1){ // 오
                    if(s.r_x < s.b_x) ns.r_x--;
                    else if(s.r_x > s.b_x) ns.b_x--;
                }
                else if(k==2){ // 위
                    if(s.r_y < s.b_y) ns.b_y++;
                    else if(s.r_y > s.b_y) ns.r_y++;
                }
                else if(k==3){ // 아래
                    if(s.r_y < s.b_y) ns.r_y--;
                    else if(s.r_y > s.b_y) ns.b_y--;
                }
            }
            if(ns.r_y>=0 && ns.r_y <N && ns.r_x >=0 && ns.r_x<M && ns.b_y>=0 && ns.b_y <N && ns.b_x >=0 && ns.b_x<M){
                if(check[ns.r_y][ns.r_x][ns.b_y][ns.b_x]) continue;
                else{
                    check[ns.r_y][ns.r_x][ns.b_y][ns.b_x] = true;
                    d[ns.r_y][ns.r_x][ns.b_y][ns.b_x] = d[s.r_y][s.r_x][s.b_y][s.b_x] + 1;
                    q.push(ns);
                }
            }
            
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(answer > d[o_y][o_x][i][j] && check[o_y][o_x][i][j] == true){
                answer = d[o_y][o_x][i][j];
            }
        }
    }
    if(answer > 10) cout << -1 << endl;
    else cout << answer << endl;
    return 0;
}