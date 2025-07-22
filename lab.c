#include <stdio.h>

int main()
{
    int n = 4;
    int processID[] = {1, 2, 3, 4};
    int arrivalTime[] = {0, 1, 2, 3};
    int burstTime[] = {3, 2, 1, 4};
    int completionTime[4], turnaroundTime[4], waitingTime[4];

    int currentTime = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentTime < arrivalTime[i])
        {
            currentTime = arrivalTime[i];
        }

        currentTime += burstTime[i];
        completionTime[i] = currentTime;

        turnaroundTime[i] = completionTime[i] - arrivalTime[i];

        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processID[i], arrivalTime[i], burstTime[i],
               completionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    return 0;
}
