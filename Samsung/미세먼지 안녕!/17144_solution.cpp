#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[50][50];
int copy_map[50][50];
int R, C, T;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<pair<int, int>> airs;
void rotation(pair<int, int> air, bool isupper){
    vector<int> group;
    if(isupper){
        for(int i=air.first, j=air.second; j<C-1; j++){
            if(map[i][j] == -1) group.push_back(0);
            else group.push_back(map[i][j]);
        }
        for(int i=air.first, j=C-1; i>0; i--) group.push_back(map[i][j]);
        for(int i=0, j=C-1; j>0; j--) group.push_back(map[i][j]);
        for(int i=0, j=0; i<air.first; i++) group.push_back(map[i][j]);
        rotate(group.rbegin(), group.rbegin()+1, group.rend());
        int idx = 0;
        for(int i=air.first, j=air.second; j<C-1; j++){
            if(map[i][j] != -1) map[i][j] = group[idx++];
            else idx++;
        }
        for(int i=air.first, j=C-1; i>0; i--) map[i][j] = group[idx++];
        for(int i=0, j=C-1; j>0; j--) map[i][j] = group[idx++];
        for(int i=0, j=0; i<air.first; i++) map[i][j] = group[idx++];
    }
    else{
        for(int i=air.first, j=air.second; j<C-1; j++){
            if(map[i][j] == -1) group.push_back(0);
            else group.push_back(map[i][j]);
        }
        for(int i=air.first, j=C-1; i<R-1; i++) group.push_back(map[i][j]);
        for(int i=R-1, j=C-1; j>0; j--) group.push_back(map[i][j]);
        for(int i=R-1, j=0; i>air.first; i--) group.push_back(map[i][j]);
        rotate(group.rbegin(), group.rbegin()+1, group.rend());
        int idx = 0;
        for(int i=air.first, j=air.second; j<C-1; j++){
            if(map[i][j] != -1) map[i][j] = group[idx++];
            else idx++;
        }
        for(int i=air.first, j=C-1; i<R-1; i++) map[i][j] = group[idx++];
        for(int i=R-1, j=C-1; j>0; j--) map[i][j] = group[idx++];
        for(int i=R-1, j=0; i>air.first; i--) map[i][j] = group[idx++];
    }
}
int main(){
    cin >> R >> C >> T;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];
            copy_map[i][j] = map[i][j];
            if(map[i][j] == -1){
                airs.push_back(make_pair(i, j));
            }
        } 
    }
    int tmp = 0;
    while(T--){
        // 확산
        bool check[50][50];
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(copy_map[i][j] >= 5) check[i][j] = true;
                else check[i][j] = false;
            }
        }
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(check[i][j]){
                    int cnt = 0;
                    for(int k=0; k<4; k++){
                        int ny = i + dy[k]; int nx = j + dx[k];
                        if(ny>=0 && ny<R && nx>=0 && nx<C){
                            if(map[ny][nx] != -1){
                                map[ny][nx] += copy_map[i][j] / 5; cnt++;
                            }
                        }
                    }
                    map[i][j] -= (copy_map[i][j]/5)*cnt;
                }
            }
        }
        rotation(airs[0], true);
        rotation(airs[1], false);
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                copy_map[i][j] = map[i][j];
            }
        }
    }
    int amount = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] != -1) amount += map[i][j]; 
        }
    }
    cout << amount << endl;
    return 0;
}