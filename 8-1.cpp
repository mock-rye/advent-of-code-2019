#include <iostream>
#include <vector>
using namespace std;

struct layer{
	int zero, one, two;
	void zeron(){
		zero = 0;
		one = 0;
		two = 0;
	}
};

vector<layer> getInput(int height, int width){
	vector<layer> out;
	int counter = 0;
	layer aux;
	char a;
	while(cin >> a){
		if(counter%(height*width) == 0){
			out.push_back(aux);
			aux.zeron();
		}
		switch(a){
			case '0':
				aux.zero++;
				break;
			case '1':
				aux.one++;
				break;
			case '2':
				aux.two++;
				break;
		}
		counter++;
	}
	return out;
}

int solve(vector<layer> input){
	int leastZeros = 1000000, l_Z_a;
	for(int i = 0; i < input.size(); ++i){
		if(leastZeros > input[i].zero){
			leastZeros = input[i].zero;
			l_Z_a = i;
		}
	}
	return input[l_Z_a].one * input[l_Z_a].two;
}

int main(){
	freopen("input8.txt","r",stdin);
	vector<layer> input = getInput(6, 25);
	cout << solve(input) << endl;
	return 0;
}
