#include "c_Date.h"

c_Date::c_Date()
{
	this->day = 1;
	this->mounth = 1;
	this->year = 1900;
}

c_Date::c_Date(int day, int mounth, int year)
{
	this->setDay(day);
	this->setMounth(mounth);
	this->setYear(year);
}

void c_Date::setDay(int day)
{
	try
	{
		if (day >= 1 && day <= 31) {
			this->day = day;
		}
		else {
			this->day = 1;
			throw std::string("Day can only be positive and not more than 31");
		}
	}
	catch (std::string ex)
	{
		std::cout << ex<< "\n";
	}
}

void c_Date::setMounth(int mounth)
{
	try
	{
		if (mounth >= 1 && mounth <= 12) {
			this->mounth = mounth;
		}
		else {
			this->mounth = 1;			
			throw std::string("Mounth can only be positive and not more than 12");
		}
	}
	catch (std::string ex)
	{
		std::cout << ex << "\n";
	}
}

void c_Date::setYear(int year)
{
	try
	{
		if (year >= 1900 && year <= 2022) {
			this->year = year;
		}
		else {
			this->year = 1900;
			throw std::string("Year can only be positive and not more than 1900 and less 2022");
		}
	}
	catch (std::string ex)
	{
		std::cout << ex << "\n";
	}
}

std::string c_Date::toString()
{
	std::string res;
	res += std::to_string(this->day);
	res.push_back('/');
	res += std::to_string(this->mounth);
	res.push_back('/');
	res += std::to_string(this->year);
	return res;
}
