#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class node{
public:
	int parent, tier = 0;
	vector<int> children;
};

typedef map<int,node> ma_in;

int toInt(string input){
	//cout << input; //print debugging
	return (input[0])*91*91 + (input[1])*91 + (input[2]);
}

ma_in readInput(){
	string str;
	int start, end;
	map<int,node> out;
	while(cin >> str){
		//cout << "reading: "; //print debugging
		start = toInt(str.substr(0,3));
		//cout << '\t'; //print debugging
		end = toInt(str.substr(4,3));
		//cout << endl; //print debugging
		out[start].children.push_back(end);
		out[end].parent = start;
	}
	return out;
}

int parse(int head, ma_in graph){
	vector<int> queue;
	int current;
	int out = 0;
	for(int i = 0; i < graph[head].children.size(); ++i){
		queue.push_back(graph[head].children[i]);
	}
	for(int i = 0; i < queue.size(); ++i){
		current = queue[i];
		//cout << current << endl; //print debugging
		for(int j = 0; j < graph[current].children.size(); ++j){
			queue.push_back(graph[current].children[j]);
		}
		graph[current].tier = graph[graph[current].parent].tier + 1;
		out += graph[current].tier;
	}
	return out;
}

int main(){
	freopen("input6.txt","r",stdin);
	ma_in graph = readInput();
	cout << parse(toInt("COM"), graph) << endl;
	return 0;
}
