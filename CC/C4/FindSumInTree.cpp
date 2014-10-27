#include <iostream>
#include <vector>

using namespace std;

//used to represent binary tree
class Node
{
  protected:
      Node* left;
      Node* right;
      int value;
  public:
      Node(Node* l, Node* r, int val):left(l), right(r), value(val){}
      Node(int val):left(NULL), right(NULL), value(val){}

      Node* getLeft() {return left;}
      Node* getRight() {return right;}
      int getValue() {return value;}
      void setLeft(Node* l) {left = l;}
      void setRight(Node* r) {right = r;}
      void setLeft(int val) {value = val;}
};

void findSumInTree(Node* root, int target, vector<Node*> buf)
{
    if(root == NULL)
    {
        return;
    }

    buf.push_back(root);

    //attention: print in the reverse order can save a lot of effort!
    int tmp = target;
    for(int i=buf.size()-1; i>=0; i--)
    {
        tmp -= buf[i]->getValue();

        //print if get hit.
        if(tmp == 0)
        {
            for(int j=buf.size()-1; j>=i; j--)
            {
                cout<<buf[j]->getValue()<<", ";
            }
            cout<<endl;
        }
    }

    //attention: buf actually is doing hard copy, so it's fine.
    findSumInTree(root->getLeft(), target, buf);
    findSumInTree(root->getRight(), target, buf);
}

int main()
{
	Node n24(16);
	Node n23(13);
	Node n22(9);
	Node n21(3);
	Node n12(&n23, &n24, 15);
	Node n11(&n21, &n22, 7);
	Node root(&n11, &n12, 10);	

    vector<Node*> buf;
    findSumInTree(&root, 10, buf);
    findSumInTree(&root, 16, buf);
}
