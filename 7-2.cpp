#include <iostream>
#include <vector>
using namespace std;

class code{
public:
	int type;
	bool first, second;
	code(int _type, bool _first, bool _second){
		type = _type;
		first = _first;
		second = _second;
	}
};

code toCode(int eger){//works good
	return code(eger%100, (eger%1000)/100, (eger%10000)/1000);
}

class amplifier{
public:
	int phase, pointer = 0;
	vector<int> program;
	amplifier(int _phase, vector<int> _program){
		phase = _phase;
		program = _program;
	}
	amplifier(vector<int> _program){
		phase = 0;
		program = _program;
	}
	int parse(int input){
		//cout << "parsing: " << input << endl; //print debugging
		code cod(0,0,0);
		int par1, par2, par3;
		bool a = 1;
		while(true){
			cod = toCode(program[pointer]);
			
			if(cod.first) par1 = pointer+1;
			else par1 = program[pointer+1];
			
			if(cod.second) par2 = pointer+2;
			else par2 = program[pointer+2];
			
			par3 = program[pointer+3];
			
			//cout << i << ": " << cod.second << cod.first << 0 << cod.type << endl; //print debugging
			//cout << '>' << program[par1] << ' ' << program[par2] << ' ' << program[par3] << endl; //print debugging
			//cout << ">>" << cod.type << endl; //print debugging
			switch(cod.type){
				case 1:
				//Opcode 1 adds together numbers read from two positions and stores the result in a third position.
					program[par3] = program[par1] + program[par2];
					pointer += 4;
					break;
				case 2:
				//Opcode 2 multiplies numbers read from two positions and stores the result in a third position.	
					program[par3] = program[par1] * program[par2];
					pointer += 4;
					break;
				case 3:
				//Opcode 3 takes a single integer as input and saves it to the position given by its only parameter.
				//For example, the instruction 3 50 would take an input value and store it at address 50.
					if(a){
						program[par1] = phase;	
						a = 0;
					}
					else{
						program[par1] = input;
					}
					pointer += 2;
					break;
				case 4:
				//Opcode 4 outputs the value of its only parameter.
				//For example, the instruction 4 50 would output the value at address 50.
					pointer += 2;
					return program[par1];
					break;
				case 5:
				//Opcode 5 is jump-if-true: if the first parameter is non-zero
				//it sets the instruction pointer to the value from the second parameter.
					pointer += 3;
					if(program[par1]) pointer = program[par2];
					break;
				case 6:
				//Opcode 6 is jump-if-false: if the first parameter is zero
				//it sets the instruction pointer to the value from the second parameter.
					pointer += 3;
					if(!program[par1]) pointer = program[par2];
					break;
				case 7:
				//Opcode 7 is less than: if the first parameter is less than the second parameter
				//it stores 1 in the position given by the third parameter
				//Otherwise, it stores 0.
					pointer += 4;
					if(program[par1] < program[par2]) program[par3] = 1;
					else program[par3] = 0;
					break;
				case 8:
				//Opcode 8 is equals: if the first parameter is equal to the second parameter
				//it stores 1 in the position given by the third parameter
				//Otherwise, it stores 0.
					pointer += 4;
					if(program[par1] == program[par2]) program[par3] = 1;
					else program[par3] = 0;
					break;
				case 99:
					return 0;
					break;
				default:
					return 0;
					break;
			}
		}
	}
};

vector<int> readInput(){//works good
	vector<int> out;
	int n;
	while(cin >> n){
		out.push_back(n);
		//cout << "reading input\n"; //print debugging
	}
	return out;
}

vector<vector<int> > genOpts(){//works good
	vector<vector<int> > out;
	for(int i = 5; i < 10; ++i){
		for(int j = 5; j < 10; ++j){
			if(j == i) continue;
			for(int k = 5; k < 10; ++k){
				if(k == i || k == j) continue;
				for(int l = 5; l < 10; ++l){
					if(l == i || l == j || l == k) continue;
					for(int m = 5; m < 10; ++m){
						if(m == i || m == j || m == k || m == l) continue;
						out.push_back({i,j,k,l,m});
					}
				}
			}
		}
	}
	return out;
}

int iterate(vector<int> input){
	int most = 0, prevE = 0, aux = 0;
	vector<amplifier> amps;
	amplifier amp(input);
	for(int i = 0; i < 5; ++i){
		amps.push_back(amp);
	}
	vector<vector<int> > options = genOpts();
	cout << options.size() << endl;
	for(int i = 0; i < options.size(); ++i){
		aux = 0;
		for(int j = 0; j < 5; ++j){
			amps[j].phase = options[i][j];
			amps[j].pointer = 0;
			cout << options[i][j];
		}
		cout << endl;
		for(int j = 0; j < 100; ++j){
			//cout << i << ": " << j << ": ";
			aux = amps[j%5].parse(aux);
			if(!aux){
				most = max(most, prevE);
				break;
			}
			if(j%5 == 4) prevE = aux;
		}
	}
	return most;
}

int main(){
	freopen("input7.txt","r",stdin);
	vector<int> input = readInput();
	cout << iterate(input) << endl;
	return 0;
}
