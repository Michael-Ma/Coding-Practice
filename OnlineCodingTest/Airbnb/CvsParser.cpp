#include <iostream>
#include <vector>

using namespace std;


string cvsParser(string& input){
	string result = "";
	string token = "";
	bool inQuote = false;
	for(int i=0; i<input.size(); i++){
		if(i == input.size()-1 && !inQuote){
			token.push_back(input[i]);
			result += "|" + token;
		}else if(i == input.size()-1 && input[i]== '"' && inQuote){
			result += "|" + token;
		}else if(input[i]== '"' && !inQuote){
			inQuote = true;
		}else if(inQuote && input[i]=='"' && input[i+1]=='"'){
			token.push_back(input[i]);
			i++;
		}else if(inQuote && input[i]=='"'){
			inQuote = false;
		}else if(input[i] == ',' && !inQuote){
			result += "|" + token;
			token = "";
		}else{
			token.push_back(input[i]);
		}
	}
	result.erase(result.begin());
	return result;
};


int main(){
	string input = "John,Smith,john.smith@gmail.com,Los Angeles,1ane,Roberts,janer@msn.com,\"San Francisco, CA\",0\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1\"\"\"Alexandra Alex\"\"\"";	
	cout<<cvsParser(input)<<endl;
}