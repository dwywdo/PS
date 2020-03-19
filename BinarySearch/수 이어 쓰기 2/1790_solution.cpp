#include <iostream>
#include <string>
using namespace std;
long long N, k;
long long getCount(int N){
    long long digitCount = 0;
    for(int i=1, len=1; i<=N; i*=10, len++){
        int last = i*10 - 1;
        if(last > N){
            last = N;
        }
        digitCount += (long long)(last - i + 1)*len;
    }
    return digitCount;
}
int main(){
    cin >> N >> k;
    if(getCount(N) < k){
        cout << -1 << endl;
        return 0;
    }
    long long left = 1;
    long long right = N;
    long long answer = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        long long count = getCount(mid);
        if(count < k){
            // 길이가 k 보다 작다. 아직 k번째 수가 나오지 않았다. 수의 범위를 키운다
            left = mid + 1;
        }
        else{
            // 길이가 k 보다 크거나 같다? k번째수가 나왔다.
            answer = mid;
            right = mid - 1;
        }
    }
    // 12345678910111213 17개 15:K
    // 
    string s = to_string(answer);
    long long l = getCount(answer);
    cout << s[s.length() - (l-k) - 1] << endl;
    return 0;
}