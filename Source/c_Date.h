#pragma once
#include <string>
#include <iostream>
class c_Date
{
private:
	int day;
	int mounth;
	int year;
public:
	c_Date();
	c_Date(int day, int mounth, int year);

	void setDay(int day);
	void setMounth(int mounth);
	void setYear(int year);

	inline int getDay() const {
		return this->day;
	}
	inline int getMounth() const{
		return this->mounth;
	}
	inline int getYear() const {
		return this->year;
	}

	std::string toString();
};

