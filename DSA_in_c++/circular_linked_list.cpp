#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    while (temp->next != head) //reaches the end of the node
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{

    node *n = new node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *temp = head;

    while (temp->next != head) //reaches the end of the node
    {
        temp = temp->next;
    }
    temp->next = n; //insert at the tail
    n->next = head;
}

void display(node *head) //not modifying
{
    node *temp = head;
    do{
        cout << temp->data << "->";
        temp = temp->next;
    }while (temp!=head );
    cout << "NULL" << endl;
}

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    node* todelete=head;
    temp->next=head->next;
    head=head->next;
    delete todelete;
}

void deletion(node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    if (pos==1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count=1;
    while (count!=pos-1) //reach the element preceeding the element to be deleted
    {
        temp = temp->next;
        count++;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next; //changing the link to the successive element of the deleted element
    delete todelete;
}


int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    deletion(head,1);
    display(head);
}