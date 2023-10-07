#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>

class Employee {
public:
	/*Calculates weekly salary.
	@return The weekly salary*/
	virtual double weekly_salary() const = 0;

	/*Calculates health care contribution.
	@return Contribution to health care*/
	virtual double health_care_cont() const = 0;

	/*Calculates vacation days or hours.
	@return Vacation quantity*/
	virtual int vacation() const = 0;
protected:
	std::string first_name;
	std::string last_name;
};

class Professional : public Employee {
public:
	/*Calculates weekly salary.
	@return The weekly salary*/
	double weekly_salary() const;

	/*Calculates health care contribution.
	@return Contribution to health care*/
	double health_care_cont() const;

	/*Calculates vacation days.
	@return Vacation quantity*/
	int vacation() const;
	Professional(std::string fname, std::string lname, double salary, int vac_days);
	Professional();
private:
	double monthly_salary;
	int v_days;
};

class Nonprofessional : public Employee {
public:
	/*Calculates weekly salary.
	@return The weekly salary*/
	double weekly_salary() const;

	/*Calculates health care contribution.
	@return Contribution to health care*/
	double health_care_cont() const;

	/*Calculates vacation hours.
	@return Vacation quantity*/
	int vacation() const;

	Nonprofessional(std::string fname, std::string lname, double hrate, int hworked);
	Nonprofessional();
private:
	double hourly_rate;
	int hours_worked;
};

#endif