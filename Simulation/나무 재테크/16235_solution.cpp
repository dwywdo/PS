#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int map[11][11];
int add[11][11];
int N, M, K;
vector<int> trees[11][11];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> add[i][j];
            map[i][j] = 5;
        }
    }
    for(int i=0; i<M; i++){
        int y = 0; int x = 0; int age = 0;
        cin >> y >> x >> age;
        trees[y][x].push_back(age);
    }
    while(K--){
        // 봄, 여름
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(trees[i][j].empty()) continue;
                sort(trees[i][j].begin(), trees[i][j].end());
                vector<int> survived;
                vector<int> deads;
                for(auto &tree : trees[i][j]){
                    if(tree <= map[i][j]){
                        map[i][j] -= tree;
                        tree++;
                        survived.push_back(tree);
                    }
                    else deads.push_back(tree);
                }
                trees[i][j].clear(); 
                trees[i][j] = survived;
                for(auto &dead : deads) map[i][j] += (dead / 2);
                int temp = 0;
            }
        }
        // 가을
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(trees[i][j].empty()) continue;
                for(auto &tree : trees[i][j]){
                    if(tree % 5 == 0){
                        for(int k=0; k<8; k++){
                            int ny = i + dy[k]; int nx = j + dx[k];
                            if(ny>=1 && ny<=N && nx>=1 && nx<=N){
                                trees[ny][nx].push_back(1);
                            }
                            int temp = 0;
                        }
                    }
                }
                
            }
        }
        // 겨울
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                map[i][j] += add[i][j];
            }
        }
    }



    int cnt = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cnt += trees[i][j].size();
        }
    }
    cout << cnt << '\n';
    return 0;
}