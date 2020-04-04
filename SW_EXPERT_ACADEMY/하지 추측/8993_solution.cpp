#include <iostream>
#include <set>
using namespace std;
int T = 0;
unsigned long long N = 0;
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N;
        bool terminate = true;
        set<long long> check; check.insert(N);
        while(N > 1){
            if(N % 2 == 0){
                N = N / 2;
                if(check.count(N)==1){
                    terminate = false; break;
                }
                else{
                    check.insert(N);
                }
            }
            else{
                N = 3*N + 3;
                if(check.count(N)==1){
                    terminate = false; break;
                }
            }
        }
        if(terminate){
            cout << "#" << test_case << " " << "YES" << "\n";
        }
        else{
            cout << "#" << test_case << " " << "NO" << "\n";
        }
    }
    return 0;
}