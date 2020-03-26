#include <iostream>
using namespace std;
int T, N, M;
int map[20][20];
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N >> M;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
            }
        }
        int answercnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=1; k<=2*(N-1); k++){
                    // 중심 i, j, 범위 k
                    int cnt = 0;
                    for(int y=0; y<N; y++){
                        for(int x=0; x<N; x++){
                            if(map[y][x] == 1){
                                if((abs(y-i) + abs(x-j)) <= k-1) cnt++;
                            }
                        }
                    }
                    int cost = k*k + (k-1)*(k-1);
                    // 이익 = 매출 - 비용 
                    int profit = cnt*M - cost;
                    if(profit < 0) continue;
                    if(answercnt < cnt) {
                        answercnt = cnt;
                    }
                }
            }
        }
        cout << "#" << test_case << " " <<  answercnt << "\n";
    }

    return 0;
}