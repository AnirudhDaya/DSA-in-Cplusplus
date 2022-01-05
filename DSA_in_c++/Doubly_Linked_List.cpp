#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
        head->prev = n;

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

    while (temp->next != NULL) //reaches the end of the node
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
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
    head->prev=NULL;
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
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next; //change the link of element precceeding to the element suceeding
    if (temp->next != NULL)
        temp->next->prev = temp->prev; //change the link of element succeeding to the element preeceeding
    delete temp;
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
    while (currptr != NULL && count < k)
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

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1; //to reach the position where you want to start a cycle
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode; //complete the cycle
}

bool detectCycle(node *&head)
{
    node *slow = head; //tortoise
    node *fast = head; //hare
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(node *&head)
{
    node *slow = head; //tortoise
    node *fast = head; //hare
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
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
    deletion(head,1);
    display(head);
}