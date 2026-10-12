#include <iostream>
#include <iomanip>
using namespace std;

double calculateBilling(double hourlyRate, int minutes, bool lowIncome)
{
    double minutesFree;
    double chargeRate;
    // If the person has low income, they get 30 minutes free and a charge rate of $0.40 per hour.
    // Otherwise, they get 20 minutes free and a charge rate of $0.70 per hour.
    if (lowIncome)
    {
        minutesFree = 30;
        chargeRate = 0.40;
    }
    else
    {
        minutesFree = 20;
        chargeRate = 0.70;
    }

    if (minutes <= minutesFree)
        return 0.0;

    return hourlyRate * chargeRate * (minutes - minutesFree) / 60.0;
}

int main()
{
    double hourlyRate;
    int minutes;
    char lowIncomeChoice;
    bool lowIncome;

    cout << "Enter the hourly rate: $";
    cin >> hourlyRate;

    cout << "Enter the total consulting time in minutes: ";
    cin >> minutes;

    cout << "Does the person have low income? (Y/N): ";
    cin >> lowIncomeChoice;

    lowIncome = (lowIncomeChoice == 'Y' || lowIncomeChoice == 'y');
    
    // Calculates the billing amount based on the user inputs from before
    double amount = calculateBilling(hourlyRate, minutes, lowIncome);

    cout << fixed << setprecision(2);
    cout << "Billing amount: $" << amount << endl;

    return 0;
}
