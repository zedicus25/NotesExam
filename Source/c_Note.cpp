#include "c_Note.h"

c_Note::c_Note()
{
	this->note = "NULL";
	this->name = "NULL";
	this->kategory = "NULL";
	this->date = new c_Date();
}

c_Note::c_Note(string note, string name, string kategory, c_Date* date)
{
	this->note = note;
	this->name = name;
	this->kategory = kategory;
	this->date = new c_Date(date->getDay(), date->getMounth(), date->getYear());
	delete date;
}
