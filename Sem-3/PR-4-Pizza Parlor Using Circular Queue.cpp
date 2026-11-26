
#include <iostream>
using namespace std;

int main() {
    int q[100], M, front = -1, rear = -1;
    int choice, order = 1;

    cout << "Enter maximum orders: ";
    cin >> M;

    do {
        cout << "\n\n1. Place Order";
        cout << "\n2. Serve Order";
        cout << "\n3. Display Orders";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        // Place order
        if (choice == 1) {
            if ((rear + 1) % M == front) {
                cout << "Queue is Full!";
            }
            else {
                if (front == -1)
                    front = rear = 0;
                else
                    rear = (rear + 1) % M;

                q[rear] = order++;
                cout << "Order placed!";
            }
        }

        // Serve order
        else if (choice == 2) {
            if (front == -1) {
                cout << "No orders!";
            }
            else {
                cout << "Serving Order: " << q[front];

                if (front == rear)
                    front = rear = -1;
                else
                    front = (front + 1) % M;
            }
        }

        // Display orders
        else if (choice == 3) {
            if (front == -1) {
                cout << "No pending orders!";
            }
            else {
                cout << "Pending Orders: ";
                int i = front;

                while (true) {
                    cout << q[i] << " ";
                    if (i == rear) break;
                    i = (i + 1) % M;
                }
            }
        }

    } while (choice != 4);

    return 0;
}


Algorithm
1. Start.
2. Read the maximum number of orders M.
3. Initialize front = -1 and rear = -1.
4. Display the menu.
5. If the user selects Place Order:
   - Check whether the queue is full.
   - If full, display "Queue is Full".
   - Otherwise, insert the new order at the rear.
6. If the user selects Serve Order:
   - Check whether the queue is empty.
   - If empty, display "No Orders".
   - Otherwise, serve the order at the front and move front forward.
7. If the user selects Display Orders:
   - Display all pending orders from front to rear.
8. Repeat until the user selects Exit.
9. Stop.
