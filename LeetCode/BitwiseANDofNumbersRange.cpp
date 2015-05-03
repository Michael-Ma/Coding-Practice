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
    Space Complexity : O(1)
    Trick: 
    	trick is since it's consecutive, the pos of bits that won't contain 0 will be the common part
    	so just find those common part (base part), and keep track of moved times.
    Special Cases : 
    Summary:
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n){
            return m;
        }
        int changedPos = 0;
        while(m != n){
            m>>=1;
            n>>=1;
            changedPos++;
        }
        return m<<changedPos;
    }
};