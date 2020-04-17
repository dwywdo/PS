#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 100
int T = 10;
vector<int> xs;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
// 아래 왼쪽 오른쪽
int dy[3] = {1, 0, 0};
int dx[3] = {0, -1, 1};
int main(){
    for(int test_case=1; test_case<=T; test_case++){
        int tc = 0; cin >> tc;
        xs.clear();
        for(int i=0; i<MAXN; i++){
            for(int j=0; j<MAXN; j++){
                cin >> map[i][j];
                if(i==0 && map[i][j]==1){
                    xs.push_back(j);
                }
            }
        }
        int answerlength = 987654321;
        int answerx = -1;
        for(auto &p : xs){
            memset(visited, false, sizeof(visited));
            int d = 0;
            int y = 0; int x = p;
            visited[y][x] = true; int length = 1;
            while(y!=MAXN-1){
                y += dy[d]; x += dx[d];
                int right_y = y; int right_x = x+1;
                int left_y = y; int left_x = x-1;
                if(right_y>=0 && right_y<MAXN && right_x>=0 && right_x<MAXN && map[right_y][right_x] == 1 && !visited[right_y][right_x]){
                    d = 2;
                }
                else if(left_y>=0 && left_y<MAXN && left_x>=0 && left_x<MAXN && map[left_y][left_x] == 1 && !visited[left_y][left_x]){
                    d = 1;
                }
                else{
                    d = 0;
                }
                visited[y][x] = true; length++;
            }
            int candx = p; int candlength = length;
            int temp = 0;
            if(answerlength > length){
                answerx = p; answerlength = length;
            }
            else if(answerlength == length){
                if(answerx < p) answerx = p;
            }
        }
        cout << "#" << tc << " " << answerx << "\n";
    }
    return 0;
}