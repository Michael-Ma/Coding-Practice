#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

vector<string> genOneEditedWord(string start, string end)
{
    vector<string> result;
    if(start.length() != end.length())
    {
        return result;
    }

    for(int i=0; i<start.length(); i++)
    {
        if(start[i] != end[i])
        {
            string edited = start;
            edited[i] = end[i];
            result.push_back(edited);
        }
    }
    cout<<endl;
    return result;
}

// print all the words transforming from start to the end
void transform(string start, string end, set<string> dict)
{
    if(start.length() != end.length())
    {
        return;  //length must be equal.
    }

    set<string>         visited;
    queue<string>       visiting;
    map<string, string> backtraceMap;
    visited.insert(start);
    visiting.push(start);
    while(!visiting.empty())
    {
        string word = visiting.front();
        visiting.pop();
        vector<string> editedWords = genOneEditedWord(word, end);
        for(int i=0; i<editedWords.size(); i++)
        {
            if(editedWords[i] == end)
            {
                string res = editedWords[i];
                vector<string> finalResult;
                finalResult.push_back(res);
                backtraceMap[res] = word;
                while(backtraceMap.find(res) != backtraceMap.end())
                {
                    res = backtraceMap[res];
                    finalResult.push_back(res);
                }
                for(int i=finalResult.size()-1; i>=0; i--)
                {
                    cout<<finalResult[i]<<" -> ";
                }
                cout<<endl;
                return;
            }

            //otherwise need to restart from this point
            if(dict.find(editedWords[i]) != dict.end())
            {
                if(visited.find(editedWords[i]) == visited.end())
                {
                    visiting.push(editedWords[i]);
                    visited.insert(editedWords[i]);
                    backtraceMap[editedWords[i]] = word;
                }
            }
        }
    }
}

int main()
{
    set<string> dict;
    dict.insert("DAMP");
    dict.insert("LAMP");
    dict.insert("LIMP");
    dict.insert("LIME");
    dict.insert("LIKE");
    dict.insert("LAKE");
    transform("DAMP", "LIKE", dict);
}
