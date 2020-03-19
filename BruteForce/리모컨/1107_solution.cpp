#include <iostream>
using namespace std;
int N = 0;
int wrongCount = 0;
bool isWrong[10];
int currentChannel = 100;
int possible(int c){
    if (c == 0){
        if (isWrong[0]){
            return 0;
        }
        else{
            return 1;
        }
    }
    int len = 0;
    while(c > 0){
        if(isWrong[c % 10]){
            return 0;
        }
        len += 1;
        c /= 10;
    }
    return len;
}
int main(){
    cin >> N;
    cin >> wrongCount;
    for(int i=0; i<wrongCount; i++){
        int channel;
        cin >> channel;
        isWrong[channel] = true;
    }
    int ans = N - currentChannel;
    if (ans < 0){
        ans = -ans;
    }
    for(int i=0; i<= 1000000; i++){
        int c = i;
        int len = possible(c);
        if (len > 0){
            int diff = c - N;
            if(diff < 0){
                diff = -diff;
            }
            if(ans > len + diff){
                ans = len + diff;
                if(ans == 0){
                    int temp = 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}