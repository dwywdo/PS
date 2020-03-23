#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define BORDER 2
int T, N, M;
bool check[50];
vector<vector<char>> board(50, vector<char>(50, 0));
int answer = 2500;
int coloring(vector<int> &chosen){
    int cnt = 0;
    int a = chosen[0]; int b = chosen[1];
    for(int i=0; i<a; i++){
        for(int j=0; j<M; j++) if(board[i][j] != 'W') cnt++;
    }
    for(int i=a; i<b; i++){
        for(int j=0; j<M; j++) if(board[i][j] != 'B') cnt++;
    }
    for(int i=b; i<N; i++){
        for(int j=0; j<M; j++) if(board[i][j] != 'R') cnt++;
    }
    return cnt;
}
void choose(int start, vector<int> &chosen){
    if(chosen.size() == BORDER){
        /* for(int i=0; i<chosen.size(); i++){
            cout << chosen[i] << " ";
        }
        cout << '\n'; */
        int result = coloring(chosen);
        if(result < answer) answer = result;
        return;
    }
    for(int i=start; i<N; i++){
        if(check[i]) continue;
        check[i] = true;
        chosen.push_back(i);
        choose(i + 1, chosen);
        check[i] = false;
        chosen.pop_back();
    }
    return;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N >> M;
        memset(check, false, sizeof(check));
        vector<vector<char>> input(50, vector<char>(50, 0));
        answer = 2500;
        for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> input[i][j];
        board = input;
        vector<int> chosen;
        choose(1, chosen);
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}