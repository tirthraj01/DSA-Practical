#include <iostream>
#include <string>
using namespace std;

// Step 1: Create a structure to store student details
struct Student {
    string prn;       // Student PRN number
    int date, month;  // Date and month of birth
};

int main() {

    // Step 2: Create three arrays
    Student A[50], B[50], SE_AIML_DOB[100];

    int n, m;  // Number of students in A and B

    // Step 3: Take input for Division A
    cout << "Enter students in A: ";
    cin >> n;

    // Enter PRN, date and month for each student
    for (int i = 0; i < n; i++) {
        cin >> A[i].prn >> A[i].date >> A[i].month;
    }

    // Step 4: Take input for Division B
    cout << "Enter students in B: ";
    cin >> m;

    // Enter PRN, date and month for each student
    for (int i = 0; i < m; i++) {
        cin >> B[i].prn >> B[i].date >> B[i].month;
    }

    // Step 5: Initialize three index variables
    // i = index of A, j = index of B
    // k = index of merged array
    int i = 0, j = 0, k = 0;

    // Step 6: Compare and merge both sorted arrays
    // Continue until one array is finished
    while (i < n && j < m) {

        // Compare months first
        // If months are equal, compare dates
        if (A[i].month < B[j].month ||
           (A[i].month == B[j].month &&
            A[i].date <= B[j].date)) {

            // Copy student from A to merged array
            // Increase i and k by 1
            SE_AIML_DOB[k++] = A[i++];
        }
        else {

            // Copy student from B to merged array
            // Increase j and k by 1
            SE_AIML_DOB[k++] = B[j++];
        }
    }

    // Step 7: Copy remaining students

    // If students remain in Array A
    while (i < n) {
        SE_AIML_DOB[k++] = A[i++];
    }

    // If students remain in Array B
    while (j < m) {
        SE_AIML_DOB[k++] = B[j++];
    }

    // Step 8: Display final sorted birthday list
   cout << "\nSorted Birthday List:\n";

    // Print PRN, date and month of each student
    for (int x = 0; x < k; x++) {
        cout << SE_AIML_DOB[x].prn << " "
             << SE_AIML_DOB[x].date << "/"
             << SE_AIML_DOB[x].month << endl;
    }

    return 0;  // End program
} 


Algorithm
1. Start.
2. Define a structure Student containing PRN, date and month.
3. Read the number of students in Array A and Array B.
4. Enter student details (PRN, date and month) into both arrays.
5. Create a third array SE_AIML_DOB.
6. Initialize three variables i = 0, j = 0 and k = 0.
7. Compare the birth dates of Array A and Array B:
   - Compare the month first.
   - If months are equal, compare the dates.
   - Copy the earlier birthday into the third array.
   - Increase the corresponding index.
8. Repeat until one of the arrays becomes empty.
9. Copy the remaining elements of Array A into the third array.
10. Copy the remaining elements of Array B into the third array.
11. Display the merged sorted array.
12. Stop.
