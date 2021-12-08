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

// To insert Node in Linked List at given position recursively
Node *insertNode(Node *head, Node *prev, int pos, int data)
{
    // No Node in a Linked Lists
    if (head == NULL)
    {
        return NULL;
    }

    // If element is to be removed is at starting
    if (prev == NULL && pos == 0)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        return head;
    }

    // If element is to be removed
    if (pos == 0)
    {
        Node *temp = new Node(data);
        temp->next = head;
        prev->next = temp;
        return temp;
    }

    // Thus connect current node with updated linked list
    head->next = insertNode(head->next, head, pos - 1, data);

    return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();

        int pos, data;
        cin >> pos >> data;

        head = insertNode(head, NULL, pos, data);

        print(head);
    }

    return 0;
}