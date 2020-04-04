#include <iostream>
#include <cstring>
using namespace std;
int T = 0;
int N = 0;
int plan[13];
int flag[13];
int price[4]; // 0: 1일 이용권 1: 1달 이용권 2: 3달 이용권 3: 1년 이용권
int day_count = 0;
int month_count = 0;
int threemonth_count = 0;
int answer = 0;
void go(int idx){
    if(idx > 12){
        int temp = 0;
        int cost = 0;
        for(int i=1; i<=12; i++){
            if(plan[i] != 0 && flag[i] == 0){
                cost += plan[i] * price[0];
            }
        }
        cost += price[1] * month_count;
        cost += price[2] * threemonth_count;
        if(cost < answer) answer = cost;
        return;
    }
    flag[idx] = 0;
    day_count++;
    go(idx+1);
    flag[idx] = -1;
    day_count--;
    // 1달 이용권
    flag[idx] = 1;
    month_count++;
    go(idx+1);
    month_count--;
    flag[idx] = -1;
    // 3달 이용권
    if(idx <= 10){
        flag[idx] = 2;
        flag[idx+1] = 2;
        flag[idx+2] = 2;
        threemonth_count++;
        go(idx+3);
        threemonth_count--;
        flag[idx] = -1;
        flag[idx+1] = -1;
        flag[idx+2] = -1;
    }
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> price[0]; cin >> price[1]; cin >> price[2]; cin >> price[3];
        answer = price[3];
        for(int i=1; i<=12; i++) cin >> plan[i];
        memset(flag, -1, sizeof(flag));
        go(1);
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}