#include <stdio.h>
#include <conio.h>

#define MAX 100

void insert(int arr[], int *n, int element, int pos) {
    int i;
    if (*n >= MAX) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (i = *n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = element;
    (*n)++;
    printf("Element inserted successfully.\n");
}

void delete(int arr[], int *n, int pos) {
    int i;
    if (*n == 0) {
        printf("Array is empty, cannot delete.\n");
        return;
    }
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (i = pos-1; i < *n-1; i++) {
        arr[i] = arr[i+1];
    }
    (*n)--;
    printf("Element deleted successfully.\n");
}

void traverse(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    int arr[MAX];
    int n = 0, choice, element, pos;

    clrscr();
    while(1) {
        printf("Array Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insert(arr, &n, element, pos);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3:
                traverse(arr, n);
                break;
            case 4:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("\n");
    }
}
