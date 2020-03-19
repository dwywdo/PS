#include <iostream>
using namespace std;
int T[15];
int P[15];
int N;
int answer = 0;
void choose(int day, int sum){
    if (day == N){
        if (sum > answer){
            answer = sum;
        }
        return;
    }
    if (day > N){
        return;
    }
    choose(day+T[day], sum+P[day]);
    choose(day+1, sum);

}
int main(){
    cin >> N;
    for(int i=0; i < N; i++){
        cin >> T[i];
        cin >> P[i];
    }
    choose(0, 0);
    cout << answer << endl;

    return 0;
}