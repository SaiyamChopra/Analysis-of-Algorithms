#include <stdio.h>
#include <stdlib.h>

int flag = 0;

// Function to print a valid subset
void printSubset(int subset[], int subsetSize) {
    printf("[ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("] ");
}

// Recursive function to find and print all subsets with given sum
void printSubsetSum(int i, int n, int set[], int targetSum, int subset[], int subsetSize) {
    if (targetSum == 0) {
        printSubset(subset, subsetSize);
        flag = 1;
        return;
    }

    if (i == n)
        return;

    // Exclude the current element
    printSubsetSum(i + 1, n, set, targetSum, subset, subsetSize);

    // Include the current element if it's not greater than targetSum
    if (set[i] <= targetSum) {
        subset[subsetSize] = set[i];
        printSubsetSum(i + 1, n, set, targetSum - set[i], subset, subsetSize + 1);
    }
}

int main() {
    int n, targetSum;

    // Input set size
    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    int *set = (int *)malloc(n * sizeof(int));
    int *subset = (int *)malloc(n * sizeof(int)); // Max size of subset = size of set

    // Input set elements
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    // Input target sum
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    // Call function
    printf("Output:\n");
    printSubsetSum(0, n, set, targetSum, subset, 0);

    if (!flag)
        printf("There is no such subset");

    free(set);
    free(subset);
    return 0;
}
