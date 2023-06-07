#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, wall, minIdx;
    wall = 0;
    for (wall = 0; wall < n - 1; wall++)
    {
        minIdx = wall;
        for (j = wall + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(&arr[wall], &arr[minIdx]);
    }
    return;
}

void insertionSort(int arr[], int n)
{
    int i, j, k, hole, value;
    for (i = 1; i < n; i++)
    {
        value = arr[i];
        hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
    return;
}

void merge(int arr[], int lo, int mid, int hi)
{
    int i, j, k;
    int n1 = mid - lo + 1;
    int n2 = hi - mid;
    int L[n1];
    int R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[lo + i];
    }
    for (i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }
    i = 0;
    j = 0;
    k = lo;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return;
}

void mergeSort(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        int mid;
        mid = lo + (hi - lo) / 2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }
}

int partition(int arr[], int lo, int hi)
{
    int i;
    int idx = lo - 1;
    int pivot = arr[hi];
    int j = lo - 1;
    for (i = lo; i < hi; i++)
    {
        if (arr[i] <= pivot)
        {
            idx++;
            swap(&arr[i], &arr[idx]);
        }
    }
    idx++;
    swap(&arr[hi], &arr[idx]);
    return idx;
}
void quickSort(int arr[], int lo, int hi)
{
    if (lo < hi)
    {
        int partitionedAt = partition(arr, lo, hi);
        quickSort(arr, lo, partitionedAt - 1);
        quickSort(arr, partitionedAt + 1, hi);
    }
    return;
}
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int N = 10;
    int arr[] = {12, 11, 13, 5, 6, 80, -78, 2, 0, 4};
    // bubbleSort(arr, N);
    // selectionSort(arr, N);
    // insertionSort(arr, N);
    // qsort(arr, N, sizeof(int), cmp);
    // quickSort(arr, 0, N);
    mergeSort(arr, 0, N);
    printArray(arr, N);
    return 0;
}
