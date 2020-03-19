#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t[1500000];
int p[1500000];
int d[1500000];
// 0~(n-1) 퇴사n
// go(day): day~(n-1) 수익
int go(int day) {
    if (day == n) {
        return 0;
    }
    if (day > n) {
        return -15000000;
    }
    if (d[day] >= 0) return d[day];
    // go(day): day~(n-1) 수익
    // day -> day+t[day] -> ... -> (n-1)
    // -----------  --------------------
    //    p[day]        go(day+t[day])
    int t1 = p[day] + go(day+t[day]);
    int t2 = go(day+1);
    return d[day] = max(t1,t2);
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i] >> p[i];
        d[i] = -1;
    }
    int ans = go(0);
    cout << ans << '\n';
    return 0;
}