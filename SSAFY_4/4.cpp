#include <iostream>
#include <vector>
vector<int> input;
int N = 0;
using namespace std;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int data = 0;
        cin >> data;
        input.push_back(data);
    }
    return 0;
}