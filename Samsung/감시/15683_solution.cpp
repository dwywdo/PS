#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
vector<vector<int>> map(8, vector<int>(8, 0));
int N, M;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<int> dirs;
vector<tuple<int, int, int>> cams;
void search(vector<vector<int>> &map, vector<vector<int>> &copymap, int y, int x, int dir){
    int N = map.size();
    int M = map[0].size();
    int ny = y;
    int nx = x;
    while(0<=ny && ny<N && nx>=0 && nx<M){
        if(map[ny][nx] == 6) break;
        copymap[ny][nx] = map[y][x];
        ny += dy[dir];
        nx += dx[dir];
    }
}
int go(vector<vector<int>> &map, vector<tuple<int, int, int>> &cams, int index, vector<int> dirs){
    if(cams.size() == index){
        vector<vector<int>> copymap(map);
        for(int i=0; i<cams.size(); i++){
            int y = get<0>(cams[i]);
            int x = get<1>(cams[i]);
            int type = get<2>(cams[i]);
            if(type == 1){
                search(map, copymap, y, x, dirs[i]);
            }
            else if(type == 2){
                search(map, copymap, y, x, dirs[i]);
                search(map, copymap, y, x, (dirs[i] + 2)%4);
            }
            else if(type == 3){
                search(map, copymap, y, x, dirs[i]);
                search(map, copymap, y, x, (dirs[i]+1)%4);
            }
            else if(type == 4){
                search(map, copymap, y, x, dirs[i]);
                search(map, copymap, y, x, (dirs[i]+1)%4);
                search(map, copymap, y, x, (dirs[i]+2)%4);
            }
            else if(type == 5){
                search(map, copymap, y, x, dirs[i]);
                search(map, copymap, y, x, (dirs[i]+1)%4);
                search(map, copymap, y, x, (dirs[i]+2)%4);
                search(map, copymap, y, x, (dirs[i]+3)%4);
            }
        }
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(copymap[i][j] == 0) cnt+=1;
            }
        }
        return cnt;
    }
    int answer = 64;
    for(int i=0; i<4; i++){
        dirs[index] = i;
        int temp = go(map, cams, index + 1, dirs);
        if(answer > temp) answer = temp;
    }
    return answer;
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6){
                cams.push_back(make_tuple(i, j, map[i][j]));
                dirs.push_back(0);
            }
        }
    }
    vector<vector<int>> copy(N, vector<int>(M, 0));
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) copy[i][j] = map[i][j];
    cout << go(map, cams, 0, dirs) << '\n';
    return 0;
}