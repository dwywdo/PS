#include <iostream>
#define MAXD 13
#define MAXW 20
using namespace std;

int film[MAXD][MAXW];
int temp[MAXD][MAXW];
int T, D, W, K, result;
bool check = false;
bool test(){
    for(int j=0; j<W; j++){
        int val = temp[0][j]; int cnt = 1;
        for(int i=1; i<D; i++){
            if(temp[i][j] == val) cnt++;
            else{
                val = temp[i][j];
                cnt = 1;
            }
            if(cnt == K) break;
        }
        if(cnt < K) return false;
    }
    return true;
}
void fill(int x, int val){
    for(int i=0; i<W; i++){
        temp[x][i] = val;
    }
    return;
}
void rollback(int x){
    for(int i=0; i<W; i++){
        temp[x][i] = film[x][i];
    }
    return;
}
void go(int x, int cnt, int now){
    if(check) return; // 먼저 이전에 답을 찾았는지 체크한다
    // 이전에 답을 찾지 못했다면, cnt의 갯수로 몇개까지 fill을 수행했는지 확인
    if(x==cnt){
        if(test()) result = cnt, check = true;
        return;
    }
    for(int i=now; i<D; i++){
        fill(i, 0);
        go(x+1, cnt, i+1);
        fill(i, 1);
        go(x+1, cnt, i+1);
        rollback(i);
    }
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> D >> W >> K;
        for(int i=0; i<D; i++){
            for(int j=0; j<W; j++){
                cin >> film[i][j];
                temp[i][j] = film[i][j];
            }
        }
        check = false, result = 0;
        for(int i=0; i<D; i++){
            if(i==0) test();
            if(check) break;
            go(0, i, 0);
        }
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;
}