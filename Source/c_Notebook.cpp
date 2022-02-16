#include "c_Notebook.h"

string c_Notebook::viewNote(c_Note* note)
{
	string res;
	res += "\t" + note->getName() + "\n";
	res += "Category: " + note->getCategory() + "\n";
	res += note->getNote() + "\n";
	res += "Date of creation: " + note->getDate()->toString() + "\n";
	return res;
}


void c_Notebook::addNote(c_Note* note)
{
	this->notes.push_back(new c_Note(*note));
}

void c_Notebook::removeNote(size_t id)
{
	if (id < 0 || id > this->notes.size()) {
		cout << "Invalid index\n";
		return;
	}

	size_t j = 0;
	c_Note* tmp = new c_Note();
	for (auto i : this->notes) {
		if (j == id) {
			tmp = i;
			break;
		}
		j++;
	}
	this->notes.remove(tmp);
	delete tmp;
}

void c_Notebook::removeNote(string name)
{
	c_Note* tmp = new c_Note();
	for (auto i : this->notes) {
		if (i->getName() == name)
		{
			tmp = i;
			break;
		}
	}
	this->notes.remove(tmp);
	if (tmp->getName() == "NULL") {
		cout << "There are no notes with this name\n";
	}
	delete tmp;
}

void c_Notebook::removeNote(c_Date* date, bool all)
{
	c_Note* tmp = new c_Note();
	if (all) {
		
		list<c_Note*> tmpl;
		for (auto i : this->notes) {
			if (i->getDate()->toString() == date->toString())
			{
				tmpl.push_back(i);
			}
		}

		if (!tmpl.empty()) {
			for (auto i : tmpl) {
				this->notes.remove(i);
			}
		}
		else {
			cout << "There were no notes on this day\n";
		}
			
	}

	for (auto i : this->notes) {
		if (i->getDate()->toString() == date->toString())
		{
			tmp = i;
			break;
		}
	}
	this->notes.remove(tmp);
	if (tmp->getName() == "NULL") {
		cout << "There were no notes on this day\n";
	}
	delete tmp;
	delete date;
}

void c_Notebook::removeCategory(string category)
{
	list<c_Note*> tmpl;
	for (auto i : this->notes) {
		if (i->getCategory() == category)
		{
			tmpl.push_back(i);
		}
	}

	if (!tmpl.empty()) {
		for (auto i : tmpl) {
			this->notes.remove(i);
		}
	}
	else {
		cout << "Category not found\n";
	}
}

void c_Notebook::removeAllNotes()
{
	this->notes.clear();
}

void c_Notebook::editNote(size_t id)
{

	if (id < 0 || id > this->notes.size()) {
		cout << "Invalid index\n";
		return;
	}

	size_t j = 0;
	c_Note* tmp = new c_Note();
	for (auto i : this->notes) {
		if (j == id) {
			tmp = i;
			break;
		}
		j++;
	}
	auto it = std::find(std::begin(this->notes), std::end(this->notes), tmp);
	
	if (it != std::end(this->notes)) {
		
		string name;
		string category;
		string note;
		cout << "Enter name: ";
		std::getline(std::cin, name);
		cout << "Enter category: ";
		std::getline(std::cin, category);
		cout << "Enter note: ";
		std::getline(std::cin, note);
		int d = 0, m = 0, y = 0;
		cout << "Enter date in format(d m y) ";
		std::cin >> d >> m >> y;
		std::cin.ignore();
		this->notes.insert(it, new c_Note(note, name, category, new c_Date(d, m, y)));
		this->notes.remove(tmp);
	}
	delete tmp;
	
}

void c_Notebook::editNote(string name)
{
	c_Note* tmp = new c_Note();
	for (auto i : this->notes) {
		if (i->getName() == name)
		{
			tmp = i;
			break;
		}
	}
	if (tmp->getName() == "NULL") {
		cout << "There are no notes with this name\n";
		return;
	}

	auto it = std::find(std::begin(this->notes), std::end(this->notes), tmp);

	if (it != std::end(this->notes)) {

		string name;
		string category;
		string note;
		cout << "Enter name: ";
		std::getline(std::cin, name);
		cout << "Enter category: ";
		std::getline(std::cin, category);
		cout << "Enter note: ";
		std::getline(std::cin, note);
		int d = 0, m = 0, y = 0;
		cout << "Enter date in format(d m y) ";
		std::cin >> d >> m >> y;
		std::cin.ignore();
		this->notes.insert(it, new c_Note(note, name, category, new c_Date(d, m, y)));
		this->notes.remove(tmp);
	}
	delete tmp;
}

void c_Notebook::editNote(c_Date* date, string name)
{
	c_Note* tmp = new c_Note();
	for (auto i : this->notes) {
		if ((i->getDate()->toString() == date->toString()) && i->getName() == name)
		{
			tmp = i;
			break;
		}
	}
	if (tmp->getName() == "NULL") {
		cout << "There were no notes on this day, with name " << name << "\n";
		return;
	}

	auto it = std::find(std::begin(this->notes), std::end(this->notes), tmp);

	if (it != std::end(this->notes)) {

		string name;
		string category;
		string note;
		cout << "Enter name: ";
		std::getline(std::cin, name);
		cout << "Enter category: ";
		std::getline(std::cin, category);
		cout << "Enter note: ";
		std::getline(std::cin, note);
		int d = 0, m = 0, y = 0;
		cout << "Enter date in format(d m y) ";
		std::cin >> d >> m >> y;
		std::cin.ignore();
		this->notes.insert(it, new c_Note(note, name, category, new c_Date(d, m, y)));
		this->notes.remove(tmp);
	}
	delete tmp;
	delete date;

}

void c_Notebook::editCategory(string oldCategory, string newCategory)
{
	list<c_Note*> tmpl;
	for (auto i : this->notes) {
		if (i->getCategory() == oldCategory)
		{
			tmpl.push_back(i);
		}
	}

	if (!tmpl.empty()) {
		for (auto note : tmpl) {
			auto it = std::find(std::begin(this->notes), std::end(this->notes), note);
			if (it != std::end(this->notes)) {
				this->notes.insert(it, new c_Note(note->getNote(),note->getName(), newCategory, note->getDate()));
				this->notes.remove(note);
			}
		}
	}
	else {
		cout << "Category not found\n";
	}
}

void c_Notebook::showAllNotes()
{
	for (auto i : this->notes) {
		cout << this->viewNote(i) << "\n";
	}
}

void c_Notebook::showByCategory(string category)
{
	for (auto i : this->notes) {
		if(i->getCategory() == category)
			cout << this->viewNote(i) << "\n";
	}
}

void c_Notebook::showByDate(c_Date* date)
{
	for (auto i : this->notes) {
		if (i->getDate()->toString() == date->toString())
			cout << this->viewNote(i) << "\n";
	}
	delete date;
}

void c_Notebook::showById(size_t id)
{
	size_t j = 0;
	for (auto i : this->notes) {
		if (j == id) {
			cout << this->viewNote(i);
			break;
		}
	}
}
