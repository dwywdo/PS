#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, C;
vector<char> chars;
vector<char> chosen;
bool ischosen[16];
bool check(vector<char> chosen){
    // 1개의 모음과 2개의 자음
    int v_count = 0;
    int c_count = 0;
    for(int i=0; i<chosen.size(); i++){
        char c = chosen[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            v_count++;
        }
        else{
            c_count++;
        }
    }
    return v_count >= 1 && c_count >= 2;
}
void choose(int c, int start){
    if(chosen.size() == c) {
        if(check(chosen)){
            for(int i=0; i<chosen.size(); i++){
                cout << chosen[i];
            }
            cout << endl;
            return;
        }
        else return;
    }
    for(int i=start; i<L; i++){
        if(ischosen[i]) continue;
        if(chosen.size() >= 1 && chosen[chosen.size()-1] >= chars[i]) continue;
        ischosen[i] = true;
        chosen.push_back(chars[i]);
        choose(c, start + 1);
        chosen.pop_back();
        ischosen[i] = false;
    }
    return;
}
int main(){
    cin >> C;
    cin >> L;
    for(int i=0; i<L; i++){
        char c;
        cin >> c;
        chars.push_back(c);
    }
    sort(chars.begin(), chars.end());
    choose(C, 0);

    return 0;
}