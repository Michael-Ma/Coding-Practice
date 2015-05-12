#include <map>
#include <bitset>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


/*
    Time Complexity  : O(n)
    Space Complexity : O(n)
    Trick: 
    1. using hashmap & bit operation to do hashing
    2. using trie
    Special Cases : special input, like empty string.
    Summary: need to think about the special input after writting your code, you are also the tester!
             be careful when using length() or size(), it returns size_t, not int. it may get overflow!
             need to be careful about the duplicate inserted into final result, 
             using bool may not distinguish dups that appears multiple times.
*/

//hashmap + bit operation
class Solution1 {
public:
    int hash(string sub){
        int result = ~0;
        for(int i=0; i<sub.size(); i++){
            switch(sub.at(i)){
                case 'A' : result = ((result<<2) | 0); break; //00
                case 'C' : result = ((result<<2) | 1); break; //01
                case 'G' : result = ((result<<2) | 2); break; //10
                case 'T' : result = ((result<<2) | 3); break; //11
            }
//            cout<<"sub.at(i) = "<<sub.at(i)<<", result = "<<(bitset<64>)result<<endl;
        }
        return result;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> dict;
        vector<string>    result;
        for(int i=0; i<=(int)(s.length())-10; i++)
        {
            string seq = s.substr(i, 10);
            int key = hash(seq); 
//            cout<<"seq = "<<seq<<", key = "<<(bitset<64>)key<<endl;
            if(dict[key] == 1)
            {
                result.push_back(seq);
            }
            dict[key]++;
        }
        return result;
    }
};



// using trie tree
class Solution2 {
    struct node
    {
        int count;
        char key;
        node* next[4];
        node(char cc, int co){
            key = cc;
            count = co;
            for(int i=0; i<4; i++){
                next[i] = NULL;
            }
        }
    };

public:
    int getIndex(char c){
        switch(c){
            case 'A' : return 0; 
            case 'C' : return 1; 
            case 'G' : return 2; 
            case 'T' : return 3;
        }
        return -1;
    }

    bool insert(node* root, string &input, int startPos){
        node* current = root;
        for(int i=0; i<10; i++){
            char c = input[i+startPos];
            int index = getIndex(c);
            node* next = current->next[index]; 
            if(next == NULL){
                node* newNode = new node(c, 1);
                current->next[index] = newNode;
            }else{
                next->count++;
            }
            current = current->next[index];
        }

        if(current->count == 2){  // is not >=2, because we don't want to add duplicate one
            return true;
        }

        return false;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>    result;
        if(s.size() < 10){
            return result;
        }

        node* root = new node(' ', 1);
        for(int i=0; i<=(int)(s.length())-10; i++)
        {
            if(insert(root, s, i)){
                result.push_back(s.substr(i, 10));
            }

        }

        return result;
    }
};


void printResult(vector<string>& input)
{
    for(int i=0; i<input.size(); i++)
    {
        cout<<input[i]<<endl;
    }
    cout<<"-------------------------------"<<endl;
}


int main()
{
//    cout<<"size of int = "<<sizeof(int)<<", ~0 = "<<(bitset<64>)~0<<", ~0<<2 | 1 = "<<(bitset<64>)((~0)<<2 | 1)<<", 0 = "<<(bitset<64>)0<<", 1 = "<<(bitset<64>)1<<", 2 = "<<(bitset<64>)2<<", 3 = "<<(bitset<64>)3<<endl;
    Solution2 test;
    vector<string> test_result1 = test.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    printResult(test_result1);
    vector<string> test_result2 = test.findRepeatedDnaSequences("AAAAACCCCCAAGGGTTT");
    printResult(test_result2);
    vector<string> test_result3 = test.findRepeatedDnaSequences("");
    printResult(test_result3);
    vector<string> test_result4 = test.findRepeatedDnaSequences("AAAAAAAAAAA");
    printResult(test_result4);
    vector<string> test_result5 = test.findRepeatedDnaSequences("AAGATCCGTCCCCCCAAGATCCGTC");
    printResult(test_result5);
}