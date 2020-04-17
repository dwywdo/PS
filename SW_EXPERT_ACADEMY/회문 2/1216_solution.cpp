#include <iostream>
using namespace std;
#define MAXN 100
char map[MAXN][MAXN];

int main(){
    int T = 10;
    for(int test_case=1; test_case<=T; test_case++){
        int tc = 0; cin >> tc;
        for(int i=0; i<MAXN; i++){
            string row; cin >> row;
            for(int j=0; j<MAXN; j++){
                map[i][j] = row[j];
            }
        }
        int answer = 1;
        bool isfound = false;
        for(int l=MAXN; l>=2; l--){
            if(l == 18){
                int temp = 0;
            }
            for(int i=0; i<MAXN; i++){
                for(int j=0; j<=MAXN - l; j++){
                    bool ispal = true;
                    for(int k=0; k<=l/2 - 1; k++){
                        if(map[i][j + k] != map[i][j + l - k - 1]){
                            ispal = false;
                        }
                    }
                    if(ispal) {
                        answer = l; isfound = true; break;
                    }
                }
                if(isfound) break;
            }
            for(int j=0; j<MAXN; j++){
                // 세로방향 회문 확인
                for(int i=0; i<=MAXN-l; i++){
                    bool ispal = true;
                    for(int k=0; k<=l/2 - 1; k++){
                        if(map[i + k][j] != map[i + l - k - 1][j]){
                            ispal = false; break;
                        }
                    }
                    if(ispal) {
                        answer = l; isfound = true; break;
                    }
                }
                if(isfound) break;
            }
            if(isfound) break;
        }
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}