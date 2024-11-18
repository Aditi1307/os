#include<bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cout << "Number of Processes: ";
    cin >> num;

    int array_at[num], array_bt[num], array_ct[num], array_tat[num], array_wt[num];
    vector<pair<int, pair<int, int>>> processes; 
    cout << "Enter the ARRIVAL TIME for each process: ";
    for (int i = 0; i < num; i++) {
        cin >> array_at[i];
    }

    cout << "Enter the BURST TIME for each process: ";
    for (int i = 0; i < num; i++) {
        cin >> array_bt[i];
        processes.push_back({array_at[i], {array_bt[i], i}}); 
    }

    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(), [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
        return a.first < b.first; // Sort by arrival time
    });

    int currentTime = 0;
    int completed = 0;
    vector<bool> isCompleted(num, false);

    // Calculate Completion Time, Turnaround Time and Waiting Time
    while (completed != num) {
        // Find the process that has the shortest burst time and has arrived by currentTime
        int minIndex = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < num; i++) {
            if (processes[i].first <= currentTime && !isCompleted[i] && processes[i].second.first < minBurst) {
                minBurst = processes[i].second.first;
                minIndex = i;
            }
        }

        if (minIndex != -1) {
            // Execute the selected process
            currentTime += processes[minIndex].second.first; // Add burst time to current time
            int processIndex = processes[minIndex].second.second; // Get the process index
            array_ct[processIndex] = currentTime;
            array_tat[processIndex] = array_ct[processIndex] - array_at[processIndex];
            array_wt[processIndex] = array_tat[processIndex] - array_bt[processIndex];
            isCompleted[minIndex] = true;
            completed++;
        } else {
            currentTime++; // If no process is ready to execute, increment time
        }
    }

    // Output the results
    cout << "\nCOMPLETION TIME: ";
    for (int i = 0; i < num; i++) {
        cout << array_ct[i] << " ";
    }

    cout << "\nTURNAROUND TIME: ";
    for (int i = 0; i < num; i++) {
        cout << array_tat[i] << " ";
    }

    cout << "\nWAITING TIME: ";
    for (int i = 0; i < num; i++) {
        cout << array_wt[i] << " ";
    }

    return 0;
}
