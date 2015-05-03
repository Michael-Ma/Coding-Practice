#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <cfloat> 
#include <climits>
//#include <unordered_set> 
//#include <unordered_map>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(r*L)
    Trick: 
    	no trick, just be patient and careful
    Special Cases : 
    Summary:
    	always put (int) before any .size(), habbit of converting makes your debug life much easier!
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if(words.size()!=0 && maxWidth==0){
            result.push_back("");
            return result;
        }
        if(words.size()==0 || maxWidth<0){
            return result;
        }
        string line = "";
        int counter = 0;
        int wordsLen = 0;
        vector<string> lineWords;
        for(int i=0; i<words.size(); i++){
            if((int)words[i].size() <= maxWidth-counter){  // never compare size() with negative number!
                lineWords.push_back(words[i]);
                counter += words[i].size()+1;
                wordsLen += words[i].size();
            }
            //format the line into the result
            else{
                if(lineWords.size() == 1){
                    line += lineWords[0];
                    for(int j=lineWords[0].size(); j<maxWidth; j++){
                        line += " ";
                    }
                }else{
                    int spaceNum = maxWidth - wordsLen;
                    //if there is extra space
                    int extra = spaceNum%(lineWords.size()-1);
                    int base  = spaceNum/(lineWords.size()-1);
                    for(int j=0; j<lineWords.size()-1; j++){
                        line += lineWords[j] + string(base, ' ');
                        if(extra != 0){
                            line += " ";
                            extra--;
                        }
                    }
                    line += lineWords[lineWords.size()-1];
                }
                result.push_back(line);
                //clean up after insert
                line.clear();
                lineWords.clear();
                counter = 0;
                wordsLen = 0;
                //because i hasn't been taken care, go back to go over it again!
                i--;
            }
        }
        //handle the last line
        for(int j=0; j<lineWords.size(); j++){
            line += lineWords[j];
            if(line.size() < maxWidth){
            	line += " ";
            }
        }
        for(int j=line.size(); j<maxWidth; j++){
            line += " ";
        }
        result.push_back(line);
        
        return result;
    }
};

int main(){
	Solution test;
	vector<string> words;
	words.push_back("");
	vector<string> result = test.fullJustify(words, 2);
	for(int i=0; i<result.size(); i++){
		cout<<result[i]<<endl;
	}

	vector<string> words2;
	words2.push_back("a");
	words2.push_back("b");
	words2.push_back("c");
	words2.push_back("d");
	words2.push_back("e");
	vector<string> result2 = test.fullJustify(words2, 1);
	for(int i=0; i<result2.size(); i++){
		cout<<result2[i]<<endl;
	}
}