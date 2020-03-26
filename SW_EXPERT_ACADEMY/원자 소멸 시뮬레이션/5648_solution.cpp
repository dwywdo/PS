#include <iostream>
#include <vector>
using namespace std;
int T; int N;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
typedef struct atom{
    int x = 0;
    int y = 0;
    int d = 0;
    int k = 0;
}ATOM;
ATOM atoms[1000];
int visited[4002][4002];
bool check[4002][4002];
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N; int cnt = N;
        int answer = 0;
        for(int i=0; i<N; i++){
            int input_x, input_y, input_d, input_k; 
            cin >> input_x >> input_y >> input_d >> input_k;
            atoms[i].x = input_x + 1000;
            atoms[i].y = input_y + 1000;
            atoms[i].d = input_d;
            atoms[i].k = input_k;
        }
        for(int i=0; i<N; i++){
            atoms[i].y *= 2; atoms[i].x *=2;
            visited[atoms[i].x][atoms[i].y]++;
        }
        int limit = 4002;
        for(int i=0; i<limit; i++){
            for(int j=0; j<cnt; j++){
                int &x = atoms[j].x; int &y = atoms[j].y;
                int d = atoms[j].d;
                visited[x][y] --;
                if(d==0) y++;
                else if(d==1) y--;
                else if(d==2) x--;
                else if(d==3) x++;

                if(x<0 || x>4000 || y<0 || y>4000){
                    int lastindex = cnt - 1;
                    atoms[j].x = atoms[lastindex].x;
                    atoms[j].y = atoms[lastindex].y;
                    atoms[j].d = atoms[lastindex].d;
                    atoms[j].k = atoms[lastindex].k;
                    cnt--;
                    j--;
                }
                else{
                    visited[x][y]++;
                    if(visited[x][y] >= 2) check[x][y] = true;
                }
            }
            for(int j=0; j<cnt; j++){
                int x = atoms[j].x; int y = atoms[j].y;
                if(check[x][y]){
                    if(visited[x][y] == 1) check[x][y] = false;
                    visited[x][y]--;
                    answer += atoms[j].k;
                    int lastindex = cnt - 1;
                    atoms[j].x = atoms[lastindex].x;
                    atoms[j].y = atoms[lastindex].y;
                    atoms[j].d = atoms[lastindex].d;
                    atoms[j].k = atoms[lastindex].k;
                    cnt--;
                    j--;
                }
            }
            if(cnt == 0) break;
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}