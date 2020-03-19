#include <iostream>
#include <vector>
using namespace std;
int map[4][4];
int symbols[16];
int N, M;
// 0: 가로 1: 세로
int answer = 0;
int cal(){
    int sum = 0;
    for(int i=0; i<N; i++){
        int rowsum = 0;
        for(int j=0; j<M; j++){
            int k = i*M + j;
            if(symbols[k] == 0){
                rowsum = 10*rowsum + map[i][j];
            }
            else{
                sum += rowsum; rowsum = 0;
            }
        }
        sum += rowsum;
    }
    for(int j=0; j<M; j++){
        int colsum = 0;
        for(int i=0; i<N; i++){
            int k = i*M + j;
            if(symbols[k] == 1){
                colsum = 10*colsum + map[i][j];
            }
            else{
                sum += colsum; colsum = 0;
            }
        }
        sum += colsum;
    }
    return sum;
}
void choose(int idx){
    if(idx >= M*N){
        int sum = cal();
        if(answer < sum) answer = sum;
        return;
    }
    symbols[idx] = 0;
    choose(idx+1);
    symbols[idx] = 1;
    choose(idx+1);
    return;
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    choose(0);
    cout << answer << endl;
    
    return 0;
}