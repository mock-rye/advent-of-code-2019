#include <iostream>
#include <vector>
using namespace std;

int f(int a){
	if(a > 8) return (int)(a/3)-2 + f((int)(a/3)-2);
	return 0;
}
int main(){
	freopen("input1.txt","r",stdin);
	int n;
	long long int sum = 0L;
	while(cin >> n){
		sum += f(n);
	}
	cout << sum << endl;
	return 0;
}
