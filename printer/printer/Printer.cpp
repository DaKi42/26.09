#include "Printer.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void Printer::displayQueue() {
    cout << "\n-------------------------------------\n";
    for (int i = 0; i < length; i++) {
        cout << "Submitted by: " << jobs[i].submitter << " \nPriority: " << priorities[i] << " - Submission Time: ";
        char timeBuff[26];
        ctime_s(timeBuff, sizeof(timeBuff), &jobs[i].submissionTime);
        cout << timeBuff;
    } 
    cout << "\n-------------------------------------\n";
}

Printer::~Printer() {
    delete[] waitTimes;
    delete[] priorities;
    delete[] jobs;
}

Printer::Printer(int capacity) {
    maxCapacity = capacity;
    waitTimes = new int[maxCapacity];
    priorities = new int[maxCapacity];
    jobs = new PrintJob[maxCapacity];
    length = 0;
}

void Printer::clearQueue() {
    length = 0;
}

bool Printer::isEmpty() {
    return length == 0;
}

bool Printer::isFull() {
    return length == maxCapacity;
}

int Printer::getJobCount() {
    return length;
}

void Printer::enqueueJob(int waitTime, int priority, const string& submitter) {
    if (!isFull()) {
        waitTimes[length] = waitTime;
        priorities[length] = priority;
        jobs[length].submitter = submitter;
        jobs[length].submissionTime = time(nullptr);
        length++;
    }
}

int Printer::dequeueJob() {
    if (!isEmpty()) {
        int maxPriority = priorities[0];
        int maxPriorityPosition = 0;

        for (int i = 1; i < length; i++) {
            if (maxPriority < priorities[i]) {
                maxPriority = priorities[i];
                maxPriorityPosition = i;
            }
        }

        int tempWaitTime = waitTimes[maxPriorityPosition];
        int tempPriority = priorities[maxPriorityPosition];
        for (int i = maxPriorityPosition; i < length - 1; i++) {
            waitTimes[i] = waitTimes[i + 1];
            priorities[i] = priorities[i + 1];
            jobs[i] = jobs[i + 1];
        }
        length--;
        return tempWaitTime;
    }
    else {
        return -1;
    }
}