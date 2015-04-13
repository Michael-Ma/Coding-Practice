#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
//#include <unordered_map>

using namespace std;



/*
    Time Complexity  : O(1)
    Space Complexity : O(n)
    Trick: 
        trick is to use a stack to keep track of min element
        insert to minStack only when there is smaller one, elements in between don't matter
    Special Cases : 
    Summary: 
    
*/ 

class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;
    
    void push(int x) {
        mainStack.push(x);
        if(minStack.empty() || x <= minStack.top()){
            minStack.push(x);
        }
    }

    void pop() {
        if(!mainStack.empty()){
            int t = mainStack.top();
            mainStack.pop();
            if(t == minStack.top()){
                minStack.pop();
            }
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};