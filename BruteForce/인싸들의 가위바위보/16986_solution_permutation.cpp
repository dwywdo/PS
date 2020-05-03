#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 9
#define MAXR 20
bool used[MAXN+1];
int wintable[MAXN+1][MAXN+1];
int N, K;
int rounds[3][MAXR + 1];
bool play(){
    int roundindex[3] = {1, 1, 1};
    int wincount[3] = {0, 0, 0};
    int p1 = 0; int p2 = 1; int p3 = 2;
    while(1){
        if(p1 > p2) swap(p1, p2); // 무조건 p2가 크도록
        if(p1 == 0 && roundindex[0] > N) break;
        if(roundindex[p1] > 20 || roundindex[p2] > 20) break;
        int a = rounds[p1][roundindex[p1]++];
        int b = rounds[p2][roundindex[p2]++];
        if(wintable[a][b] == 2){ // 이기는 경우
            wincount[p1]++; swap(p2, p3);
            if(wincount[p1] == K) break;
        }
        else{
            wincount[p2]++; swap(p1, p3);
            if(wincount[p2] == K) break;
        }
    }
    return wincount[0] >= K;
}
int main(){
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> wintable[i][j];
        }
    }
    for(int j=1; j<=N; j++){
        rounds[0][j] = j;
    }
    for(int i=1; i<=2; i++){
        for(int j=1; j<=MAXR; j++){
            cin >> rounds[i][j];
        }
    }
    do{
        bool ret = play();
        if(ret){
            cout << 1 << "\n"; return 0;
        }
    }while(next_permutation(rounds[0]+1, rounds[0]+N+1));
    cout << 0 << "\n";
    return 0;
}