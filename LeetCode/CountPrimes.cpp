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
    	A prime number (or a prime) is a natural number greater than 1 that has no positive divisors other than 1 and itself. 
    	http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    Special Cases : 
    	0 and 1 are not prime!
    Summary:
*/
class Solution {
public:
    int countPrimes(int n) {
    	n--; //because question request num of prime less than n!
        if(n < 2){
            return 0;
        }
        bool nums[n+1];
        memset(nums, 0, sizeof(nums));
        int prime = 2;
        while(prime <= n/2){ //for all the possible prime numbers
            //set the multiple of prime to be true;
            for(int i=2; i*prime<=n; i++){
                nums[i*prime] = true;
            }
            //find the next prime
            prime++;
            while(prime<=n/2 && nums[prime]){
                prime++;
            }
        }
        int count = 0;
        for(int i=2; i<=n; i++){
            if(!nums[i]){
                count++;
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	cout<<test.countPrimes(1)<<endl;
	cout<<test.countPrimes(2)<<endl;
	cout<<test.countPrimes(5)<<endl;
	cout<<test.countPrimes(10)<<endl;
	cout<<test.countPrimes(100)<<endl;
	cout<<test.countPrimes(1000)<<endl;
	return 0;
}