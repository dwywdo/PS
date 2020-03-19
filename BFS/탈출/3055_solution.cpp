#include <iostream>
#include <queue>
#include <tuple> // y, x, t를 위함
using namespace std;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int R = 0; int C = 0;
int forest[50][50];
int waterTime[50][50];
int d[50][50];
int main(){
    cin >> R >> C;
    int s_r = 0; int s_c = 0;
    int d_r = 0; int d_c = 0;
    queue<pair<int, int>> wq;
    for(int r=0; r<R; r++){
        string row = ""; cin >> row;
        for(int c=0; c<C; c++){
            forest[r][c] = row[c];
            waterTime[r][c] = -1; d[r][c] = -1;
            if(forest[r][c] == 'S'){
                s_r = r; s_c = c;
            }
            if(forest[r][c] == 'D'){
                d_r = r; d_c = c;
            }
            if(forest[r][c] == '*'){
                waterTime[r][c] = 0;
                wq.push(make_pair(r, c));
            }
        }
    }
    
    while(!wq.empty()){ // 물을 채우는 BFS
        int y = wq.front().first; int x = wq.front().second; wq.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i]; int nx = x + dx[i];
            if(ny>=0 && ny<R && nx>=0 && nx<C){
                if(waterTime[ny][nx] == -1 && forest[ny][nx] != 'X' && forest[ny][nx] != 'D'){
                    waterTime[ny][nx] = waterTime[y][x] + 1;
                    wq.push(make_pair(ny, nx));
                }
            }
        }
    }
    queue<tuple<int, int, int>> sq;
    d[s_r][s_c] = 0;
    sq.push(make_tuple(s_r, s_c, 0));
    while(!sq.empty()){
        int y = get<0>(sq.front());
        int x = get<1>(sq.front());
        int t = get<2>(sq.front());
        sq.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i]; int nx = x + dx[i];
            if(ny>=0 && ny<R && nx>=0 && nx<C){
                if(d[ny][nx] != -1) continue;
                if(forest[ny][nx] == 'X') continue;
                if(waterTime[ny][nx] != -1 && t + 1 >= waterTime[ny][nx]) continue;
                
                d[ny][nx] = d[y][x] + 1;
                sq.push(make_tuple(ny, nx, t+1));
            }
        }
    }
    if(d[d_r][d_c] == -1){
        cout << "KAKTUS" << endl;
    }
    else{
        cout << d[d_r][d_c] << endl;
    }
    return 0;
}