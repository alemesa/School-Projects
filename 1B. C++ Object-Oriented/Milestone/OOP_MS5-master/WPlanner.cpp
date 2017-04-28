//Alejandro Mesa Suarez 
//Student #038515151
//Milestone 5 Implementation
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include<iostream>
#include <iomanip>
#include "WPlanner.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"

using namespace std;
namespace ict {

	

   WPlanner::WPlanner(const char* filename) {

	   strncpy(filename_, filename, 256);
	   noOfItems_ = 0;
	   loadRecs();

   }
   WPlanner::~WPlanner() {}
  
   
	   void WPlanner::loadRecs() {
		   int readIndex = 0;
		   char id;
		   fstream datafile_(filename_, ios::in);
		   if (datafile_.fail()) {
			   datafile_.clear();
			   datafile_.close();
			   fstream datafile_(filename_, ios::out);
			   datafile_.close();
		   }
		   else {
			   while (readIndex < MAX_NO_RECS && !datafile_.fail()) {
				   id = datafile_.get();
				   if (id == 'C') {
					   items_[readIndex] = new CustomMade;
				   }
				   else if (id == 'O') {
					   items_[readIndex] = new OnShelf;
				   }

				   if (id == 'O' || id == 'C') {
					   datafile_.ignore();

					   items_[readIndex]->load(datafile_);
					   readIndex++;
					   datafile_.ignore(1000, '\n');
				   }
			   }
			   noOfItems_ = readIndex;
			   datafile_.close();
		   }
	   }
   void WPlanner::saveRecs() {
	   //Loop throught the file and save everything on the file
	   datafile_.open(filename_, ios::out);
	   int i;
	   if (datafile_.is_open()) {
		   for (i = 0; i < noOfItems_; i++) {
			   items_[i]->store(datafile_);
		   }
	   }
	   //close it
	   datafile_.close();


   }
   void WPlanner::getSku(char* sku){

	   cout << "Please enter the SKU: ";
	   cin.get();
	   cin.getline(sku, MAX_SKU_LEN + 1, '\n');
	   if (cin.fail()) {
		   cin.clear();
		   cin.ignore();
	   }



   }
   
   void WPlanner::deleteItem() {
	   //Extra Marks
	 // cout << "Not implemented!" << endl << endl;
	  char answer;
	  char* sku = new char[MAX_SKU_LEN + 1];
	  getSku(sku);
	  int _id = -1;
	  _id = SearchItems(sku);
	  int tempItem;
	  if (_id == -1) {
		  cout << "Item Not found!" << endl << endl;
	  }
	  else {
		  int x = 0;

		  items_[_id]->display(cout, false);
		  cout << endl << endl << "The following item will be deleted: ";
		  cout << endl << "Type(Y) to confirm or (N)to abort : ";
		  cin >> answer;
		  if (toupper(answer) == 'Y') {
			//Remove Item
			  items_[_id] = items_[_id+1];
			  noOfItems_ = noOfItems_ - 1;
			  items_[_id] = nullptr;
			  cout << endl << "Removed!\n";
		  }
		  else {
			  cout << endl << "Not Removed!\n";
		  }
		  saveRecs();
	  }
	  



   }
   void WPlanner::updateQty() {
	   char* sku = new char[MAX_SKU_LEN + 1];
	   getSku(sku);
	   int _id = -1;
	   _id = SearchItems(sku);
	   int tempItem;
	   if (_id == -1) {
		   cout << "Not found!" << endl << endl;
	   }
	   else {
		   int x = 0;
		   items_[_id]->display(cout, false);
		   cout << endl << endl << "Please enter the number of purchased goods: ";
		   cin >> tempItem;
		   if (cin.fail()) {
			   cout << "Invalid Quantity value!" << endl;
		   }
		   else {
			   x = (items_[_id]->qtyNeeded() - items_[_id]->quantity());
			   if (tempItem <= x) {
				   *items_[_id] += tempItem;
			   }
			   else {
				   cout << endl;
				   cout << "Too many purchased, only " << items_[_id]->qtyNeeded() <<
					   " needed, please return the extra " << -tempItem + items_[_id]->qtyNeeded() << "." << endl;
			   }
			   saveRecs();
			   cout << endl << "Updated!\n";

		   }
	   }

   }

