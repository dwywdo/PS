#include <iostream>
#include <vector>
using namespace std;
int K; int N;
vector<int> lines;
long long maximum = 0;
long long answer = 0;
int cut(int unit){
    int result = 0;
    for(int i=0; i<lines.size(); i++){
        result += lines[i] / unit;
    }
    return result;
}
// 랜선 하나는 int 안에 들어오지만 랜선이 10,000개이고 이걸 다 1cm짜리로 자른다고 치면 10,000 × (231 − 1)조각이 나오므로 안됩니다.
int main(){
    cin >> K >> N;
    for(int i=0; i<K; i++){
        int line; cin >> line;
        lines.push_back(line);
        if(maximum < line) maximum = line;
    }
    long long left = 1; long long right = maximum;
    while(left <= right){
        long long mid = (left + right)/2;
        long long count = cut(mid);
        if(count >= N){
            // 갯수가 N개보다 같거나 많으면, 더 긴 길이로 잘라보기 위해 right 쪽으로..
            left = mid + 1;
            if(mid > answer) answer = mid;
        }
        else{
            // 갯수가 N개보다 작다면, 더 작은 길이로 잘라야 N개를 넘길 수 있다.
            right = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}