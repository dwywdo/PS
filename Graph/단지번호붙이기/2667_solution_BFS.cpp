#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> counts;
int danjiCount = 0;
int N; int map[25][25]; bool visited[25][25];
// 상 하 좌 우
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]) continue;
            if(map[i][j] == 0) continue;
            queue<pair<int, int> > q;
            danjiCount++;
            int count = 1;
            visited[i][j] = true; 
            q.push(make_pair(i, j));
            while(!q.empty()){
                pair<int, int> point = q.front(); q.pop();
                int y = point.first; int x = point.second;
                for(int i=0; i<4; i++){
                    int ny = y + dy[i]; int nx = x + dx[i];
                    if(ny>=0 && ny<N && nx>=0 && nx<N && !visited[ny][nx] && map[ny][nx] == 1){
                        count++; visited[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
            counts.push_back(count);
        }
    }
    cout << danjiCount << endl;
    sort(counts.begin(), counts.end());
    for(int i=0; i<counts.size(); i++){
        cout << counts[i] << " " << endl;
    }
    return 0;
}