   void WPlanner::listItems()const {


	   cout << " Row | SKU | Good Name          | Cost  |Tax| QTY|Need| Delivery" << endl
		    << "-----|-----|--------------------|-------|---|----|----|----------" << endl;

	   double total = 0.0;

	   for (int i = 0; i < noOfItems_; i++) {
		   cout << right << setfill(' ') << setw(4) << (i + 1) << " | " << *items_[i] << endl;
		   total += *items_[i];
	   }

	  // cout << "---------------------------------------------------------------------------" << endl;
	   cout << "-----+-----+--------------------+-------+---+----+----+----------" << endl;
	   cout << "Total cost of the Wedding: $";
	   cout << fixed << left << setprecision(2) << total << endl << endl;







   }
  
   int WPlanner::SearchItems(const char* sku)const {
	   int i;
	   int index = -1;
	   for (i = 0; i < noOfItems_; i++) {
		   if (!strcmp(items_[i]->sku(), sku)) {
			   index = i;
		   }
	   }
	   return index;
   }
   void WPlanner::addItem(bool isCustomMade) {


	   if (isCustomMade == true) {

		   CustomMade *newMade = new CustomMade();
		   cin >> *newMade;

		   if (!cin.fail()) {
			   items_[noOfItems_++] = newMade;
			   saveRecs();
			   cout << "Good added\n" << endl;
		   }
		   else {
			   cout << *newMade; 
			   cin.clear();
			   cin.ignore();
		   }
	   }
	   else {
		   OnShelf *newShelf = new OnShelf();
		   cin >> *newShelf;

		   if (!cin.fail()) {
			   items_[noOfItems_++] = newShelf;
			   saveRecs();
			   cout << "Good added\n" << endl;
		   }
		   else {
			   cout << *newShelf; 
			   cin.clear();
			   cin.ignore();
		   }
	   }

   }
   int WPlanner::menu() {
      int selection;
	  
	  cout << "Wedding Planner Management Program" << endl;
	  cout << "1 - List goods" << endl;
	  cout << "2 - Add On Shelf Good" << endl;
	  cout << "3 - Add Custom-Made Good" << endl;
	  cout << "4 - Update Good quantity" << endl;
	  cout << "5 - Delete" << endl;
	  cout << "0 - Exit program" << endl;
	  cout << "> ";
	  cin >> selection;
	  cout << endl;

	  if (cin.fail()) {
		  cin.clear();
		  cin.ignore(2000, '\n');
		  selection = -1;
	  }

	  /*while ((selection = getchar()) != '\n' && selection != EOF);
	  if (cin.fail() || selection >5 || selection<0) {
		  cin.clear();
		  cin.ignore();
		  selection = -1;
	  }
	  return selection;*/

	  switch (selection) {

	  case 1:
		  selection = 1;
		  break;

	  case 2:
		  selection = 2;
		  break;

	  case 3:
		  selection = 3;
		  break;

	  case 4:
		  selection = 4;
		  break;

	  case 5:
		  selection = 5;
		  break;

	  case 0:
		  selection = 0;
		  break;

	  default:
		  selection = -1;
		  break;
	  }



      return selection;
   }
   int WPlanner::run() {
      bool done = false;
	  int option;
	  

      while (!done) {
		 option = menu();
         switch(option){
         case 1:
			 listItems();
            break;
         case 2:
			 addItem(false);

            break;
         case 3:
			 addItem(true);

            break;
         case 4:
			 updateQty();
            break;
         case 5:
			 deleteItem();
            break;
         case 0:
            done = true;
            cout << "Goodbye!!" << endl << endl;
            break;
         case -1:
            cout << "===Invalid Selection, try again.===" << endl <<endl ;
            break;
         }
      }
      return 0;
   } // WPlanner::run() end
}


/* outputs

Wedding Planner Management Program
1 - List goods
2 - Add On Shelf Good
3 - Add Custom-Made Good
4 - Update Good quantity
5 - Delete
0 - Exit program
>



Not found!

Please enter the number of purchased goods:

Too many purchased, only 5 needed, please return the extra 15.

Updated!

Not implemented!

*/