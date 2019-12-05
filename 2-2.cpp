#include <iostream>
#include <vector>
using namespace std;

int parse(vector<int> vi){ //reused from 2-1, tidied up based on my day 5 solutions
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
	vector<int> opcode;
	freopen("input2.txt","r",stdin); //you'll need to replace the commas with spaces beforehand
	int n;
	while(cin >> n){
		opcode.push_back(n);
	}
	for(int i = 0; i < opcode.size(); ++i){
		opcode[1] = i;
		for(int j = 0; j < opcode.size(); ++j){
			opcode[2] = j;
			if(parse(opcode) == 19690720) cout << i*100 + j << endl;
		}
	}
	return 0;
}
