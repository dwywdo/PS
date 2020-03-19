#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N = 0;
vector<string> words;
vector<char> all;
char conversion[256];
int answer = 0;
/* void go(int index, int len){
	if(index == all.size()){
		int sum = 0;
		for(int i=0; i<words.size(); i++){
			int subsum = 0;
			for(int j=0; j<words[i].size(); j++){
				subsum += conversion[words[i][j]-'A'] * pow(10, words[i].size() - j - 1);
			}
			sum += subsum;
		}
		if(answer < sum) answer = sum;
		return;
	}
	int alphabet = all[index] - 'A';
	if(conversion[alphabet]!=-1){
		go(index+1, len);
	}
	else{
		for(int i=9; i>9-len; i--){
			if(check[i]) continue;
			check[i] = true;
			conversion[alphabet] = i;
			go(index + 1, len);
			check[i] = false;
			conversion[alphabet] = -1;
		}
	}
	return;
} */
int cal(vector<string> &words, vector<char> &chars, vector<int> &d){
	int len = chars.size();
	int sum = 0;
	for(int i=0; i<len; i++){
		conversion[chars[i]] = d[i];
	}
	for(string word : words){
		int subsum = 0;
		for(char c : word){
			subsum = subsum * 10 + conversion[c];
		}
		sum += subsum;
	}
	return sum;
}
int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		string word = ""; cin >> word;
		words.push_back(word);
		for(int j=0; j<word.size(); j++){
			all.push_back(word[j]);
		}
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	int len = all.size();

	vector<int> d;
	for(int i=9; i>9-len; i--) d.push_back(i);
	sort(d.begin(), d.end());
	int answer = 0;
	do{
		int now = cal(words, all, d);
		if(answer < now){
			answer = now;
		}
	}while(next_permutation(d.begin(), d.end()));
	// go(0, len);
	cout << answer << endl;
	return 0;

}
