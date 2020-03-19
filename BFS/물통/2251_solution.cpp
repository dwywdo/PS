#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int AC, BC, CC = 0;
bool visited[200][200][200];
int main(){
    cin >> AC >> BC >> CC;
    int a = 0; int b = 0; int c = CC;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(a, b, c));
    visited[a][b][c] = true;
    vector<int> answers;
    while(!q.empty()){
        tuple<int, int, int> cur = q.front(); q.pop();
        int a = get<0>(cur); int b = get<1>(cur); int c= get<2>(cur);
        if(a==0 && find(answers.begin(), answers.end(), c) == answers.end()){
            answers.push_back(c);
        }
        if(a>0){
            if(a + b > BC){ // A -> B
                int na = a - (BC - b); int nb = BC; int nc = c;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
            if(a + b <= BC){
                int na = 0; int nb = a + b; int nc = c;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
            if(a + c > CC){
                int na = a - (CC - c); int nb = b; int nc = CC;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
            if(a + c <= CC){
                int na = 0; int nb = b; int nc = a + c;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
        }
        if(b>0){ // b에 있는 물을 옮긴다.
            if(a + b > AC){ // 가득찰때까지
                int na = AC; int nb = b - (AC - a); int nc = c;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
            if(a + b <= AC){
                int na = a + b; int nb = 0; int nc = c;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
            if(b + c > CC){
                int na = a; int nb = b - (CC - c); int nc = CC;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
            if(b + c <= CC){
                int na = a; int nb = 0; int nc = b + c;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
        }
        if(c>0){
            if(a + c > AC){ // 가득찰때까지
                int na = AC; int nb = b; int nc = c - (AC - a);
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
            if(a + c <= AC){
                int na = a + c; int nb = b; int nc = 0;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
            if(b + c > BC){
                int na = a; int nb = BC; int nc = c - (BC - b);
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
            if(b + c <= BC){
                int na = a; int nb = b + c; int nc = 0;
                if(!visited[na][nb][nc]){
                    visited[na][nb][nc] = true;
                    q.push(make_tuple(na, nb, nc));
                }
            }
        }
    }
    sort(answers.begin(), answers.end());
    for(int i=0; i<answers.size(); i++){
        printf("%d ", answers[i]);
    }
    printf("\n");
    return 0;
}