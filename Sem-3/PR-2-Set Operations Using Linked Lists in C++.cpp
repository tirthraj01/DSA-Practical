
#include <iostream>
using namespace std;

// Step 1: Create a linked list node
struct Node
{
    int prn;
    Node *next;
};

// Step 2: Check if a student exists in a list
bool contains(Node *head, int x)
{
    while (head)
    {
        if (head->prn == x)
            return true;
        head = head->next;
    }
    return false;
}

// Step 3: Insert a student into the list
void insert(Node *&head, int x)
{
    // Avoid duplicate PRNs
    if (contains(head, x))
        return;

    Node *node = new Node{x, nullptr};

    // If list is empty
    if (!head)
    {
        head = node;
        return;
    }

    // Go to the last node
    Node *p = head;
    while (p->next)
        p = p->next;

    p->next = node;
}

int main()
{
    // Step 4: Create two empty linked lists
    Node *A = nullptr, *B = nullptr;
    int total, n, x, count = 0;

    // Input total number of students
    cout << "Total students: ";
    cin >> total;

    // Input students liking Vanilla
    cout << "Students liking Vanilla: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(A, x);
    }

    // Input students liking Butterscotch
    cout << "Students liking Butterscotch: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(B, x);
    }

    // Step 5: UNION (A or B or both)
    cout << "Union: ";

    // Print all students from A
    for (Node *p = A; p; p = p->next)
    {
        cout << p->prn << " ";
        count++;
    }

    // Print students from B not present in A
    for (Node *p = B; p; p = p->next)
        if (!contains(A, p->prn))
        {
            cout << p->prn << " ";
            count++;
        }

    // Step 6: INTERSECTION (Both)
    cout << "\nBoth: ";
    for (Node *p = A; p; p = p->next)
        if (contains(B, p->prn))
            cout << p->prn << " ";

    // Step 7: Only Vanilla (A - B)
    cout << "\nOnly Vanilla: ";
    for (Node *p = A; p; p = p->next)
        if (!contains(B, p->prn))
            cout << p->prn << " ";

    // Step 8: Only Butterscotch (B - A)
    cout << "\nOnly Butterscotch: ";
    for (Node *p = B; p; p = p->next)
        if (!contains(A, p->prn))
            cout << p->prn << " ";

    // Step 9: Students liking neither
    cout << "\nNeither: " << total - count << endl;

    return 0;
}


Algorithm
1. Start.
2. Create two linked lists, A and B.
3. Read the number of students who like Vanilla.
4. Insert their details into linked list A.
5. Read the number of students who like Butterscotch.
6. Insert their details into linked list B.
7. Find Union (A ∪ B):
   - Traverse linked list A and display all students.
   - Traverse linked list B.
   - Display only students who are not already present in A.
8. Find Intersection (A ∩ B):
   - Traverse linked list A.
   - Check whether each student is present in B.
   - Display students present in both lists.
9. Find Only Vanilla (A - B):
   - Traverse linked list A.
   - Display students who are not present in B.
10. Find Only Butterscotch (B - A):
    - Traverse linked list B.
    - Display students who are not present in A.
11. Find students who like neither:
    - Read the total number of students in the class.
    - Count the unique students present in A or B.
    - Calculate:
    \[
    \text{Neither} = \text{Total Students} - |A \cup B|
    \]
12. Display all results.
13. Stop.
