#include <iostream>
#include <queue>
using namespace std;
struct node{
    int first;int second;
};
bool operator < (node a, node b){
    return a.first > b.second;
}
int main(){
    return 0;
}