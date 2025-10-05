#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>


class Tax {
protected:
	double income;
public:
	Tax(double income) : income(income) {}
	virtual double detTax() const = 0;
	virtual ~Tax() = default;
};
class SimpleTax : public Tax {
public:
	using Tax::Tax;
	
	double detTax() const override {
		return income * 0.05;
	}
};
class GeneralTax : public Tax {
public:
	using Tax::Tax;
	double detTax() const override {
		return income * 0.18;
	}
};
class SalaryTax : public Tax {
public:
	using Tax::Tax;
	double detTax() const override {
		return income * 0.4;
	}
};
Tax* createNewTax(const int id, double salary)
{
	if (id == 1)
		return new SimpleTax(salary);
	if (id == 2)
		return new GeneralTax(salary);
	if (id == 3)
		return new SalaryTax(salary);
	return nullptr;
}


int main() {
	std::vector<std::unique_ptr<Tax>> data;
	std::ifstream file("C:\\Users\\PC\\OneDrive\\Документы\\C++Education\\Hillel\\HW19\\data.csv");
	if (!file.is_open()) {
		std::cerr << "Error opening file." << std::endl;
		return 1;
	}
	std::string line;

	while(std::getline(file, line)) {
		std::stringstream ss(line);
		std::string typeStr, valueStr;
		if (std::getline(ss, typeStr, ',') && std::getline(ss, valueStr)) {
			int type = std::stoi(typeStr);
			double value = std::stod(valueStr);
			data.emplace_back(createNewTax(type, value));
		}
	}
	file.close();
	for(const auto& tax : data) {
		std::cout << "Tax: " << tax->detTax() << std::endl;
	}
}; 