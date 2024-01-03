#include<stdio.h>
 
// Function for printing the array
void printArray(int*A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

// Function for sorting array using bubble sort method
void bubbleSort(int*A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For the number of passes
    {
        printf("Working on pass number %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j < n-1-i; j++) // For the number of comparisons
        {
            if (A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
            if (isSorted)
            {
                return;
            }           
        }  
    }    
}

int main()
{   
    int A[] = {12, 57, 22, 28, 1, 10, 35};
    int n = 7;
    printArray(A, n); // Printing the array before sorting
    bubbleSort(A, n); // Sorting the array
    printArray(A, n); // Printing the array after sorting
    return 0;
}