#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int T = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char map[102][102]; bool visited[102][102]; bool keys[26];
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        int h = 0; int w = 0;
        cin >> h >> w;
        memset(map, '.', sizeof(map));
        memset(visited, false, sizeof(visited));
        memset(keys, false, sizeof(keys));
        queue<pair<int, int>> doors[26];
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin >> map[i][j];
            }
        }
        string keystring = ""; cin >> keystring;
        if(keystring != "0"){
            for(int k=0; k<keystring.size(); k++) keys[keystring[k]-'a'] = true;
        }
        // BFS 진행
        queue<pair<int, int>> q;
        visited[0][0] = true;
        q.push(make_pair(0, 0));
        int docCount = 0;
        while(!q.empty()){
            int y = q.front().first; int x = q.front().second; q.pop();
            for(int k=0; k<4; k++){
                int ny = y + dy[k]; int nx = x + dx[k];
                if(ny>=0 && ny<=h+1 && nx>=0 && nx<=w+1){
                    if(map[ny][nx] == '*') continue;
                    if(visited[ny][nx]) continue;
                    visited[ny][nx] = true;
                    if('A' <= map[ny][nx] && map[ny][nx] <= 'Z'){
                        // 문을 만난 경우, 열쇠가 있으면 연다.
                        // 열쇠가 없으면 그 문을 일단 저장해둔다.
                        if(keys[map[ny][nx]-'A']) q.push(make_pair(ny, nx));
                        else doors[map[ny][nx]-'A'].push(make_pair(ny, nx));
                    }
                    else if('a' <= map[ny][nx] && map[ny][nx] <= 'z'){
                        // 열쇠를 찾은 경우
                        // 해당 열쇠로 있는 모든 문의 좌표를 큐에 넣어준다 (방문처리)
                        keys[map[ny][nx]-'a'] = true;
                        q.push(make_pair(ny, nx));
                        char key = map[ny][nx];
                        while(!doors[key-'a'].empty()){
                            int door_y = doors[key-'a'].front().first;
                            int door_x = doors[key-'a'].front().second;
                            doors[key-'a'].pop();
                            visited[door_y][door_x] = true;
                            q.push(make_pair(door_y, door_x));
                        }
                    }
                    else if(map[ny][nx] == '.'){
                        q.push(make_pair(ny, nx));
                    }
                    else if(map[ny][nx] == '$'){
                        docCount++;
                        q.push(make_pair(ny, nx));
                    }
                }
                
            }
        }
        cout << docCount << '\n';
    }
    return 0;
}