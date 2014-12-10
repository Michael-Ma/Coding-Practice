#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

bool cmp(const string& ll, const string& rr)
{
    return ll.size() > rr.size();  //descending order
}

bool isWordMakeable(const string& word, map<string, bool>& hashmap)
{
    int len = word.size();
    if(len == 0)
    {
        return true;  //means find the end of iteration.
    }

    for(int i=1; i<=len; i++)
    {
        string headPart = word.substr(0, i);
        string tailPart = word.substr(i);
//        cout<<"headPart = "<< headPart<<", tailPart = "<<tailPart<<endl;
        if(hashmap[headPart])
        {
            if(isWordMakeable(tailPart, hashmap))
            {
                return true;
            }
        }
    }
    return false;
}

void printLongestMakeableWord(string words[], int size)
{
    map<string, bool> hashmap;
    for(int i=0; i<size; i++)
    {
        hashmap[words[i]] = true;
    }
    sort(words, words+size, cmp);

    for(int i=0; i<size; i++)
    {
        if(isWordMakeable(words[i], hashmap))
        {
            cout<<"Longest makeable word is "<<words[i]<<endl;
            return;
        }
    }
}

int main()
{
    string words[10] = {"test", "tester", "testertest", "testing", "batti","bat", "testingtester", "testbattingcat", "ngcat", "batting"};
    printLongestMakeableWord(words, 10);

}

