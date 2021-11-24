#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

template <typename T>
class BinaryTree
{
   public:
      T data;
      BinaryTree<T>* left;
      BinaryTree<T>* right;

      BinaryTree(){}
      BinaryTree(T data)
      {
          this->data = data;
          left = NULL;
          right = NULL;
      }

      // To Take Input for the Binary Tree
      /*BinaryTree<T>* inputBTree()
      {
          T rootData;
          cout<<"Enter Data"<<endl;
          cin>>rootData;

          if(rootData == -1)
          {
              return NULL;
          }

          BinaryTree<T>* root = new BinaryTree<T>(rootData);
          BinaryTree<T>* leftChild = inputBTree();
          BinaryTree<T>* rightChild = inputBTree();

          if(leftChild != NULL)
          {
              root->left = leftChild;
          }

          if(rightChild != NULL)
          {
              root->right = rightChild;
          }

          return root;
      }*/

      // To Take input LevelWise for Binary Tree
      BinaryTree<T>* inputBTreeLevelWise()
      {
          T rootData;
          cout<<"Enter the root data "<<endl;
          cin>> rootData;

          if(rootData == -1)
          {
              return NULL;
          }

          BinaryTree<T>* root = new BinaryTree<T>(rootData);

          queue<BinaryTree<T>*> pendingNodes;
          pendingNodes.push(root);

          while(!pendingNodes.empty())
          {
              BinaryTree<T>* front = pendingNodes.front();
              pendingNodes.pop();

              T leftChildData;
              cout<<"Enter the left child data of "<<front->data<<endl;
              cin>>leftChildData;

              if(leftChildData != -1)
              {
                  BinaryTree<T>* child = new BinaryTree<T>(leftChildData);
                  front->left = child;
                  pendingNodes.push(child);
              }
              
              T rightChildData;
              cout<<"Enter the right child data of "<<front->data<<endl;
              cin>>rightChildData;

              if(rightChildData != -1)
              {
                  BinaryTree<T>* child = new BinaryTree<T>(rightChildData);
                  front->right = child;
                  pendingNodes.push(child);
              }
          }

          return root;
      }
      
      // To Count No of nodes in Binary Tree
      int numberNodes(BinaryTree<T>* root)
      {
          if(root == NULL)
          {
              return 0;
          }

          return 1 + numberNodes(root->left) + numberNodes(root->right);
      }

      // To Print the Binary Tree
      /*void printBTree(BinaryTree<T>* root)
      {
         if(root == NULL)
         {
             return;
         }

         cout<<root->data<<": ";

         if(root->left != NULL)
         {
             cout<<"L"<<root->left->data<<" ";
         }

         if(root->right != NULL)
         {
             cout<<"R"<<root->right->data<<" ";
         }
         cout<<endl;

         printBTree(root->left);
         printBTree(root->right);
      }
      */

     // To find a node in the Binary Tree
     bool findNode(BinaryTree<T>* root, T x)
     {
         if(root == NULL)
         {
             return false;
         }

         if(root->data == x)
         {
             return true;
         }

         return findNode(root->left,x) || findNode(root->right,x);
     }

     // To find height of Binary Tree
     int heightBTree(BinaryTree<T>* root)
     {
         if(root == NULL)
         {
             return 0;
         }

         int x = heightBTree(root->left);
         int y = heightBTree(root->right);

         return 1 + max(x,y);
     }
     
     // To Mirror a given tree
     void mirrorBTree(BinaryTree<T>* root)
     {
         if(root == NULL)
         {
             return;
         }

         BinaryTree<T>* help = root->left;
         root->left = root->right;
         root->right = help;

         mirrorBTree(root->left);
         mirrorBTree(root->right);

         return;
     }

     // To get Diameter of a Binary Tree
     pair<int, int> heightDiameter(BinaryTree<T>* root)
     {
         if(root == NULL)
         {
             pair<int, int> p;
             p.first = 0;
             p.second = 0;
             return p;
         }

         pair<int, int> leftPair = heightDiameter(root->left);
         pair<int, int> rightPair = heightDiameter(root->right);

         int Height = 1 + max(leftPair.first, rightPair.first);
         int Diameter = max(leftPair.first + rightPair.first ,max(leftPair.second, rightPair.second));

         pair<int, int> ans;
         ans.first = Height;
         ans.second = Diameter;

         return ans;
     }

     // To print the Node Path in a Binary Tree
     vector<int>* NodeToPath(BinaryTree<int>* root,int k)
     {
         if(root == NULL)
         {
             return NULL;
         }

         if(root->data == k)
         {
             vector<int>* output = new vector<int>();
             output->push_back(root->data);
             return output;
         }

         vector<int>* Loutput = NodeToPath(root->left,k);
         if(Loutput != NULL)
         {
            Loutput->push_back(root->data);
            return Loutput;
         }

        vector<int>* Routput = NodeToPath(root->right,k);
        if(Routput != NULL)
        {
            Routput->push_back(root->data);
            return Routput;
        }
        else{
            return NULL;
        }

     }

     // To print the Binary Tree Level wise;
     void printBTreeLevelWise(BinaryTree<T>* root)
     {
         if(root == NULL)
         {
             return;
         }

         queue<BinaryTree<T>*> printNode;
         printNode.push(root);

         while(!printNode.empty())
         {
             BinaryTree<T>* front = printNode.front();
             printNode.pop();

             cout<<front->data<<": ";
            
            if(front->left != NULL)
            {
                cout<<"L:"<<front->left->data<<",";
                printNode.push(front->left);
            }
            else{
                cout<<"L:"<<-1<<",";
            }

            if(front->right != NULL)
            {
                cout<<"R:"<<front->right->data;
                printNode.push(front->right);
            }
            else{
                cout<<"R:"<<-1;
            }

            cout<<endl;
         }
     }

      ~BinaryTree()
      {
          delete left;
          delete right;
      }
};

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 
int main()
{
    BinaryTree<int>* root = new BinaryTree<int>();

    root = root->inputBTreeLevelWise();
    root->printBTreeLevelWise(root);
    
    cout<<"No of nodes in Binary Tree is "<< root->numberNodes(root)<<endl;
    
    /*
    cout<<"Check if 3 is present "<<root->findNode(root,3)<<endl;

    cout<<"Height of the Binary Tree is "<<root->heightBTree(root);

    cout<<"Mirror the Binary Tree "<<endl;
    root->mirrorBTree(root);

    cout<<"Mirrored Binary Tree is: "<<endl;
    root->printBTreeLevelWise(root);

    pair<int, int> BTree = root->heightDiameter(root);

    cout<<"Height : "<<BTree.first<<endl;
    cout<<"Diameter : "<<BTree.second<<endl;

    */

    vector<int>* ans = root->NodeToPath(root,5);

    for(int i=0; i< ans->size(); i++)
    {
        cout<<ans->at(i)<<" ";
    }
    delete ans;

    delete root;
    return 0;
}