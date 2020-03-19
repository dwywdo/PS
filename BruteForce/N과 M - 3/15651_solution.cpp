#include <iostream>
#include <vector>
using namespace std;
vector<int> chosen;
void choose(int count, int n, int m){
    if(chosen.size() == m){
        for(int i=0; i<chosen.size(); i++){
            cout << chosen[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        chosen.push_back(i);
        choose(count + 1, n, m);
        chosen.pop_back();
    }
    return;
}
int main(){
    int N, M;
    cin >> N;
    cin >> M;
    choose(0, N, M);
    return 0;
}