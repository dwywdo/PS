#include <iostream>
using namespace std;
int T;
int M, N, x, y;
int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> M;
        cin >> N;
        cin >> x;
        cin >> y;
        int day_x = 0;
        int day_y = 0;
        int day = 0;
        bool found = false;
        while(!(day_x == M && day_y == N)){
            day++;
            if(day_x < M){
                day_x++;
            }
            else{
                day_x = 1;
            }

            if(day_y < N){
                day_y++;
            }
            else{
                day_y = 1;
            }
            if(day_x == x && day_y == y){
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