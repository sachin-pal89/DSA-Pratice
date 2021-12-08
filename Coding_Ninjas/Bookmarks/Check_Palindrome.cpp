#include <iostream>
using namespace std;

// Node Class
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

// To take input nodes
Node *takeinput()
{
    int data;
    cin >> data;

    Node *head = NULL, *tail = NULL;

    while (data != -1)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }

        cin >> data;
    }

    return head;
}

// To get Length of linked list
int getLength(Node* head)
{
    if(head == NULL)
    {
        return 0;
    }

    Node* temp = head;
    int length = 0;

    while(temp != NULL)
    {
       length++;
       temp = temp->next;
    }

    return length;
}

// To check if given linnked list is palindrome or not
bool palindromeHelper(Node* head, int start, int end)
{
    // If linked satisfy condition for all nodes
    if(start >= end)
    {
        return true;
    }
    
    Node* tail = head;

    // To get to the last node with respect to current node for checking the palindrome
    for(int i = start; i < end; i++)
    {
        tail = tail->next;
    }
    
    // If data of first and last are not same then it is not a palindrome
    if(head->data != tail->data)
    {
        return false;
    }

    return palindromeHelper(head->next,start+1,end-1);
}

// To get result of palindrome for a linked list
bool checkPalindrome(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    int length = getLength(head);

    return palindromeHelper(head,0,length-1);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        Node* head = takeinput();

        bool ans = checkPalindrome(head);

        if(ans)
           cout<<"true"<<endl;
        else
           cout<<"false"<<endl;
    }

    return 0;
}