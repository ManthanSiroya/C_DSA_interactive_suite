#include "job_scheduling.h"
#include <stdio.h>

// Shortest Job First, non-preemptive: at each step pick the shortest-burst job
// among those that have already arrived; once started it runs to completion.
void sjf_demo(void)
{
    Process procs[10];
    int n;

    if (!js_read_processes(procs, &n, 0))
    {
        printf("\nExiting SJF demo....\n");
        return;
    }

    int done[10] = {0};
    int completed = 0;
    int current_time = 0;

    while (completed < n)
    {
        int chosen = -1;

        for (int i = 0; i < n; i++)
        {
            if (done[i] || procs[i].arrival > current_time)
            {
                continue;
            }

            if (chosen == -1 || procs[i].burst < procs[chosen].burst ||
                (procs[i].burst == procs[chosen].burst && procs[i].arrival < procs[chosen].arrival))
            {
                chosen = i;
            }
        }

        if (chosen == -1)
        {
            // no job has arrived yet, idle forward to the next arrival
            int next_arrival = -1;

            for (int i = 0; i < n; i++)
            {
                if (!done[i] && (next_arrival == -1 || procs[i].arrival < next_arrival))
                {
                    next_arrival = procs[i].arrival;
                }
            }

            current_time = next_arrival;
            continue;
        }

        current_time += procs[chosen].burst;
        procs[chosen].completion = current_time;
        procs[chosen].turnaround = procs[chosen].completion - procs[chosen].arrival;
        procs[chosen].waiting = procs[chosen].turnaround - procs[chosen].burst;
        done[chosen] = 1;
        completed++;
    }

    js_print_result(procs, n);
}
