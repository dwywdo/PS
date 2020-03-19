#include <iostream>
#include <vector>
using namespace std;
int N, L;
int mapdata[100][100];
int main(){
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> mapdata[i][j];
        }
    }
    vector<int> map[200]; int idx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            map[idx].push_back(mapdata[i][j]);
        }
        idx++;
    }
    for(int j=0; j<N; j++){
        for(int i=0; i<N; i++){
            map[idx].push_back(mapdata[i][j]);
        }
        idx++;
    }
    int answer = 0;
    for(int i=0; i<2*N; i++){
        int cnt = 1; bool possible = true;
        for(int j=0; j<N-1; j++){
            if(map[i][j] == map[i][j+1]){
                cnt++; continue;
            }
            // 올라가는 경우
            else if(map[i][j] < map[i][j+1]){
                if(map[i][j+1] - map[i][j] > 1){
                    possible = false; break;
                }
                else if(map[i][j+1] - map[i][j] == 1){
                    if(cnt >= L) {
                        cnt = 1;
                        continue;
                    }
                    else{
                        possible = false; break;
                    }
                }
            }
            // 내려가는 경우
            else if(map[i][j] > map[i][j+1]){
                if(map[i][j] - map[i][j+1] > 1){
                    possible = false; break;
                }
                else if(map[i][j+1] - map[i][j] == -1){
                    if(L > N-(j+1)){
                        possible = false; break;
                    }
                    else{
                        for(int k=j+1; k<j+1+L; k++){
                            if(map[i][j+1] != map[i][k]){
                                possible = false; break;
                            }
                        }
                        if(!possible) break;
                        j = j+L - 1; cnt = 0;
                    }
                }
            }
        }
        if(possible) answer++;
    }
    cout << answer << '\n';
    return 0;
}