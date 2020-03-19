#include <iostream>
using namespace std;
bool visited[1501][1501];
int sum = 0;
int A; int B; int C;
void go(int a, int b){
    if(visited[a][b]) return;
    visited[a][b] = true;
    int state[3] = {a, b, sum-a-b};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(state[i] < state[j]){
                int next_state[3] = {a, b, sum-a-b};
                next_state[i] += state[i];
                next_state[j] -= state[i];
                go(next_state[0], next_state[1]);
            }
        }
    }
}
int main(){
    cin >> A >> B >> C;
    sum = A + B + C;
    if(sum % 3 != 0){
        cout << 0 << endl; 
        return 0 ;
    }
    go(A, B);
    if(visited[sum/3][sum/3]){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }

    return 0;
}