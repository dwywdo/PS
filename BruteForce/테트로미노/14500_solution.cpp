#include <iostream>
using namespace std;
int N; int M;
int map[500][500];
int main(){
    cin >> N;
    cin >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    int answer = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            // 일자형
            if(j+3 < M){
                int sum = 0;
                sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
                answer = sum > answer ? sum : answer;
            }
            if(i+3 < N){
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
                answer = sum > answer ? sum : answer;
            }
            // 권총형
            if(i+2 < N && j+1 < M){
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1];
                answer = sum > answer ? sum : answer;
                sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
                answer = sum > answer ? sum : answer;
                sum = map[i+2][j] + map[i+2][j+1] + map[i+1][j+1] + map[i][j+1];
                answer = sum > answer ? sum : answer;
                sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i][j+1];
                answer = sum > answer ? sum : answer;
            }
            if(i+1 < N && j+2 < M){
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i][j+1] + map[i][j+2];
                answer = sum > answer ? sum : answer;
                sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2];
                answer = sum > answer ? sum : answer;
                sum = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+2];
                answer = sum > answer ? sum : answer;
                sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
                answer = sum > answer ? sum : answer;
            }
            // 꼬인형
            if(i+2 < N && j+1 < M){
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
                answer = sum > answer ? sum : answer;
                sum = map[i][j+1] + map[i+1][j+1] + map[i+1][j] + map[i+2][j];
                answer = sum > answer ? sum : answer;
            }
            if(i+1 < N && j+2 < M){
                int sum = 0;
                sum = map[i+1][j] + map[i+1][j+1] + map[i][j+1] + map[i][j+2];
                answer = sum > answer ? sum : answer;
                sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2];
                answer = sum > answer ? sum : answer;
            }
            // 십자형
            if(i+1 < N && j+2 < M){
                int sum = 0;
                sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
                answer = sum > answer ? sum : answer;
                sum = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+1];
                answer = sum > answer ? sum : answer;
            }
            if(i+2 < N && j+1 < M){
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
                answer = sum > answer ? sum : answer;
                sum = map[i+1][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
                answer = sum > answer ? sum : answer;
            }
            // 사각형
            if(i+1 < N && j+1 < M){
                int sum = 0;
                sum = map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1];
                answer = sum > answer ? sum : answer;
            }
        }
    }
    cout << answer << endl;
    
    return 0;
}