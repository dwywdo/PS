#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int>> board(20, vector<int>(20));
int N;
int MAX_COUNT = 5;
vector<int> dirs;
int cnt = 0;
int answer = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int cal(vector<int> &order){
    vector<vector<int>> temp(20, vector<int>(20));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j] = board[i][j];
        }
    }
    int max = 0;
    for(int o=0; o<order.size(); o++){
        int dir = order[o];
        bool check[20][20]; memset(check, false, sizeof(check));
        if(dir==0){ // 위쪽으로 옮기기
            for(int i=1; i<N; i++){
                for(int j=0; j<N; j++){
                    int y=i; int x=j;
                    if(temp[y][x] != 0){
                        while(y-1>=0 && temp[y-1][x] == 0) y--;
                        if(y==i && x==j && temp[y-1][x] != temp[i][j]) continue;
                        if(y-1 >= 0 && temp[y-1][x] == temp[i][j] && !check[y-1][x]){
                            check[y-1][x] = true;
                            temp[y-1][x] = temp[y-1][x]*2; temp[i][j] = 0;
                            continue;
                        }
                        if(temp[y][x] == 0){
                            temp[y][x] = temp[i][j]; temp[i][j] = 0; continue;
                        }
                        
                    }
                }
            }
        }
        else if(dir==1){ // 아랫쪽으로 옮기기
            for(int i=N-2; i>=0; i--){
                for(int j=0; j<N; j++){
                    int y=i; int x=j;
                    if(temp[y][x] != 0){
                        while(y+1<N && temp[y+1][x] == 0) y++;
                        if(y==i && x==j && temp[y+1][x] != temp[i][j]) continue;
                        if(y+1 < N && temp[y+1][x] == temp[i][j] && !check[y+1][x]){
                            check[y+1][x] = true;
                            temp[y+1][x] = temp[y+1][x]*2; temp[i][j] = 0;
                            continue;
                        }
                        if(temp[y][x] == 0){
                            temp[y][x] = temp[i][j]; temp[i][j] = 0; continue;
                        }
                        
                    }
                }
            }
        }
        else if(dir==2){ // 왼쪽으로 옮기기
            for(int j=1; j<N; j++){
                for(int i=0; i<N; i++){
                    int y = i; int x = j;
                    if(temp[y][x] != 0){
                        while(x-1>=0 && temp[y][x-1] == 0) x--;
                        if(y==i && x==j && temp[y][x-1] != temp[i][j]) continue;
                        if(x-1 >= 0 && temp[y][x-1] == temp[i][j] && !check[y][x-1]){
                            check[y][x-1] = true;
                            temp[y][x-1] = temp[y][x-1] * 2; temp[i][j] = 0;
                            continue;
                        }
                        if(temp[y][x] == 0){
                            temp[y][x] = temp[i][j]; temp[i][j] = 0; continue;
                        }
                    }
                }
            }
        }
        else if(dir==3){ // 오른쪽으로 옮기기
            for(int j=N-2; j>=0; j--){
                for(int i=0; i<N; i++){
                    int y = i; int x = j;
                    if(temp[y][x] != 0){
                        while(x+1<N && temp[y][x+1] == 0) x++;
                        if(y==i && x==j && temp[y][x+1] != temp[i][j]) continue;
                        if(x+1 < N && temp[y][x+1] == temp[i][j] && !check[y][x+1]){
                            check[y][x+1] = true;
                            temp[y][x+1] = temp[y][x+1] * 2; temp[i][j] = 0;
                            continue;
                        }
                        if(temp[y][x] == 0){
                            temp[y][x] = temp[i][j]; temp[i][j] = 0; continue;
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(max < temp[i][j]) max = temp[i][j];
        }
    }
    return max;
}
void choose(vector<int> &order){
    if(order.size() == MAX_COUNT){
        int maxblock = cal(order);
        if(answer < maxblock) answer = maxblock;
        return;
    }
    for(int i=0; i<4; i++){
        order.push_back(i);
        choose(order);
        order.pop_back();
    }
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
    choose(dirs);
    // vector<int> test; test.push_back(0);test.push_back(3);test.push_back(0);test.push_back(2);test.push_back(0);
    // cal(test);
    cout << answer << '\n'; 
    return 0;
}
