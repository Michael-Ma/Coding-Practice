#include <sstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
//#include <unordered_map>

using namespace std;


// Definition for binary tree*
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    Time Complexity  : O(n)
    Space Complexity : O(logn) - O(1)
    Trick: 
    Special Cases : 
    Summary: 
    for this kind of problems, using stack is for storing info which will be needed in the future,
    when the program is running back to this point.
*/


class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        
    }
};