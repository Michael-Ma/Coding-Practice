#include <sstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


//helper functions
int charToRowNum(char c)
{
	switch(c)
	{
	case 'A': return 1; break;
	case 'B': return 2; break;
	case 'C': return 3; break;
	case 'D': return 4; break;
	case 'E': return 5; break;
	case 'F': return 6; break;
	case 'G': return 7; break;
	case 'H': return 8; break;
	case 'I': return 9; break;
	case 'J': return 10; break;
	case 'K': return 11; break;
	case 'L': return 12; break;
	case 'M': return 13; break;
	case 'N': return 14; break;
	case 'O': return 15; break;
	case 'P': return 16; break;
	case 'Q': return 17; break;
	case 'R': return 18; break;
	case 'S': return 19; break;
	case 'T': return 20; break;
	case 'U': return 21; break;
	case 'V': return 22; break;
	case 'W': return 23; break;
	case 'X': return 24; break;
	case 'Y': return 25; break;
	case 'Z': return 26; break;
	}
	return -1; //means sth wrong
}

bool isNumeric(const string input){
	if(input.size() == 0){
		return false;
	}
	if((input.size()>=2 && input[0]=='-') || (input[0]>='0' && input[0]<='9')){
	}else{
		return false;
	}
    for(int i=1; i<(int)input.size(); i++){
        if(input[i]<'0' || input[i]>'9'){
            return false;
        }
    }
    return true;
}

bool isOp(const string input){
	return input=="*" || input=="+" || input=="-" || input=="/" || input=="--" || input=="++";
}

bool isCell(const string input, int &col, int &row){
	if(input.size()>=2 && input[0]>='A' && input[0]<='Z'){
		row = charToRowNum(input[0]);
		string rest = input.substr(1, input.size()-1);
		if(isNumeric(rest)){
			col = atoi(rest.c_str());
		}else{
			return false;
		}
	}else{
		return false;
	}
	return true;
} 

void strSplit(const string input, vector<string> &result){
	string token = "";
	for(int i=0; i<(int)input.size(); i++){
		if(input[i] !=  ' '){
			token.push_back(input[i]);
		}else{
			result.push_back(token);
			token = "";
		}
	}
	result.push_back(token);
}



// basic class to store cell data
class Node{
public:
	string raw;
	double value;
	set<Node*> inNodes;
	set<Node*> outNodes;

	Node(const string &input):raw(input), value(0){}
};



// class represents spreadsheet, and do all the data parsing and calculation
// Note : this class support negative number and operator "++" and "--"
class SpreadSheet{
protected:
	int colNum;
	int rowNum;
	vector<vector<Node*> > data;
	bool isInit;
	int edges;

public:
	SpreadSheet():isInit(false), edges(0){}
	virtual ~SpreadSheet(){
		if(isInit){
			for(int i=rowNum-1; i>=0; i--){
				for(int j=colNum-1; j>=0; j--){
					delete data[i][j];
				}
			}
		}
	}

	void init(){
		//first parse all the stdin data
		string buffer;
		if(getline (std::cin, buffer)){
			vector<string> tmp;
			strSplit(buffer, tmp);
			if(tmp.size()!=2 || !isNumeric(tmp[0]) || !isNumeric(tmp[1])){
				cout<<"Error : wrong input format -> column/row number is not correct!"<<endl;
				return;
			}else{
				colNum = atoi(tmp[0].c_str());
				rowNum = atoi(tmp[1].c_str());
			}
		}
		for(int i=0; i<rowNum; i++){
			vector<Node*> row;
			for(int j=0; j<colNum; j++){
				if(getline (std::cin, buffer)){
					Node* tmp = new Node(buffer);
					row.push_back(tmp);
				}else{
					cout<<"Error : wrong input format -> not enough data!"<<endl;
					return;
				}
			}
			data.push_back(row);
		}

		//parse data for each node
		for(int i=0; i<rowNum; i++){
			for(int j=0; j<colNum; j++){
				vector<string> tmp;
				strSplit(data[i][j]->raw, tmp);
				for(int k=0; k<(int)tmp.size(); k++){
					int col = -1;
					int row = -1;
					if(!isNumeric(tmp[k]) && !isOp(tmp[k])){
						if(!isCell(tmp[k], col, row)){
							cout<<"Error : wrong input format -> cell data is not correct!"<<endl;
							return;
						}else{
							data[i][j]->inNodes.insert(data[row-1][col-1]);
							data[row-1][col-1]->outNodes.insert(data[i][j]);
							edges++;
						}
					}
				}
			}
		}
		isInit = true;
	}

	//do topological sort and decide if it has cycle, return false if it has.
	bool topSort(vector<Node*> &result){
		queue<Node*> zeroInQueue;
		for(int i=0; i<rowNum; i++){
			for(int j=0; j<colNum; j++){
				if(data[i][j]->inNodes.size() == 0){
					zeroInQueue.push(data[i][j]);
				}
			}
		}

		while(!zeroInQueue.empty()){
			Node* v = zeroInQueue.front();
			zeroInQueue.pop();
			result.push_back(v);
			//remove each out edges
			if(!v->outNodes.empty()){
				for(set<Node*>::iterator it=v->outNodes.begin(); it!=v->outNodes.end(); it++){
					Node* w = *it;
					//remove v from w's edges
					w->inNodes.erase(v);
					edges--;
					if(w->inNodes.size()==0){
						zeroInQueue.push(w);
					}
				}
			}
		}

		if(edges != 0){
			return false;
		}
		return true;
	}


	bool calVal(){
		//check if data is correctly init before calculating
		if(!isInit){
			return false;
		}

		//call topSort() inside calVal()
		vector<Node*> sortResult;
		if(!topSort(sortResult)){
			cout<<"Error : Has cyclic dependencies!"<<endl;
			return false;
		}

		for(int i=0; i<(int)sortResult.size(); i++){
			stack<double> calSt;
			vector<string> tmp;
			strSplit(sortResult[i]->raw, tmp);
			for(int k=0; k<(int)tmp.size(); k++){
				int col = -1;
				int row = -1;
				if(isNumeric(tmp[k])){
					calSt.push(atoi(tmp[k].c_str()));
				}else if(isCell(tmp[k], col, row)){
					calSt.push(data[row-1][col-1]->value);
				}else if(isOp(tmp[k])){
					double res = 0;
					double right = calSt.top();
					calSt.pop();
					if(tmp[k] == "--"){
						res = right-1;
					}else if(tmp[k] == "++"){
						res = right+1;
					}else{
						double left = calSt.top();
						calSt.pop();
						if(tmp[k] == "+"){
							res = left + right;
						}else if(tmp[k] == "-"){
							res = left + right;
						}else if(tmp[k] == "*"){
							res = left * right;
						}else if(tmp[k] == "/"){
							res = left / right;
						}
					}
					calSt.push(res);
				}else{
					cout<<"Error : calculation error!"<<endl;
					return false;
				}
			}
			sortResult[i]->value = calSt.top();
			calSt.pop();
			if(!calSt.empty()){
				cout<<"Error : calculation error!"<<endl;
				return false;
			}
		}
		return true;
	}


	void printSpreadSheet(){
		cout<<colNum<<" "<<rowNum<<endl;
		for(int i=0; i<(int)data.size(); i++){
			for(int j=0; j<(int)data[i].size(); j++){
				printf("%.5f\n", data[i][j]->value);
			}
		}
	}
};


int main(){
	SpreadSheet sheet;
	sheet.init();

	if(!sheet.calVal()){
		return 1;
	}else{
		sheet.printSpreadSheet();
	}

	return 0;
}