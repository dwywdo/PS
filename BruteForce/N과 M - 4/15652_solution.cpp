#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> chosen;
void choose(int count, int start, int n, int m){
    if(count == m){
        for(int i=0; i<chosen.size(); i++){
            cout << chosen[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=start; i<=n; i++){
        chosen.push_back(i);
        choose(count + 1, i, n, m);
        chosen.pop_back();
    }
}
int main(){
    cin >> N;
    cin >> M;
    choose(0, 1, N, M);
    return 0;
}