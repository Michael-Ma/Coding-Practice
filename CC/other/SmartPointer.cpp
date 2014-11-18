#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class SmartPointer
{
  public:
	SmartPointer(T* ptr)
	{
		obj_ptr = ptr;	
		//important: one new ref_count is bounded with one obj pointer
//		ref_count = new unsigned(1);
		ref_count = (unsigned*) malloc(sizeof(unsigned));
		*ref_count = 1;
		cout<<"new smart pointer!"<<endl;
	}
	SmartPointer(SmartPointer<T>& sptr):obj_ptr(sptr.obj_ptr), ref_count(sptr.ref_count)
	{
		(*ref_count)++;
		cout<<"new smart pointer!"<<endl;
	}
	~SmartPointer()
	{
		(*ref_count)--;
		if(*ref_count == 0)
		{
			clear();
		}
	}

	SmartPointer<T>& operator = (SmartPointer<T>& sptr)
	{
		if(this != &sptr)
		{
			(*ref_count)--;
			if(*ref_count == 0)
			{
				clear();
			}
			obj_ptr = sptr.obj_ptr;
			ref_count = sptr.ref_count;
			(*ref_count)++;
		}
		return *this;
	}

	T getValue()
	{
		return *obj_ptr;
	}

  private:
	void clear()
	{
		if(ref_count==NULL || *ref_count!=0)
		{
			return;
		}

		if(obj_ptr != NULL)
		{
			delete obj_ptr;
			obj_ptr = NULL;
		}

		//	delete ref_count;
		free(ref_count);
		ref_count = NULL;
		cout<<"cleared memory!"<<endl;
	}

  protected:
	T* obj_ptr;
	unsigned* ref_count;
};


int main()
{
	int *p1 = new int(111);
	int *p2 = new int(222);
	SmartPointer<int> sp1(p1), sp2(p2);
	SmartPointer<int> sp3 = sp1;
	sp2 = sp3;
	return 0;
}

