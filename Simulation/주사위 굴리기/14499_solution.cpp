#include <iostream>
#include <vector>
using namespace std;
int map[20][20];
vector<int> insts;
typedef struct dice{
    int front = 0;
    int back = 0;
    int up = 0;
    int bottom = 0;
    int right = 0;
    int left = 0;
    int y = 0;
    int x = 0;
}DICE;
DICE d;
int n = 0; int m = 0; int start_x = 0; int start_y = 0; int k = 0;
void roll(int inst){
    // 1:동 2:서 3:북 4:남
    int ny = 0; int nx = 0;
    if(inst==1) {ny = d.y + 1; nx = d.x;}
    else if(inst==2) {ny = d.y - 1; nx = d.x;}
    else if(inst==3) {nx = d.x - 1; ny = d.y;}
    else if(inst==4) {nx = d.x + 1; ny = d.y;}
    if(nx<0 || nx>=n || ny<0 || ny>=m) return;
    d.y = ny; d.x = nx;
    if(inst == 1){
        int temp = d.bottom;
        d.bottom = d.right;
        d.right = d.up;
        d.up = d.left;
        d.left = temp;
    }
    else if(inst == 2){
        int temp = d.bottom;
        d.bottom = d.left;
        d.left = d.up;
        d.up = d.right;
        d.right = temp;
    }
    else if(inst == 3){
        int temp = d.bottom;
        d.bottom = d.back;
        d.back = d.up;
        d.up = d.front;
        d.front = temp;
    }
    else if(inst == 4){
        int temp = d.bottom;
        d.bottom = d.front;
        d.front = d.up;
        d.up = d.back;
        d.back = temp;
    }
    if(map[d.x][d.y]==0) map[d.x][d.y] = d.bottom;
    else {
        d.bottom = map[d.x][d.y]; map[d.x][d.y] = 0;
    }
    cout << d.up << '\n';
}
int main(){
    cin >> n >> m >> start_x >> start_y >> k;
    d.x = start_x;
    d.y = start_y;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int inst = 0; cin >> inst;
        insts.push_back(inst);
    }
    for(int i=0; i<k; i++) roll(insts[i]);
    return 0;
}