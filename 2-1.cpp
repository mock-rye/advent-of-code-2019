#include <iostream>
#include <vector>
using namespace std;

int parse(vector<int> vi){
	int par1, par2, par3, i = 0;
	while(true){
		par1 = vi[i+1];
		par2 = vi[i+2];
		par3 = vi[i+3];
		switch(vi[i]){
			case 1:
				vi[par3] = vi[par1] + vi[par2];
				i += 4;
				break;
			case 2:
				vi[par3] = vi[par1] * vi[par2];
				i += 4;
				break;
			case 99:
				return vi[0];
				break;
			default:
				return vi[0];
				break;
		}
	}
}

int main(){
	vector<int> program;
	freopen("input2.txt","r",stdin); //you'll need to replace the commas with spaces beforehand
	int n;
	while(cin >> n){
		program.push_back(n);
	}
	cout << parse(program) << endl;
}
