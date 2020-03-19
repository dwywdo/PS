#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> chosen;
vector<int> numbers;
vector<vector<int> > chosenNumbers;
bool check[10];
void choose(int start, int n, int m){
    if(chosen.size() == m){
        vector<int> temp;
        for(int i=0; i<chosen.size(); i++){
            temp.push_back(chosen[i]);
        }
        chosenNumbers.push_back(temp);
        return;
    }
    for(int i=start; i<n; i++){
        if(check[i]) continue;
        check[i] = true;
        chosen.push_back(numbers[i]);
        choose(i, n, m);
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
    sort(chosenNumbers.begin(), chosenNumbers.end());
    chosenNumbers.erase(unique(chosenNumbers.begin(), chosenNumbers.end()), chosenNumbers.end());
    for(int i=0; i<chosenNumbers.size(); i++){
        for(int j=0; j<chosenNumbers[i].size();j++){
            cout << chosenNumbers[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}