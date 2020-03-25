#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
   if (!b) return a;
   return gcd(b, a%b);
}

class angle{
public:
	int dx, dy;
	angle(int x, int y){
		if(x && y){
			int g = gcd(abs(x), abs(y));
			dx = x/g;
			dy = y/g;
		}
		else if(x){
			dx = x/abs(x);
			y = 0;
		}
		else if(y){
			x = 0;
			dy = y/abs(y);
		}
		else{
			dx = 0;
			dy = 0;
		}
	}
};

bool operator==(angle a, angle b){
	return ((a.dx == b.dx) && (a.dy == b.dy));
}

bool isInVect(vector<angle> angles, angle alpha){
	for(int i = 0; i < angles.size(); ++i){
		if(angles[i] == alpha) return 1;
	}
	return 0;
}

int check(int x, int y, int width, vector<bool> grid){
	vector<angle> angle_counter;
	for(int i = 0; i < grid.size()/width; ++i){
		for(int j = 0; j < width; ++j){
			if(grid[i * width + j]){
				if(!isInVect(angle_counter, angle(i-x, j-y))){
					angle_counter.push_back(angle(i-x, j-y));
				}
			}
		}
	}
	return angle_counter.size();
}

void iterate(int height, int width, vector<bool> grid){
	int m = 0;
	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			if(m < check(i, j, width, grid)){
				m = check(i, j, width, grid);
				cout << i << ' ' << j << endl;
			}
		}
	}
	cout << m;
}

vector<bool> readInput(int height, int width){
	vector<bool> out;
	char ch;
	for(int i = 0; i < height*width; ++i){
		cin >> ch;
		if(ch == '#'){
			out.push_back(1);
		}
		else if(ch == '.'){
			out.push_back(0);
		}
		else{
			--i;
		}
	}
	return out;
}

int main(){
	int height = 30, width = 30;
	freopen("input10.txt","r",stdin);
	vector<bool> inputGrid = readInput(height, width);
	iterate(height, width, inputGrid);
	return 0;
}
