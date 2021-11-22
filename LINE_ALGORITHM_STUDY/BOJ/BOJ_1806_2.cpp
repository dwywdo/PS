#include <iostream>
using namespace std;
 
int n, s;
int num[100000];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int ans = n+1;
    int sum = num[0];
    int left = 0;
    int right = 0;
    while(left <= right && right < n) {
        if (sum < s) {
            right++;
            sum += num[right];
        }
        else if (sum > s) {
            int len = right - left + 1;
            if (ans > len) ans = len;
            sum -= num[left];
            left++;
        }
        else {
            int len = right - left + 1;
            if (ans > len) ans = len;
            right++;
            sum += num[right];
        }
    }
    if (ans == n + 1) ans = 0;
    cout << ans << '\n';
    return 0;
}
