#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double ten = 10.0;

vector<int> vect(int a){
	int b;
	vector<int> vect;
	int pten;
	for(int i = 5; i >= 0; --i){
		b = a% (int)pow(ten, (double)i+1);
		b = b/ (int)pow(ten, (double)i);
		vect.push_back(b);
	}
	return vect;
}

int check(vector<int> vect){
	bool adjacent = 0, nondescendent = 1;
	for(int i = 0; i < 5; ++i){
		if(vect[i] > vect[i+1]) nondescendent = 0;
		if(vect[i] == vect[i+1]) adjacent = 1;
	}	
	return (adjacent&&nondescendent);
}

int main(){
	vector<int> vi;
	int start = 240920, end = 789857;
	int counter = 0;
	for(int i = start; i < end; ++i){
		if(check(vect(i))) counter++;
	}
	cout << counter << endl;
	return 0;
}
