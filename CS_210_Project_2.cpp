//Damon Ditrichs
//08/04/24

#include "InvestmentCalculator.h"

InvestmentCalculator::InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_years)
    : m_initialInvestment(t_initialInvestment), m_monthlyDeposit(t_monthlyDeposit), m_annualInterestRate(t_annualInterestRate), m_years(t_years) {}

//Method to calculate without monthly deposits
std::vector<InvestmentCalculator::YearlyReport> InvestmentCalculator::calculateWithoutMonthlyDeposits() {
    std::vector<YearlyReport> reports;
    double openingAmount = m_initialInvestment;
    double interestRatePerMonth = (m_annualInterestRate / 100) / 12;

    for (int year = 1; year <= m_years; ++year) {
        double yearEndBalance = openingAmount * pow(1 + interestRatePerMonth, 12);
        double earnedInterest = yearEndBalance - openingAmount;
        reports.push_back({ year, yearEndBalance, earnedInterest });
        openingAmount = yearEndBalance;
    }

    return reports;
}

//Method to calculate with monthly deposits
std::vector<InvestmentCalculator::YearlyReport> InvestmentCalculator::calculateWithMonthlyDeposits() {
    std::vector<YearlyReport> reports;
    double openingAmount = m_initialInvestment;
    double interestRatePerMonth = (m_annualInterestRate / 100) / 12;

    for (int year = 1; year <= m_years; ++year) {
        for (int month = 1; month <= 12; ++month) {
            double total = openingAmount + m_monthlyDeposit;
            double interest = total * interestRatePerMonth;
            double closingBalance = total + interest;
            openingAmount = closingBalance;
        }
        double yearEndBalance = openingAmount;
        double earnedInterest = yearEndBalance - (m_initialInvestment + m_monthlyDeposit * 12 * year);
        reports.push_back({ year, yearEndBalance, earnedInterest });
    }

    return reports;
}

void InvestmentCalculator::displayReports() {
    std::vector<YearlyReport> withoutDeposits = calculateWithoutMonthlyDeposits();
    std::vector<YearlyReport> withDeposits = calculateWithMonthlyDeposits();

    //Displays without monthly deposits
    std::cout << "Year End Balances and Earned Interest Without Additional Monthly Deposits:\n";
    std::cout << "--------------------------------------------------------------\n";
    std::cout << "--------------------------------------------------------------\n";
    for (const auto& report : withoutDeposits) {
        std::cout << "Year " << report.year << ": Year End Balance = " << report.yearEndBalance
            << ", Earned Interest = " << report.yearEndInterest << "\n";
    }

    //Displays with monthly deposits
    std::cout << "\nYear End Balances and Earned Interest With Additional Monthly Deposits:\n";
    std::cout << "--------------------------------------------------------------\n";
    std::cout << "--------------------------------------------------------------\n";
    for (const auto& report : withDeposits) {
        std::cout << "Year " << report.year << ": Year End Balance = " << report.yearEndBalance
            << ", Earned Interest = " << report.yearEndInterest << "\n";
    }
}

int main() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int years;

    std::cout << "Airgead Banking Investment Calculator\n";

    //Displays prompts and gathers user input
    std::cout << "Enter Initial Investment Amount: ";
    std::cin >> initialInvestment;
    std::cout << "Enter Monthly Deposit Amount: ";
    std::cin >> monthlyDeposit;
    std::cout << "Enter Annual Interest Rate (in percentage): ";
    std::cin >> annualInterestRate;
    std::cout << "Enter Number of Years: ";
    std::cin >> years;

    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterestRate, years);
    calculator.displayReports();

    return 0;
}
