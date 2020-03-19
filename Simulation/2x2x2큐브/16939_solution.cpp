#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> cube(25, -1);
bool check(vector<int> cube){
    int side[6][4] = {
        {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17, 18, 19, 20}, {21, 22, 23, 24}
    };
    bool ok = true;
    for(int i=0; i<6; i++){
        if(!(cube[side[i][0]]==cube[side[i][1]] && cube[side[i][1]]==cube[side[i][2]]
        && cube[side[i][2]]==cube[side[i][3]] && cube[side[i][3]]==cube[side[i][0]])){
            ok = false; break;
        }
    }
    return ok;
}
vector<int> go(int type, int count){
    vector<int> result(cube);
    vector<int> group;
    vector<int> idxs;
    // 뒤쪽 돌리기
    if(type==0){
        idxs.push_back(1);idxs.push_back(2);idxs.push_back(18);idxs.push_back(20);
        idxs.push_back(12);idxs.push_back(11);idxs.push_back(15);idxs.push_back(13);
        for(int i=0; i<idxs.size(); i++) group.push_back(cube[idxs[i]]);
    }
    // 앞쪽 돌리기
    else if(type==1){
        idxs.push_back(3);idxs.push_back(4);idxs.push_back(17);idxs.push_back(19);
        idxs.push_back(10);idxs.push_back(9);idxs.push_back(16);idxs.push_back(14);
        for(int i=0; i<idxs.size(); i++) group.push_back(cube[idxs[i]]);
    }
    //오른쪽 돌리기
    else if(type==2){
        idxs.push_back(2);idxs.push_back(4);idxs.push_back(6);idxs.push_back(8);
        idxs.push_back(10);idxs.push_back(12);idxs.push_back(23);idxs.push_back(21);
        for(int i=0; i<idxs.size(); i++) group.push_back(cube[idxs[i]]);
    }
    //왼쪽돌리기
    else if(type==3){
        idxs.push_back(1);idxs.push_back(3);idxs.push_back(5);idxs.push_back(7);
        idxs.push_back(9);idxs.push_back(11);idxs.push_back(24);idxs.push_back(22);
        for(int i=0; i<idxs.size(); i++) group.push_back(cube[idxs[i]]);
    }
    //아랫쪽 돌리기
    else if(type==4){
        idxs.push_back(15);idxs.push_back(16);idxs.push_back(7);idxs.push_back(8);
        idxs.push_back(19);idxs.push_back(20);idxs.push_back(23);idxs.push_back(24);
        for(int i=0; i<idxs.size(); i++) group.push_back(cube[idxs[i]]);
    }
    //윗쪽 돌리기
    else if(type==5){
        idxs.push_back(13);idxs.push_back(14);idxs.push_back(5);idxs.push_back(6);
        idxs.push_back(17);idxs.push_back(18);idxs.push_back(21);idxs.push_back(22);
        for(int i=0; i<idxs.size(); i++) group.push_back(cube[idxs[i]]);
    }
    for(int i=0; i<count; i++){
        rotate(group.rbegin(), group.rbegin() + 2, group.rend());
        for(int j=0; j<8; j++){
            result[idxs[j]] = group[j];
        }
    }
    return result;
}
int main(){
    for(int i=1; i<=24; i++){
        int color = 0; cin >> color;
        cube[i] = color;
    }
    int answer = 0;
    for(int i=0; i<6; i++){
        vector<int> res = go(i, 1);
        if(check(res)){
            answer = 1; break;
        }
    }
    for(int i=0; i<6; i++){
        vector<int> res = go(i, 3);
        if(check(res)){
            answer = 1; break;
        }
    }
    cout << answer << '\n';
    return 0;
}