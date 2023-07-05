#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include <Mmsystem.h>
#include <ctime>
#include <cmath>
#include <string>
#include <stack>

using namespace std;
struct Node // node ka structure -->
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *prv;
void insert(int newdata)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    newnode->data = newdata;
    newnode->next = head;
    if (head != NULL)
    {
        while (ptr->next != head)
            ptr = ptr->next;

        ptr->next = newnode;
    }
    else
        newnode->next = newnode; //  10...
    head = newnode;
}
void slow()
{
    for (int i = 0; i < 30000000; i++)
        cout << "";
}

void deleteNode(int key) // 1
{
    if (head->data == key)
    {

        head = head->next; // 1..4..3..2..5
    }

    // Find the required node
    struct Node *curr = head, *prev;
    while (curr->data != key)
    {

        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    free(curr);
}
struct Node *ptr;

void display(Node *temp)
{
    ptr = temp;
    clock_t clockVariable;
    clockVariable = clock();

    //PlaySound(TEXT("song.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
    while (ptr != NULL && (clock() - clockVariable) / CLOCKS_PER_SEC < 5.0)
    {
        cout << ptr->data << " "; // 5 4 3 2 1   1

        slow();
        prv = ptr; // 1
        ptr = ptr->next;
    }
}
stack<int> s;
int n;
void start()
{
    int a;
    cout << "Each player can choose a number to represent him" << endl;
    cout << "Enter the player numbers" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        insert(a);
    }
    cout << "The circular linked list is: ";
    display(head);
    cout << "-->" << prv->data;
    s.push(prv->data);
    deleteNode(prv->data);
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        cout << "The circular linked list is: ";
        display(ptr);
        cout << "-->" << prv->data;
        s.push(prv->data);
        deleteNode(prv->data);
        cout << endl;
    }
    cout << "winner is " << prv->data << endl;
    cout << "Leaderboard is :" << endl;
    while (!s.empty())
    {
        cout << ' ' << s.top();
        s.pop();
    }
    cout << endl;
}

bool buyticket()
{
    int amount;
    bool flag = false;
    cout << "Enter number of players" << endl;
    cin >> n;
    int bill = n * 50;
    int temp = bill;
    cout << "Due amount:" << bill << endl;
    cout << "Enter the amount to pay: " << endl;

    while (temp > 0)
    {
        cin >> amount;
        temp = temp - amount; // 250...90...160
        if (temp < 0)
        {
            cout << "Take " << amount - bill << "Rs back" << endl;
            cout << "No due amount left,you can now start the game" << endl;
            flag = true;
            break;
        }

        else if (temp == 0)
        {
            cout << "No due amount left,you can now start the game" << endl;
            cout << endl;
            flag = true;
            break;
        }
        else if (temp > 0)
        {
            cout << "Pending amount: " << temp << endl;
            cout << "Enter the due amount: " << endl;
        }
    }
    return flag;
}

int main()
{
    system("COLOR 0A");
    bool check = false;
    while (1)
    {

        int choice, a;

        cout << "1.Buy the ticket" << endl;
        cout << "2.Start the game" << endl;

        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {

        case 1:
            check = buyticket();
            break;
        case 2:
            if (check)
            {
                start();
                break;
            }
            else
            {
                cout << "Ticket not bought" << endl;
                break;
            }
        }
    }
}
