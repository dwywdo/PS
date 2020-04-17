#include <iostream>
using namespace std;
int getpower(int a, int b){
    if(b==1) {
        return a;
    }
    int answer = a * getpower(a, b-1);
    return answer;
}
int main(){
    int T = 10;
    for(int test_case=1; test_case<=T; test_case++){
        int tc = 0; cin >> tc;
        int a, b; cin >> a >> b;
        int answer = getpower(a, b);
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}