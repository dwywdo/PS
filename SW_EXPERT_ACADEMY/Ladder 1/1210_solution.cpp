#include <iostream>
#include <cstring>
using namespace std;
int T = 10;
int map[100][100];
bool visited[100][100];
// 위쪽 // 오른쪽 // 왼쪽
int dy[3] = {-1, 0, 0};
int dx[3] = {0, 1, -1};
int main(){
    for(int test_case=1; test_case<=T; test_case++){
        int tc = 0; cin >> tc;
        int y = 0; int x = 0;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin >> map[i][j];
                if(map[i][j] == 2){
                    y = i; x = j;
                }
            }
        }
        int d = 0;
        visited[y][x] = true;
        while(y!=0){
            int ry = y; int rx = x+1;
            int ly = y; int lx = x-1;
            if(ry>=0 && ry<100 && rx>=0 && rx<100 && map[ry][rx] == 1 && !visited[ry][rx]){
                d = 1;
            }
            else if(ly>=0 && ly<100 && lx>=0 && lx<100 && map[ly][lx] == 1 && !visited[ly][lx]){
                d = 2;
            }
            else{
                d = 0;
            }
            y += dy[d]; x += dx[d]; visited[y][x] = true;
        }
        cout << "#" << tc << " " << x << "\n";
    }
    return 0;
}