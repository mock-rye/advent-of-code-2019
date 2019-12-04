#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> opcode;
	freopen("input2.txt","r",stdin);
	int n;
	while(cin >> n){
		opcode.push_back(n);
	}
	bool a = 0;
	for(int i = 0; i < opcode.size()/4; ++i){
		if(a) break;
		switch(opcode[4*i]){
			case 1:
				opcode[opcode[4*i+3]] = opcode[opcode[4*i + 1]] + opcode[opcode[4*i + 2]];
				break;
			case 2:
				opcode[opcode[4*i+3]] = opcode[opcode[4*i + 1]] * opcode[opcode[4*i + 2]];
				break;
			case 99:
				a = true;
				break;
			default:
				a = true;
				break;
		}
	}
	cout << opcode[0] << endl;
}
