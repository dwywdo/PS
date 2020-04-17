#include <iostream>
#include <string>
using namespace std;
int main(){
    int T = 10;
    for(int test_case=1; test_case<=T; test_case++){
        int tc = 0 ; cin >> tc;
        string target; cin >> target;
        string str; cin >> str;
        int count = 0; int idx = 0;
        while(1){
            if(str.find(target, idx) == string::npos) break;
            else{
                count++; idx = str.find(target, idx) + 1;
            }
        }
        cout << "#" << tc << " " << count << "\n";
    }
    return 0;
}