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

typedef map<int,node> tree;

int toInt(string input){
	return (input[0])*91*91 + (input[1])*91 + (input[2]);
}

tree readInput(){
	string str;
	int start, end;
	map<int,node> out;
	while(cin >> str){
		start = toInt(str.substr(0,3));
		end = toInt(str.substr(4,3));
		out[start].children.push_back(end);
		out[end].parent = start;
	}
	return out;
}

int parse(int head, tree graph){
	vector<int> queue;
	int current;
	int out = 0;
	for(int i = 0; i < graph[head].children.size(); ++i){
		queue.push_back(graph[head].children[i]);
	}
	for(int i = 0; i < queue.size(); ++i){
		current = queue[i];
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
	tree graph = readInput();
	cout << parse(toInt("COM"), graph) << endl;
	return 0;
}
