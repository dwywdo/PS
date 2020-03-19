#include <iostream>
#include <vector>
using namespace std;
int board[9][9];
bool row[9][10];
bool col[9][10];
bool area[9][10];
void dfs(int loc_num){
    if(loc_num == 81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << board[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }
    int y = loc_num / 9; int x = loc_num % 9;
    if(board[y][x] != 0){
        dfs(loc_num + 1);
    }
    else{
        for(int i=1; i<=9; i++){
            if(row[y][i]==0 && col[x][i]==0 && area[(y/3)*3+x/3][i]==0){
                row[y][i] = col[x][i] = area[(y/3)*3+x/3][i] = true;
                board[y][x] = i;
                dfs(loc_num + 1);
                board[y][x] = 0;
                row[y][i] = col[x][i] = area[(y/3)*3+x/3][i] = false;
            }
        }
    }
    return;
}
int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> board[i][j];
            if(board[i][j] != 0){
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                area[(i/3)*3+j/3][board[i][j]] = true;
            }
        }
    }
    dfs(0);
    return 0;
}
