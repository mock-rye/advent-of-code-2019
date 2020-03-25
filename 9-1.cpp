#include <iostream>
#include <vector>
using namespace std;


class code{
public:
	int type = 0, first = 0, second = 0, third = 0;
	code(int _type = 0, int _first = 0, int _second = 0, int _third = 0){
		type = _type;
		first = _first;
		second = _second;
		third = _third;
	}
};

code toCode(int eger){
	return code((eger%100), (eger%1000)/100, (eger%10000)/1000, (eger%100000)/10000);
}

class computer{
private:
	vector<long int> program;
	int pointer, phase;
public:
	computer(vector<long int> _program, int _pointer, int _phase){
		program = _program;
		pointer = _pointer;
		phase = _phase;
	}
	vector<long int> getProgram(){
		return program;
	}
	int getPointer(){
		return pointer;
	}
	int getPhase(){
		return phase;
	}
	void changeProgram(vector<long int> _program){
		program = _program;
	}
	void changePhase(int _phase){
		phase = _phase;
	}
	void changePointer(int _pointer){
		pointer = _pointer;
	}
};

int main(){
	return 0;
}
