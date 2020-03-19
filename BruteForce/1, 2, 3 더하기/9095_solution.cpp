#include <iostream>
using namespace std;
int N;
int T;
int answer;
int choose(int sum, int n){
    if(sum == n){
        return 1;
    }
    int now = 0;
    if(sum > n) return 0;
    for(int i=1; i<=3; i++){
        now += choose(sum + i, n);
    }
    return now;
}
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N; answer = 0;
        answer = choose(0, N);
        cout << answer << endl;
    }
    return 0;
}