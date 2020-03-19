#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <string>
using namespace std;
int N; int k;
int main(){
    cin >> N >> k;
    vector<string> lines(2);
    for(int i=0; i<2; i++){
        cin >> lines[i];
    }
    vector<vector<int>> d(2, vector<int>(N, -1));
    vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,k}};
    queue<pair<int, int>> q;
    d[0][0] = 0;
    q.push(make_pair(0, 0));
    bool clearable = false;
    while(!q.empty()){
        int y; int x;
        tie(y, x) = q.front(); q.pop();
        for(auto &dir : dirs){
            int dx; int dy;
            tie(dy, dx) = dir;
            int ny = (y + dy)%2;
            int nx = x + dx;
            if(nx>=N){
                clearable = true; break;
            }
            if(nx<0) continue;
            if(d[ny][nx] != -1) continue;
            if(lines[ny][nx] == '0') continue;
            if(nx < d[y][x] + 1) continue;
            d[ny][nx] = d[y][x] + 1;
            q.push(make_pair(ny, nx)); 
        }
        if(clearable) break;
    }
    if(clearable) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}