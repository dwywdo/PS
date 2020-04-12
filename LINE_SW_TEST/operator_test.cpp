#include <iostream>
#include <queue>
using namespace std;
struct node{
    int first;int second;
};
bool operator < (pair<int, int> a, pair<int, int> b){
    return a.first > b.second;
}
int main(){
    return 0;
}