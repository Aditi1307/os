#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Process {
    string id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};


bool compareByArrivalTime(const Process &a, const Process &b) {
    return a.arrival_time < b.arrival_time;
}

void preemptive_sjf(vector<Process> &processes) {
    int n = processes.size();
    int current_time = 0;
    int completed_count = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    vector<bool> completed(n, false);
    
    sort(processes.begin(), processes.end(), compareByArrivalTime);

    for (int i = 0; i < n; ++i) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    while (completed_count < n) {
        int min_remaining_time = numeric_limits<int>::max();
        int min_index = -1;

        for (int i = 0; i < n; ++i) {
            if (!completed[i] && processes[i].arrival_time <= current_time && processes[i].remaining_time < min_remaining_time) {
                min_remaining_time = processes[i].remaining_time;
                min_index = i;
            }
        }

        if (min_index == -1) {
            current_time++;
        } else {
            processes[min_index].remaining_time--;
            current_time++;

            if (processes[min_index].remaining_time == 0) {
                processes[min_index].completion_time = current_time;
                processes[min_index].turnaround_time = processes[min_index].completion_time - processes[min_index].arrival_time;
                processes[min_index].waiting_time = processes[min_index].turnaround_time - processes[min_index].burst_time;
                completed[min_index] = true;
                completed_count++;
                total_waiting_time += processes[min_index].waiting_time;
                total_turnaround_time += processes[min_index].turnaround_time;
            }
        }
    }
    
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (const Process &process : processes) {
        cout << process.id << "\t\t" << process.arrival_time << "\t\t" << process.burst_time << "\t\t" 
             << process.completion_time << "\t\t" << process.turnaround_time << "\t\t" << process.waiting_time << "\n";
    }

    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << "\n";
    cout << "Average Waiting Time: " << (float)total_waiting_time / n << "\n";
}

int main() {
    vector<Process> processes = {{"P1", 0, 3}, {"P2", 1, 5}, {"P3", 2, 3}, {"P4", 3, 1}, {"P5", 4, 2}, {"P6", 5, 1}};
    preemptive_sjf(processes);

    return 0;
}
