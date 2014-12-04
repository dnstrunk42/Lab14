#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;

   TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);

   //DO THIS
   //thoroughly test your table
   ListArrayIterator<CD>* iter = cds -> iterator();
   while (iter -> hasNext())
   {
		CD* cd = iter -> next();
		slt -> tableInsert(cd);
	}
	delete iter;
	
	ListDoublyLinkedIterator<CD>* iter2 = slt -> iterator();
	while (iter2 -> hasNext())
	{
		CD* cd2 = iter2 -> next();
		cd2 -> displayCD();
	}
	delete iter2;

	String title = String("Wolves");
	slt -> tableRemove(&title);
	ListDoublyLinkedIterator<CD>* iter3 = slt -> iterator();
	while (iter3 -> hasNext())
	{
		CD* cd3 = iter3 -> next();
		cd3 -> displayCD();
	}
	delete iter3;
	
	String title2 = String("NotHere");
	slt -> tableRemove(&title);
	ListDoublyLinkedIterator<CD>* iter4 = slt -> iterator();
	while (iter4 -> hasNext())
	{
		CD* cd4 = iter4 -> next();
		cd4 -> displayCD();
	}
	delete iter4;



   deleteCDs(cds);
   delete cds;
   delete slt;
   return 0;
}
