#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M;
int map[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1 ,1};
int answer = 50*50;
vector<pair<int, int>> virus;
int BFS(vector<pair<int, int>> actives){
    int dist[50][50]; memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    for(int i=0; i<actives.size(); i++){
        int y = actives[i].first; int x = actives[i].second;
        dist[y][x] = 0; q.push(make_pair(y, x));
    }
    while(!q.empty()){
        int y = q.front().first; int x = q.front().second; q.pop();
        for(int k=0; k<4; k++){
            int ny = y + dy[k]; int nx = x + dx[k];
            if(ny>=0 && ny<N && nx>=0 && nx<N){
                if(dist[ny][nx] != -1) continue;
                if(map[ny][nx] == 1) continue;
                if(map[ny][nx] == 0 || map[ny][nx] == 2){
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    bool possible = true;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dist[i][j] == -1 && map[i][j] == 0) {
                possible = false; break;
            }
        }
    }
    if(possible == false){
        return -1;
    }

    int mintime = 0; 
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dist[i][j] == -1) continue;
            if(dist[i][j] > mintime && map[i][j] == 0) mintime = dist[i][j];
        }
    }
    return mintime;
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }
    vector<int> d;
    for(int i=0; i<M; i++) d.push_back(1);
    for(int i=0; i<virus.size() - M; i++) d.push_back(0);
    sort(d.begin(), d.end());
    do{
        vector<pair<int, int>> active;
        for(int i=0; i<d.size(); i++){
            if(d[i] == 1) active.push_back(make_pair(virus[i].first, virus[i].second));
        }
        int t = BFS(active);
        if(t == -1) continue;
        if(t < answer) answer = t;
        int temp = 0;
    }while(next_permutation(d.begin(), d.end()));
    if(answer == 2500){
        cout << -1 << '\n';
        return 0;
    }
    cout << answer << '\n';
    return 0;
}