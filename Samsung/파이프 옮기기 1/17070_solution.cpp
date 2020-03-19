#include <iostream>
using namespace std;
#define GARO 0
#define SERO 1
#define DAEGAK 2

int map[17][17];
bool check[17][17];
int N;
int answerCount = 0;

int dy[3] = {0, 1, 1};
int dx[3] = {1, 0, 1};

int garo[2] = {0, 2};
int sero[2] = {1, 2};
int daegak[3] = {0, 1, 2};

void traverse(int y, int x, int status){
    if(y==N && x==N){
        answerCount++;
        return;
    }
    check[y][x] = true;
    if(status == GARO){
        for(int i=0; i<2; i++){
            int idx = garo[i];
            int ny = y + dy[idx]; int nx = x + dx[idx];
            if(ny<1 || ny>N || nx<1 || nx>N) continue;
            if(i==0){
                if(check[ny][nx] == false && map[ny][nx] == 0){
                    traverse(ny, nx, GARO);
                    check[ny][nx] = false;
                }
            }
            else if(i==1){
                if(check[ny][nx] == false && map[ny][nx] == 0 && map[ny-1][nx] == 0 && map[ny][nx-1] == 0){
                    traverse(ny, nx, DAEGAK);
                    check[ny][nx] = false;
                }
            }
        }
    }
    else if(status == SERO){
        for(int i=0; i<2; i++){
            int idx = sero[i];
            int ny = y + dy[idx]; int nx = x + dx[idx];
            if(ny<1 || ny>N || nx<1 || nx>N) continue;
            if(i==0){
                if(check[ny][nx] == false && map[ny][nx] == 0) {
                    traverse(ny, nx, SERO);
                    check[ny][nx] = false;
                }
            }
            else if(i==1){
                if(check[ny][nx] == false && map[ny][nx] == 0 && map[ny-1][nx] == 0 && map[ny][nx-1] == 0){
                    traverse(ny, nx, DAEGAK);
                    check[ny][nx] = false;
                }
            }
        }
    }
    else if(status == DAEGAK){
        for(int i=0; i<3; i++){
            int idx = daegak[i];
            int ny = y + dy[idx]; int nx = x + dx[idx];
            if(ny<1 || ny>N || nx<1 || nx>N) continue;
            if(i==0){
                if(check[ny][nx] == false && map[ny][nx] == 0) {
                    traverse(ny, nx, GARO);
                    check[ny][nx] = false;
                }
            }
            else if(i==1){
                if(check[ny][nx] == false && map[ny][nx] == 0) {
                    traverse(ny, nx, SERO);  
                    check[ny][nx] = false;
                }
            }
            else if(i==2){
                if(check[ny][nx] == false && map[ny][nx] == 0 && map[ny-1][nx] == 0 && map[ny][nx-1] == 0){
                    traverse(ny, nx, DAEGAK);
                    check[ny][nx] = false;
                }
            }
        }
    }
    
}
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }
    traverse(1, 2, GARO);
    cout << answerCount << endl;
    return 0;
}
