#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

// Comparison function to sort jobs by profit in descending order
int compare(const void *a, const void *b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Function to perform job sequencing
void jobSequencing(int id[], int deadline[], int profit[], int n) {
    Job jobs[n];
    for (int i = 0; i < n; i++) {
        jobs[i].id = id[i];
        jobs[i].deadline = deadline[i];
        jobs[i].profit = profit[i];
    }

    // Sort jobs based on profit in decreasing order
    qsort(jobs, n, sizeof(Job), compare);

    // Array to store result of job sequence
    int result[n];
    int jobSequence[n];
    for (int i = 0; i < n; i++) {
        result[i] = -1; // Initialize result array with -1
        jobSequence[i] = -1; // Initialize job sequence array with -1
    }

    int count = 0; // Number of jobs done
    int totalProfit = 0; // Total profit earned

    for (int i = 0; i < n; i++) {
        int start = (jobs[i].deadline < n) ? jobs[i].deadline - 1 : n - 1;
        for (int j = start; j >= 0; j--) {
            if (result[j] == -1) { // If slot is empty
                result[j] = i;
                jobSequence[j] = jobs[i].id; // Store the job ID in the sequence
                totalProfit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    printf("Total Jobs: %d\nTotal Profit: %d\n", count, totalProfit);
    printf("Job Sequence: ");
    for (int i = 0; i < n; i++) {
        if (jobSequence[i] != -1) {
            printf("%d ", jobSequence[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of Jobs: ");
    scanf("%d", &n);
    int deadline[n], profit[n], id[n];

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("Enter the deadline and profit of Job %d: ", i + 1);
        scanf("%d %d", &deadline[i], &profit[i]);
    }

    jobSequencing(id, deadline, profit, n);

    return 0;
}
