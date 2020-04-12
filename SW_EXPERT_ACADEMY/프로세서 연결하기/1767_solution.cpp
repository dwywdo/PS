#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 12
int T, N;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answercount = 0;
int answerlength = 0;
vector<pair<int, int>> cores;
void go(int idx, int connectedCount, int length, int corecount){
    // 더이상 탐색해도 여태까지 나온 최솟값보다 더 연결할 수 없으면
    if(answercount > connectedCount + corecount - idx) return;
    if(idx==corecount){ // 다 처리했으면
        if(connectedCount > answercount){
            answercount = connectedCount;
            answerlength = length;
        }
        else if (answercount == connectedCount){
            if(answerlength > length) answerlength = length;
        }
        return;
    }
    int y = cores[idx].first; 
    int x = cores[idx].second;
    bool tempvisited[MAXN][MAXN];

    for(int i=0; i<N; i++) for(int j=0; j<N; j++) tempvisited[i][j] = visited[i][j];
    
    if(y==0 || y==N-1 || x==0 || x==N-1){ // 이미 연결되어 있으면
        go(idx + 1, connectedCount + 1, length, corecount);
    }
    else{ // 선의 연결이 필요한 경우?
        for(int i=0; i<4; i++){
            bool connected = true;
            int ny = y; int nx = x;
            while(1){
                ny = ny += dy[i]; nx = nx += dx[i];
                // if(ny<0 || ny>=N || nx<0 || nx>N) break;
                if(visited[ny][nx] == true || map[ny][nx] ==1){
                    connected = false; break;
                }
                else{
                    visited[ny][nx] = true;
                    if(ny==0 || ny==N-1 || nx==0 || nx==N-1){
                        break;
                    }
                }
            }
            if(connected){
                int pluslength = abs(ny - y) + abs(nx - x);
                go(idx + 1, connectedCount + 1, length + pluslength, corecount);
            }
            else{
                go(idx + 1, connectedCount, length, corecount);
            }
            for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
                visited[i][j] = tempvisited[i][j];
            }
        }
    }
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N;
        cores.clear();
        answercount = 0;
        answerlength = 0;
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
                if(map[i][j] == 1) cores.push_back(make_pair(i, j));
            }
        }
        int corecount = cores.size();
        go(0, 0, 0, corecount);
        cout << "#" << test_case << " " << answerlength << "\n";
    }
    return 0;
}