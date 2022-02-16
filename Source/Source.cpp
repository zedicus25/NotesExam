#include <iostream>
#include "c_Notebook.h"
using std::cin;
int main()
{
    c_Notebook* notes = new c_Notebook();

    int userInput = -1;
    do
    {
        system("cls");
        cout << "1 - Add note\n";
        cout << "2 - Remove note by id\n";
        cout << "3 - Remove note by name\n";
        cout << "4 - Remove note by date\n";
        cout << "5 - Remove notes by category(all with the same category)\n";
        cout << "6 - Remove all notes\n";
        cout << "7- Edit note by id\n";
        cout << "8 - Edit note by name\n";
        cout << "9 - Edit categories in notes\n";
        cout << "10 - Show all notes\n";
        cout << "11 - Show by category \n";
        cout << "12 - Show by date \n";
        cout << "13 - Show by id \n";
        cout << "0 - Exit \n";
        cin >> userInput;
        switch (userInput)
        {
        case 1: {
            system("cls");
            string name;
            string category;
            string note;
            cin.ignore();
            cout << "Enter name: ";
            std::getline(cin, name);
            cout << "Enter category: ";
            std::getline(cin, category);
            cout << "Enter note: ";
            std::getline(cin, note);
            int d = 0, m = 0, y = 0;
            cout << "Enter date(d m y): ";
            cin >> d >> m >> y;
            notes->addNote(*(new c_Note(note, name, category, new c_Date(d, m, y))));
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            int id = 0;
            cout << "Enter id: ";
            cin >> id;
            notes->removeNote(id);
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            string name;
            cin.ignore();
            cout << "Enter name: ";
            std::getline(cin, name);
            notes->removeNote(name);
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            int d = 0, m = 0, y = 0, f=0;
            cout << "Enter date(d m y): ";
            cin >> d >> m >> y;
            cout << "Delete all notes with this date? (1-true/0-false)";
            cin >> f;
            if (f <= 1 || f >= 0)
                notes->removeNote(new c_Date(d, m, y), f);
            else
                notes->removeNote(new c_Date(d, m, y), false);
            system("pause");
            break;
        }
        case 5: {
            system("cls");
            string category;
            cin.ignore();
            cout << "Enter category: ";
            std::getline(cin, category);
            notes->removeCategory(category);
            system("pause");
            break;
        }
        case 6: {
            system("cls");
            notes->removeAllNotes();
            system("pause");
            break;
        }
        case 7: {
            system("cls");
            int id;
            cout << "Enter id: ";
            cin >> id;
            notes->editNote(id);
            system("pause");
            break;
        }
        case 8: {
            system("cls");
            string name;
            cin.ignore();
            cout << "Enter name: ";
            std::getline(cin, name);
            notes->editNote(name);
            system("pause");
            break;
        }
        case 9: {
            system("cls");
            string oldCategory;
            string newCategory;
            cin.ignore();
            cout << "Enter old category: ";
            std::getline(cin, oldCategory);
            cout << "Enter new category: ";
            std::getline(cin, newCategory);
            notes->editCategory(oldCategory, newCategory);
            system("pause");
            break;
        }
        case 10: {
            system("cls");
            notes->showAllNotes();
            system("pause");
            break;
        }
        case 11: {
            system("cls");
            string category;
            cin.ignore();
            cout << "Enter category: ";
            std::getline(cin, category);
            notes->showByCategory(category);
            system("pause");
            break;
        }
        case 12: {
            system("cls");
            int d = 0, m = 0, y = 0;
            cout << "Enter date(d m y): ";
            cin >> d >> m >> y;
            notes->showByDate(new c_Date(d, m, y));
            system("pause");
            break;
        }
        case 13: {
            system("cls");
            int id = 0;
            cout << "Enter id: ";
            cin >> id;
            notes->showById(id);
            system("pause");
            break;
        }
        case 0:
            break;
        default:
            cout << "Incorrect input\n";
            break;
        }
    } while (userInput != 0);

    delete notes;
}