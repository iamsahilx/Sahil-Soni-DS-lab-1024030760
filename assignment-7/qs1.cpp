// selection sort 

#include <stdio.h>

void selectionSort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i]; a[i] = a[min]; a[min] = temp;
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    selectionSort(a, n);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
}


// insertion sort

#include <stdio.h>

void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    insertionSort(a, n);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
}


// bubble sort

#include <stdio.h>

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    bubbleSort(a, n);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
}

// merge sort

#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int b[r - l + 1];
    while (i <= m && j <= r) {
        if (a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l, k = 0; i <= r; i++, k++) a[i] = b[k];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    mergeSort(a, 0, n - 1);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
}


// quick sort

#include <stdio.h>

int partition(int a[], int l, int r) {
    int pivot = a[r], i = l - 1, j, temp;
    for (j = l; j < r; j++) {
        if (a[j] < pivot) {
            i++;
            temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    temp = a[i + 1]; a[i + 1] = a[r]; a[r] = temp;
    return i + 1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
}
