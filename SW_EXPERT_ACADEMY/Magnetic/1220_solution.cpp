#include <iostream>
#include <stack>
using namespace std;
#define MAXN 100
int map[MAXN][MAXN];
int main(){
    int T = 10;
    for(int test_case=1; test_case<=T; test_case++){
        int n = 0; cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
            }
        }
        int answer = 0;
        for(int j=0; j<n; j++){
            stack<int> pstack;
            for(int i=0; i<n; i++){
                if(map[i][j] == 0) continue;
                else if(map[i][j] == 1){
                    pstack.push(1);
                }
                else if(map[i][j] == 2){
                    if(pstack.empty()) continue;
                    else{
                        if(pstack.top() == 2) continue;
                        else if(pstack.top() == 1){
                            answer++; pstack.push(2);
                        }
                    }
                }
            }
        }
        cout << answer << "\n";
    }
    return 0;
}