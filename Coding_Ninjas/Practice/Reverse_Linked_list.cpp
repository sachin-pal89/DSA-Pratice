#include <iostream>

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

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL;
    Node *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* reverse(Node* head, Node* temp)
{
   if(head == NULL || head->next == NULL)
       {
           head->next = temp;
           return head;
       }

    Node* y = head->next;
    head->next = temp;

    return reverse(y,head);
}

Node* reverseLinkedListRec(Node* head)
{
    if(head==NULL)
       return NULL;
    
   return reverse(head,NULL);
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}
