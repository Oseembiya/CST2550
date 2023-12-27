#include <iostream>
#include <vector>

using namespace std;

// Function to check if the system is in a safe state
bool isSafe(vector<vector<int>>& max, vector<vector<int>>& allocation, vector<int>& available, int process, int resource) {
    // Step 1: Check if the request is within the maximum claim of the process
    if (resource > max[process][resource] - allocation[process][resource]) {
        cout << "Request exceeds maximum claim. Denied.\n";
        return false;
    }

    // Step 2: Try allocating the resources
    vector<int> work = available;
    vector<bool> finish(allocation.size(), false);

    // Assume the resource is allocated temporarily
    allocation[process][resource] += resource;
    work[resource] -= resource;

    // Check if the system is in a safe state
    bool safe = false;
    for (int i = 0; i < allocation.size(); ++i) {
        if (!finish[i]) {
            bool canAllocate = true;
            for (int j = 0; j < available.size(); ++j) {
                if (max[i][j] - allocation[i][j] > work[j]) {
                    canAllocate = false;
                    break;
                }
            }
            if (canAllocate) {
                finish[i] = true;
                for (int j = 0; j < available.size(); ++j) {
                    work[j] += allocation[i][j];
                }
                safe = true;
            }
        }
    }

    // Rollback the temporary allocation
    allocation[process][resource] -= resource;

    return safe;
}

int main() {
    int numProcesses, numResources;

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    cout << "Enter the number of resources: ";
    cin >> numResources;

    // Step 2: Get the maximum claim of each process
    vector<vector<int>> max(numProcesses, vector<int>(numResources));
    cout << "Enter the maximum claim of each process:\n";
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numResources; ++j) {
            cin >> max[i][j];
        }
    }

    // Step 3: Get the current allocation
    vector<vector<int>> allocation(numProcesses, vector<int>(numResources));
    cout << "Enter the current allocation for each process:\n";
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numResources; ++j) {
            cin >> allocation[i][j];
        }
    }

    // Step 4: Calculate the need matrix
    vector<vector<int>> need(numProcesses, vector<int>(numResources));
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numResources; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Step 5: Get the available resources
    vector<int> available(numResources);
    cout << "Enter the available resources: ";
    for (int i = 0; i < numResources; ++i) {
        cin >> available[i];
    }

    // Step 6: Check if the system is in a safe state
    bool safe = false;
    for (int i = 0; i < numProcesses; ++i) {
        if (isSafe(max, allocation, available, i, 0)) {
            safe = true;
            break;
        }
    }

    if (safe) {
        cout << "The system is in a safe state.\n";
    } else {
        cout << "The system is not in a safe state.\n";
    }

    return 0;
}