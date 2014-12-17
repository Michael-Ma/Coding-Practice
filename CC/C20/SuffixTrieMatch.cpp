#include <iostream>
#include <cstring>

using namespace std;

class Trie{
  public:
    static const int MAX_N = 100*100; // 100 is the length of string, need to hold 100 suffix for this string
    static const int NODE_SIZE = 26;  // each node has 26 element.
    int size;   // utilized size after inserting.
    int trie[MAX_N][NODE_SIZE];
    
    Trie(const char* source);
    void insert(const char* source);
    bool find(const char* source);
};

Trie::Trie(const char* source)
{
    //init every bit to be -1
    for(int i=0; i<MAX_N; i++)
    {
        for(int j=0; j<NODE_SIZE; j++)
        {
            trie[i][j] = -1;
        }
    }
    size = 1;      // 0 is the root, every suffix start from root, and 
    while(*source)
    {
        insert(source);
        source++;
    }
}

void Trie::insert(const char* source)
{
    int cur_pointer = 0;
    while(*source)
    {
        int i = *source - 'a';
        if(trie[cur_pointer][i] == -1)
        {
            trie[cur_pointer][i] = size;
            size++;
        }
        cur_pointer = trie[cur_pointer][i];
        source++;
    }
}

bool Trie::find(const char* source)
{
    int cur_pointer = 0;
    while(*source)
    {
        int i = *source - 'a';
        if(trie[cur_pointer][i] == -1)
        {
            return false;
        }
        cur_pointer = trie[cur_pointer][i];
        source++;
    }
    return true;
}


int main()
{
    Trie tree("mississippi");
    const char* patt[5] = {"is", "sip", "hi", "sis", "mississippa"};
    for(int i=0; i<5; i++)
    {
        cout<<patt[i]<<" : "<<tree.find(patt[i])<<endl;
    }
}
