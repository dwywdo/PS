#include <iostream>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    int number = 1;
    int digitsize = 1;
    long long answer = 0;
    while(number <= n){
        int maximum = number*10 - 1;
        if(maximum > n){
            answer += (long long)(n - number + 1)*digitsize;
            digitsize++;
        }
        else{
            answer += (long long)(maximum - number + 1)*digitsize;
            digitsize++;

        }
        number*=10;
    }
    cout << answer << endl;
    return 0;
}