#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 50
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
int N = 0; int M = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    cin >> N >> M;
    vector<pair<int, int>> cand;
    int answer = 987654321;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                cand.push_back(make_pair(i, j));
            }
        }
    }
    vector<int> d(cand.size(), 0);
    for(int i=0; i<M; i++){
        d[i] = 1;
    }
    sort(d.begin(), d.end());
    do{
        queue<pair<int, int>> q;
        memset(visited, -1, sizeof(visited));
        for(int i=0; i<d.size(); i++){
            if(d[i] == 1){
                visited[cand[i].first][cand[i].second] = 0;
                q.push(make_pair(cand[i].first, cand[i].second));
            }
        }

        // BFS
        while(!q.empty()){
            int y = q.front().first; int x = q.front().second; q.pop();
            for(int k=0; k<4; k++){
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if(map[ny][nx] == 1) continue;
                if(visited[ny][nx] != -1) continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
        int time = 0; bool possible = true;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j] > time) time = visited[i][j];
                if(visited[i][j] == -1 && map[i][j] == 0){
                    possible = false; break;
                }
            }
            if(!possible) break;
        }
        if(possible){
            if(time < answer) {
                answer = time;
            }
        }
    }while(next_permutation(d.begin(), d.end()));
    if(answer == 987654321){
        cout << -1 << "\n";
    }
    else cout << answer << "\n";
    return 0;
}