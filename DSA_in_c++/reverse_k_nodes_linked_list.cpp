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
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{

    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;

    while (temp->next != NULL) //reaches the end of the node
    {
        temp = temp->next;
    }
    temp->next = n; //insert at the tail
}

void display(node *head) //not modifying
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *todelete = head;
    head = head->next; // to change the head to the next element
    delete todelete;
}

void deletion(node *&head, int key)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next = NULL)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != key) //reach the element preceeding the element to be deleted
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next; //changing the link to the successive element of the deleted element
    delete todelete;
}

node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr; //reverse the link

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

node *reverseRecursion(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = reverseRecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node *reversek(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    int count = 0;
    while (currptr != NULL && count<k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr; //reverse the link

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
        head->next = reversek(nextptr, k);
    return prevptr;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    node *newhead = reversek(head,2);
    display(newhead);
}