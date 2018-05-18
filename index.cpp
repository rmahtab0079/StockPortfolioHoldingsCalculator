//
//  portfolioManagementSystem.cpp
//  mealCalculate
//
//  Created by Rageeb Mahtab on 5/13/18.
//  Copyright © 2018 Rageeb Mahtab. All rights reserved.
//

#include "portfolioManagementSystem.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <typeinfo>

using namespace std;
// initializer
class stock {
    string name;
    int volume;
    double openingPrice;
    double closingPrice;
    double buyPrice;
    
public:
    //default constructor
    stock() {
        name = "unknown";
        volume = 0;
        openingPrice = 0;
        closingPrice = 0;
        buyPrice = 0;
    }
    //mutators
    void setName(string pName) {
        name = pName;
    }
    void setVolume(int pVolume) {
        volume = pVolume;
    }
    void setOpeningPrice(double pOpeningPrice) {
        openingPrice = pOpeningPrice;
    }
    void setClosingPrice(double pClosingPrice) {
        closingPrice = pClosingPrice;
    }
    void setBuyPrice(double pBuyPrice) {
        buyPrice = pBuyPrice;
    }
    
    //accessors
    string getName() {
        return name;
    }
    int getVolume() {
        return volume;
    }
    double getOpeningPrice() {
        return openingPrice;
    }
    double getClosingPrice() {
        return closingPrice;
    }
    double getBuyPrice() {
        return buyPrice;
    }
    // parameterized constructor
    stock(string pName, int pVolume, double pBuyPrice, double pOpeningPrice, double pClosingPrice) {
        setName(pName);
        setVolume(pVolume);
        setBuyPrice(pBuyPrice);
        setOpeningPrice(pOpeningPrice);
        setClosingPrice(pClosingPrice);
    }
    
    //member functions
    double getCurrentHolding() {
        return volume * buyPrice;
    }
    double getHoldingMarketOpen() {
        return volume * openingPrice;
    }
    double getHoldingMarketClose() {
        return volume * closingPrice;
    }
    
};

void portfolio() {
    stock y[5];
    double H = 0, HMO = 0, HMC = 0; string SYMS;
    const int sizeOfArray = 5;
    for (int i = 0; i < sizeOfArray; i++) {
        //All the variables that I pass in as parameters
        string pName; int pVolume; double pBuyPrice, pOpeningPrice, pClosingPrice;
        cout << "Enter the Stock Symbol, Volume, Buy Price, Opening Price, and Closing Price of your stock: " << endl;
        // These variable I use as parameters for the setter functions.
        cin >> pName >> pVolume >> pBuyPrice >> pOpeningPrice >> pClosingPrice;
        // If the length of the String is greater than 5, left blank (calls default constructor where name = "unknown", display error message and then end loop.
        if (pName.length() > 5 || pName == "unknown") {
            cerr << "Symbol is not allowed to be blank and should not be more than 5 characters long." << endl;
            break;
        } else if (pVolume <= 0){
            cerr << "Volume must be greater than 0." << endl;
            break;
        } else if (pBuyPrice <= 0 || pOpeningPrice <= 0 || pClosingPrice <= 0) {
            cerr << "All prices must be greater than 0." << endl;
            break;
        } else {
        y[i].setName(pName); y[i].setVolume(pVolume); y[i].setBuyPrice(pBuyPrice); y[i].setOpeningPrice(pOpeningPrice);
        y[i].setClosingPrice(pClosingPrice);
        }
    }
   // Loop that outputs the Symbols, Holding, Holding, Ma
    for (int i = 0; i < sizeOfArray; i++) {
        cout << "SYM=" << y[i].getName() << ", H=" << y[i].getCurrentHolding() << ", HMO=" << y[i].getHoldingMarketOpen()
        << ", HMC=" << y[i].getHoldingMarketClose() << endl;
        // Adds all the H, HMO, and HMC to 0 with which the variables were initialized
        SYMS += y[i].getName() + ", ";
        H += y[i].getCurrentHolding(); HMO += y[i].getHoldingMarketOpen(); HMC += y[i].getHoldingMarketClose();
    }
    //Outputs the Total Holdings, Total Holdings at Market Open, and Total Holdings at Market Close
    cout << SYMS << endl;
    cout << "Total Holdings: " << H << endl;
    cout << "Total Holdings at Market Open: " << HMO << endl;
    cout << "Total Holdings at Market Close: " << HMC << endl;
}
// Better coding practice is to call function from main.
int main() {
    portfolio();
}
