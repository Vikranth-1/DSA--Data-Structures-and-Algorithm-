#include <stdio.h>
#include <conio.h>

#define MAX 100

int heap[MAX];
int heap_size = 0;

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up to maintain max heap property after insertion
void heapify_up(int index) {
    int parent = (index - 1) / 2;
    if (index && heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapify_up(parent);
    }
}

// Heapify down to maintain max heap property after deletion
void heapify_down(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap_size && heap[left] > heap[largest])
        largest = left;

    if (right < heap_size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[largest], &heap[index]);
        heapify_down(largest);
    }
}

// Insert a new value into the heap
void insert(int val) {
    if (heap_size == MAX) {
        printf("Heap overflow! Cannot insert %d\n", val);
        return;
    }
    heap[heap_size] = val;
    heapify_up(heap_size);
    heap_size++;
    printf("Inserted %d into the heap.\n", val);
}

// Delete and return the max element (root) from the heap
int deleteMax() {
    if (heap_size <= 0) {
        printf("Heap underflow! No elements to delete.\n");
        return -1;
    }
    int max_val = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    heapify_down(0);
    printf("Deleted max element %d from the heap.\n", max_val);
    return max_val;
}

// Display heap elements
void display() {
    int i;
    if (heap_size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap elements: ");
    for (i = 0; i < heap_size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

void main() {
    int choice, val;

    clrscr();
    while (1) {
        printf("\nPriority Queue (Max Heap) Operations:\n");
        printf("1. Insert\n2. Delete Max\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                deleteMax();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
