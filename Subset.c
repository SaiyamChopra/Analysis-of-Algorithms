#include <stdio.h>

int flag = 0;

void printSubsetSum(int i, int n, int set[], int target, int subset[], int size) {
    if (target == 0) {
        printf("[ ");
        for (int i = 0; i < size; i++) {
            printf("%d ", subset[i]);
        }
        printf("] ");
        flag = 1;
        return;
    }
    if (i == n) return;

    // Exclude current element
    printSubsetSum(i + 1, n, set, target, subset, size);

    // Include current element if it doesn't exceed the remaining target
    if (set[i] <= target) {
        subset[size] = set[i];
        printSubsetSum(i + 1, n, set, target - set[i], subset, size + 1);
    }
}

int main() {
    int n, targetSum;
    int set[20], subset[20];  // Fixed size for simplicity

    // Input size of the set
    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    // Input elements of the set
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    // Input target sum
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Output:\n");
    printSubsetSum(0, n, set, targetSum, subset, 0);

    if (!flag)
        printf("There is no such subset");

    return 0;
}
