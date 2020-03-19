#include <iostream>
#include <queue>
using namespace std;
bool visited[200][200];
int d[200][200];
int N;
int dr[6] = {-2, -2, 0, 0, 2, 2};
int dc[6] = {-1, +1, -2, +2, -1, +1};
int main(){
    cin >> N; int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    for(int i=0; i<200; i++){
        for(int j=0; j<200; j++){
            d[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    visited[r1][c1] = true;
    d[r1][c1] = 0;
    q.push(make_pair(r1, c1));
    while(!q.empty()){
        int loc_r = q.front().first;
        int loc_c = q.front().second;
        q.pop();
        for(int i=0; i<6; i++){
            int nr = loc_r + dr[i];
            int nc = loc_c + dc[i];
            if(nr>=0 && nr<N && nc>=0 && nc<N && !visited[nr][nc]){
                visited[nr][nc] = true;
                d[nr][nc] = d[loc_r][loc_c] + 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
    if(d[r2][c2] == -1){
        cout << -1 << endl;
    }
    else{
        cout << d[r2][c2] << endl;
    }
    return 0;
}