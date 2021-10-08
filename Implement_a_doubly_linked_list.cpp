// /*
//     PRIYANSHU IS A PEACEFULL SOUAL
// */
// #include <bits/stdc++.h>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *next;
//     node *prev;
//     node(int val)
//     {
//         data = val;
//         next = NULL;
//         prev = NULL;
//     }
// };
// int Count = 1;
// void insert_at_beginning(node *&head, int val)
// {
//     node *n = new node(val);
//     n->next = head;

//     if (head == NULL)
//     {
//         head = n;
//         Count++;
//     }
//     else if (Count < 10)
//     {
//         head->prev = n;
//         Count++;
//     }
//     else
//     {
//         printf("List can not accommodate more than 10 elements");
//         return;
//     }
// }
// void insert_at_end(node *&head, int val)
// {
//     node *n = new node(val);
//     node *temp = head;
//     if (head == NULL)
//     {
//         insert_at_beginning(head, val);
//         return;
//     }

//     else if (Count < 10)
//     {
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = n;
//         n->prev = temp;
//         Count++;
//     }
//     else
//     {
//         printf("List can not accommodate more than 10 elements");
//         exit(0);
//     }
// }
// void delete_from_beginning(node *&head)
// {
//     if (head == NULL)
//     {
//         printf("INVALID SEQUENCE OF COMMANDS");
//         exit(0);
//     }
//     node *temp = head;
//     head = head->next;
//     head->prev = NULL;
//     delete temp;
// }
// void delete_from_end(node *&head)
// {
//     if (head == NULL)
//     {
//         printf("INVALID SEQUENCE OF COMMANDS");
//         exit(0);
//     }
//     node *p = head;
//     node *q = head->next;
//     while (q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }

//     p->next = NULL;
//     delete q;
// }

// void print_list(node *head)
// {
//     if (head == NULL)
//     {
//         cout << "List is Empty";
//         exit(0);
//     }
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }
// node *reverseRecursion(node *&head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     node *newHead = reverseRecursion(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return newHead;
// }
// int main()
// {
//     node *head = NULL;
//     node *newHead;
//     int k = 1;
//     while (k)
//     {
//         int input;
//         cin >> input;
//         int value;
//         switch (input)
//         {
//         case 0:
//             cin >> value;
//             insert_at_beginning(head, value);
//             break;
//         case 1:
//             cin >> value;
//             insert_at_end(head, value);
//             break;

//         case 2:
//             delete_from_beginning(head);
//             break;

//         case 3:
//             delete_from_end(head);
//             break;
//         case 4:
//             print_list(head); //code 4
//             newHead = reverseRecursion(head);
//             print_list(newHead);
//             k = 0;
//             break;
//         default:
//             printf("INVALID SEQUENCE OF COMMANDS");
//             break;
//         }
//     }
//     return 0;
// }

// // void insert_at_beginning(int value);    //code 0
// // void insert_at_end(int value);          //code 1
// // void delete_from_beginning();           //code 2
// // void delete_from_end();                 //code 3
// // void print_list();                      //code 4
/*
    PRIYANSHU IS A PEACEFULL SOUAL
*/
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
int Count = 1;

void insert_at_beginning(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
        Count++;
    }
    else if (Count > 10)
    {
        printf("List can not accommodate more than 10 elements");
        exit(0);
    }
    head = n;
    Count++;
}
void insert_at_end(node *&head, int val)
{
    if (head == NULL)
    {
        insert_at_beginning(head, val);
        return;
    }
    else if (Count > 10)
    {
        printf("List can not accommodate more than 10 elements");
        exit(0);
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    Count++;
}
void delete_from_beginning(node*head)
{
    if (head == NULL)
    {
        cout<<"INVALID SEQUENCE OF COMMANDS";
        exit(0);
    }
    node *temp = head;
    head = head->next;
    free(temp);
    Count--;
}
void delete_from_end(node*head)
{
    if (head == NULL)
    {
        cout<<"INVALID SEQUENCE OF COMMANDS";
        exit(0);
    }
    node*tail=NULL;
    node *temp = tail;
    tail = tail->prev;
    free(temp);
    Count--;
}

void print_list(node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty";
        exit(0);
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
node *reverseRecursion(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newHead = reverseRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
int main()
{
    node *head = NULL;
    node *newHead;
    int choice, val, i = 0;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 0:
            cin >> val;
            insert_at_beginning(head, val);
            break;
        case 1:
            cin >> val;
            insert_at_end(head, val);
            break;
        case 2:
            delete_from_beginning(head); //code 2
            break;
        case 3:
            delete_from_end(head); //code 3
            break;
        case 4:
            print_list(head); //code 4
            newHead = reverseRecursion(head);
            print_list(newHead);
            break;
        default:
            printf("INVALID SEQUENCE OF COMMANDS");
        }

    } while (choice != 4);
    return 0;
}

// void insert_at_beginning(int value);    //code 0
// void insert_at_end(int value);          //code 1
// void delete_from_beginning();           //code 2
// void delete_from_end();                 //code 3
// void print_list();                      //code 4
