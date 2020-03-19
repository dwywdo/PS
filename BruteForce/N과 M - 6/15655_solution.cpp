#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n; int m;
vector<int> numbers;
vector<int> chosen;
bool check[10];
void choose(int start, int n, int m){
    if(chosen.size() == m){
        for(int i=0; i<chosen.size(); i++){
            cout << chosen[i] << " ";
        }
        cout << "\n";
    }
    for(int i = start; i<n; i++){
        if(check[i]) continue;
        check[i] = true;
        chosen.push_back(numbers[i]);
        
        choose(i+1, n, m);

        check[i] = false;
        chosen.pop_back();
    }
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