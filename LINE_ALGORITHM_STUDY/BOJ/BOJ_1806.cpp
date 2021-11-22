#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 200000
int N = 0;
int S = 0;
int arr[MAX_N];
int D[MAX_N];
int main() {
  scanf("%d %d", &N, &S);
  for(int i=1; i<=N; i++) {
    scanf("%d", &arr[i]);
    D[i] = D[i-1] + arr[i];
  }
  int answer = MAX_N;
  for (int idx = 1; idx <= N; idx++) {
    int value = distance(D, lower_bound(D, D + N + 1, S + D[idx - 1]));
    if (value > N) continue;
    answer = min(answer, value - idx + 1);
  }
  if (answer == MAX_N) answer = 0;
  printf("%d", answer);
  return 0;
}