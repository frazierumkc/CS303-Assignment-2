#include <iostream>
#include "Employee.h"

using namespace std;

int main() {
	double d_input;
	int i_input;
	std::string str_input, str_input2;

	/*Making professional and nonprofessional test instances from user inputs*/
	cout << "Enter the first and last name of the professional employee\n";
	cin >> str_input;
	cin >> str_input2;
	cout << "\nEnter the monthly salary of the professional employee\n";
	cin >> d_input;
	cout << "\nEnter the set vacation day quantity of the professional employee\n";
	cin >> i_input;
	Professional test_prof(str_input, str_input2, d_input, i_input);
	cout << "\n\nEnter the first and last name of the nonprofessional employee\n";
	cin >> str_input;
	cin >> str_input2;
	cout << "\nEnter the hourly rate of the nonprofessional employee\n";
	cin >> d_input;
	cout << "\nEnter the hours worked of the nonprofessional employee\n";
	cin >> i_input;
	Nonprofessional test_nonprof(str_input, str_input2, d_input, i_input);

	/*Displaying calculations for test instances*/
	cout << "\nProfessional employee calcuations:\nWeekly salary: " << test_prof.weekly_salary();
	cout << "\nHealth care contributions: " << test_prof.health_care_cont();
	cout << "\nVacaction days: " << test_prof.vacation();

	cout << "\n\nNonprofessional employee calcuations:\nWeekly salary: " << test_nonprof.weekly_salary();
	cout << "\nHealth care contributions: " << test_nonprof.health_care_cont();
	cout << "\nVacaction hours earned this week: " << test_nonprof.vacation() << "\n";
}