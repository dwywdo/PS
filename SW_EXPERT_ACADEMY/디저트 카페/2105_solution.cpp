#include <iostream>
#define MAXN 20
using namespace std;
int N, T = 0;
int map[MAXN][MAXN];
bool check(int y, int x){
    if(y>=0 && y<N && x>=0 && x<N) return true;
    else return false;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
            }
        }
        bool found = false;
        int answer = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int d1=1; d1<N; d1++){
                    for(int d2=1; d2<N; d2++){
                        if(!check(i+d2, j+d2)) continue;
                        if(!check(i+d1, j-d1)) continue;
                        if(!check(i+d1+d2, j+d2-d1)) continue;
                        int cnt = 0; bool check[101] = {false, };
                        int pass = true;
                        check[map[i][j]] = true; cnt++;
                        for(int k=1; k<=d1; k++){
                            if(check[map[i+k][j-k]]){
                                pass = false; break;
                            }
                            else {
                                check[map[i+k][j-k]] = true;
                                cnt++;
                            }
                        }
                        if(!pass) continue;
                        for(int k=1; k<=d2; k++){
                            if(check[map[i+k][j+k]]){
                                pass = false; break;
                            }
                            else {check[map[i+k][j+k]] = true; cnt++;}
                        }
                        if(!pass) continue;
                        for(int k=1; k<=d2; k++){
                            if(check[map[i+d1+k][j-d1+k]]){
                                pass = false; break;
                            }
                            else{
                                check[map[i+d1+k][j-d1+k]] = true; cnt++;
                            }
                        }
                        if(!pass) continue;
                        for(int k=1; k<d1; k++){
                            if(check[map[i+d2+k][j+d2-k]]){
                                pass = false; break;
                            }
                            else{
                                check[map[i+d2+k][j+d2-k]]= true; cnt++;
                            }
                        }
                        if(!pass) continue;
                        found = true;
                        if(cnt > answer) answer = cnt;
                    }
                }
            }
        }
        if(!found) cout << "#" << test_case << " " <<  -1 << "\n";
        else{
            cout << "#" << test_case << " " <<  answer << "\n";
        }
    }
    return 0;
}