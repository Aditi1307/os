#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Function to sort an array using bubble sort
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



int main() {
    int n;
    printf("Enter the number of integers to sort: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process sorting the array...\n");
        bubble_sort(arr, n);
        printf("Sorted array by Child: ");
        print_array(arr, n);

        // Orphan state: sleep to demonstrate
        sleep(5);
        printf("Child process (Orphan) exiting.\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent process sorting the array...\n");
        bubble_sort(arr, n);
        printf("Sorted array by Parent: ");
        print_array(arr, n);

        // Demonstrating Zombie state
        printf("Parent process waiting for child to exit...\n");
        wait(NULL);
        printf("Child process has exited, no Zombie state as wait() was used.\n");

        // Orphan state demonstration:
        sleep(10); // Parent sleeps so child becomes orphan before parent exits
        printf("Parent process exiting.\n");

    }



    return 0;

}