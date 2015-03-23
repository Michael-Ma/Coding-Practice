#include <sstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
//#include <unordered_map>

using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

/*
    Time Complexity  : O(n^n) -> C(k, n)
    Space Complexity : O(n^n)
    Trick: 
        need to pass result's reference since each recursion may generate 1-n results
        and need to remember remove the added item after return from recursion
    Special Cases : 
    Summary: 
    
*/
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL){
            return NULL;
        }
        queue<UndirectedGraphNode*>     needVisit;
        map<int, UndirectedGraphNode*>  createdNodes;
        needVisit.push(node);
        
        while(!needVisit.empty()){
            UndirectedGraphNode* visting = needVisit.front();
            needVisit.pop();
            
            UndirectedGraphNode* copy;
            // create the node if not exist, otherwise will add neighbors for it later.
            if(createdNodes.find(visting->label) == createdNodes.end()){
                copy = new UndirectedGraphNode(visting->label);
                createdNodes[copy->label] = copy;
            }else{
                copy = createdNodes[visting->label];
            }
            
            for(int i=0; i<visting->neighbors.size(); i++){
                UndirectedGraphNode* n = visting->neighbors[i];
                if(createdNodes.find(n->label) == createdNodes.end()){
                    needVisit.push(n); //will need to revisit it later since it's newly created node
                    UndirectedGraphNode* copy_neighbor = new UndirectedGraphNode(n->label);
                    createdNodes[copy_neighbor->label] = copy_neighbor;
                    copy->neighbors.push_back(copy_neighbor);
                }else{
                    copy->neighbors.push_back(createdNodes[n->label]);
                }
            }
        }
        return createdNodes[node->label];
    }
};


int main(){
    UndirectedGraphNode* root = new UndirectedGraphNode(9);
    UndirectedGraphNode* root1 = new UndirectedGraphNode(99);
    UndirectedGraphNode* root2 = new UndirectedGraphNode(999);
    root->neighbors.push_back(root1);
    root->neighbors.push_back(root2);
    root1->neighbors.push_back(root2);
    Solution test;
    UndirectedGraphNode* result = test.cloneGraph(root);
    cout<<result->label<<endl;
    for(int i=0; i<result->neighbors.size(); i++){
        cout<<result->neighbors[i]->label<<endl;
    }
}