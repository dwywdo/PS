#include <iostream>
using namespace std;
int n, m;
bool check[9];
int chosenList[9];
void choose(int count, int start, int n, int m){
    if(count == m){
        for(int i=0; i<m; i++){
            cout << chosenList[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=start; i<=n; i++){
        if(check[i]) continue;
        check[i] = true;
        chosenList[count] = i;
        choose(count + 1, i+1, n, m);
        check[i] = false;
    }
}
int main(){
    cin >> n >> m;
    choose(0, 1, n, m);
    return 0;
}