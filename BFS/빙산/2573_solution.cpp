#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>
#define MAXN 300
#define MAXM 300
using namespace std;

int map[2][MAXN][MAXM];
bool visited[MAXN][MAXM];
int N, M = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<tuple<int, int, int>> icebergs;
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[0][i][j];
            if(map[0][i][j] != 0){
                icebergs.push_back(make_tuple(i, j, map[0][i][j]));
            }
        }
    }
    int curmap = 0;
    int time = 0;
    bool possible = true;
    while(1){
        time++;
        vector<tuple<int, int, int>> deads;
        memset(map[1-curmap], 0, sizeof(map[1-curmap]));
        for(auto &p : icebergs){
            int y = get<0>(p); int x = get<1>(p); int value = get<2>(p);
            int seacount = 0;
            for(int k=0; k<4; k++){
                int ny = y + dy[k]; int nx = x + dx[k];
                if(ny>=0 && ny<N && nx>=0 && nx<M){
                    if(map[curmap][ny][nx] == 0){
                        seacount++;
                    }
                }
            }
            if(value - seacount <= 0) deads.push_back(make_tuple(y, x, value));
            else{
                map[1 - curmap][y][x] = value - seacount;
                p = make_tuple(y, x, value - seacount);
            }
        }
        for(auto &dead : deads) {
            icebergs.erase(find(icebergs.begin(), icebergs.end(), dead));
        }
        int totalcnt = icebergs.size();
        if(totalcnt == 0) {
            possible = false;
            break;
        }
        int cnt = 0;
        queue<pair<int, int>> q;
        memset(visited, false, sizeof(visited));
        int start_y = get<0>(icebergs[0]);
        int start_x = get<1>(icebergs[0]);
        visited[start_y][start_x] = true; cnt++;
        q.push(make_pair(start_y, start_x));
        while(!q.empty()){
            int y = q.front().first; int x = q.front().second; q.pop();
            for(int k=0; k<4; k++){
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(!(ny>=0 && ny<N && nx>=0 && nx<M)) continue;
                if(map[1 - curmap][ny][nx] == 0) continue;
                if(visited[ny][nx]) continue;
                visited[ny][nx] = true;
                cnt++;
                q.push(make_pair(ny, nx));
            }
        }
        if(cnt != totalcnt) {
            break;
            possible = true;
        }
        curmap = 1 - curmap;
    }
    if(possible) cout << time << "\n";
    else cout << 0 << "\n";
    return 0;
}