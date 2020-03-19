#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
char grim[100][100];
char abnormalGrim[100][100];
bool check[100][100];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int N;
int main(){
    cin >> N;
    int normalCount = 0;
    int abnormalCount = 0;
    for(int i=0; i<N; i++){
        string row = "";
        cin >> row;
        for(int j=0; j<N; j++){
            grim[i][j] = row[j];
            abnormalGrim[i][j] = row[j];
            if(abnormalGrim[i][j] == 'R') abnormalGrim[i][j] = 'G';
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(check[i][j]) continue;
            normalCount++;
            check[i][j] = true;
            queue<tuple<int, int, char>> q;
            q.push(make_tuple(i, j, grim[i][j]));
            while(!q.empty()){
                int y = get<0>(q.front());
                int x = get<1>(q.front());
                char color = get<2>(q.front());
                q.pop();
                for(int k=0; k<4; k++){
                    int ny = y + dy[k]; int nx = x + dx[k];
                    if(ny>=0 && ny<N && nx>=0 && nx<N){
                        if(grim[ny][nx] == color && !check[ny][nx]){
                            check[ny][nx] = true;
                            q.push(make_tuple(ny, nx, grim[ny][nx]));
                        }
                    }
                }

            }
        }
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) check[i][j] = false;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(check[i][j]) continue;
            abnormalCount++;
            check[i][j] = true;
            queue<tuple<int, int, char>> q;
            q.push(make_tuple(i, j, abnormalGrim[i][j]));
            while(!q.empty()){
                int y = get<0>(q.front());
                int x = get<1>(q.front());
                char color = get<2>(q.front());
                q.pop();
                for(int k=0; k<4; k++){
                    int ny = y + dy[k]; int nx = x + dx[k];
                    if(ny>=0 && ny<N && nx>=0 && nx<N){
                        if(check[ny][nx]) continue;
                        if(abnormalGrim[ny][nx] == color && !check[ny][nx]){
                            check[ny][nx] = true;
                            q.push(make_tuple(ny, nx, abnormalGrim[ny][nx]));
                        }
                    }
                }
            }
        }
    }
    cout << normalCount << " ";
    cout << abnormalCount << endl;
}