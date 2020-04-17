#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T = 0;
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        string tc; int len = 0; cin >> tc >> len;
        vector<int> numbers;
        for(int i=0; i<len; i++){
            string strnum; cin >> strnum;
            if(strnum == "ZRO"){
                numbers.push_back(0);
            }
            if(strnum == "ONE"){
                numbers.push_back(1);
            }
            if(strnum == "TWO"){
                numbers.push_back(2);
            }
            if(strnum == "THR"){
                numbers.push_back(3);
            }
            if(strnum == "FOR"){
                numbers.push_back(4);
            }
            if(strnum == "FIV"){
                numbers.push_back(5);
            }
            if(strnum == "SIX"){
                numbers.push_back(6);
            }
            if(strnum == "SVN"){
                numbers.push_back(7);
            }
            if(strnum == "EGT"){
                numbers.push_back(8);
            }
            if(strnum == "NIN"){
                numbers.push_back(9);
            }
        }
        sort(numbers.begin(), numbers.end());
        cout << tc << "\n";
        for(int i=0; i<numbers.size(); i++){
            int number = numbers[i];
            switch(number){
                case 0:
                cout << "ZRO" << " ";
                break;
                case 1:
                cout << "ONE" << " ";
                break;
                case 2:
                cout << "TWO" << " ";
                break;
                case 3:
                cout << "THR" << " ";
                break;
                case 4:
                cout << "FOR" << " ";
                break;
                case 5:
                cout << "FIV" << " ";
                break;
                case 6:
                cout << "SIX" << " ";
                break;
                case 7:
                cout << "SVN" << " ";
                break;
                case 8:
                cout << "EGT" << " ";
                break;
                case 9:
                cout << "NIN" << " ";
                break;
                default:
                break;
            }
        }
        cout << "\n";
    }
    return 0;
}