#include "Employee.h"

/*Calculates weekly salary.
@return The weekly salary*/
double Professional::weekly_salary() const {
	return monthly_salary * 12 / 52;
}

/*Calculates health care contribution.
@return Contribution to health care*/
double Professional::health_care_cont() const {
	return weekly_salary() / 2;
}

/*Calculates vacation days.
@return Vacation quantity*/
int Professional::vacation() const {
	return v_days;
}

Professional::Professional(std::string fname, std::string lname, double salary, int vac_days) {
	first_name = fname;
	last_name = lname;
	monthly_salary = salary;
	v_days = vac_days;
}

Professional::Professional() {
	first_name = "";
	last_name = "";
	monthly_salary = 0;
	v_days = 0;
}