#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

class MedianContainer
{
  private:
    priority_queue<int, vector<int>, less<int> > max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;

  public:
    void insert(int value);
    int getMedian();
};

void MedianContainer::insert(int value)
{
    if(max_heap.empty())
    {
        max_heap.push(value);
        return;
    }
    if(min_heap.empty())
    {
        min_heap.push(value);
        return;
    }

    if(value >= max_heap.top())
    {
        min_heap.push(value);
        if(max_heap.size() < min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    else
    {
        max_heap.push(value);
        if(max_heap.size() > min_heap.size()+1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
}

int MedianContainer::getMedian()
{
    if(max_heap.empty() && min_heap.empty())
    {
        return -999;  //indicate error
    }
    if(max_heap.size() == min_heap.size())
    {
        return (max_heap.top() + min_heap.top())/2;
    }
    if(max_heap.size() > min_heap.size())
    {
        return max_heap.top();
    }
    else
    {
        return min_heap.top();
    }
}

int main()
{
    srand((unsigned)time(0));
    MedianContainer median;
    vector<int> orderedLsit;
    for(int i=0; i<30; i++)
    {
        int value = rand()%100;
        orderedLsit.push_back(value);
        median.insert(value);
    }
    sort(orderedLsit.begin(), orderedLsit.end());
    for(int i=0; i<orderedLsit.size(); i++)
    {
        cout<<orderedLsit[i]<<", ";
    }
    cout<<endl;
    cout<<"median is : "<<median.getMedian()<<endl;
}
