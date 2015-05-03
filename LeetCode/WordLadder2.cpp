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
#include <unordered_set> 
#include <unordered_map>

using namespace std;


//Compile : g++ -g WordLadder2.cpp -std=gnu++11


/*
    Time Complexity  : O(26*n*L)
    Space Complexity : O(n)
    Trick: 
    	model the problem to be a graph problem, basically each word is like a node in a graph, dict tells where edges are.
    	solve this problem is like find the min path from start node to end node.
    	using DFS to find the min path.
    Special Cases : 
    Summary:
    	algorithm of graph is very useful! 
*/
// Word Ladder 
class Solution1 {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if(beginWord.size()!=endWord.size() || beginWord.size()==0 || wordDict.size()==0){
            return 0;
        }
        queue<string> visitQueue;
        unordered_set<string> visited;
        int levelNodes = 1;
        int curLevelNodes = 0;
        int level = 1;
        
        visitQueue.push(beginWord);
        while(!visitQueue.empty()){
            string cur = visitQueue.front();
            visitQueue.pop();
            visited.insert(cur);
            levelNodes--;
            for(int i=0; i<cur.size(); i++){
                string tmp = cur;  // need to reset string for each time
                for(char c='a'; c<='z'; c++){
                    tmp[i] = c;
                    if(tmp == endWord){
                        return level+1;
                    }
                    if(wordDict.find(tmp)!=wordDict.end() && visited.find(tmp)==visited.end()){
                        visitQueue.push(tmp);
                        visited.insert(tmp);  //careful about what visited means!
                        curLevelNodes++;
                    }
                }
            }
            if(levelNodes == 0){
                levelNodes = curLevelNodes;
                curLevelNodes = 0;
                level++;
            }
        }
        
        return 0;
    }
};



/*
    Time Complexity  : O(26*n*L)
    Space Complexity : O(n*L)
    Trick: 
    	http://www.cnblogs.com/TenosDoIt/p/3443512.html
    Special Cases : 
    Summary:
*/
// Word Ladder II
class Solution2 {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        if(start.size()!=end.size() || start.size()==0 || dict.size()==0){
            return result;
        }
        queue<string> visitQueue;
        unordered_map<string, vector<string> > nodeMap;
        unordered_set<string> levelNodes;
        int levelNodesNum = 1;
        int level = 0;
        bool found = false;
        
        visitQueue.push(start);
        while(!visitQueue.empty()){
            string cur = visitQueue.front();
            visitQueue.pop();
            levelNodesNum--;
            for(int i=0; i<cur.size(); i++){
                string tmp = cur;  // need to reset string for each time
                for(char c='a'; c<='z'; c++){
                    tmp[i] = c;
                    if(tmp == end){
                        found = true;  //if found, no need to go over all other possible variations for this word
                        nodeMap[cur].push_back(tmp);
                        break;
                    }
                    if(dict.find(tmp)!=dict.end()){
                        visitQueue.push(tmp);
                        if(levelNodes.find(tmp) != levelNodes.end()){
                        	levelNodes.insert(tmp);  //remove them later
                		}
                        nodeMap[cur].push_back(tmp);
                    }
                }
                if(found){
                    break;
                }
            }
            
            if(levelNodesNum == 0){
                levelNodesNum = levelNodes.size();
                dict.erase(levelNodes.begin(), levelNodes.end());
                levelNodes.clear();
                level++;
                if(found){
                    break;
                }
            }
        }
//        cout<<"level = "<<level<<", found = "<<found<<endl;
        if(!found){
            return result;
        }
                
        vector<string> tmpRes;
        tmpRes.push_back(start);
        getPath(start, end, level, nodeMap, tmpRes, result);
        
        return result;
    }
    
    void getPath(string &start, string &end, int level, unordered_map<string, vector<string> > &nodeMap, vector<string> &tmpRes, vector<vector<string> > &result){
        if(start == end){
            reverse(tmpRes.begin(), tmpRes.end());
            result.push_back(tmpRes);
            reverse(tmpRes.begin(), tmpRes.end());
        }else{
            if(level > 0){
                level--;
                for(int i=0; i<nodeMap[start].size(); i++){
                    tmpRes.push_back(nodeMap[start][i]);
                    getPath(nodeMap[start][i], end, level, nodeMap, tmpRes, result);
                    tmpRes.pop_back();
                }
            }
        }
    }
};

int main(){
	Solution2 test;
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	vector<vector<string>> result = test.findLadders("a", "c", dict);
	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"->";
		}
		cout<<endl;
	}
}