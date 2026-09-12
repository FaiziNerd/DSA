#include <iostream>
using namespace std;

int main() {
    int X, startPower, stopPower;
    long long totalSum = 0;

    cout << "Enter base X: ";
    cin >> X;
    cout << "Enter start power: ";
    cin >> startPower;
    cout << "Enter stop power: ";
    cin >> stopPower;

    for (int i = startPower; i <= stopPower; i++) {
   
        long long currentTerm = 1;
        for (int j = 0; j < i; j++) {
            currentTerm *= X;
        }
        
        totalSum += currentTerm;
    }

    cout << "Summation Result: " << totalSum << endl;
    return 0;
}