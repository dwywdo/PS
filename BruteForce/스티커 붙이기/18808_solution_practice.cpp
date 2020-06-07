#include <iostream>
#include <algorithm>
using namespace std;
int sticker[10][10];
int laptop[40][40];
int tmp[10][10];
int N, M, K;
int R, C;
int answer = 0;
void rotate() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			tmp[i][j] = sticker[i][j];

	for (int i = 0; i < C; i++)
		for (int j = 0; j < R; j++)
			sticker[i][j] = tmp[R - 1 - j][i];
	swap(R, C);
}
bool check(){
    // 붙일 수 있는지 확인하자
    for(int r=0; r<4; r++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(sticker[0][0] == 1 && laptop[i][j] == 1) continue;
                bool canPut = true;
                for(int y=0; y<R; y++){
                    for(int x=0; x<C; x++){
                        if(i + R > N || j + C > M){
                            canPut = false; break;
                        }
                        if(sticker[y][x] == 1 && laptop[y+i][x+j] == 1){
                            canPut = false; break;
                        }
                    }
                    if(!canPut) break;
                }
                if(canPut){
                    for(int y=0; y<R; y++){
                        for(int x=0; x<C; x++){
                            if(sticker[y][x] == 1) laptop[y+i][x+j] = 1;
                        }
                    }
                    return true;
                }
            }
        }
        rotate();
    }
    return false;
}
int main(){
    cin >> N >> M >> K;
    while(K--){
        cin >> R >> C;
        int sticker_size = 0;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin >> sticker[i][j];
                if(sticker[i][j] == 1) sticker_size++;
            }
        }
        if(check()) answer += sticker_size;
    }
    cout << answer << "\n";
    return 0;
}