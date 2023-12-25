#include <iostream> 
#include <string> 
#include "Printer.h" 
using namespace std;

int main() {

    Printer printer(10);
    printer.enqueueJob(3, 2, "Vlad"); 
    printer.enqueueJob(2, 1, "Anthony");
    printer.enqueueJob(4, 3, "King");
    printer.enqueueJob(1, 4, "Liza");
    cout << "Current Queue:\n";
    printer.displayQueue();

    int waitTime = printer.dequeueJob();
    if (waitTime != -1) {
        cout << "Job with the highest priority is printed. Wait time: " << waitTime << " seconds.\n";
    }
    else {
        cout << "Queue is empty.\n";
    }

    cout << "\nUpdated Queue:\n";
    printer.displayQueue();
}