#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N; int map[25][25];bool visited[25][25];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int cnt = 0;
void DFS(int y, int x){
    visited[y][x] = true; cnt++;
    for(int i=0; i<4; i++){
        int ny = y+dy[i]; int nx = x+dx[i];
        if(ny>=0 && ny<N && nx>=0 && nx<N && !visited[ny][nx] && map[ny][nx] == 1){
            DFS(ny, nx);
        }
    }
    return ;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    vector<int> counts;
    int danjiCount = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]) continue;
            if(map[i][j] == 0) continue;
            cnt = 0;
            danjiCount++;
            DFS(i, j);
            counts.push_back(cnt);
        }
    }
    sort(counts.begin(), counts.end());
    cout << danjiCount << endl;
    for(int i=0; i<counts.size(); i++){
        cout << counts[i] << endl;
    }
    return 0;
}