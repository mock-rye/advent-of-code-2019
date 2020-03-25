#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
	int counter = 0;
	char a;
	vector<int> v, k;
	int out[150] = {0};
	while(cin >> a){
		switch(a){
			case '0':
				v.push_back(0);
				break;
			case '1':
				v.push_back(1);
				break;
			case '2':
				v.push_back(2);
				break;
		}
		counter++;
	}
	for(int i = v.size() -1; i >= 0; --i){
		k.push_back(v[i]);
	}
	for(int i = 0; i < k.size(); ++i){
		if(k[i] == 2) continue;
		out[i%150] = k[i];
	}
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 25; ++j){
			switch(k[i*25+j]){
				case 0:
					cout << '+';
					break;
				case 1:
					cout << ' ';
					break;
				default:
					break;
			}
		}
		cout << endl;
	}
}

int main(){
	freopen("input8.txt","r",stdin);
	solve();
	return 0;
}


