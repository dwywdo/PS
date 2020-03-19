#include <iostream>
#include <vector>
using namespace std;
string form = "";
vector<string> answers;
void go(string& board, int idx, int count){
    if(board.size() == count){
        answers.push_back(board);
        return;
    }
    if(form[idx] == 'c'){
        for(int i='a'; i<='z'; i++){
            if(idx - 1 >= 0 && board[idx-1] != i){
                board.push_back(i);
                go(board, idx + 1, count);
                board.pop_back();
            }
            else if(idx == 0){
                board.push_back(i);
                go(board, idx + 1, count);
                board.pop_back();
            }
        }
    }
    else if(form[idx] == 'd'){
        for(int i=0; i<=9; i++){
            if(idx - 1 >= 0 && board[idx-1] != i+'0'){
                board.push_back(i+'0');
                go(board, idx + 1, count);
                board.pop_back();
            }
            else if(idx == 0){
                board.push_back(i+'0');
                go(board, idx + 1, count);
                board.pop_back();
            }
        }
    }
}
int main(){
    cin >> form;
    string result = "";
    go(result, 0, form.size());
    cout << answers.size() << endl;

    return 0;
}