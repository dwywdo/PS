#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int T;
bool check[12];
int N, W, H; 
vector<vector<int>> arr(15, vector<int>(12, 0));
int dy[4] = {-1, 1, 0, 0}; // 위 아래 왼쪽 오른쪽
int dx[4] = {0, 0, -1, 1};
int answer = 15 * 12;
// 선택된 구슬 쏘는 순서에 따라서 시뮬레이션을 진행하는 함수
int go(vector<int> &chosen){
    vector<vector<int>> copyarr(arr); // 배열 복사

    // BFS 진행
    queue<pair<int, int>> q;
    for(int i=0; i<chosen.size(); i++){
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        int col = chosen[i]; int rowindex = 0;
        bool isfound = false;
        vector<pair<int, int>> blocks;
        // 해당 열에서 가장 위에있는 블록(0이 아닌 값)을 찾는다.
        for(int r=0; r<H; r++){
            if(copyarr[r][col] != 0){
                isfound = true; 
                q.push(make_pair(r, col));
                visited[r][col] = true;
                blocks.push_back(make_pair(r, col)); // 동시에 부숴지게 될 블록들의 좌표를 저장
                break;
            }
        }
        // 못찾았으면 구슬을 쏘아서 부술 수 있는 블록이 없는 것이므로 다음 순서 진행
        if(isfound == false) continue;
        
        while(!q.empty()){
            int y = q.front().first; int x = q.front().second; q.pop();
            int v = copyarr[y][x];
            for(int k=0; k<4; k++){
                for(int l=1; l<v; l++){
                    int ny = y + l*dy[k];
                    int nx = x + l*dx[k];
                    if(ny>=0 && ny<H && nx>=0 && nx<W){
                        if(visited[ny][nx]) continue;
                        if(copyarr[ny][nx] == 0) continue;
                        visited[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                        blocks.push_back(make_pair(ny, nx));
                    }
                }
            }
        }
        for(auto &p : blocks) copyarr[p.first][p.second] = 0; // 부숴질 블록을 부숨

        // 블록들을 부순 후, 빈 공간이 생겼을 때 내리는 로직 
        for (int i = 0; i < W; i++) {
            for (int j = H-1; j >=1; j--) {
                for (int k = j - 1; k >= 0; k--) {
                    if (copyarr[j][i] != 0) break;
                    if (copyarr[k][i] != 0) {
                        copyarr[j][i] = copyarr[k][i];
                        copyarr[k][i] = 0;
                        break;
                    }
                }
            }
        }
        // 시간 초과가 났던 부분
        /*for(int j=0; j<W; j++){
            vector<int> numbers;
            for(int i=H-1; i>=0; i--){
                if(copyarr[i][j] != 0) numbers.push_back(copyarr[i][j]);
                copyarr[i][j] = 0;
            }
            for(int i=0; i<numbers.size(); i++) copyarr[H-1-i][j] = numbers[i];
        }*/
    }
    int cnt = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(copyarr[i][j] != 0) cnt++;
        }
    }
    return cnt;
}
int choose(int idx, int howmany, int W, vector<int> &chosen){
    if(chosen.size() == howmany){
        int res = go(chosen);
        return res;
    }
    int ans = W*H;
    for(int i=0; i<W; i++){
        chosen.push_back(i);
        int res = choose(idx + 1, howmany, W, chosen);
        chosen.pop_back();
        if(ans > res) ans = res;
        if(ans == 0) break;
    }
    return ans;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N >> W >> H; answer = W*H;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin >> arr[i][j];
            }
        }
        memset(check, false, sizeof(check));
        vector<int> chosen;
        printf("#%d %d\n", test_case, choose(0, N, W, chosen));
    }
    return 0;
}
