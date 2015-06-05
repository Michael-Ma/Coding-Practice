#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>

using namespace std;


/*
    Time Complexity  : O(nk^2)
    Space Complexity : O(1)
    Trick: 
		brute force compare with each one.
    Special Cases :
    Summary: 
*/
class Solution1{
	public:
	vector<string> getWordsWithKEditDistance(string &target, vector<string> &candidates, int k){
		vector<string> result;
		for(int i=0; i<candidates.size(); i++){
			if(getEditDistance(target, candidates[i]) <= k){
				result.push_back(candidates[i]);
			}
		}
		return result;
	}

	private:
	int getEditDistance(string &left, string &right){
		int ed[2][right.size()+1];
		for(int i=0; i<2; i++){
			for(int j=0; j<right.size()+1; j++){
				ed[i][j] = j;
			}
		}

		for(int i=0; i<left.size(); i++){
			int prev = i%2;
			int index = (i+1)%2;
			ed[index][0] = i+1;
			for(int j=0; j<right.size(); j++){
				if(left[i] == right[j]){
					ed[index][j+1] = ed[prev][j];
				}else{
					ed[index][j+1] = min(ed[prev][j+1], min(ed[prev][j], ed[index][j]))+1;
				}
			}
		}
		return ed[left.size()%2][right.size()];
	}
};



/*
    Time Complexity  : O(n)
    Space Complexity : O(kn)
    Trick: 
		using trie
    Special Cases :
    Summary: 
*/
class Solution2{
protected:
	struct Node{
		char key;
		Node* next[26];
		bool isEnd;
		Node(char k){
			key = k;
			isEnd = false;
			for(int i=0; i<26; i++){
				next[i] = NULL;
			}
		}
	};

	void insertToTrie(Node* root, string &input){
		for(int i=0; i<input.size(); i++){
			int index = input[i] - 'a';
			if(root->next[index] == NULL){
				root->next[index] = new Node(input[i]);
			}
			if(i == input.size()-1){
				root->next[index]->isEnd = true;
			}
			root = root->next[index];
		}
	}

	void findWordInTrie(string target, int pos, string result, Node* root, int k, vector<string> &results){
//		cout<<"pos="<<pos<<", result="<<result<<", k="<<k<<endl;
		if(k<0){
			return;
		}
		if(pos==target.size()){
			if(root->isEnd){
				results.push_back(result);
//				cout<<"push back "<<result<<endl;
			}else if(k == 0){
//				cout<<"k==0 "<<result<<endl;
				return;
			}else{
				for(int i=0; i<26; i++){
					if(root->next[i] != NULL){
						findWordInTrie(target, pos, result+root->next[i]->key, root->next[i], k-1, results);
					}
				}
			}
		}else if(pos > target.size()){
			return;
		}

		int index = target[pos]-'a';
		if(root->next[index] == NULL){
			findWordInTrie(target, pos+1, result, root, k-1, results);
		}else{
			findWordInTrie(target, pos+1, result+target[pos], root->next[index], k, results);
		}
		for(int i=0; i<26; i++){
			if(root->next[i] != NULL){
				findWordInTrie(target, pos, result+root->next[i]->key, root->next[i], k-1, results);
				findWordInTrie(target, pos+1, result+root->next[i]->key, root->next[i], k-1, results);
			}
		}
	}

public:
	vector<string> getWordsWithKEditDistance(string &target, vector<string> &candidates, int k){
		vector<string> results;
		//build trie
		Node* root = new Node('0');
		for(int i=0; i<candidates.size(); i++){
			insertToTrie(root, candidates[i]);
		}

		//find the word within k ed with target
		findWordInTrie(target, 0, "", root, k, results);
		return results;
	}

};

int main(){

	vector<string> candidates;
	candidates.push_back("dat");
	candidates.push_back("bat");
	candidates.push_back("batt");
	candidates.push_back("beetle");
	candidates.push_back("bet");

	string target = "datt";

	Solution1 test1;
	vector<string> res1 = test1.getWordsWithKEditDistance(target, candidates, 1);
	cout<<"res1"<<endl;
	for(int i=0; i<res1.size(); i++){
		cout<<res1[i]<<", ";
	}
	cout<<endl;

	Solution2 test2;
	vector<string> res2 = test2.getWordsWithKEditDistance(target, candidates, 1);
	cout<<"res2"<<endl;
	for(int i=0; i<res2.size(); i++){
		cout<<res2[i]<<", ";
	}
	cout<<endl;
}