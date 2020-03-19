#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char map[20][20];
int W = 0; int H = 0;
vector<vector<int>> BFS(int y, int x){
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    vector<vector<int>> dist(H, vector<int>(W, -1));
    dist[y][x] = 0;
    while(!q.empty()){
        int cury = q.front().first; int curx = q.front().second; q.pop();
        for(int k=0; k<4; k++){
            int ny = cury + dy[k]; int nx = curx + dx[k];
            if(ny>=0 && ny<H && nx>=0 && nx<W){
                if(dist[ny][nx] != -1) continue;
                if(map[ny][nx] == 'x') continue;
                dist[ny][nx] = dist[cury][curx] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    return dist;
}
int main(){
    while(1){
        cin >> W >> H;
        if(W==0 && H==0) break;
        int start_y = 0; int start_x = 0;
        memset(map, '.', sizeof(map));
        vector<pair<int, int>> dusts(1);
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin >> map[i][j];
                if(map[i][j] == 'o'){
                    start_y = i; start_x = j;
                    dusts[0].first = i; dusts[0].second = j;
                }
                if(map[i][j] == '*'){
                    dusts.push_back(make_pair(i, j));
                }
            }
        }
        int dust_size = dusts.size();
        bool possible = true;
        vector<vector<int>> d(dust_size, vector<int>(dust_size));
        for(int i=0; i<dust_size; i++){
            auto dist = BFS(dusts[i].first, dusts[i].second);
            for(int j=0; j<dust_size; j++){
                d[i][j] = dist[dusts[j].first][dusts[j].second];
                if(d[i][j] == -1) possible = false;
            }
        }
        if(!possible) {
            cout << -1 << '\n'; continue;
        }
        vector<int> p(dust_size-1);
        for(int i=0; i<dust_size-1; i++){
            p[i] = i+1;
        }
        sort(p.begin(), p.end());
        int ans = -1;
        do{
            int now = d[0][p[0]];
            for(int i=0; i<dust_size-2; i++){
                now += d[p[i]][p[i+1]];
            }
            if(ans == -1 || ans > now) ans = now;
        }while(next_permutation(p.begin(), p.end()));
        
        cout << ans << '\n';
        int temp = 0;
    }
    return 0;
}