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
    Summary: 
        
*/
// Remove Duplicates from Sorted Array 
class Solution1 {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 0){
            return 0;
        }
        int cur = 1;
        int nonDupHead = 0;
        while(cur<n){
            if(A[cur] != A[cur-1]){
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




/*
    Time Complexity  : O(n)
    Space Complexity : O(1)
    Trick: 
        need to add a counter since it allows 2 duplicate results
    Special Cases : 
    Summary: 
        
*/
// Remove Duplicates from Sorted Array II
class Solution2 {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 0){
            return 0;
        }
        int cur = 1;
        int nonDupHead = 0;
        int counter = 1;
        while(cur<n){
            if(A[cur] != A[cur-1]){
                counter = 1;  //reset counter
                nonDupHead++;
                //no need to swap! just set the value will be all!
                if(cur != nonDupHead){
                    A[nonDupHead] = A[cur];
                }
            }else{
                counter++;
                if(counter <= 2){
                    nonDupHead++;
                    if(cur != nonDupHead){
                        A[nonDupHead] = A[cur];
                    }
                }
            }
            cur++;
        }
        return nonDupHead+1;
    }
};

int main(){
	Solution test;
	int A[7] = {0, 1, 1, 2, 3, 3, 3};
	cout<<test.removeDuplicates(A, 7)<<endl;
}