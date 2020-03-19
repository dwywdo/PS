#include <iostream>
using namespace std;
int T;
int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        bool found = false;
        int day = 0;
        for(day = x; day < m*n; day+=m){
            int day_y = day % n == 0 ? n : day % n;
            if(day_y == y){
                found = true;
                break;
            }
        }
        if(found){
            cout << day << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}