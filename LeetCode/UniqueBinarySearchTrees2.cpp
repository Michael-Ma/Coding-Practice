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
        it's a math problem: divide and conquer, each node can be the root, and nodes on the left/right will be fixed because of the order.
        for the nodes on the left/right, they are the same problem but smaller size.
        using dp to solve it.
    Special Cases : 
    Summary:
*/
//Unique Binary Search Trees
class Solution1 {
public:
    int numTrees(int n) {
        if(n <= 0){
            return 0;
        }
        int res[n+1];
        memset(res, 0, sizeof(res));
        res[0] = 1;
        res[1] = 1;
        for(int i=2; i<=n; i++){
            //need to remove the node from left and right nodes
            for(int j=0; j<i; j++){
                res[i] += res[j]*res[i-1-j];
            }
        }
        return res[n];
    }
};



/*
    Time Complexity  : O(n!)
    Space Complexity : O(1)   // no extra space
    Trick: 
        same idea, but use recursion to solve it.
    Special Cases : 
    Summary:
        common method to solve O(n!) NP problem, using helper function and use recusion.
*/
//Unique Binary Search Trees II
class Solution2 {
public:
    vector<TreeNode *> generateTrees(int n) {
        return *generateTreesInRange(1, n);
    }
    
    vector<TreeNode *>* generateTreesInRange(int start, int end){
        vector<TreeNode *>* result = new vector<TreeNode *>;
        if(start > end){
            result->push_back(NULL);
            return result;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode *>* left = generateTreesInRange(start, i-1);
            vector<TreeNode *>* right = generateTreesInRange(i+1, end);
            for(int m=0; m<left->size(); m++){
                for(int n=0; n<right->size(); n++){
                    TreeNode* cur = new TreeNode(i);
                    cur->left = (*left)[m];
                    cur->right = (*right)[n];
                    result->push_back(cur);
                }
            }
        }
        return result;
    }
};