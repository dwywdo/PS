#include <iostream>
using namespace std;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int map[50][50]; bool visited[50][50];
void DFS(int y, int x, int w, int h){
    visited[y][x] = true;
    for(int i=0; i<8; i++){
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny>=0 && ny<h && nx>=0 && nx<w && !visited[ny][nx] && map[ny][nx] == 1){
            DFS(ny, nx, w, h);
        }
    }
    return;
}
int main(){
    int w = 0; int h = 0;
    do{
        cin >> w >> h;
        int sumCount = 0;
        if(w==0 && h==0) break;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++) {
                visited[i][j] = false;
                cin >> map[i][j];    
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++) {
                if(visited[i][j]) continue;
                if(map[i][j] == 0) continue;
                sumCount++;
                DFS(i, j, w, h);
            }
        }
        cout << sumCount << endl;

    }while(1);
    return 0;
}