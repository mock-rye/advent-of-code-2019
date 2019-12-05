#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double ten = 10.0;

vector<int> vectorize(int dec){
	int b;
	vector<int> vect;
	int pten;
	for(int i = log10(dec); i >= 0; --i){
		b = dec% (int)pow(ten, (double)i+1);
		b = b/ (int)pow(ten, (double)i);
		vect.push_back(b);
	}
	return vect;
}

int check(vector<int> vect){
	bool adjacent = 0, nondescendent = 1;
	for(int i = 0; i < vect.size()-1; ++i){
		if(vect[i] > vect[i+1]) nondescendent = 0;
		if(vect[i] == vect[i+1]) adjacent = 1;
	}	
	return (adjacent&&nondescendent);
}

int main(){
	int start = 240920, end = 789857, counter = 0;
	for(int i = start; i < end; ++i){
		if(check(vectorize(i))) counter++;
	}
	cout << counter << endl;
	return 0;
}
