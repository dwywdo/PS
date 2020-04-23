#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T = 0;
bool check(const string& pattern, const string& target){
    int pos = 0;
    while(pos < pattern.size() && pos < target.size() && (pattern[pos] == '?' || pattern[pos] == target[pos])){
        ++pos;
    }
    if(pos == pattern.size()){
        return pos == target.size();
    }
    if(pattern[pos] == '*'){
        for(int skip=0; pos+skip <= target.size(); ++skip){
            if(check(pattern.substr(pos+1), target.substr(pos+skip))){
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        string pattern = ""; cin >> pattern;
        int N = 0; cin >> N; 
        vector<string> targets;
        for(int i=0; i<N; i++){
            string target = ""; cin >> target;
            targets.push_back(target);
        }
        vector<string> matches;
        for(int i=0; i<N; i++){
            string str = targets[i];
            if(check(pattern, str)) matches.push_back(str);
        }
        sort(matches.begin(), matches.end());
        for(int i=0; i<matches.size(); i++){
            cout << matches[i] << "\n";
        }

    }
    return 0;

}