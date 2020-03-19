#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, D;
int g_map[16][16];
int castleRow = 0;
bool check[16];
int enemyCount = 0;
int answer = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int playGame(vector<pair<int, int>> archers){
    int killCount = 0;
    int enemyCnt = enemyCount;
    int map[16][16];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) map[i][j] = g_map[i][j];
    }
    // 궁수들은 모두 *동시에 공격하며, 가장 가까운 적 우선 공격, 여러 명이라면 가장 왼쪽의 적을 공격한다.
    while(enemyCnt != 0){
        vector<pair<int, int>> targets;
        for(int i=0; i<archers.size(); i++){
            int a_y = archers[i].first; int a_x = archers[i].second;
            queue<pair<int, int>> q;
            int d[16][16];
            for(int j=0; j<N; j++){
                for(int k=0; k<M; k++) d[j][k] = -1;
            }
            d[a_y][a_x] = 0;
            q.push(make_pair(a_y, a_x));
            while(!q.empty()){
                int y = q.front().first; int x = q.front().second; q.pop();
                for(int k=0; k<4; k++){
                    int ny = y + dy[k]; int nx = x + dx[k];
                    if(ny>=0 && ny<N && nx>=0 && nx<M){
                        if(d[ny][nx] == -1){
                            d[ny][nx] = d[y][x] + 1;
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
            }
            int dist = 987654321;
            int target_y = -1; int target_x = -1;
            for(int l=0; l<M; l++){
                for(int m=0; m<N; m++){
                    if(d[m][l] != -1 && map[m][l] == 1){
                        if(dist > d[m][l] && d[m][l] <= D) {
                            dist = d[m][l];
                            target_y = m; target_x = l;
                        }
                    }
                }
            }
            if(!(target_y == -1 && target_x == -1)){
                targets.push_back(make_pair(target_y, target_x));
            }
        }
        for(int t=0; t<targets.size(); t++){
            if(map[targets[t].first][targets[t].second] == 1){
                map[targets[t].first][targets[t].second] = 0; killCount++; enemyCnt--;
            }
        }
        for(int i=N; i>=1; i--){
            for(int j=M-1; j>=0; j--){
                if(map[i-1][j] == 1){
                    map[i][j] = 1; map[i-1][j] = 0;
                    if(i == castleRow) enemyCnt--;
                }
            }
        }
    }
    return killCount;
}
// 0 ~ M-1까지의 수 중에 3개를 골라야 한다.
void choose(int N, int start, vector<pair<int, int>> archers){
    if(archers.size() == 3){
        int killCount = playGame(archers);
        if(killCount > answer) {
            answer = killCount;
        }
        return;
    }
    for(int i = start; i<=N; i++){
        if(check[i]) continue;
        check[i] = true;
        archers.push_back(make_pair(castleRow, i));
        choose(N, i+1, archers);
        check[i] = false;
        archers.pop_back();
    }
}
int main(){
    cin >> N >> M >> D;
    castleRow = N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> g_map[i][j];
            if(g_map[i][j] == 1){
                enemyCount++;
            }
        }
    }
    vector<pair<int, int>> archers;
    choose(M-1, 0, archers);
    cout << answer << endl;
    return 0;
}
