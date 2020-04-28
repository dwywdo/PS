#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 1000
char map[MAXN][MAXN];
int visited[MAXN][MAXN];
int T = 0; int W, H;
typedef struct node{
    int y = 0;
    int x = 0;
    bool isperson = false;
}NODE;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        memset(map, '0', sizeof(map));
        memset(visited, -1, sizeof(visited));
        int answer = 987654321;
        bool possible = false;
        cin >> W >> H;
        queue<NODE> q;
        int person_y; int person_x;
        for(int i=0; i<H; i++){
            string row = ""; cin >> row;
            for(int j=0; j<W; j++){
                map[i][j] = row[j];
                if(map[i][j] == '*'){
                    NODE a; a.y = i; a.x = j; a.isperson = false; q.push(a);
                    visited[i][j] = 0;
                }
                if(map[i][j] == '@'){
                    person_y = i; person_x = j;
                }
            }
        }

        NODE person; person.y = person_y; person.x = person_x; person.isperson = true;
        visited[person_y][person_x] = 0;
        q.push(person);

        while(!q.empty()){
            int y = q.front().y;
            int x = q.front().x;
            bool isperson = q.front().isperson;
            q.pop();
            for(int k=0; k<4; k++){
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(!isperson){
                    if(visited[ny][nx] != -1) continue;
                    if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
                    if(map[ny][nx] == '#') continue;
                    visited[ny][nx] = visited[y][x] + 1;
                    NODE na; na.y = ny; na.x = nx; na.isperson = false;
                    q.push(na);
                }
                else{
                    if(ny < 0 || ny >= H || nx < 0 || nx >= W){
                        int totaltime = visited[y][x] + 1;
                        if(answer > totaltime) answer = totaltime;
                    }
                    else{
                        if(visited[ny][nx] != -1) continue; // 방문되었으면 못감
                        if(map[ny][nx] == '#') continue; // 벽이면 못감
                        if(map[ny][nx] == '*') continue; // 불이면 못감
                        visited[ny][nx] = visited[y][x] + 1;
                        NODE na; na.y = ny; na.x = nx; na.isperson = true;
                        q.push(na);
                    }
                    
                    
                }
            }
        }
        if(answer == 987654321){
            cout << "IMPOSSIBLE" << "\n";
        }
        else{
            cout << answer << "\n";
        }
    }

    return 0;
}
