#include <iostream>
using namespace std;
#define MAXR 20
#define MAXN 9
#define MAXK 6
int N, K =0;
bool used[MAXN+1] = {false, };
int rounds[3][MAXR+1];
int wintable[MAXN+1][MAXN+1];
int roundsindex[3] = {0, 0, 0};
int wincount[3] = {0, 0, 0};
int answer = 0;
void play(int p1, int p2){
    if(wincount[0] == K) {
        answer = 1; return;
    }
    if(wincount[1] == K || wincount[2] == K) return;
    if(answer == 1) return;
    if(roundsindex[0] > N) return;
    for(int i=1; i<=N; i++){
        if(p1!=0 && p2!=0){
            i = N;
        }
        else{
            if(used[i]) continue;
            used[i] = true;
            rounds[0][roundsindex[0]] = i;
        }
        int winner = 0;
        int turn1 = roundsindex[p1];
        int turn2 = roundsindex[p2];
        int n1 = rounds[p1][turn1];
        int n2 = rounds[p2][turn2];
        if(wintable[n1][n2] == 2) winner = p1;
        else if(wintable[n1][n2] == 0) winner = p2;
        else winner = (p1 < p2) ? p2 : p1;
        
        roundsindex[p1]++; roundsindex[p2]++;
        wincount[winner]++;
        play(winner, 3 - (p1 + p2));
        wincount[winner]--;
        roundsindex[p1]--; roundsindex[p2]--;
        if(p1 == 0 || p2 == 0) used[i] = false;
    }

}
int main(){
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> wintable[i][j];
        }
    }
    int temp = 0;
    for(int p=1; p<=2; p++){
        for(int i=0; i<MAXR; i++){
            cin >> rounds[p][i];
        }
    }

    play(0, 1);
    cout << answer << "\n";
    return 0;
}