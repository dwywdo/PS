#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int map[20][20];
int shark_size = 2;
int eat_count = 0;
int N;
int main(){
    cin >> N;
    int s_y = 0; int s_x = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                s_y = i; s_x = j;
            }
        }
    }
    int t = 0;
    while(1){
        // 먹을 수 있는 물고기가 있는지 확인 - BFS로 확인한다!
        int d[20][20]; 
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) d[i][j] = -1;
        d[s_y][s_x] = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(s_y, s_x));
        while(!q.empty()){
            int y = q.front().first; int x = q.front().second; q.pop();
            for(int i=0; i<4; i++){
                int ny = y + dy[i]; int nx = x + dx[i];
                if(ny>=0 && ny<N && nx>=0 && nx<N){
                    if(shark_size < map[ny][nx]) continue;
                    if(d[ny][nx] != -1) continue;
                    d[ny][nx] = d[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
        // BFS 결과를 가지고 방문 가능한 물고기들에 대해서 가장 가까운 걸 찾자
        int distance = 987654321;
        int target_y = -1; int target_x = -1;
        // 이렇게 짜면, 가장 위 / 왼쪽 걸 자동적으로 찾게된다 (등호가 아님에 유의 d[i][j] < distance )
        // 벡터에 넣고, 정렬함수까지 굳이 짜려고 하지 말자
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(d[i][j] != -1 && map[i][j]>=1 && map[i][j]<=6 && map[i][j] < shark_size){
                    if(d[i][j] < distance){
                        distance = d[i][j];
                        target_y = i; target_x = j;
                    }
                }
            }
        }
        // 물고기를 먹으면서 맵과 상어의 정보를 업데이트하자
        if(target_y == -1 && target_x == -1) break;
        map[target_y][target_x] = 0;
        map[s_y][s_x] = 0;
        t += d[target_y][target_x];
        eat_count++;
        if(eat_count == shark_size){
            eat_count = 0;
            shark_size++;
        }
        s_y = target_y; s_x = target_x;
        int temp = 0;
    }
    cout << t << endl;
    return 0;
}