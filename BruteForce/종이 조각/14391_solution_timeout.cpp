#include <iostream>
#include <cmath>
using namespace std;
int N, M;
int map[4][4];
bool check[4][4];
int answer = 0;
void cover(int y, int x, int sum, int covered){
    int loc = 0;
    int ny=0; int nx=0;
    if(covered == N*M){
        if(sum > answer) answer = sum;
        return;
    }
    while(1){
        ny = loc / M; nx = loc % M;
        if(!check[ny][nx]) break;
        loc++;
    }
    if(loc>M*N) return;
    //가로
    for(int c=1; c<=M-nx; c++){
        int subsum = 0;
        for(int i=0; i<c; i++){
            check[ny][nx+i] = true;
            subsum += (pow(10, c-i-1) * map[ny][nx+i]);
        }
        cover(ny, nx+c-1, sum + subsum, covered + c);
        for(int i=0; i<c; i++) check[ny][nx+i] = false;
    }
    //세로
    for(int c=1; c<=N-ny; c++){
        int subsum = 0;
        for(int i=0; i<c; i++){
            check[ny+i][nx] = true;
            subsum += (pow(10, c-i-1) * map[ny+i][nx]);
        }
        cover(ny+c-1, nx, sum + subsum, covered + c);
        for(int i=0; i<c; i++) check[ny+i][nx] = false;
    }
    return;
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    // 한 지점에서 가로, 세로로 붙일 수 있고 1개에서부터 남은 끝자락까지 붙일 수 있다.
    cover(0, 0, 0, 0);
    cout << answer << endl;
    return 0;
}