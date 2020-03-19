#include <iostream>
using namespace std;
int N;
char map[50][50];
// 상 하 좌 우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int check(char map[50][50], int n){
    int candies = 1;
    int len = 0;
    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=1; j<n; j++){
            if(map[i][j] == map[i][j-1]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            if(candies < cnt) candies = cnt;
        }
        cnt = 1;
        for(int j=1; j<n; j++){
            if(map[j][i] == map[j-1][i]){
                cnt ++;
            }
            else{
                cnt = 1;
            }
            if(candies < cnt) candies = cnt;
        }
    }
    return candies;
}
int main(){
    int answer = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char currentColor = map[i][j];
            for(int k=0; k<4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny >=0 && ny < N && nx >= 0 && nx < N){
                    char nextColor = map[ny][nx];
                    if(currentColor != nextColor){
                        map[i][j] = nextColor;
                        map[ny][nx] = currentColor;
                        int candies = check(map, N);
                        if(answer < candies){
                            answer = candies;
                        }
                        map[i][j] = currentColor;
                        map[ny][nx] = nextColor;
                    }
                    else{
                        int candies = check(map, N);
                        if(answer < candies){
                            answer = candies;
                        }
                    }
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}