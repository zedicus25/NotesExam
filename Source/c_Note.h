#pragma once
#include "c_Date.h"
using std::string;
class c_Note
{
private:
	string note;
	string name;
	string category;
	c_Date* date;
public:
	c_Note();
	c_Note(string note, string name, string category, c_Date* date);
	c_Note(const c_Note& tmp);

	void setName(string name);
	void setNote(string note);
	void setCategory(string category);
	void setDate(int day, int mounth, int year);

	inline string getName() const {
		return this->name;
	}
	inline string getNote() const {
		return this->note;
	}
	inline string getCategory() const {
		return this->category;
	}
	inline c_Date* getDate() const  {
		return this->date;
	}
	
	~c_Note()
	{
		delete this->date;
	}
};

