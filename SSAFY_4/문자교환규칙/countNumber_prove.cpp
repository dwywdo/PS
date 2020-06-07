#include <iostream>
#include <string>
using namespace std;
string maximum;
string target;
int main(){
    cin >> maximum;
    cin >> target;
    char target_char = target[0];
    int max_int = stoi(maximum);
    int answer = 0;
    for(int i=1; i<=max_int; i++){
        string str = to_string(i);
        for(int i=0; i<str.size(); i++){
            if(target_char == str[i]) answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}