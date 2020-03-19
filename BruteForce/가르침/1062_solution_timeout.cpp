#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
vector<char> alphabets;
vector<string> words;
int main(){
    for(int i=0; i<26; i++) alphabets.push_back(char('a'+i));
    cin >> N; cin >> K;
    for(int i=0; i<N; i++){
        string word; cin >> word;
        words.push_back(word);
    }
    vector<int> d;
    for(int i=0; i<K; i++) d.push_back(1);
    for(int i=0; i<26-K; i++) d.push_back(0);
    sort(d.begin(), d.end());
    int answer = 0;
    do{
        int canReadCount = 0;
        vector<bool> taught(26, false);
        for(int i=0; i<d.size(); i++)
            if(d[i] == 1) taught[i] = true;
        for(string &word : words){
            bool canRead = true;
            for(char &c : word){
                if(taught[c-'a']!=true){
                    canRead=false; break;
                }
                else continue;
            }
            if(canRead) canReadCount++;
        }
        if(answer < canReadCount) answer = canReadCount;
    }while(next_permutation(d.begin(), d.end()));

    cout << answer << endl;
    return 0;
}