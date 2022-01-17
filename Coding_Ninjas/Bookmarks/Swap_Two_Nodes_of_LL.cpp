/*
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' 
Swap the nodes that are present at the 'i-th' and 'j-th' positions.

Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4

Sample Output 1 :
3 4 5 6 2 1 9 

Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6

Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
*/

#include<iostream>
using namespace std;

class Node
{
   public:
      int data;
      Node *next;

      Node(int data)
      {
          this->data = data;
          this->next = NULL;
      }
};

Node* takeinput()
{
    int data;
    cin>>data;

    Node *head = NULL, *tail = NULL;

    while(data != -1)
    {
        Node *newNode = new Node(data);
        
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }

        cin>>data;
    }
    tail->next = NULL;
    return head;
}

void print(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    Node *temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

Node* swapNodes(Node* head, int i, int j)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    if(i == j)
    {
        return head;
    }

    Node* temp = head;
    Node *prev1 = NULL, *node1 = NULL;
    Node *prev2 = NULL, *node2 = NULL;
    int mini,maxi;
    
    mini = min(i,j);
    maxi = max(i,j);

    int count = 0;

    while(count != maxi && temp != NULL)
    {
        count++;

        if(mini == count)
        {
            prev1 = temp;
            node1 = temp->next;
        }

        if(maxi == count)
        {
            prev2 = temp;
            node2 = temp->next;
        }

        temp = temp->next;
    } 

    if((i == 0 || j == 0) && abs(i-j) == 1)
    {
        head->next = node2->next;
        node2->next = head;
        head = node2;
    } 
    else if((i == 0 || j == 0))
    {
        Node* nxt = head->next;
        head->next = node2->next;
        node2->next = nxt;
        prev2->next = head;
        head = node2;
    }
    else if(abs(i-j) == 1)
    {
        prev1->next = node2;
        node1->next = node2->next;
        node2->next = node1;
    }
    else
    {
        prev1->next = node2;
        prev2->next = node1;

        Node *nxt = node2->next;

        node2->next = node1->next;
        node1->next = nxt;
    }
    return head;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int i,j;

        Node *head = takeinput();
        cin>>i;
        cin>>j;

        head = swapNodes(head,i,j);
        print(head);
    }
    return 0;
}
