#include <stdio.h>
#include <conio.h>

int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1; // Not found
}

void main() {
    int arr[100], n, key, result, i;
    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);

    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", result);

}
