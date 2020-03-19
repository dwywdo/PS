#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int I = 0;
int T = 0;
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> I;
        int board[300][300] = {0, };
        bool visited[300][300] = {false, };
        int start_y = 0; int start_x = 0;
        int target_y = 0; int target_x = 0;
        cin >> start_y >> start_x;
        cin >> target_y >> target_x;
        queue<tuple<int, int, int>> q;
        q.push(make_tuple(start_y, start_x, 0)); visited[start_y][start_x] = true;
        while(!q.empty()){
            tuple<int, int, int> point = q.front(); q.pop();
            int y = get<0>(point); int x = get<1>(point); int d = get<2>(point);
            if(y == target_y && x == target_x){
                cout << d << endl;
                break;
            }
            for(int i=0; i<8; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                int nd = d + 1;
                if(nx>=0 && nx<I && ny>=0 && ny<I && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    q.push(make_tuple(ny, nx, nd));
                }
            }
        }
    }
    return 0;
}
