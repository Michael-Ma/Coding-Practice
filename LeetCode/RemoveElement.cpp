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
        use 2 pointer to search and set. try to put the right element to the right place at one shot.
    Special Cases : 
        just careful about the case then the first element is also the target!
    Summary: 
        everytime finished the logic, need to go over several cases to test!
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n <= 0){
            return 0;
        }
        int cur = 0;
        int nonDupHead = -1;
        while(cur<n){
            if(A[cur] != elem){
                nonDupHead++;
                //no need to swap! just set the value will be all!
                if(cur != nonDupHead){
                    A[nonDupHead] = A[cur];
                }
            }
            cur++;
        }
        return nonDupHead+1;
    }
};