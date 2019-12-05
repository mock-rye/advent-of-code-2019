#include <iostream>
#include <vector>
using namespace std;

int f(int a){
	return (int)(a/3)-2;
}

int main(){
	freopen("input1.txt","r",stdin);
	int n, fcu;
	vector<int> a;
	while(cin >> n){
		a.push_back(n);
	}
	for(int i = 0; i < a.size(); ++i){
		fcu += f(a[i]);
	}
	cout << fcu << endl;
	return 0;
}
