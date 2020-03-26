#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 8
int T = 0;
int N, K = 0;
int map[MAXN][MAXN];
int temp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int answer = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void go(int y, int x, int dist, bool check){
    if(dist > answer) answer = dist;
    int height = temp[y][x];
    for(int k=0; k<4; k++){
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(!(ny>=0 && ny<N && nx>=0 && nx<N)) continue;
        if(visited[ny][nx]) continue;
        int nextheight = temp[ny][nx];
        if(nextheight < height){
            // 만약 다음 높이가 낮으면
            visited[ny][nx] = true;
            go(ny, nx, dist+1, check);
            visited[ny][nx] = false;
        }
        else{
            // 만약 다음 높이가 낮지 않으면
            if(!check && nextheight - K < height){
                visited[ny][nx] = true;
                temp[ny][nx] = height - 1;
                go(ny, nx, dist+1, true);
                visited[ny][nx] = false;
                temp[ny][nx] = nextheight;
            }
        }
    }
    return ;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N >> K;
        int maxheight = 0; answer = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
                temp[i][j] = map[i][j];
                if(map[i][j] > maxheight) maxheight = map[i][j];
            }
        }
        vector<pair<int, int>> starts;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] == maxheight) starts.push_back(make_pair(i, j));
            }
        }
        
        for(auto &p : starts){
            memset(visited, false, sizeof(visited));
            visited[p.first][p.second] = true;
            go(p.first, p.second, 1, false);
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}