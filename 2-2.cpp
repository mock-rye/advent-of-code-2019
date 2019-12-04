#include <iostream>
#include <vector>
using namespace std;

int opc(vector<int> opcode){
	bool a = 0;
	for(int i = 0; i < opcode.size(); i+=4){
		if(a) break;
		switch(opcode[i]){
			case 1:
				opcode[opcode[i+3]] = opcode[opcode[i + 1]] + opcode[opcode[i + 2]];
				break;
			case 2:
				opcode[opcode[i+3]] = opcode[opcode[i + 1]] * opcode[opcode[i + 2]];
				break;
			case 99:
				a = true;
				break;
			default:
				a = true;
				break;
		}
	}
	return opcode[0];
}

int main(){
	vector<int> opcode;
	freopen("input2.txt","r",stdin);
	int n;
	while(cin >> n){
		opcode.push_back(n);
	}
	for(int i = 0; i < opcode.size(); ++i){
		opcode[1] = i;
		for(int j = 0; j < opcode.size(); ++j){
			opcode[2] = j;
			if(opc(opcode) == 19690720) cout << i*100 + j << endl;
		}
	}
	return 10;
}
