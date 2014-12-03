#include <iostream>
#include <string>

using namespace std;

const int N = 32000;
const int SIZE = sizeof(int)*8;

class BitMap
{
  public:
      BitMap(int size)
      {
          bits = new int[size/SIZE+1]; //size/SIZE will also be used as index;
      }
      ~BitMap()
      {
          delete bits;
      }

      void set(int num)
      {
          bits[num/SIZE] |= 1<<(num%SIZE);
      }
      bool get(int num)
      {
          return (bits[num/SIZE] & (1<<(num%SIZE))) != 0;
      }

  private:
      int* bits;
};

void printDup(int input[], int size, int range)
{
    BitMap bm(range);
    for(int i=0; i<size; i++)
    {
        if(bm.get(input[i]))
        {
            cout<<"Find dup : "<<input[i]<<endl;
        }else{
            bm.set(input[i]);
        }
    }
}

int main()
{
    int input[] = {0, 1, 3, 44, 923, 99, 44, 32000, 32000, 22443};
    printDup(input, 10, N+1); //since it starts from 0;
}

