#include <iostream>
#include <string>
using namespace std;

int main() {
    char vehicleType;
    int daysHired;
    string insuranceCover, customerType, loyaltyCard = "No Card";
    double dailyCharge = 0.0, totalCost = 0.0;
    const double INSURANCE_COST = 15.50;
    const double DEPOSIT = 50.0;


    do {
        cout << "Enter vehicle type (S for Saloon, H for High Performance, V for Van): ";
        cin >> vehicleType;
        vehicleType = (vehicleType);
        switch (vehicleType) {
            case 'S': dailyCharge = 22.50; break;
            case 'H': dailyCharge = 28.00; break;
            case 'V': dailyCharge = 35.00; break;
            default: cout << "Invalid vehicle type. Try again.\n";
        }
    } while (vehicleType != 'S' && vehicleType != 'H' && vehicleType != 'V');

    
    cout << "Enter the number of days for Car hire (1-10): ";
    cin >> daysHired;
    while (daysHired < 1 || daysHired > 10) {
        cout << "Invalid number of days. Please enter a value between the number 1 and 10: ";
        cin >> daysHired;
    }


    cout << "Do you need insurance cover? (Yes/No): ";
    cin >> insuranceCover;


    for (int i = 0; i < 3; i++) {
        cout << "Are you a new or an existing customer? ";
        cin >> customerType;
        if (customerType == "New" || customerType == "Existing") break;
        cout << "Invalid response. Must enter 'New' or 'Existing'.\n";
        if (i == 2) {
            cout << "Too many invalid attempts. Exiting program.\n";
            return 1;
        }
    }

    
    if (customerType == "Existing") {
        do {
            cout << "Enter loyalty card type (Bronze, Silver, Gold): ";
            cin >> loyaltyCard;
            if (loyaltyCard == "Bronze" || loyaltyCard == "Silver" || loyaltyCard == "Gold") break;
            cout << "Invalid loyalty card type. Try again.\n";
        } while (true);
    }


    totalCost = dailyCharge * daysHired;
    if (daysHired > 7) totalCost *= 0.9;

    if (insuranceCover == "Yes") totalCost += INSURANCE_COST;

    if (customerType == "Existing" && loyaltyCard == "Gold" && vehicleType == 'H') {
        totalCost -= 18.00;
    }

    totalCost += DEPOSIT;


    cout << "\nCar Hire Quote Summary\n";
    cout << "-----------------------\n";
    cout << "Vehicle Type: " << (vehicleType == 'S' ? "Saloon" : vehicleType == 'H' ? "High Performance" : "Van") << endl;
    cout << "Days Hired: " << daysHired << endl;
    cout << "Customer Type: " << customerType << endl;
    cout << "Loyalty Card: " << loyaltyCard << endl;
    cout << "Insurance Cover: " << (insuranceCover == "Yes" ? "Included" : "Not Included") << endl;
    cout << "Total Hire Cost: £" << totalCost << endl;

    return 0;
}
