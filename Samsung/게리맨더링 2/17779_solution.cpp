#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N;
int A[21][21];
int G[21][21];
bool check(int y, int x){
    return y>=1 && y<=N && x>=1 && x<=N;
}
void grouping(int y, int x, int d1, int d2){
    // 경계선 표시
    for(int i=0; i<=d1; i++) G[y+i][x-i] = 5;
    for(int i=0; i<=d2; i++) G[y+i][x+i] = 5;
    for(int i=0; i<=d1; i++) G[y+d2+i][x+d2-i] = 5;
    for(int i=0; i<=d2; i++) G[y+d1+i][x-d1+i] = 5;
    // 경계선 안을 그룹 5로 지정
    for(int i=1; i<=N; i++){
        int start_x = 1;
        vector<int> xs;
        for(int j=1; j<=N; j++){
            if(G[i][j] == 5) xs.push_back(j);
        }
        if(xs.size() == 2){
            int start_x = xs[0]; int end_x = xs[1];
            for(int j=start_x+1; j<end_x; j++) G[i][j] = 5;
        }
    }
    // 그룹 5로 지정되지 않은 곳에 대한 그룹 지정
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(G[i][j] != 0) continue;
            if(1<=i && i<y+d1 && j>=1 && j<=x) G[i][j] = 1;
            else if(1<=i && i<=y+d2 && j>x && j<=N) G[i][j] = 2;
            else if(y+d1<=i && i<=N && j>=0 && j<x+d2-d1) G[i][j] = 3;
            else if(i>y+d2 && i<=N && j>=x+d2-d1 && j<=N) G[i][j] = 4;
        }
    }
    return;
}
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> A[i][j];
        }
    }
    int answer = 987654321;
    for(int y=1; y<=N; y++){
        for(int x=1; x<=N; x++){
            for(int d1=1; d1<=N; d1++){
                for(int d2=1; d2<=N; d2++){
                    if(!check(y+d2, x+d2)) continue;
                    if(!check(y+d1, x-d1)) continue;
                    if(!check(y+d1+d2, x+d2-d1)) continue;
                    memset(G, 0, sizeof(G));
                    grouping(y, x, d1, d2);
                    vector<int> sum(5, 0);
                    for(int i=1; i<=N; i++){
                        for(int j=1; j<=N; j++){
                            sum[G[i][j] - 1] += A[i][j]; 
                        }
                    }
                    int max = -987654321;
                    int min = 987654321;
                    for(int i=0; i<sum.size(); i++){
                        if(max < sum[i]) max = sum[i];
                        if(min > sum[i]) min = sum[i];
                    }
                    int diff = abs(max - min);
                    if(answer > diff) answer = diff;
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}