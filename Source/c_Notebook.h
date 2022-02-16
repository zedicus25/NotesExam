#pragma once
#include <algorithm>
#include <list>
#include "c_Note.h"
using std::list;
using std::cout;
class c_Notebook
{
private:
	list<c_Note> notes;
public:
	c_Notebook();

	void addNote();

	void removeNote(size_t id);//remove one note
	void removeNote(string name);//remove one note
	void removeNote(c_Date* date, bool all);//remove first note wirh date or all note with date
	void removeKategory(string kategory);//remove all notes in kategory
	void removeAllNotes();//remove all notes

	void editNote(size_t id);
	void editNote(string name);
	void editNote(c_Date* date, string name);
	void editKategory(string kategory);
	void editDate(c_Date* date, string name);

	void saveToFile();
	void readFromFile();

	~c_Notebook()
	{
		//this->saveToFile();
		this->notes.clear();
	}
};

