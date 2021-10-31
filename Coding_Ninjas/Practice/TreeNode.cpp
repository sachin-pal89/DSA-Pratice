#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class TreeNode
{
    public:
      T data;
      vector<TreeNode<T>*> children;

      TreeNode(){}

      TreeNode(T data)
      {
          this->data = data;
      }

      // To Take input level wise using queue
      TreeNode<T>* inputNodeLevel()
      {
          T rootData;
          cout<<"Enter the data of root "<<endl;
          cin>>rootData;

          TreeNode<T>* root = new TreeNode<T>(rootData);

          queue<TreeNode<T>*> pendingNodes;

          pendingNodes.push(root);

          while(!pendingNodes.empty())
          {
              TreeNode<T>* front = pendingNodes.front();
              pendingNodes.pop();

              int numChild;
              cout<<"Enter the no of children node of "<<front->data<<endl;
              cin>>numChild;

              for(int i=0; i<numChild; i++)
              {
                  T nodeData;
                  cout<<"Enter the "<<i<<"th element of "<<front->data<<endl;
                  cin>> nodeData;

                  TreeNode<T>* child = new TreeNode<T>(nodeData);

                  front->children.push_back(child);
                  pendingNodes.push(child);
              }
          }

          return root;
      }



      // To take input for tree
     /* TreeNode<T>* inputNode()
      {
          T nodeData;
          cout<<"Enter the data "<<endl;
          cin>>nodeData;

          TreeNode<T>* node = new TreeNode<T>(nodeData);

          int n;
          cout<<"Enter the number of Children "<<endl;
          cin>>n;

          for(int i=0 ; i<n; i++)
          {
              TreeNode<T>* next = inputNode();
              node->children.push_back(next);
          }

          return node;
      }
      */

      // To print Tree level wise using queue
      void printNodeLevel(TreeNode<T>* root)
      {
          if(root == NULL)
          {
              return;
          }

          queue<TreeNode<T>*> printNode;

          printNode.push(root);

          while(!printNode.empty())
          {
              TreeNode<T>* front = printNode.front();
              printNode.pop();

              cout<<front->data<<":";

              for(int i=0; i<front->children.size(); i++)
              {
                  TreeNode<T>* x = front->children[i];
                  printNode.push(x);
                  cout<<x->data;
                  if(i+1 != front->children.size())
                  {
                      cout<<",";
                  }
              }
              cout<<endl;
          }
      }

      // To print a tree
      /* void printNode(TreeNode<T>* root)
      {
          if(root == NULL)
          {
              return;
          }

          cout<<root->data<<": ";

          for(int i=0 ; i<root->children.size() ; i++)
          {
              cout<<root->children[i]->data<<",";
          }
          cout<<endl;

          for(int i=0; i<root->children.size(); i++)
          {
              printNode(root->children[i]);
          }
      }
      */
};

int main()
{
    // To Take input
    
    
    TreeNode<char>* root = new TreeNode<char>();

    TreeNode<char>* x = root->inputNodeLevel();
    root->printNodeLevel(x);

    return 0;
}