#include<iostream>
using namespace std;

class Node
{   
   public:
    int data;
    Node* next;
   
   Node(int data)
   {
       this -> data = data;
       next = NULL;
   }
};


// Inserting a node recursively
Node* insert(Node* head,int i,int data)
{
    if(head==NULL)
    {
        return head;
    }

    if(i==0)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    if(head==NULL && i==0)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return head;
    }

    Node* x = insert(head->next,i-1,data);
    head->next = x;
    return head;
}

/*
Node* insert(Node* head,int i,int data)
{   
    Node* newNode = new Node(data);

    if(i==0)
    {
       newNode->next = head;
       head = newNode;
       return head;
    }
    
    int count=0;
    Node* temp = head;

    while(count < i-1 && temp != NULL)
    {
        temp = temp -> next;
        count++;
    }

    if(temp != NULL)
    {   
        newNode->next = temp -> next;
        temp -> next = newNode;
    }

    return head;
}
*/

//Delete a node from linked list recursively
Node* remove(Node* head,int i)
{
    if(head==NULL)
    {
        return head;
    }

    if(i==0)
    {   
        Node* x = head;
        head = head->next;
        delete x;
        return head;
    }

    Node* x = remove(head->next,i-1);
    head->next = x;
    return head;

}

/*
Node* remove(Node* head,int i)
{   
    if(head == NULL)
       return head;
    

    if(i==0)
    {
       Node* a = head;
       head = head->next;
       delete a;
       return head;
    }

    int count=0;
    Node* temp = head;
    while(count < i-1 && temp != NULL)
    {
        temp = temp -> next;
        count++;
    }
    
    if(temp != NULL && temp->next == NULL)
    {
        return head;
    }
    
    if(temp !=NULL )
    {
        Node* x = temp -> next;
        temp -> next = x -> next;
        delete x;
    }

    return head;
}
*/

Node* input()
{
    int data;
    cin>>data;

    Node* head = NULL;
    Node* tail = NULL;

    while(data != -1)
    {
        Node* newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode; 
        }
        else{
             tail -> next = newNode;
             tail = tail -> next;
        }

        cin>>data;
    }

    return head;
}

void print(Node* head)
{
   // Storing the address of the head pointer in a temporary pointer of type node
   Node* temp = head;

   while(temp != NULL)
   {
       cout<< temp -> data <<" ";
       temp = temp -> next;
   }
   cout<<endl;
}


int main()
{   
    Node* head = input();
    print(head);
    
    int i,data;
    cin>>i;
    cin>>data;
    // function for inserting an node in the linked list
    head = insert(head,i,data);
    print(head);

    // function for removing an node from linked list
    int j;
    cin>>j;
    head = remove(head,j);
    print(head);

    /*
    //Static Linked list
    
    // Adding nodes in linked list
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    
    // Creating head to store address of first node
    Node* head = &n1;
    
    // Storing address of next node in current node next
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    
    // Function to print the element of nodes in the linked list
    print(head);
    
    
    // Dynamic Linked List
    Node *n12 = new Node(10);
    Node *n13 = new Node(20);

    Node* dynahead = n12;
    
    n12 -> next = n13;
    
    print(dynahead);
    
    */

    return 0;
}