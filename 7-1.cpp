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

code toCode(int eger){
	return code(eger%100, (eger%1000)/100, (eger%10000)/1000);
}

int parse(vector<int> vi, int phase, int input){
	//cout << "parsing: " << phase << endl; //print debugging
	int i = 0;
	int prei = 1;
	code cod(0,0,0);
	int par1, par2, par3;
	bool a = 1;
	while(true){
		cod = toCode(vi[i]);
		
		if(cod.first) par1 = i+1;
		else par1 = vi[i+1];
		
		if(cod.second) par2 = i+2;
		else par2 = vi[i+2];
		
		par3 = vi[i+3];
		
		//cout << i << ": " << cod.second << cod.first << 0 << cod.type << endl; //print debugging
		//cout << '>' << vi[par1] << ' ' << vi[par2] << ' ' << vi[par3] << endl; //print debugging
		//cout << ">>" << cod.type << endl; //print debugging
		switch(cod.type){
			case 1:
			//Opcode 1 adds together numbers read from two positions and stores the result in a third position.
				vi[par3] = vi[par1] + vi[par2];
				i += 4;
				break;
			case 2:
			//Opcode 2 multiplies numbers read from two positions and stores the result in a third position.	
				vi[par3] = vi[par1] * vi[par2];
				i += 4;
				break;
			case 3:
			//Opcode 3 takes a single integer as input and saves it to the position given by its only parameter.
			//For example, the instruction 3 50 would take an input value and store it at address 50.
				if(a){
					vi[par1] = phase;	
					a = 0;
				}
				else{
					vi[par1] = input;
				}
				i += 2;
				break;
			case 4:
			//Opcode 4 outputs the value of its only parameter.
			//For example, the instruction 4 50 would output the value at address 50.
				return vi[par1];
				i += 2;
				break;
			case 5:
			//Opcode 5 is jump-if-true: if the first parameter is non-zero
			//it sets the instruction pointer to the value from the second parameter.
				i += 3;
				if(vi[par1]) i = vi[par2];
				break;
			case 6:
			//Opcode 6 is jump-if-false: if the first parameter is zero
			//it sets the instruction pointer to the value from the second parameter.
				i += 3;
				if(!vi[par1]) i = vi[par2];
				break;
			case 7:
			//Opcode 7 is less than: if the first parameter is less than the second parameter
			//it stores 1 in the position given by the third parameter
			//Otherwise, it stores 0.
				i += 4;
				if(vi[par1] < vi[par2]) vi[par3] = 1;
				else vi[par3] = 0;
				break;
			case 8:
			//Opcode 8 is equals: if the first parameter is equal to the second parameter
			//it stores 1 in the position given by the third parameter
			//Otherwise, it stores 0.
				i += 4;
				if(vi[par1] == vi[par2]) vi[par3] = 1;
				else vi[par3] = 0;
				break;
		}
	}
}

vector<int> readInput(){
	vector<int> out;
	int n;
	while(cin >> n){
		out.push_back(n);
		//cout << "reading input\n"; //print debugging
	}
	return out;
}

int iterate(vector<int> input){
	//cout << "iterating\n"; //print debugging
	int bla[5] = {-1,1,2,3,4};
	int most = 0;
	while(bla[0] < 5){
		bla[0]++;
		while(bla[1] < 5){
			bla[1]++;
			if(bla[1] == bla[0]) continue;
			while(bla[2] < 5){
				bla[2]++;
				if(bla[2] == bla[0] || bla[2] == bla[1]) continue;
				while(bla[3] < 5){
					bla[3]++;
					if(bla[3] == bla[0] || bla[3] == bla[1] || bla[3] == bla[2]) continue;
					while(bla[4] < 5){
						bla[4]++;
						if(bla[4] == bla[0] || bla[4] == bla[1] || bla[4] == bla[2] || bla[4] == bla[3]) continue;
						most = max(parse(input, bla[4], parse(input, bla[3], parse(input, bla[2], parse(input, bla[1], parse(input, bla[0], 0))))), most);
					}
					bla[4] = -1;
				}
				bla[3] = -1;
			}
			bla[2] = -1;
		}
		bla[1] = -1;
	}
	return most;
}

int main(){
	freopen("input7.txt","r",stdin);
	vector<int> input = readInput();
	cout << iterate(input) << endl;
	return 0;
}
