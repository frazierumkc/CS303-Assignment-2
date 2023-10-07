#include "Employee.h"

/*Calculates weekly salary.
@return The weekly salary*/
double Nonprofessional::weekly_salary() const {
	return hours_worked * hourly_rate;
}

/*Calculates health care contribution.
@return Contribution to health care*/
double Nonprofessional::health_care_cont() const {
	return weekly_salary() / 3;
}

/*Calculates vacation hours.
@return Vacation quantity*/
int Nonprofessional::vacation() const {
	return hours_worked / 15;
}

Nonprofessional::Nonprofessional(std::string fname, std::string lname, double hrate, int hworked) {
	first_name = fname;
	last_name = lname;
	hourly_rate = hrate;
	hours_worked = hworked;
}

Nonprofessional::Nonprofessional() {
	first_name = "";
	last_name = "";
	hourly_rate = 0;
	hours_worked = 0;
}