#include <iostream>
using namespace std;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
typedef struct data{
    int status = 0;
    int LP = 0;
    int HP = 0;
}DATA;
DATA map[2][350][350];
int main(){
    int T = 0; cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        int N, M, K; cin >> N >> M >> K;
        for(int i=0; i<N + (K/2)*2; i++){
            for(int j=0; j<M + (K/2)*2; j++){
                map[0][i][j].status = 0;
                map[1][i][j].status = 0;
                map[0][i][j].HP = 0;
                map[1][i][j].HP = 0;
                map[0][i][j].LP = 0;
                map[1][i][j].LP = 0;
            }
        }
        for(int i=(K/2) + 0; i<(K/2) + N; i++){
            for(int j=(K/2) + 0; j<(K/2) + M; j++){
                int lp = 0; cin >> lp;
                if(lp > 0){
                    map[0][i][j].status = 1;
                    map[0][i][j].HP = 0;
                    map[0][i][j].LP = lp;
                }
            }
        }

        N = N + (K/2)*2; M = M + (K/2)*2;
        
        int curMap = 0;
        for(int k=0; k<K; k++){
            int temp = 0;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(map[curMap][i][j].status == 3){
                        map[1 - curMap][i][j].status = 3;
                        continue;
                    }
                    else if(map[curMap][i][j].status == 1){
                        map[1 - curMap][i][j].HP = map[curMap][i][j].HP + 1;
                        map[1 - curMap][i][j].LP = map[curMap][i][j].LP;

                        if(map[1 - curMap][i][j].HP == map[1-curMap][i][j].LP){
                            map[1 - curMap][i][j].status = 2;
                        }
                        else{
                            map[1 - curMap][i][j].status = 1;
                        }
                    }
                    else if(map[curMap][i][j].status == 2){
                        // 이미 활성상태인 경우
                        if(map[curMap][i][j].HP == map[curMap][i][j].LP){
                            for(int d=0; d<4; d++){
                                int ni = i + dy[d];
                                int nj = j + dx[d];
                                if(map[curMap][ni][nj].status == 0){
                                    if(map[1 - curMap][ni][nj].status == 0){
                                        map[1 - curMap][ni][nj].status = 1;
                                        map[1 - curMap][ni][nj].LP = map[curMap][i][j].LP;
                                        map[1 - curMap][i][j].HP = 0;
                                    }
                                    else if(map[1 - curMap][ni][nj].status == 1 && map[1 - curMap][ni][nj].LP < map[curMap][i][j].LP){
                                        map[1 - curMap][ni][nj].LP = map[curMap][i][j].LP;
                                    }
                                }
                            }
                        }
                        map[1 - curMap][i][j].HP = map[curMap][i][j].HP - 1;
                        if(map[1 - curMap][i][j].HP == 0){
                            map[1 - curMap][i][j].status = 3;
                        }
                        else{
                            map[1 - curMap][i][j].status = 2;
                        }
                    }
                }
            }
            curMap = 1 - curMap;
        }
        int answer = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[curMap][i][j].status == 1 || map[curMap][i][j].status == 2) answer++;
            }
        }
        cout << "#" << test_case << " " << answer << '\n';
    }
    return 0;
}