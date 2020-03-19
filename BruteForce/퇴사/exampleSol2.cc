#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t[15];
int p[15];
int go(int day, int sum) { //sum: 0~(day-1) 수익
    if (day == n) {
        return sum;
    }
    if (day > n) {
        return 0;
    }
    int t1 = go(day+t[day], sum+p[day]);
    int t2 = go(day+1, sum);
    return max(t1,t2);
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i] >> p[i];
    }
    int ans = go(0, 0);
    cout << ans << '\n';
    return 0;
}