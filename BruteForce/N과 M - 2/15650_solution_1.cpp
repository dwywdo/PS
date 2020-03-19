#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> chosen;
bool check[10];
void choose(vector<int> chosen, int start, int n, int m)
{
    if(chosen.size() == m){
        for(int i=0; i<chosen.size(); i++){
            cout << chosen[i] << " ";
        }
        cout << '\n';
    }
    for(int i=start; i<=n; i++){
        if(check[i]) continue;
        check[i] = true;
        chosen.push_back(i);
        choose(chosen, i + 1, n, m);
        check[i] = false;
        chosen.pop_back();
    }
}
int main(){
    cin >> n >> m;
    choose(chosen, 1, n, m);
    return 0;
}