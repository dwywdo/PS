#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define CW  1
#define CCW -1
#define N 0
#define S 1
vector<int> wheels[1001];
int cnt = 0;
int T = 0;
vector<pair<int, int>> insts;
void go(int index, int dir){
    int cur_index = index;
    int cur_dir = dir;
    bool check[1001]; memset(check, false, sizeof(check));
    int dirs[1001]; memset(dirs, 0, sizeof(dirs));
    check[cur_index] = true;
    dirs[cur_index] = dir;
    int left_index = cur_index - 1;
    int right_index = cur_index + 1;

    while(left_index >= 1){
        if(wheels[left_index][2] != wheels[cur_index][6]){
            check[left_index] = true;
            dirs[left_index] = -dirs[cur_index];
            cur_index--;
            left_index--;
        }
        else break;
    }
    cur_index = index;
    while(right_index <= T){
        if(wheels[cur_index][2] != wheels[right_index][6]){
            check[right_index] = true;
            dirs[right_index] = -dirs[cur_index];
            cur_index++;
            right_index++;
        }
        else break;
    }
    // 회전시키기
    for(int i=1; i<=T; i++){
        if(check[i]){
            if(dirs[i] == CCW) {
                rotate(wheels[i].begin(), wheels[i].begin() + 1, wheels[i].end());
            }
            else if(dirs[i] == CW) {
                rotate(wheels[i].rbegin(), wheels[i].rbegin() + 1, wheels[i].rend());
            }
        }
    }
    return;
}
int main(){
    cin >> T;
    for(int i=1; i<=T; i++){
        for(int j=0; j<8; j++){
            int temp = 0;
            scanf("%1d", &temp);
            wheels[i].push_back(temp);
        }
    }
    cin >> cnt;
    for(int i=0; i<cnt; i++){
        int num = 0;
        int dir = 0;
        cin >> num >> dir;
        insts.push_back(make_pair(num, dir));
    }
    for(int i=0; i<cnt; i++) go(insts[i].first, insts[i].second);
    int answer = 0;
    for(int i=1; i<=T; i++){
        if(wheels[i][0] == S) answer++;
    }
    printf("%d\n", answer);
    return 0;
}