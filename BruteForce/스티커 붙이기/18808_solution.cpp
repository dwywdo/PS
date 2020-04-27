#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int laptop[40][40];
int sticker[10][10];
int tmp[10][10];
int N, M, K, R, C;
bool canstick(int &a, int &b){
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(a + r >= N || b + c >= M) return false;
            if(laptop[a+r][b+c] && sticker[r][c]) return false;
        }
    }
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(sticker[r][c]) laptop[a+r][b+c] = 1;
        }
    }
    return true;
}
void rotate() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			tmp[i][j] = sticker[i][j];

	for (int i = 0; i < C; i++)
		for (int j = 0; j < R; j++)
			sticker[i][j] = tmp[R - 1 - j][i];
	swap(R, C);
}
bool canPut(){
    for(int rotation = 0; rotation < 4; rotation++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(laptop[i][j] && sticker[0][0]) continue;
                if(canstick(i, j)) return true;
            }
        }
        rotate();
    }
    return false;
}
int main(){
    cin >> N >> M >> K;
    int answer = 0;
    while(K--){
        cin >> R >> C;
        memset(sticker, 0, sizeof(sticker));
        int sticker_size = 0;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin >> sticker[i][j];
                if(sticker[i][j] == 1) sticker_size++;
            }
        }
        if(canPut()) answer += sticker_size;
    }
    cout << answer << "\n";
    return 0;
}