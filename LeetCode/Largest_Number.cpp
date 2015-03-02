#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include <sstream>

/*
    Time Complexity  : O(nlogn)
    Space Complexity : O(n)
    Trick: when comparing with 2 string number, simply comparing it's combinations
    Special Cases : when multiple 0 in the array, need to output only one 0.
    Summary:  [how to convert from bad solution to good solution] [how to tackle such kind of problem]
*/


bool str_compare(const string &ll, const string &rr){
    string llrr = ll+rr;
    string rrll = rr+ll;
    return llrr > rrll;
}
    
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> num_str;
        string result = "";
        //convert int vector to string vector
        for(int i=0; i<num.size(); i++){
            std::stringstream ss;
            ss<<num[i];
            num_str.push_back(ss.str());
        }
        sort(num_str.begin(), num_str.end(), str_compare);
        //generate result
        if(num_str[0] == "0"){
            return "0";
        }
        for(int i=0; i<num_str.size(); i++){
            result += num_str[i];
        }
        return result;
    }
};

int main()
{
    vector<int> input;
    input.push_back(128);
    input.push_back(12);


    cout<<Solution::largestNumber(input)<<endl;

    return 0;
}