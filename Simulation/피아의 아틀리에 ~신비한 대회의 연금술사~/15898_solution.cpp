#include <iostream>
using namespace std;
#define BOARD_SIZE 5
#define ING_SIZE 4
typedef struct data{
    int qual = 0;
    char color = '0';
}DATA;
int start_y[4] = {0, 0, 1, 1};
int start_x[4] = {0, 1, 0, 1};
DATA ings[10][ING_SIZE][ING_SIZE];
bool used[10];
DATA board[BOARD_SIZE][BOARD_SIZE];
int N = 0;
int answer = 0;
int calqual(DATA board[][BOARD_SIZE]){
    int rc = 0; int bc = 0; int gc = 0; int yc = 0;
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            switch(board[i][j].color){
                case 'R':
                    rc += board[i][j].qual;
                    break;
                case 'B':
                    bc += board[i][j].qual;
                    break;
                case 'G':
                    gc += board[i][j].qual;
                    break;
                case 'Y':
                    yc += board[i][j].qual;
                    break;
                default:
                    break; 
            }
        }
    }
    return 7*rc + 5*bc + 3*gc + 2*yc;
}
void putIngredient(DATA board[][BOARD_SIZE], DATA ing[][ING_SIZE], int y, int x){
    for(int i=y; i<y+ING_SIZE; i++){
        for(int j=x; j<x+ING_SIZE; j++){
            board[i][j].qual += ing[i-y][j-x].qual;
            if(board[i][j].qual > 9) board[i][j].qual = 9;
            if(board[i][j].qual < 0) board[i][j].qual = 0;
            if(ing[i-y][j-x].color != 'W'){
                board[i][j].color = ing[i-y][j-x].color;
            }
        }
    }
}
void rotate90(DATA ing[][ING_SIZE]){
    DATA tmp[ING_SIZE][ING_SIZE];
    for(int a=0; a<ING_SIZE; a++){
        for(int b=0; b<ING_SIZE; b++){
            tmp[a][b] = ing[a][b];
        }
    }
    for(int a=0; a<ING_SIZE; a++){
        for(int b=0; b<ING_SIZE; b++){
            ing[a][b] = tmp[ING_SIZE - 1 - b][a];
        }
    }
}
void go(int cnt, DATA b[][BOARD_SIZE]){
    if(cnt == 3){
        int quality = calqual(b);
        if(quality > answer) answer = quality;
        return ;
    }
    // 재료 선택
    for(int i=0; i<N; i++){
        if(used[i]) continue;
        used[i] = true;
        DATA temp[BOARD_SIZE][BOARD_SIZE];
        DATA ing_temp[ING_SIZE][ING_SIZE];
        for(int y=0; y<ING_SIZE; y++) for(int x=0; x<ING_SIZE; x++) ing_temp[y][x] = ings[i][y][x];

        for(int l=0; l<4; l++){ // 재료를 넣을 위치 선택
            int s_y = start_y[l];
            int s_x = start_x[l];
            // 회전 별 입력
            for(int r=0; r<4; r++){
                for(int y=0; y<BOARD_SIZE; y++) for(int x=0; x<BOARD_SIZE; x++) temp[y][x] = b[y][x];
                putIngredient(b, ing_temp, s_y, s_x);
                go(cnt + 1, b);
                for(int y=0; y<BOARD_SIZE; y++) for(int x=0; x<BOARD_SIZE; x++) b[y][x] = temp[y][x];
                rotate90(ing_temp);
            }
        }
        used[i] = false;
    }
}
int main(){
    cin >> N;
    for(int n=0; n<N; n++){
        for(int i=0; i<ING_SIZE; i++){
            for(int j=0; j<ING_SIZE; j++){
                cin >> ings[n][i][j].qual;
            }
        }
        for(int i=0; i<ING_SIZE; i++){
            for(int j=0; j<ING_SIZE; j++){
                cin >> ings[n][i][j].color;
            }
        }
    }
    int temp = 0;
    go(0, board);
    cout << answer << "\n";
    return 0;
}