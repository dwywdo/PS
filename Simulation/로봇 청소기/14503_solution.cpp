#include <iostream>
using namespace std;
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
int map[50][50];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int n = 0; int m = 0;
typedef struct robot{
    int r = 0;
    int c = 0;
    int d = 0;
}ROBOT;
ROBOT robot;
int getleft(int d){
    if(d==0) return 3;
    if(d==1) return 0;
    if(d==2) return 1;
    if(d==3) return 2;
    return -1;
}
int getback(int d){
    if(d==0) return 2;
    if(d==1) return 3;
    if(d==2) return 0;
    if(d==3) return 1;
    return -1;
}
int main(){
    cin >> n >> m;
    cin >> robot.r >> robot.c >> robot.d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    int answer = 0;
    while(1){
        if(map[robot.r][robot.c] == 0){
            map[robot.r][robot.c] = 2;
            answer++;
        }
        if(map[robot.r+1][robot.c] != 0 && map[robot.r-1][robot.c] != 0 && map[robot.r][robot.c-1] != 0 && map[robot.r][robot.c+1] != 0){
            int backd = getback(robot.d);
            int br = robot.r + dr[backd];
            int bc = robot.c + dc[backd];
            if(map[br][bc] == 1) break;
            else{
                robot.r = br;
                robot.c = bc;
            }
        }
        else{
            int leftd = getleft(robot.d);
            int nr = robot.r + dr[leftd];
            int nc = robot.c + dc[leftd];
            if(map[nr][nc] == 0){
                robot.r = nr;
                robot.c = nc;
                robot.d = leftd;
            }
            else robot.d = leftd;
        }
    }
    cout << answer << '\n';
    return 0;
}