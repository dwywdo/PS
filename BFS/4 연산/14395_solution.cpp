#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
long long s = 0; long long t = 0;
const long long limit = 1000000000LL;
vector<string> answers;
// 만들어지는 수가 10억개에 딱 맞게 나올까? 그렇지 않다.. visited를 전부 만드는 것은 에바
// 그러지 말고 셋을 이용해서 중복체크를 하자(방문이 되었는지 안되었는지를 set.count() 함수의 결과값으로 판단하자)
int main(){
    cin >> s >> t;
    set<long long> check;
    queue<pair<long long, string>> q;
    q.push(make_pair(s, ""));
    check.insert(s);
    while(!q.empty()){
        long long x = q.front().first;
        string str = q.front().second;
        q.pop();
        if(x==t){
            if(str.length() == 0) str = "0";
            cout << str << endl;
            return 0;
        }
        if(0<=x*x && x*x <= limit && check.count(x*x) == 0){
            q.push(make_pair(x*x, str+"*"));
            check.insert(x*x);
        }
        if(0<=x+x && x+x <= limit && check.count(x+x) == 0){
            q.push(make_pair(x+x, str+"+"));
            check.insert(x+x);
        }
        if(0<=x-x && x-x <= limit && check.count(x-x) == 0){
            q.push(make_pair(x-x, str+"-"));
            check.insert(x-x);
        }
        if(x!=0){
            if(0<=x/x && x/x<= limit && check.count(x/x) == 0){
                q.push(make_pair(x/x, str+"/"));
                check.insert(x/x);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}