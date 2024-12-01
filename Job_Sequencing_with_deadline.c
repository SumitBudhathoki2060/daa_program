#include <stdio.h>

// Structure to represent a job
typedef struct 
{
    int id;
    int deadline;
    int profit;
}Job;

// Function to compare two jobs based on their profits
int compare(const void *a, const void *b) 
{
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

// Function to find the maximum profit
void jobSequencing(Job jobs[], int n) 
{
	int i, j;
    // Sort the jobs based on their profits
    qsort(jobs, n, sizeof(Job), compare);
    // Create a boolean array to track the deadlines
    int deadlines[10] = {0};
    // Initialize the maximum profit
    int maxProfit = 0;
    // Iterate through the sorted jobs
    for (i = 0; i < n; i++) 
	{
        // Find a deadline that can accommodate the current job
        for (j = jobs[i].deadline; j >= 1; j--) 
		{
            if (!deadlines[j]) 
			{
                deadlines[j] = 1;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("Maximum Profit: %d\n", maxProfit);
}

int main() 
{
    int i, n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    printf("Enter the job details (id, deadline, profit):\n");
    for (i = 0; i < n; i++)
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    jobSequencing(jobs, n);
    return 0;
}
