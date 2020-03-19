include <iostream>
using namespace std;
int E;
int S;
int M;
int main(){
    cin >> E;
    cin >> S;
    cin >> M;
    int e = 1;
    int s = 1;
    int m = 1;
    int day = 1;
    do{
        if(e==E && s==S && m==M){
            cout << day << endl;
            break;
        }
        day++;
        e++;
        s++;
        m++;
        if(e == 16){
            e = 1;
        }
        if(s == 29){
            s = 1;
        }
        if(m == 20){
            m = 1;
        }
    }while(1);
    return 0;
}
