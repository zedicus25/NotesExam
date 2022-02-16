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

string c_Notebook::toString()
{
	string res;
	for (auto i: this->notes) {
		res += i->getName() + "|" + i->getCategory() + "|";
		res += i->getNote() + "|" + i->getDate()->toString() + "\n";
	}
	return res;
}

void c_Notebook::addNote(c_Note &note)
{
	this->notes.push_back(&note);
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
			auto it = std::find(this->notes.begin(), this->notes.end(), i);
			if (it != this->notes.end())
				this->notes.remove((*it));
			break;
		}
		j++;
	}
}

void c_Notebook::removeNote(string name)
{
	for (auto i : this->notes) {
		if (i->getName() == name)
		{
			auto it = std::find(this->notes.begin(), this->notes.end(), i);
			if (it != this->notes.end())
				this->notes.remove((*it));
			break;
		}
	}
}

void c_Notebook::removeNote(c_Date* date, bool all)
{
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
			auto it = std::find(this->notes.begin(), this->notes.end(), i);
			if (it != this->notes.end())
				this->notes.remove((*it));
			break;
		}
	}

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
	for (auto i : this->notes) {
		if (j == id) {
			auto it = std::find(std::begin(this->notes), std::end(this->notes), i);

			if (it != std::end(this->notes)) {

				string name;
				string category;
				string note;
				cout << "Enter name: ";
				std::getline(std::cin, name);
				(*it)->setName(name);
				cout << "Enter category: ";
				std::getline(std::cin, category);
				(*it)->setCategory(category);
				cout << "Enter note: ";
				std::getline(std::cin, note);
				(*it)->setNote(note);
				int d = 0, m = 0, y = 0;
				cout << "Enter date in format(d m y) ";
				std::cin >> d >> m >> y;
				std::cin.ignore();
				(*it)->setDate(d, m, y);
			}
			return;
		}
		j++;
	}
}

void c_Notebook::editNote(string name)
{
	for (auto i : this->notes) {
		if (i->getName() == name)
		{
			auto it = std::find(std::begin(this->notes), std::end(this->notes), i);

			if (it != std::end(this->notes)) {

				string name;
				string category;
				string note;
				cout << "Enter name: ";
				std::getline(std::cin, name);
				(*it)->setName(name);
				cout << "Enter category: ";
				std::getline(std::cin, category);
				(*it)->setCategory(category);
				cout << "Enter note: ";
				std::getline(std::cin, note);
				(*it)->setNote(note);
				int d = 0, m = 0, y = 0;
				cout << "Enter date in format(d m y) ";
				std::cin >> d >> m >> y;
				std::cin.ignore();
				(*it)->setDate(d, m, y);
			}
			return;
		}
	}
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
				(*it)->setCategory(newCategory);
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

void c_Notebook::saveToFile()
{
	std::ofstream file("Data.txt");
	file << this->toString();
	file.close();
}

void c_Notebook::readFromFile()
{
	std::ifstream file("Data.txt");
	string str;
	string name;
	string category;
	string note;
	size_t pos = 0;
	while (!file.eof()) {
		std::getline(file, str);

		pos = str.find("|");
		name = str.substr(0, pos);
		str.erase(0, pos + 1);

		pos = str.find("|");
		category = str.substr(0, pos);
		str.erase(0, pos + 1);

		pos = str.find("|");
		note = str.substr(0, pos);
		str.erase(0, pos + 1);

		int d = 0, m = 0, y = 0;
		pos = str.find("/");
		d = atoi(str.substr(0, pos).c_str());
		str.erase(0, pos + 1);
		
		pos = str.find("/");
		m = atoi(str.substr(0, pos).c_str());
		str.erase(0, pos + 1);

		y = atoi(str.substr(0, string::npos).c_str());

		if(name != "")
			this->addNote(*(new c_Note(note, name, category, new c_Date(d, m, y))));
	}
}
