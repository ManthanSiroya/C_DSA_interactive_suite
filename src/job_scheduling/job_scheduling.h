#ifndef JOB_SCHEDULING_H
#define JOB_SCHEDULING_H

// A single process / job as seen by the CPU schedulers. arrival and burst are
// supplied by the user; priority is only used by priority scheduling. The
// remaining fields are filled in while an algorithm runs.
typedef struct Process
{
    int id;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
} Process;

void job_scheduling_demo(void);
void fcfs_demo(void);
void sjf_demo(void);
void priority_scheduling_demo(void);
void round_robin_demo(void);

// Prompts for the process count and then each process's arrival and burst time
// (and priority when need_priority is non-zero), filling procs and *n. Returns
// 1 once a valid set has been read, or 0 if the user asked to exit (-1).
int js_read_processes(Process* procs, int* n, int need_priority);

// Prints the per-process completion / turnaround / waiting times followed by
// the average waiting and turnaround times.
void js_print_result(const Process* procs, int n);

#endif
