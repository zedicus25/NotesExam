#pragma once
#include <algorithm>
#include <list>
#include "c_Note.h"
using std::list;
using std::cout;
class c_Notebook
{
private:
	list<c_Note*> notes;
	string viewNote(c_Note* note);
	bool rightCategory(c_Note& note, string category) {
		return note.getCategory() == category;
	}
public:
	c_Notebook() {

	}

	void addNote(c_Note* note);

	void removeNote(size_t id);
	void removeNote(string name);
	void removeNote(c_Date* date, bool all);
	void removeCategory(string category);
	void removeAllNotes();

	void editNote(size_t id);
	void editNote(string name);
	void editNote(c_Date* date, string name);
	void editCategory(string oldCategory, string newCategory);

	void showAllNotes();
	void showByCategory(string category);
	void showByDate(c_Date* date);
	void showById(size_t id);

	void saveToFile();
	void readFromFile();

	~c_Notebook()
	{
		//this->saveToFile();
		this->notes.clear();
	}
};

