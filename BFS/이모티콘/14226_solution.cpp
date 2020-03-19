#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int S = 0;
int d[1001][1001];
int main(){
    cin >> S;
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    d[1][0] = 0;
    while(!q.empty()){
        int s, c;
        s = q.front().first;
        c = q.front().second;
        q.pop();
        if(d[s][s] == -1){
            d[s][s] = d[s][c] + 1;
            q.push(make_pair(s, s));
        }
        if(s+c <= S && d[s+c][c] == -1){
            d[s+c][c] = d[s][c] + 1;
            q.push(make_pair(s+c, c));
        }
        if(s-1 >= 0 && d[s-1][c] == -1){
            d[s-1][c] = d[s][c] + 1;
            q.push(make_pair(s-1, c));
        }
    }
    int answer = -1;
    for(int i=0; i<=S; i++){
        if(d[S][i] != -1){
            if(answer == -1 || answer > d[S][i]) answer = d[S][i];
        }
    }
    cout << answer << endl;
    return 0;
}