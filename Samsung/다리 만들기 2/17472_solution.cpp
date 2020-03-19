#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[10][10];
int group[10][10];
bool visited[10][10];
vector<vector<int>> costs;
int N, M;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool compare(vector<int> &a, vector<int> &b){
    return a[2] < b[2]; 
}
int getParent(int set[], int x){
    if(set[x] == x) return x;
    set[x] = getParent(set, set[x]);
    return set[x];
}
void unionParent(int set[], int a, int b){
    a = getParent(set, a);
    b = getParent(set, b);
    if(a < b) set[b] = a;
    else set[a] = b;
}
bool find(int set[], int a, int b){
    a = getParent(set, a);
    b = getParent(set, b);
    return a == b;
}
int grouping(){
    int groupNumber = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0) continue;
            if(visited[i][j]) continue;
            queue<pair<int, int>> q;
            visited[i][j] = true;
            q.push(make_pair(i, j));
            group[i][j] = groupNumber;
            while(!q.empty()){
                int y = q.front().first; int x = q.front().second; q.pop();
                for(int k=0; k<4; k++){
                    int ny = y + dy[k]; int nx = x + dx[k];
                    if(ny>=0 && ny<N && nx>=0 && nx<M && !visited[ny][nx] && map[ny][nx] != 0){
                        group[ny][nx] = groupNumber; visited[ny][nx] = groupNumber;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
            groupNumber++;
        }
    }
    return groupNumber - 1;
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> map[i][j];
    int groupCount = grouping();
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0) continue;
            int source_group = group[i][j];
            for(int k=0; k<4; k++){
                int y = i; int x = j;
                int cost = 0;
                int target_group = 0;
                while(1){
                    y = y + dy[k]; x = x + dx[k];
                    if(y>=0 && y<N && x>=0 && x<M){
                        if(map[y][x] != 0){
                            if(group[y][x] == source_group) break;
                            target_group = group[y][x]; break;
                        }
                        else cost++;
                    }
                    else break;
                }
                if(target_group == 0) continue;
                vector<int> v; 
                if(cost == 1) continue;
                v.push_back(source_group); v.push_back(target_group); v.push_back(cost);
                costs.push_back(v);
            }
        }
    }
    int answer = 0;
    costs.erase(unique(costs.begin(), costs.end()), costs.end());
    sort(costs.begin(), costs.end(), compare);
    /*for(int i=0; i<costs .size(); i++){
        cout << costs[i][0] << "-" << costs[i][1] << ": " << costs[i][2] << endl;
    }*/
    int set[10];
    int connCount = 1;
    for(int i=0; i<10; i++) set[i]= i;
    for(int i=0; i<costs.size(); i++){
        int from = costs[i][0]; int to = costs[i][1]; int cost = costs[i][2];
        if(!find(set, from, to)){
            answer += cost; connCount++;
            unionParent(set,  from, to);
        }
    }
    
    if(groupCount != connCount){
        cout << -1 << endl; return 0;
    }
    else cout << answer << endl;
    return 0;
}