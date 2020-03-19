#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
bool visited[1501][1501];
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    int sum = A + B + C;
    if(sum % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    queue<pair<int, int>> q;
    visited[A][B] = true;
    q.push(make_pair(A, B));
    int answer = 0;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        int c = sum - a - b;
        q.pop();
        if(a == b && b == c){
            answer = 1;
            break;
        }
        int na = 0; int nb = 0; int nc = 0;
        if(a!=b){
            if(a > b){
                na = a - b;
                nb = b + b;
                nc = c;
            }
            else{
                na = a + a;
                nb = b - a;
                nc = c;
            }
            if(!visited[na][nb]){
                visited[na][nb] = true;
                q.push(make_pair(na, nb));
            }
        }
        if(b!=c){
            if(b > c){
                na = a; nb = b - c; nc = c + c;
            }
            else{
                na = a; nb = b + b; nc = c - b;
            }
            if(!visited[na][nb]){
                visited[na][nb] = true;
                q.push(make_pair(na, nb));
            }
        }
        if(a!=c){
            if(a > c){
                na = a - c; nc = c + c; nb = b;
            }
            else{
                na = a + a; nc = c - a; nb = b;
            }
            if(!visited[na][nb]){
                visited[na][nb] = true;
                q.push(make_pair(na, nb));
            }
        }
    }
    cout << answer << endl;
}