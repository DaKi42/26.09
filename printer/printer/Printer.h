#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct PrintJob {
    string submitter; 
    time_t submissionTime;
};

class Printer {
    int* waitTimes;
    int* priorities;
    PrintJob* jobs;
    int maxCapacity;
    int length;

public:
    Printer(int m);
    ~Printer();
    void enqueueJob(int waitTime, int priority, const string& submitter);
    int dequeueJob();
    void clearQueue();
    bool isEmpty();
    bool isFull();
    int getJobCount();
    void displayQueue();
};