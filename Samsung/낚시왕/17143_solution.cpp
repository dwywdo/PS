#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int R, C, M;
// direction 
// 0 1 2 3 
// 위 아래 오른쪽 왼쪽
vector<tuple<int, int, int>> shark[100][100];
tuple<int, int, int> get_next(int y, int x, int speed, int direction){
    for(int k=0; k<speed; k++){
        if(direction == 0){
            if(y==0){
                y = 1; direction = 1;
            }
            else y-=1;
        }
        else if(direction == 1){
            if(y==R-1){
                y = R-2; direction = 0;
            }
            else y+=1;
        }
        else if(direction == 2){
            if(x==C-1){
                x = C-2; direction = 3;
            }
            else x += 1;
        }
        else if(direction == 3){
            if(x==0){
                x = 1; direction =2;
            }
            else x-=1;
        }
    }
    return make_tuple(y, x, direction);
}
int main(){
    cin >> R >> C >> M;
    for(int i=0; i<M; i++){
        int y, x, speed, direction, size;
        cin >> y >> x >> speed >> direction >> size;
        shark[y-1][x-1].push_back(make_tuple(size, speed, direction-1));
    }
    long long answer = 0;
    for(int c=0; c<C; c++){
        // 상어를 잡는다
        for(int r=0; r<R; r++){
            if(shark[r][c].size() == 1){
                answer += get<0>(shark[r][c][0]);
                shark[r][c].clear();
                break;
            }
        }
        vector<tuple<int, int, int>> newshark[100][100];
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(shark[i][j].size() == 0) continue;
                else if(shark[i][j].size() == 1){
                    int size = get<0>(shark[i][j][0]);
                    int speed = get<1>(shark[i][j][0]);
                    int direction = get<2>(shark[i][j][0]);
                    if(direction == 0 || direction == 1) speed = speed%(2*R-2);
                    if(direction == 2 || direction == 3) speed = speed%(2*C-2);
                    auto next = get_next(i, j, speed, direction);
                    int ny = get<0>(next); 
                    int nx = get<1>(next);
                    int nd = get<2>(next);
                    newshark[ny][nx].push_back(make_tuple(size, speed, nd));
                }
            }
        }
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                shark[i][j].clear();
                if(newshark[i][j].size() > 0){
                    sort(newshark[i][j].begin(), newshark[i][j].end());
                    shark[i][j].push_back(newshark[i][j].back());
                    newshark[i][j].clear();
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}