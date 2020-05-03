#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 50
int map[MAXN][MAXN];
int N, M;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = 987654321;
int BFS(vector<pair<int, int>> &cand, vector<int> &d){
    queue<pair<int, int>> q;
    int dist[MAXN][MAXN]; memset(dist, -1, sizeof(dist));
    bool initialActivated[MAXN][MAXN]; memset(initialActivated, false, sizeof(initialActivated));
    for(int i=0; i<d.size(); i++){
        if(d[i] == 1) {
            q.push(make_pair(cand[i].first, cand[i].second));
            dist[cand[i].first][cand[i].second] = 0;
            initialActivated[cand[i].first][cand[i].second] = true;
        }
    }
    while(!q.empty()){
        int y = q.front().first; int x = q.front().second; q.pop();
        for(int k=0; k<4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(map[ny][nx] == 1) continue;
            if(dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
    int mintime = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 0 && dist[i][j] == -1) return 987654321;
            if(initialActivated[i][j] != true && map[i][j] == 2) continue;
            if(dist[i][j] > mintime) mintime = dist[i][j];
        }
    }
    return mintime;
}
int main(){
    cin >> N >> M;
    vector<pair<int, int>> cand;
    vector<int> d;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) {
                cand.push_back(make_pair(i, j));
                d.push_back(0);
            }
        }
    }
    for(int i=0; i<M; i++) d[i] = 1;
    sort(d.begin(), d.end());
    do{
        int mintime = BFS(cand, d);
        if(answer > mintime) answer = mintime;
    }while(next_permutation(d.begin(), d.end()));
    if(answer == 987654321) cout << -1 << "\n";
    else cout << answer << "\n";
    return 0;
}