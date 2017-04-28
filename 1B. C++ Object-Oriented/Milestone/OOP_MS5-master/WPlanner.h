//Alejandro Mesa Suarez 
//Student #038515151
//Milestone 5 Implementation
#ifndef __ict_WPlanner_H__
#define __ict_WPlanner_H__
#include "wpgeneral.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"
namespace ict {
   class WPlanner {
	   //Private members
	   //Variables
      char filename_[256];
      Good* items_[MAX_NO_RECS];
      std::fstream datafile_;   //file
      int noOfItems_;
	  //functions
      int menu();
      void loadRecs();
      void saveRecs();
      void listItems()const;
      int SearchItems(const char* sku)const;
      void updateQty();
      void addItem(bool isCustomMade);
      void deleteItem();
      void getSku(char* sku);
   public:
      //Copy and assignment prevention goes here:
	   WPlanner(const char* filename);
	   ~WPlanner();
      int run();
   };
}
#endif
