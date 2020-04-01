#include <iostream>
#include <cstring>
using namespace std;
int T = 0;
int N, M, K;
typedef struct info{
    int amount = 0;
    int direction = 0;
    int maxamount = 0;
}INFO;
INFO map[2][100][100];
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};
int getback(int d){
    if(d==1) return 2;
    if(d==2) return 1;
    if(d==3) return 4;
    if(d==4) return 3;
    return 0;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        memset(map, 0, sizeof(map));
        cin >> N >> M >> K;
        for(int i=0; i<K; i++){
            int y; int x; int a; int d;
            cin >> y >> x >> a >> d;
            map[0][y][x].amount = a;
            map[0][y][x].direction = d;
            map[0][y][x].maxamount = a;
        }
        int time = 0;
        int curmap = 0;
        while(time < M){
            
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(map[curmap][i][j].amount != 0){
                        int d = map[curmap][i][j].direction;
                        int ny = i + dy[d]; int nx = j + dx[d];
                        if(ny == 0 || ny == N-1 || nx == 0 || nx == N-1){
                            map[1 - curmap][ny][nx].amount = (int)(map[curmap][i][j].amount / 2);
                            map[1 - curmap][ny][nx].direction = getback(d);
                            map[1 - curmap][ny][nx].maxamount = map[1 - curmap][i][j].amount;
                            map[curmap][i][j].amount = 0; 
                            map[curmap][i][j].direction = 0;
                            map[curmap][i][j].maxamount = 0;
                        }
                        else{
                            // 미생물이 다음 타임에 없는 경우
                            if(map[1-curmap][ny][nx].amount == 0){
                                map[1-curmap][ny][nx].amount = map[curmap][i][j].amount;
                                map[1-curmap][ny][nx].direction = d;
                                map[1-curmap][ny][nx].maxamount = map[1-curmap][ny][nx].amount;
                                map[curmap][i][j].amount = 0; 
                                map[curmap][i][j].direction = 0;
                                map[curmap][i][j].maxamount = 0;
                            }
                            // 미생물이 다음 타임에 있는 경우
                            else{
                                map[1-curmap][ny][nx].amount += map[curmap][i][j].amount;
                                if(map[1-curmap][ny][nx].maxamount < map[curmap][i][j].amount){
                                    map[1-curmap][ny][nx].maxamount = map[curmap][i][j].amount;
                                    map[1-curmap][ny][nx].direction = map[curmap][i][j].direction;
                                }
                                map[curmap][i][j].amount = 0; 
                                map[curmap][i][j].direction = 0;
                                map[curmap][i][j].maxamount = 0;
                            }
                        }
                    }
                }
            }
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(map[curmap][i][j].amount != 0){
                        map[1-curmap][i][j].maxamount = map[1-curmap][i][j].amount;
                    }
                }
            }
            int temp = 0;
            curmap = 1 - curmap;
            time++;
        }
        int answer = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[curmap][i][j].amount != 0){
                    answer += map[curmap][i][j].amount;
                }
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}