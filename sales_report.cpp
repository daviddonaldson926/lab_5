#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>  


void printSalesReport(const std::vector<double>& sales, const std::vector<std::string>& months) {
    std::cout << "Monthly sales report for 2022:\n";
    std::cout << "Month Sales\n";
    for (size_t i = 0; i < months.size(); ++i) {
        std::cout << months[i] << " $" << sales[i] << "\n";
    }
}


void printSalesSummary(const std::vector<double>& sales, const std::vector<std::string>& months) {
    auto minmax = std::minmax_element(sales.begin(), sales.end());
    double sum = std::accumulate(sales.begin(), sales.end(), 0.0);
    double average = sum / sales.size();

    std::cout << "\nSales summary:\n";
    std::cout << "Minimum sales: $" << *minmax.first << " (" << months[std::distance(sales.begin(), minmax.first)] << ")\n";
    std::cout << "Maximum sales: $" << *minmax.second << " (" << months[std::distance(sales.begin(), minmax.second)] << ")\n";
    std::cout << "Average sales: $" << std::fixed << std::setprecision(2) << average << "\n";
}


void printMovingAverages(const std::vector<double>& sales, const std::vector<std::string>& months) {
    std::cout << "\nSix-Month Moving Average Report:\n";
    for (size_t i = 0; i <= sales.size() - 6; ++i) {
        double average = std::accumulate(sales.begin() + i, sales.begin() + i + 6, 0.0) / 6;
        std::cout << months[i] << " - " << months[i + 5] << " $" << std::fixed << std::setprecision(2) << average << "\n";
    }
}


void printSalesHighestToLowest(std::vector<double> sales, std::vector<std::string> months) {
    std::vector<std::pair<double, std::string>> paired;
    for (size_t i = 0; i < sales.size(); ++i) {
        paired.push_back({sales[i], months[i]});
    }


    std::sort(paired.begin(), paired.end(), [](const std::pair<double, std::string>& a, const std::pair<double, std::string>& b) {
        return a.first > b.first; 
    });

    std::cout << "\nSales Report (Highest to Lowest):\n";
    std::cout << "Month Sales\n";
    for (const auto& pair : paired) {
        std::cout << pair.second << " $" << pair.first << "\n";
    }
}

int main() {
    std::vector<std::string> months = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    std::vector<double> sales;
    std::string fileName = "sales.txt"; 

   
    std::ifstream file(fileName);
    if (file.is_open()) {
        double value;
        while (file >> value) {
            sales.push_back(value);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    printSalesReport(sales, months);
    printSalesSummary(sales, months);
    printMovingAverages(sales, months);
    printSalesHighestToLowest(sales, months);

    return 0;
}
