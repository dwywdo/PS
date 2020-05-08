#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 50
int N, L, R;
int map[MAXN][MAXN];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
typedef struct groupInfo{
    int groupNumber = 0;
    int sum = 0;
    int groupCount = 0;
    int average = 0;
}GROUP_INFO;
GROUP_INFO BFS(int y, int x, int groupNumber, int groupInfo[][MAXN]){
    queue<pair<int, int>> q;
    groupInfo[y][x] = groupNumber;
    q.push(make_pair(y, x));
    GROUP_INFO g_info;
    g_info.groupCount = 1;
    g_info.groupNumber = groupNumber;
    g_info.sum = map[y][x];
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(groupInfo[ny][nx] != -1) continue;
            int diff = abs(map[cy][cx] - map[ny][nx]);
            if(diff >= L && diff <= R){
                groupInfo[ny][nx] = groupNumber;
                g_info.sum += map[ny][nx];
                g_info.groupCount++;
                q.push(make_pair(ny, nx));
            }
        }
    }
    g_info.average = g_info.sum / g_info.groupCount;
    return g_info;
}
bool grouping(){
    int groupInfo[MAXN][MAXN];
    memset(groupInfo, -1, sizeof(groupInfo));
    int groupNumber = 0;
    int groupCount = 0;
    vector<GROUP_INFO> groupSumInfos;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(groupInfo[i][j] != -1) continue;
            groupCount++;
            groupSumInfos.push_back(BFS(i, j, groupNumber, groupInfo));
            groupNumber++;
        }
    }
    if(groupCount == N*N) return false;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int gNum = groupInfo[i][j];
            map[i][j] = groupSumInfos[gNum].average;
        }
    }
    return true;
}
int main(){
    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    int answer = 0;
    while(grouping()){
        answer++;
    }
    cout << answer << "\n";
    return 0;
}