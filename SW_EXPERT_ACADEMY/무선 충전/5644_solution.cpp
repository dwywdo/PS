#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int T; int M; int A;
typedef struct bc{
    int y = 0;
    int x = 0;
    int c = 0;
    int p = 0;
    bool used = false;
}BC;

BC BCs[8];
typedef struct user{
    int y = 0;
    int x = 0;
}USER;
USER user[2];

int moves[2][100];

int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};
bool check(int userindex, int bcindex){
    int dist = abs(user[userindex].x - BCs[bcindex].x) + abs(user[userindex].y - BCs[bcindex].y);
    return dist <= BCs[bcindex].c;
}
int ret = 0;
void DFS(int uindex, int sum){
    if(uindex == 2){
        ret = ret > sum ? ret : sum;
        return;
    }
    for(int i=0; i<A; i++){
        if(!BCs[i].used && check(uindex, i)){
            BCs[i].used = true;
            DFS(uindex + 1, sum + BCs[i].p);
            BCs[i].used = false;
        }
    }
    DFS(uindex + 1, sum);
}
int download(){
    ret = 0;
    DFS(0, 0);
    return ret;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        
        cin >> M >> A;
        for(int i=0; i<2; i++) for(int j=0; j<M ;j++) cin >> moves[i][j];
        for(int i=0; i<A; i++){
            cin >> BCs[i].x >> BCs[i].y >> BCs[i].c >> BCs[i].p; BCs[i].used = false;
        }
        user[0].y = 1; user[0].x = 1;
        user[1].y = 10; user[1].x = 10;

        int answer = 0;
        answer += download();
        for(int t=0; t<M; t++){
            // 현재 위치에서 모든 접속 가능한 방법을 DFS로 구현한다.
            for(int j=0; j<2; j++){
                user[j].x += dx[moves[j][t]];
                user[j].y += dy[moves[j][t]];
            }
            answer += download();
        }
        cout << "#" << test_case << " " << answer << '\n';
    }
    return 0;
}