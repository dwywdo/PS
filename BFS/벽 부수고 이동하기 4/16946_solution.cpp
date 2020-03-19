#include <iostream>
#include <queue>
#include <set>
using namespace std;
int map[1000][1000];
int g[1000][1000];
bool visited[1000][1000];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<int> groups_info;
int N; int M;
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &map[i][j]);
            g[i][j] = -1;
        }
    }
    int group_number = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 1 || visited[i][j]) continue;
            int group_size = 0;
            queue<pair<int, int>> q;
            visited[i][j] = true;
            g[i][j] = group_number; group_size++;
            q.push(make_pair(i, j)); 
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if(nx>=0 && nx<M && ny>=0 && ny<N && map[ny][nx] == 0){
                        if(visited[ny][nx]) continue;
                        visited[ny][nx] = true;
                        g[ny][nx] = group_number;
                        group_size++;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
            groups_info.push_back(group_size);
            group_number++;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 1){
                set<int> groups;
                for(int k=0; k<4; k++){
                    int ny = i + dy[k]; int nx = j + dx[k];
                    if(nx>=0 && nx<M && ny>=0 && ny<N && g[ny][nx] != -1){
                        groups.insert(g[ny][nx]);
                    }
                }
                int sum = 1;
                for(int g : groups){
                    sum += groups_info[g];
                }
                map[i][j] = sum % 10;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}

