#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 10
int N, M, K;
typedef struct tree{
    int age = 0;
    bool alive = false; 
}TREE;
bool compare(tree &a, tree& b){
    return a.age < b.age;
}
vector<TREE> map[4][MAXN+1][MAXN+1];
int yangboon[4][MAXN+1][MAXN+1];
int a[MAXN+1][MAXN+1];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int main(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            yangboon[0][i][j] = 5;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<M; i++){
        int x, y, z;
        cin >> x >> y >> z;
        TREE tree; tree.age = z; tree.alive = true;
        map[0][x][y].push_back(tree);
    }
    int cur = 0;
    for(int k=0; k<K; k++){
        // 봄: 0 나무가 양분을 먹고 나이를 먹는다
        int temp = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                yangboon[cur+1][i][j] = yangboon[cur][i][j];
                if(map[cur][i][j].empty()) continue;
                else{
                    sort(map[cur][i][j].begin(), map[cur][i][j].end(), compare);
                    for(auto & tree : map[cur][i][j]){
                        if(tree.alive){
                            if(yangboon[cur][i][j] >= tree.age){
                                yangboon[cur+1][i][j] -= tree.age;
                                tree.age++;
                            }
                            else{
                                tree.alive = false;
                            }
                        }
                    }
                }
                map[cur+1][i][j] = map[cur][i][j];
            }
        }
        cur++;
        // 여름. 죽은 나무가 양분이 된다
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                yangboon[cur+1][i][j] = yangboon[cur][i][j];
                if(map[cur][i][j].empty()) continue;
                else{
                    for(auto & tree : map[cur][i][j]){
                        if(!tree.alive){
                            yangboon[cur+1][i][j] += tree.age / 2;
                        }
                    }
                }
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(map[cur][i][j].empty()) continue;
                for(auto & tree : map[cur][i][j]){
                    if(tree.alive) map[cur+1][i][j].push_back(tree);
                }
            }
        }
        cur++;
        // 가을. 나무가 번식한다
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                yangboon[cur+1][i][j] = yangboon[cur][i][j];
                if(map[cur][i][j].empty()) continue;
                else{
                    for(auto & tree : map[cur][i][j]){
                        if(tree.alive && tree.age % 5 == 0){
                            for(int k=0; k<8; k++){
                                int ny = i + dy[k];
                                int nx = j + dx[k];
                                if(ny<1 || ny>N || nx<1 || nx>N) continue;
                                TREE newtree; newtree.age = 1; newtree.alive = 1;
                                map[cur+1][ny][nx].push_back(newtree);
                            }
                        }
                    }
                }
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(map[cur][i][j].empty()) continue;
                for(auto & tree : map[cur][i][j]) map[cur+1][i][j].push_back(tree);
            }
        }
        cur++;
        // 겨울.
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                yangboon[0][i][j] = yangboon[cur][i][j];
                yangboon[0][i][j] += a[i][j];
                if(map[cur][i][j].empty()) continue;
                map[0][i][j].clear();
                map[0][i][j] = map[cur][i][j];
            }
        }
        cur = 0;
        for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) for(int y=1; y<=3; y++){
            map[y][i][j].clear();
            yangboon[y][i][j] = 0;
        }
        int tmp = 0;
    }
    int alivecount = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(map[0][i][j].empty()) continue;
            for(auto &tree : map[0][i][j]){
                if(tree.alive) alivecount++;
            }
        }
    }
    cout << alivecount << "\n";
    return 0;
}