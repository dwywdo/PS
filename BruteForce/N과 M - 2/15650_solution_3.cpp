#include <iostream>
using namespace std;
int n, m;
bool check[10];
int chosen[10];
void choose(int idx, int selected, int n, int m){
    if(selected == m){
        for(int i=0; i<m; i++){
            cout << chosen[i] << " ";
        }
        cout << '\n';
        return;
    }
    if(idx > n){
        return;
    }
    chosen[selected] = idx;
    choose(idx + 1, selected + 1, n, m);
    chosen[selected] = 0;
    choose(idx + 1, selected, n, m);

}
int main(){
    cin >> n >> m;
    choose(1, 0, n, m);
    return 0;
}