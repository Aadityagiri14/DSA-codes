#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compareJob(const Job &a, const Job &b) {
    return a.profit > b.profit; 
}

void bestJob(Job jobs[], int sizeOfJobs) {
    char jobsToDo[5] = {'\0'};
    for (int i = 0; i < sizeOfJobs; i++) {
        int k = jobs[i].deadline - 1;
        while (jobsToDo[k] != '\0' && k >= 0) {
            k--;
        }
        if (k != -1)
            jobsToDo[k] = jobs[i].id;
    }
    cout << "\nBest order and jobs to do is: ";
    for (int idx = 0; jobsToDo[idx] != '\0'; idx++) {
        cout << jobsToDo[idx] << " ";
    }
}

void display(Job jobs[], int n) {
    cout << "Job Id:\t";
    for (int i = 0; i < n; i++) {
        cout << jobs[i].id << "\t";
    }
    cout << "\nJob Deadline:\t";
    for (int i = 0; i < n; i++) {
        cout << jobs[i].deadline << "\t";
    }
    cout << "\nJob Profit:\t";
    for (int i = 0; i < n; i++) {
        cout << jobs[i].profit << "\t";
    }
    cout << "\n";
}

int main() {
    Job jobs[] = {{'w', 1, 19}, {'v', 2, 100}, {'x', 2, 27},
                  {'y', 1, 25}, {'z', 3, 15}};

    display(jobs, 5);

    sort(jobs, jobs + 5, compareJob);

    bestJob(jobs, 5);

    return 0;
}
