#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("input1.txt","r",stdin);
	int n, fcu;
	vector<int> a;
	while(cin >> n){
		a.push_back(n);
	}
	for(int i = 0; i < a.size(); ++i){
		fcu += (int)(a[i]/3)-2;
	}
	cout << fcu << endl;
	return 0;
}
