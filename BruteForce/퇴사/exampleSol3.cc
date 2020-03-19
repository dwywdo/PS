#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t[15];
int p[15];
// 0~(n-1) 퇴사n
// go(day): day~(n-1) 수익
int go(int day) {
    if (day == n) {
        return 0;
    }
    if (day > n) {
        return -15000000;
    }
    // go(day): day~(n-1) 수익
    // day -> day+t[day] -> ... -> (n-1)
    // -----------  --------------------
    //    p[day]        go(day+t[day])
    int t1 = p[day] + go(day+t[day]);
    int t2 = go(day+1);
    return max(t1,t2);
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i] >> p[i];
    }
    int ans = go(0);
    cout << ans << '\n';
    return 0;
}