#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int N = 20000;

int main()
{
    //generate test file
    ofstream otestFile;
    otestFile.open("12.3.input");
    int miss = 12231;
    for(int i=0; i<N; i++)
    {
        if(i == miss)
        {
            continue;
        }
        otestFile<<i<<endl;
    }
    otestFile.close();

    //calculate size and generate bitmap
    int bucketSize = sizeof(int) * 8;
    int bucketNum  = N / bucketSize;
    int bitMap[bucketNum+1];  //remember bucketNum will also be used as index

    //load data to bit map
    ifstream itestFile;
    itestFile.open("12.3.input");
    string line;
    if(itestFile.is_open())
    {
        cout << "able to open file"<<endl;
        while(getline(itestFile, line))
        {
            int data = stoi(line);
            bitMap[data/bucketSize] |= 1<<(data%bucketSize);
        }
        itestFile.close();
    } else {
        cout << "Unable to open file"<<endl;
        return -1;
    }

    bool found = false;
    //find the missing number from bitMap
    for(int i=0; i<=bucketNum; i++)
    {
        for(int j=0; j<bucketSize; j++)
        {
            if((bitMap[i] & (1<<j)) == 0)
            {
                cout<<"Find the missing number! Missing = "<<i*bucketSize + j<<endl;
                found = true;
                break;
            }
        }
        if(found)
        {
            break;
        }
    }

    return 0;
}
