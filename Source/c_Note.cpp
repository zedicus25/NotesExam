#include "c_Note.h"

c_Note::c_Note()
{
	this->note = "NULL";
	this->name = "NULL";
	this->category = "NULL";
	this->date = new c_Date();
}

c_Note::c_Note(string note, string name, string kategory, c_Date* date)
{
	this->note = note;
	this->name = name;
	this->category = kategory;
	this->date = new c_Date(date->getDay(), date->getMounth(), date->getYear());
	delete date;
}

c_Note::c_Note(const c_Note& tmp) 
{
	this->note = tmp.getNote();
	this->name = tmp.getName();
	this->category = tmp.getCategory();
	this->date = new c_Date(tmp.getDate()->getDay(), tmp.getDate()->getMounth(), tmp.getDate()->getYear());
}

void c_Note::setName(string name)
{
	this->name = name;
}

void c_Note::setNote(string note)
{
	this->note = note;
}

void c_Note::setCategory(string category)
{
	this->category = category;
}

void c_Note::setDate(int day, int mounth, int year)
{
	delete this->date;
	this->date = new c_Date(day, mounth, year);
}
