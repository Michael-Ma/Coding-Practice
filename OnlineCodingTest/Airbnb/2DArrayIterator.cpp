#include <iostream>
#include <vector>

using namespace std;

class ArrayIterator{
private:
	int col;
	int row;
	vector<vector<string> > data;
public:
	ArrayIterator(vector<vector<string> > input){
		data = input;
		col = 0;
		row = 0;
	}

	bool hasNext(){
		if(row >= data.size() || col >= data[row].size()){
			return false;
		}
		
		while(row < data.size()){
			while(col < data[row].size()){
				if(data[row][col] == ""){
					col++;
				}else{
					return true;
				}
			}
			row++;
			col = 0;
		}
		return false;
	}

	string next(){
		string result = "";
		if(hasNext()){
			result = data[row][col];
			//move the needle
			col++;
			while(row < data.size()){
				while(col < data[row].size()){
					if(data[row][col] == ""){
						col++;
					}else{
						return result;
					}
				}
				row++;
				col = 0;
			}
		}
		return result;
	}

	bool remove(){
		if(row >= data.size() || col >= data[row].size()){
			return false;
		}
		data[row][col] = "";
		return true;
	}
};

int main(){
	vector<vector<string> > input;
	vector<string> line1;
	line1.push_back("1");
	line1.push_back("2");
	line1.push_back("3");
	line1.push_back("4");
	line1.push_back("5");
	line1.push_back("");
	vector<string> line2;
	line2.push_back("");
	line2.push_back("22");
	line2.push_back("23");
	line2.push_back("24");
	line2.push_back("");
	line2.push_back("26");
	vector<string> line3;
	line3.push_back("31");
	line3.push_back("32");
	line3.push_back("");
	line3.push_back("34");
	line3.push_back("35");
	line3.push_back("");
	input.push_back(line1);
	input.push_back(line2);
	input.push_back(line3);

	ArrayIterator test1(input);
	for(int i=0; i<8; i++){
		cout<<test1.next()<<", ";
	}
	cout<<endl;
	test1.remove();
	test1.remove();
	cout<<test1.next()<<endl;
}