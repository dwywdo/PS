#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> chosen;
vector<string> ans;
int k = 0;
char signs[9];
bool check[10];
void choose(int count, int k){
    if(count == k){
        string number = "";
        for(int i=0; i<chosen.size(); i++){
            number += chosen[i] + '0';
        }
        ans.push_back(number);
        return;
    }
    for(int i=0; i<=9; i++){
        if(check[i]) continue;
        if(count >= 1){
            char sign = signs[count - 1];
            if (sign == '<' && chosen[count - 1] < i){
                check[i] = true;
                chosen.push_back(i);
                choose(count + 1, k);
                check[i] = false;
                chosen.pop_back();
            }
            else if (sign == '>' && chosen[count - 1] > i){
                check[i] = true;
                chosen.push_back(i);
                choose(count + 1, k);
                check[i] = false;
                chosen.pop_back();
            }
        }
        else if (count == 0){
            check[i] = true;
            chosen.push_back(i);
            choose(count + 1, k);
            check[i] = false;
            chosen.pop_back();
        }
        
    }
}
int main(){
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> signs[i];
    }
    choose(0, k+1);
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << endl;
    cout << *p.first << endl;
    return 0;
}
