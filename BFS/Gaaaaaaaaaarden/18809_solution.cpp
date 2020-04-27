#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define GREEN 3
#define RED 4
int map[50][50];
int tmpmap[50][50];
int N, M, G, R;
int answer = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void BFS(queue<pair<int, int>> &q){
    int flowercount = 0;
    int time = 1;
    int timemap[50][50]; memset(timemap, 0, sizeof(timemap));
    while(!q.empty()){
        int len = q.size();
        for(int l=0; l<len; l++){
            int y = q.front().first; int x = q.front().second; q.pop();
            if(timemap[y][x] == -1) continue;
            for(int k=0; k<4; k++){
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
                if(map[ny][nx] == 0) continue;
                if(map[ny][nx] == 1 || map[ny][nx] == 2){
                    timemap[ny][nx] = time;
                    map[ny][nx] = map[y][x];
                    q.push(make_pair(ny, nx));
                }
                else{
                    if(time == timemap[ny][nx] && map[y][x] != map[ny][nx]){
                        flowercount++;
                        map[ny][nx] = 0;
                        timemap[ny][nx] = -1;
                    }
                }
            }
        }
        time++;
    }
    if(answer < flowercount) answer = flowercount;
}
int main(){
    cin >> N >> M >> G >> R;
    vector<pair<int, int>> pos;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            tmpmap[i][j] = map[i][j];
            if(map[i][j] == 2){
                pos.push_back(make_pair(i, j));
            }
        }
    }
    int poscount = pos.size();
    vector<int> d(poscount, 0);
    for(int i=0; i<R+G; i++){
        if(i<R) d[i] = GREEN;
        else d[i] = RED;
    }
    sort(d.begin(), d.end());
    
    do{
        queue<pair<int, int>> q;
        for(int i=0; i<d.size(); i++){
            if(d[i] != 0){
                q.push(make_pair(pos[i].first, pos[i].second));
                map[pos[i].first][pos[i].second] = d[i];
            }
        }
        
        BFS(q);

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                map[i][j] = tmpmap[i][j];
            }
        }

    }while(next_permutation(d.begin(), d.end()));
    
    cout << answer << "\n";
    return 0;
}