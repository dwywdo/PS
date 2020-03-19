#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, T;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void move(vector<vector<int>> &rounds, int x, int d, int k){
    if(d==0){
        rotate(rounds[x].rbegin(), rounds[x].rbegin() + k, rounds[x].rend());
    }
    else if(d==1){
        rotate(rounds[x].begin(), rounds[x].begin() + k, rounds[x].end());
    }
}
bool remove(vector<vector<int>> &rounds){
    vector<vector<bool>> visited(N+1, vector<bool>(M, 0));
    bool ischanged = false;
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            if(visited[i][j]) continue;
            if(rounds[i][j] == 0) continue;
            visited[i][j] = true;
            queue<pair<int, int>> q; q.push(make_pair(i, j));
            vector<pair<int, int>> v; v.push_back(make_pair(i, j));
            while(!q.empty()){
                int y = q.front().first; int x = q.front().second; q.pop();
                for(int k=0; k<4; k++){
                    int ny = y + dy[k]; int nx = x + dx[k];
                    nx = (nx + M) % M;
                    if(ny>=1 && ny<=N && nx>=0 && nx<M){
                        if(visited[ny][nx] == false && rounds[ny][nx] == rounds[y][x]){
                            visited[ny][nx] = true;
                            v.push_back(make_pair(ny, nx));
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
            }
            if(v.size() == 1) continue;
            ischanged = true;
            for(auto &p : v){
                int y = p.first; int x = p.second;
                rounds[y][x] = 0;
            }
        }
    }
    return ischanged;
}
void adjust(vector<vector<int>> &rounds){
    long long cnt = 0; long long sum = 0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            if(rounds[i][j] == 0) continue;
            cnt++; sum += rounds[i][j];
        }
    }
    if(cnt == 0LL) return;
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            if(rounds[i][j] == 0) continue;
            if((long long)rounds[i][j]*cnt > sum){
                rounds[i][j] -= 1;
            }
            else if((long long)rounds[i][j]*cnt < sum){
                rounds[i][j] += 1;
            }
        }
    }
}
int main(){
    cin >> N >> M >> T;
    vector<vector<int>> rounds(N+1, vector<int>(M));
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            cin >> rounds[i][j];
        }
    }
    while(T--){
        int x, d, k; cin >> x >> d >> k;
        for(int i = x; i<=N; i+=x){
            move(rounds, i, d, k);
        }
        bool removed = remove(rounds);
        if(!removed){
            adjust(rounds);
        }
    }
    int answer = 0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            answer += rounds[i][j];
        }
    }
    cout << answer << '\n';
    return 0;
}
