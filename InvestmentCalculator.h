//Damon Ditrichs
//08/04/24

#ifndef AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_

#include <iostream>
#include <vector>
#include <cmath>

//Defines data types for InvestmentCalculator class
class InvestmentCalculator {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_years;

    //Struct to store YearlyReport info
    struct YearlyReport {
        int year;
        double yearEndBalance;
        double yearEndInterest;
    };

    //Methods to calculate with and without deposits
    std::vector<YearlyReport> calculateWithoutMonthlyDeposits();
    std::vector<YearlyReport> calculateWithMonthlyDeposits();

public:
    InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_years);

    //Displays investment reports
    void displayInputScreen();
    void displayReports();
};

#endif 
