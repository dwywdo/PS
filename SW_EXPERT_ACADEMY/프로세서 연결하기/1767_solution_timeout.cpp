#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 12
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int T, N;
int map[MAXN][MAXN];
int check[MAXN][MAXN];
bool iscore[MAXN][MAXN];
int setnumber = 0;
vector<pair<int, int>> cores;
int targetCount = 0;
int answerlength = 987654321;
int answercount = 0;
pair<int, int> connect(vector<int> &dirs, vector<pair<int, int>> &cores){
    int length[MAXN]; bool connectedCheck[MAXN];
    /*if(dirs[0] == 0 && dirs[1] == 1 && dirs[2] == 1 && dirs[3] == 0 && dirs[4] == 2 && dirs[5] == 1 && dirs[6] == 3){
        int temp = 0;
    }*/
    memset(check, -1, sizeof(check));
    for(int i=0; i<cores.size(); i++) {
        check[cores[i].first][cores[i].second] = i;
    }
    memset(length, 0, sizeof(length)); memset(connectedCheck, false, sizeof(connectedCheck));
    for(int i=0; i<cores.size(); i++){
        int d = dirs[i];
        int y = cores[i].first; int x = cores[i].second;
        if(y==0 || y==N-1 || x==0 || x==N-1){
            check[y][x] = i; length[i] = 0; connectedCheck[i] = true; 
            continue;
        }
        while(1){
            y += dy[d]; x += dx[d];
            if(check[y][x] != -1){
                if(iscore[y][x] == true){
                    connectedCheck[i] = false; break;
                }
                else{
                    connectedCheck[check[y][x]] = false;
                    connectedCheck[i] = false; break;
                }
            }
            else{
                check[y][x] = i;
            }
            if(y==0 || y==N-1 || x==0 || x==N-1){
                connectedCheck[i] = true; length[i] = abs(cores[i].first - y) + abs(cores[i].second - x);
                break;
            }
        }
    }
    int connectcount = 0; int totallength = 0;
    for(int i=0; i<MAXN; i++){
        if(connectedCheck[i]) {
            connectcount++; totallength += length[i];
        }
    }
    return make_pair(connectcount, totallength);
}
void choosedirection(vector<int> &dirs, int howmany){
    if(howmany == dirs.size()){
        /*cout << ++setnumber << ": ";
        for(int i=0; i<dirs.size(); i++){
            cout << dirs[i] << " ";
        }
        cout << "\n";*/
        pair<int, int> result = connect(dirs, cores);
        int cnt = result.first; int tl = result.second;
        if(answercount < cnt){ // 더 많이 연결할 수 있으면
            answercount = cnt; answerlength = tl;
        }
        else if  (answercount == cnt){
            if(answerlength > tl) answerlength = tl;
        }
        return;
    }
    for(int i=0; i<4; i++){
        dirs.push_back(i);
        choosedirection(dirs, howmany);
        dirs.pop_back();
    }
    return;
}
int main(){
    scanf("%d", &T);
    for(int test_case=1; test_case<=T; test_case++){
        scanf("%d", &N);
        cores.clear();
        memset(iscore, false, sizeof(iscore));
        answerlength = 987654321; answercount = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &map[i][j]);
                if(map[i][j] == 1) {
                    cores.push_back(make_pair(i, j)); iscore[i][j] = true;
                }
            }
        }
        targetCount = cores.size();
        vector<int> dirs;
        choosedirection(dirs, targetCount);
        cout << "#" << test_case << " " << answerlength << "\n";
    }
    return 0;
}