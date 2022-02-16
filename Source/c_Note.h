#pragma once
#include "c_Date.h"
using std::string;
class c_Note
{
private:
	string note;
	string name;
	string kategory;
	c_Date* date;
public:
	c_Note();
	c_Note(string note, string name, string kategory, c_Date* date);

	inline string getName() const {
		return this->name;
	}
	inline string getNote() const {
		return this->note;
	}
	inline string getKategory() const {
		return this->kategory;
	}
	inline c_Date* getDate() const  {
		return this->date;
	}
	
	~c_Note()
	{
		delete this->date;
	}
};

