#include <iostream>
using namespace std;
int n;
int t[15];
int p[15];
int ans = 0;
void go(int day, int sum) {
    if (day == n) {
        if (ans < sum) {
            ans = sum;
        }
        return;
    }
    if (day > n) {
        return;
    }
    go(day+t[day], sum+p[day]);
    go(day+1, sum);
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i] >> p[i];
    }
    go(0, 0);
    cout << ans << '\n';
    return 0;
}