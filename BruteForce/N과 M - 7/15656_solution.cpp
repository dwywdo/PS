#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> numbers;
vector<int> chosen;
void choose(int n, int m){
    if(chosen.size() == m){
        for(int i=0; i<chosen.size(); i++){
            cout << chosen[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        chosen.push_back(numbers[i]);
        choose(n, m);        
        chosen.pop_back();
    }
    return;
}
int main(){
    cin >> n;
    cin >> m;
    for(int i=0; i < n; i++){
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    sort(numbers.begin(), numbers.end());
    choose(n, m);
    return 0;
}

