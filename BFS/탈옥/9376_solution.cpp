#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int T = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<vector<int>> bfs(int y, int x, vector<string> &map){
    int h = map.size();
    int w = map[0].size();
    vector<vector<int>> d(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            d[i][j] = -1;
        }
    }
    deque<pair<int, int>> q;
    q.push_back(make_pair(y, x));
    d[y][x] = 0;
    while(!q.empty()){
        int y = q.front().first; int x = q.front().second;
        q.pop_front();
        for(int k=0; k<4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(nx<0 || nx >= w || ny<0 || ny>=h) continue;
            if(d[ny][nx] != -1) continue;
            if(map[ny][nx] == '*') continue;
            if(map[ny][nx] == '#'){
                d[ny][nx] = d[y][x] + 1;
                q.push_back(make_pair(ny, nx));
            }
            else{
                d[ny][nx] = d[y][x];
                q.push_front(make_pair(ny, nx));
            }
        }
    }
    return d;
}
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        int h = 0; int w = 0;
        cin >> h >> w;
        vector<pair<int, int>> crims;
        vector<string> map(h+2);
        for(int i=1; i<=h; i++){
            cin >> map[i];
            map[i] = "." + map[i] + ".";
        }
        h+=2; w+=2;
        for(int j=0; j<w; j++){
            map[0] += ".";
            map[h-1] += ".";
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] == '$') crims.push_back(make_pair(i,j));
            }
        }
        vector<vector<int>> d0 = bfs(0, 0, map);
        vector<vector<int>> d1 = bfs(crims[0].first, crims[0].second, map);
        vector<vector<int>> d2 = bfs(crims[1].first, crims[1].second, map);
        int answer = w*h;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] == '*') continue;
                int cur = d0[i][j] + d1[i][j] + d2[i][j];
                if(map[i][j] == '#') cur -=2;
                if(answer > cur) answer = cur;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}