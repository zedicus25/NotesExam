#include <iostream>
#include "c_Notebook.h"
int main()
{
    c_Note* nt = new c_Note("fdgsdfg", "name", "category", new c_Date(5, 5, 2021));
    c_Note* nt1 = new c_Note("sfghsfhfsgh", "name1", "category", new c_Date(3, 1, 2021));
    c_Note* nt2 = new c_Note("sDFGFD", "name2", "DAFGAD", new c_Date(5, 5, 2021));
    c_Notebook* notes = new c_Notebook();
    notes->addNote(nt);
    notes->addNote(nt1);
    notes->addNote(nt2);
    //notes->showAllNotes();
    //notes->removeCategory("category");
    //notes->editNote(new c_Date(5, 5, 2021), "name");
    //notes->editCategory("category", "NEWCATEGORY");
    //notes->showByCategory("category");
    //notes->showByDate(new c_Date(5,5,2021));
    cout << "----------------------------------------\n";
    //notes->showAllNotes();
    delete nt;
    delete nt1;
    delete nt2;
    delete notes;
    
}