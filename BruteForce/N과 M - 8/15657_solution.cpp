#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> numbers;
vector<int> chosen;
int n, m;
void choose(int start, int n, int m){
    if(chosen.size() == m){
        for(int i=0; i<chosen.size(); i++){
            cout << chosen[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=start; i<n; i++){
        chosen.push_back(numbers[i]);
        choose(i, n, m);
        chosen.pop_back();
    }
    return;
}
int main(){
    cin >> n; 
    cin >> m;
    for(int i=0; i<n; i++){
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    sort(numbers.begin(), numbers.end());
    choose(0, n, m);
    return 0;
}