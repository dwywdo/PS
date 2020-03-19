#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int N, L, R;
int map[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    while(1){
        int check[50][50]; memset(check, -1, sizeof(check));
        int group_index = 0;
        vector<int> groupsum;
        vector<int> groupcount;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(check[i][j] != -1) continue;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j)); check[i][j] = group_index;
                groupsum.push_back(0); groupsum[group_index] += map[i][j];
                groupcount.push_back(0); groupcount[group_index] += 1;
                while(!q.empty()){
                    int y = q.front().first; int x = q.front().second; q.pop();
                    for(int k=0; k<4; k++){
                        int ny = y + dy[k]; int nx = x + dx[k];
                        if(check[ny][nx] != -1) continue;
                        if(ny>=0 && ny<N && nx>=0 && nx<N){
                            int diff = abs(map[ny][nx] - map[y][x]);
                            if(diff >= L && diff <= R){
                                check[ny][nx] = group_index;
                                groupsum[group_index] += map[ny][nx];
                                groupcount[group_index]++;
                                q.push(make_pair(ny, nx));
                            }
                        }
                    }
                }
                group_index++;
            }
        }
        if(groupsum.size() == N*N) break;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int idx = check[i][j];
                map[i][j] = groupsum[idx] / groupcount[idx];
            }
        }
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}