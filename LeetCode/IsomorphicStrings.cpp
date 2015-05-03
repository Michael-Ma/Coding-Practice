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
    Space Complexity : O(n)
    Trick: 
        need to use 2 hashmap, because case like "aa" and "ab", it's bidirection!
    Special Cases : 
    Summary:
        when the problem is about comparing, and need to keep some past info, think about hashmap!
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<char, char> sTot;
        map<char, char> tTos;
        for(int i=0; i<s.size(); i++){
            if(sTot.find(s[i])==sTot.end() && tTos.find(t[i])==tTos.end()){
                sTot[s[i]] = t[i];
                tTos[t[i]] = s[i];
            }else{
                if(sTot[s[i]]!=t[i] || tTos[t[i]]!=s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};