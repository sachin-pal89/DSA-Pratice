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

     // To count no.of Nodes in the tree
     int numNodes(TreeNode<T>* root)
     {
         if(root == NULL)
         {
             return 0;
         }

         int ans = 1;

         for(int i=0; i<root->children.size(); i++)
         {
             ans += numNodes(root->children[i]);
         }

         return ans;
     }

     // Sum of all nodes data
     T sumNodes(TreeNode<T>* root)
     {
         if(root == NULL)
         {
             return 0;
         }

         T sum = root->data;

         for(int i=0; i<root->children.size(); i++)
         {
             sum  += sumNodes(root->children[i]);
         }

         return sum;
     }

     //To get Node with maximum data value in the tree
     TreeNode<T>* maxValueNode(TreeNode<T>* root)
     {
         if(root == NULL)
         {
             return root;
         }

         T max = root->data;
         TreeNode<T>* ans = root;

         for(int i=0; i<root->children.size(); i++)
         {
             TreeNode<T>* x = maxValueNode(root->children[i]);

             if(max < x->data)
             {
                 max = x->data;
                 ans = x;
             }
         }

         return ans;
     }
     
     // To print nodes data which are at depth k from root
     void nodeAtDepth(TreeNode<T>* root, int k)
     {
         if(root == NULL)
         {
             return ;
         }

         if(k == 0)
         {
             cout<<root->data<<endl;
             return;
         }

         for(int i=0; i<root->children.size(); i++)
         {
             nodeAtDepth(root->children[i], k-1);
         }
     }

     // To find height of the tree
     int treeHeight(TreeNode<T>* root)
     {
         if(root == NULL)
         {
             return 0;
         }

         int height = 1;
         int max = 0;

         for(int i=0; i<root->children.size(); i++)
         {
             int x = treeHeight(root->children[i]);

             if(max < x)
             {
                 max = x;
             }
         }

         return max + height;
     }

     // Count of leaf Node
     int countLeaf(TreeNode<T>* root)
     {
         if(root == NULL)
         {
             return 0;
         }

         if(root->children.empty())
         {
             return 1;
         }

         int count = 0;

         for(int i=0; i<root->children.size(); i++)
         {
            count += countLeaf(root->children[i]);
         }

         return count;
     }

     // To print tree in post order
     void printPostOrder(TreeNode<T>* root)
     {
         if(root == NULL)
         {
             return;
         }

         if(root->children.empty())
         {
             cout<<root->data<<" ";
             return;
         }

         for(int i=0; i<root->children.size(); i++)
         {
             printPostOrder(root->children[i]);
         }
         
         cout<<root->data<<" ";
         return;
     }

     // Destructor
     ~TreeNode()
     {
         for(int i=0; i< children.size(); i++)
         {
             delete children[i];
         }
     }
};

int main()
{
    // To Take input
    
    
    TreeNode<int>* root = new TreeNode<int>();

    root = root->inputNodeLevel();
    root->printNodeLevel(root);

    cout<<"No.of nodes is "<<root->numNodes(root)<<endl;

    cout<<"Post order print "<<endl;
    root->printPostOrder(root);
    cout<<endl;

    cout<<"Sum of all Nodes is "<<root->sumNodes(root)<<endl;

    TreeNode<int>* x = root->maxValueNode(root);
    if(x != NULL)
    {
        cout<<"maximum node value in tree is "<<x->data<<endl;
    }

    cout<<"height of the tree is "<<root->treeHeight(root)<<endl;

    cout<<"Number of Leaf Node in tree is "<<root->countLeaf(root)<<endl;

    int k;
    cout<<"Enter the Depth at which element is to be found ";
    cin>>k;

    cout<<"Node at Depth "<<k<<" is "<<endl;
    root->nodeAtDepth(root,k);

    delete root;

    return 0;
}