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

// To Print the linked list
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return;
}

// To Remove Duplicates from the given Linked List

/* First Approach
Node *RemoveDuplicates(Node *head)
{
    // If Linked list is empty
    if (head == NULL)
    {
        return NULL;
    }

    // If next nodes data is duplicate of current element and also current node should not be the last node
    while ( head->next != NULL && head->data == head->next->data)
    {
        head->next = head->next->next;
    }

    // To connect our current head with updated linked list
    head->next = RemoveDuplicates(head->next);

    return head;
}
*/

// Faster Approach :- Two Pointer approach
Node *Calci(Node *temp1, Node *temp2)
{
    // If our current node reached at last node
    if (temp2 == NULL && temp1->next == NULL)
    {
        return temp1;
    }

    // If we have suitation where our second node pointer reach out of linked list but first Node pointer is not at last
    if (temp2 == NULL && temp1->next != NULL)
    {
        temp1->next = NULL;
        return temp1;
    }

    // If the data of two Node pointers are same
    if (temp1->data == temp2->data)
    {
        Node *x = temp2;
        temp2 = temp2->next;
        Node *y = Calci(temp1, temp2);
        delete x;
        return y;
    }
    else
    {

        temp1->next = Calci(temp2, temp2->next);
        return temp1;
    }
}

Node *RemoveDuplicates(Node *head)
{
    // if linked list is empty
    if (head == NULL)
    {
        return NULL;
    }

    Node *ans = Calci(head, head->next);

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();

        head = RemoveDuplicates(head);

        print(head);
    }

    return 0;
}