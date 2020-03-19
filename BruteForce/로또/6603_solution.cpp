#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt = 0;
int main(){
    while(1){
        cin >> cnt;
        if(cnt == 0){
            break;
        }
        vector<int> numbers;
        vector<int> idx;
        for(int i=0; i<cnt; i++){
            int number = 0;
            cin >> number;
            numbers.push_back(number);
        }
        for(int i=0; i<6; i++){
            idx.push_back(1);
        }
        for(int i=0; i<numbers.size()-6; i++){
            idx.push_back(0);
        }
        sort(numbers.begin(), numbers.end());
        
        do{
            vector<int> chosen;
            for(int i=0; i<numbers.size(); i++){
                if(idx[i] == 1){
                    chosen.push_back(numbers[i]);
                }
                else continue;
            }
            for(int i=0; i<chosen.size(); i++){
                cout << chosen[i] << " ";
            }
            cout << endl;
        }while(prev_permutation(idx.begin(), idx.end()));
        cout << endl;
    }
    return 0;
}