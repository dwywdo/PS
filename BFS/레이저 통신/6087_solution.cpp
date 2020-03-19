#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int W, H;
char map[100][100];
int dist[100][100];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<pair<int, int>> lasers;
int main(){
    cin >> W >> H;
    for(int i=0; i<H; i++){
        string row = ""; cin>> row;
        for(int j=0; j<W; j++){
            map[i][j] = row[j];
            dist[i][j] = -1;
            if(map[i][j] == 'C') lasers.push_back(make_pair(i, j));
        }
    }

    queue<pair<int, int>> q;
    int l1_y = lasers[0].first; int l1_x = lasers[0].second;
    dist[l1_y][l1_x] = 0;
    q.push(make_pair(l1_y, l1_x));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y; int nx = x;
            while(1){
                ny = ny + dy[i]; nx = nx + dx[i];
                if(ny<0 || ny>=H || nx<0 || nx>=W) break;
                if(map[ny][nx] == '*') break;
                if(dist[ny][nx] == -1){
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
                // 아래 코드와의 실행 차이를 알아야 한다.
                /*
                if(dist[ny][nx] != -1) break;
                dist[ny][nx] = dist[y][x] + 1;
                q.push(make_pair(ny, nx));
                */
            }
        }
    }
    int l2_y = lasers[1].first; int l2_x = lasers[1].second;
    cout << dist[l2_y][l2_x] - 1 << endl;
    return 0;
}