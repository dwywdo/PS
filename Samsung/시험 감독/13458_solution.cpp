#include <iostream>
#include <vector>
using namespace std;
long long N, B, C;
long long a[1000001];
int main(){
    long long answer = 0;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    cin >> B >> C;
    for(int i=1; i<=N; i++){
        if (a[i] <= B) answer++;
        else{
            answer++;
            a[i] -= B;
            if(a[i] % C == 0) answer += a[i]/C;
            else answer += ((a[i]/C)+1);
        }
    }
    cout << answer << '\n';
    return 0;
}