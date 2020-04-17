#include <iostream>
using namespace std;
#define MAXN 8
char map[8][8];
int main(){
    int T = 10;
    for(int test_case=1; test_case<=T; test_case++){
        int len = 0; cin >> len;
        for(int i=0; i<MAXN; i++){
            string row; cin >> row;
            for(int j=0; j<MAXN; j++){
                map[i][j] = row[j];
            }
        }
        int answer = 0;
        for(int i=0; i<MAXN; i++){
            // 가로방향 회문 확인
            for(int j=0; j<=MAXN-len; j++){
                bool ispal = true;
                for(int k=0; k<len/2; k++){
                    if(map[i][j + k] != map[i][j + len - k - 1]){
                        ispal = false;
                    }
                }
                if(ispal) {
                    answer++;
                }
            }
        }
        for(int j=0; j<MAXN; j++){
            // 세로방향 회문 확인
            for(int i=0; i<=MAXN-len; i++){
                bool ispal = true;
                for(int k=0; k<len/2; k++){
                    if(map[i + k][j] != map[i + len - k - 1][j]){
                        ispal = false; break;
                    }
                }
                if(ispal) {
                    answer++;
                }
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}
/*
01234567
CBBCBAAB
len = 4;
j = 0 0~3까지
0 <-> 3
1 <-> 2
j = 1 1~4까지 
1 <-> 4 k = 1; j = 1; 1 + 4 - 1 - 1 = 3
2 <-> 3
*/