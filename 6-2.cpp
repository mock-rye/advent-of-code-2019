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

vector<int> pathToCOM(int _node, int COM, tree graph){
	vector<int> queue;
	int current = _node;
	if(current == COM) return queue;
	queue.push_back(graph[current].parent);
	for(int i = 0; i < queue.size(); ++i){
		current = queue[i];
		if(current == COM) return queue;
		queue.push_back(graph[current].parent);
	}
}

int smallestCommon(vector<int> in1, vector<int> in2){
	int out = 100000;
	for(int i = 0; i < in1.size(); ++i){
		for(int j = 0; j < in2.size(); ++j){
			if(in1[i] == in2[j]){
				out = min(i+j, out);
			}	
		}
	}
	return out;
}

int parse(int COM, int YOU, int SAN, tree graph){
	vector<int> santaPath, youPath;
	santaPath = pathToCOM(SAN, COM, graph);
	youPath = pathToCOM(YOU, COM, graph);
	return smallestCommon(santaPath, youPath);
}

int main(){
	freopen("input6.txt","r",stdin);
	tree graph = readInput();
	int YOU = toInt("YOU"), SAN = toInt("SAN"), COM = toInt("COM");
	cout << parse(COM, YOU, SAN, graph) << endl;
	return 0;
}
