#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int T, N, M, C;
int map[10][10];
int check[10][10];
bool pickcheck[5];
int maxprofit = 0;
void go(int idx, int sum, vector<int>& numbers, vector<int> &chosen){
    if(sum > C){
        int profit = 0;
        for(int i=0; i<chosen.size()-1; i++) profit += chosen[i]*chosen[i];
        if(maxprofit < profit) maxprofit = profit;
        return;
    }
    if(idx >= M){
        int profit = 0;
        for(int i=0; i<chosen.size(); i++) profit += chosen[i]*chosen[i];
        if(maxprofit < profit) maxprofit = profit;
        return;
    }
    for(int i=idx; i<M; i++){
        sum += numbers[i];
        chosen.push_back(numbers[i]);
        go(i+1, sum, numbers, chosen);
        sum -= numbers[i];
        chosen.pop_back();
    }
}
int cal_profit(int y, int x, int c){
    vector<int> numbers;
    vector<int> chosen;
    maxprofit = 0;
    memset(pickcheck, false, sizeof(pickcheck));
    for(int j=x; j<x+c; j++){
        numbers.push_back(map[y][j]);
    }
    go(0, 0, numbers, chosen);
    return maxprofit;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N >> M >> C;
        memset(map, 0, sizeof(map));
        memset(check, 0, sizeof(check));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
            }
        }
        vector<int> worker1;
        vector<int> worker2;
        int profit = 0;
        int answer = 0;
        for(int y1=0; y1<N; y1++){
            for(int x1=0; x1<N; x1++){
                if(N-x1 < M) continue;
                int sum1 = 0; int max1 = 0;
                for(int j=x1; j<x1+M; j++){
                    check[y1][j] = 1;
                }
                for(int y2=0; y2<N; y2++){
                    for(int x2=0; x2<N; x2++){
                        if(N-x2 < M) continue;
                        bool ok = true;
                        for(int j=x2; j<x2+M; j++) {
                            if(check[y2][j] == 1){
                                ok = false; break;
                            }
                        }
                        if(ok){
                            for(int j=x2; j<x2+M; j++) {
                                check[y2][j] = 2;
                            }
                            int totalprofit = 0;
                            totalprofit += cal_profit(y2, x2, M);
                            totalprofit += cal_profit(y1, x1, M);
                            if(totalprofit > answer) answer = totalprofit;
                        }
                        else continue;

                        for(int j=x2; j<x2+M; j++) {
                            check[y2][j] = 0;
                        }
                    }
                }

                for(int j=x1; j<x1+M; j++) check[y1][j] = 0;
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}