#include <iostream>
#include <queue>
using namespace std;
// 12시 방향에서 시계방향으로
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int T = 0;
int main(){
    int w = 0; int h = 0;
    do{
        cin >> w >> h;
        if(w==0 && h==0) break;
        int map[50][50];
        bool visited[50][50];
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> map[i][j];
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                visited[i][j] = false;
            }
        }
        int sumCount = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(visited[i][j]) continue;
                if(map[i][j] == 0) continue;
                sumCount++;
                queue<pair<int, int> > q;
                visited[i][j] = true; q.push(make_pair(i, j));
                while(!q.empty()){
                    pair<int, int> point = q.front(); q.pop();
                    for(int i=0; i<8; i++){
                        int ny = point.first + dy[i];
                        int nx = point.second + dx[i];
                        if(nx>=0 && nx<w && ny>=0 && ny<h && !visited[ny][nx] && map[ny][nx] == 1){
                            visited[ny][nx] = true;
                            q.push(make_pair(ny, nx));
                        }
                    }
                }

            }
        }
        cout << sumCount << endl;
    }while(1);

    return 0;
}