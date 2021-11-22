#include <iostream>
using namespace std;
#define MAX 300
int N = 0;
int M = 0;
int K = 0;
int arr[MAX][MAX];
int d[MAX][MAX];
int main() {
  cin >> N >> M >> K;
  int count = 0;
  for (int i=0; i<N; i++){ 
    for (int j=0; j<M; j++) {
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<N; i++) {
    int row_sum = 0;
    for (int j=0; j<M; j++){
      row_sum += arr[i][j];
      d[i][j] = row_sum;
    }
  }
  for(int j=0; j<M; j++) {
    int col_sum = 0;
    for(int i=0; i<N; i++) {
      col_sum += d[i][j];
      d[i][j] = col_sum;
    }
  }
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }
  for(int s=0; s<N*M; s++){ // k=5일 때, i = k / N, j = k % N 
    for(int e=s; e<N*M; e++) {
      int s_y = s / M;
      int s_x = s % M;
      int e_y = e / M;
      int e_x = e % M;
      if(s_y <= e_y && s_x <= e_x) {
        cout << "(" << s_y << ", " << s_x << "), " << "(" << e_y << ", " << e_x << ")";
        int partial_sum = d[e_y][e_x] - d[s_y][e_x-1] - d[e_y-1][s_x] + d[s_y-1][s_x-1];
        cout << ": " << partial_sum << endl;
        if (partial_sum % K == 0) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
}