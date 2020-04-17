#include <iostream>
#include <set>
using namespace std;
int T = 0;
set<string> check;
int go(string &board, int cnt, int n){
    if(cnt == n){
        return stoi(board);
    }
    if(check.count(board) != 0) return 0;
    check.insert(board);
    int maxvalue = 0;
    for(int i=0; i<board.size() - 1; i++){
        for(int j=i+1; j<board.size(); j++){
            char temp = board[i];
            board[i] = board[j];
            board[j] = temp;
            maxvalue = max(maxvalue, go(board, cnt + 1, n));
            temp = board[i];
            board[i] = board[j];
            board[j] = temp;
        }
    }
    return maxvalue;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        string board = ""; int n = 0;
        cin >> board >> n; check.clear();
        int answer = go(board, 0, n);
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}