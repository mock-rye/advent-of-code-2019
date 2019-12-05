#include <iostream>
#include <vector>
using namespace std;
// Precomputes the vector for 5-1 and 5-2 so you can use manual input
void out(int i){
	cout << "diagnostic.push_back(" << i << ");\n";
}

int main(){
	vector<int> vect;
	freopen("input5.txt","r",stdin);
	freopen("cheat5.txt","w",stdout);
	int n;
	while(cin >> n){
		vect.push_back(n);
	}
	for(int i = 0; i < vect.size(); ++i){
		out(vect[i]);
	}
}
