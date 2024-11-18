
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int num, timeQuantum;
    cout << "Number of Processes: ";
    cin >> num;
    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;

    vector<int> array_at(num), array_bt(num), array_ct(num, 0), array_tat(num), array_wt(num);
    vector<int> remaining_bt(num);
    queue<int> q;  // Queue to manage processes in a round-robin manner

    cout << "Enter the ARRIVAL TIME for each process: ";
    for (int i = 0; i < num; i++) {
        cin >> array_at[i];
    }

    cout << "Enter the BURST TIME for each process: ";
    for (int i = 0; i < num; i++) {
        cin >> array_bt[i];
        remaining_bt[i] = array_bt[i];
    }

    int currentTime = 0, completed = 0;
    vector<bool> isInQueue(num, false);

    // Initially enqueue all processes that have arrived by time 0
    for (int i = 0; i < num; i++) {
        if (array_at[i] <= currentTime && !isInQueue[i]) {
            q.push(i);
            isInQueue[i] = true;
        }
    }

    while (completed != num) {
        if (q.empty()) {
            currentTime++;
            for (int i = 0; i < num; i++) {
                if (array_at[i] <= currentTime && !isInQueue[i]) {
                    q.push(i);
                    isInQueue[i] = true;
                }
            }
            continue;
        }

        int index = q.front();
        q.pop();

        if (remaining_bt[index] <= timeQuantum) {
            currentTime += remaining_bt[index];
            array_ct[index] = currentTime;
            array_tat[index] = array_ct[index] - array_at[index];
            array_wt[index] = array_tat[index] - array_bt[index];
            remaining_bt[index] = 0;
            completed++;
        } else {
            currentTime += timeQuantum;
            remaining_bt[index] -= timeQuantum;
        }

        for (int i = 0; i < num; i++) {
            if (array_at[i] <= currentTime && !isInQueue[i] && remaining_bt[i] > 0) {
                q.push(i);
                isInQueue[i] = true;
            }
        }

        if (remaining_bt[index] > 0) {
            q.push(index);
        }
    }

    cout << "\nCOMPLETION TIME: ";
    for (int i = 0; i < num; i++) {
        cout << array_ct[i] << " ";
    }
    cout << "\nTURN AROUND TIME: ";
    for (int i = 0; i < num; i++) {
        cout << array_tat[i] << " ";
    }
    cout << "\nWAITING TIME: ";
    for (int i = 0; i < num; i++) {
        cout << array_wt[i] << " ";
    }

    return 0;
}
