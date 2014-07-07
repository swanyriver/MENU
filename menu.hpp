/**********************************************************
 *
 *  Author: Brandon Swanson
 *
 *  Date Created: 07-06-2014
 *
 *  Last Modification Date: 07-06-2014
 *
 *  Filename: menu.hpp
 *
 *  Overview:
 *
 *  Input:
 *
 *  Output:
 *
 * **********************************************************/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "myFunctions.h"
using namespace std;

#define DFLT_REPEART "would you like to do that again"
#define QUIT "EXIT PROGRAM"
#define EXIT "EXIT MENU"
#define SHOW_ALL "DEMONSTRATE ALL FUNCTIONS"
#define NUM_IN "Please choose by number:"

class MenuItem {
private:
   void (*myFunction) ();
public:
   string title, intro, repeatpromt;
   bool itemRepeat;
   bool hasIntro;
   MenuItem ( void (*itemFunction) () , string itemTitle , string itemIntro ,
         string itemRepeatprompt = DFLT_REPEART ) {
      itemRepeat = true;
      hasIntro = true;
      title = itemTitle;
      intro = itemIntro;
      repeatpromt = itemRepeatprompt;
      myFunction = itemFunction;
   }

   void ItemSelected () {
      do {
         if ( hasIntro )
            cout << endl << intro << endl;
         myFunction();
      } while ( itemRepeat && swansonInput::yesNo( repeatpromt ) );
   }
};

class Menu {
private:
   vector<MenuItem> menuItems;
   string menuIntro;

public:

   bool menuRepeat;
   bool demoAllItem, exitMenuItem;

   Menu ( string intro ) :
         menuIntro( intro ), menuRepeat( false ),
         demoAllItem( false ), exitMenuItem( false ) {}

   void addItem ( MenuItem item ) {
      menuItems.push_back( item );
   }

   void showMenu ( bool withIntro = true ) {
      int demoItemNumber = -1;
      int exitItemNumber = -1;
      do {
         if ( withIntro )
            cout << endl << menuIntro << endl;
         int i = 0;
         for (; i < menuItems.size() ; i++ ) {
            cout << "[" << i + 1 << "] ";
            cout << menuItems.at( i ).title;
            cout << endl;
         }
         i++;
         if(demoAllItem){
            cout << "[" << i << "] " << SHOW_ALL << endl;
            demoItemNumber = i;
            i++;
            //for ( int i = 0 ; i < menuItems.size() ; i++ )
            //   menuItems.at(i).ItemSelected;
         }
         if(exitMenuItem){
            cout << "[" << i << "] " << EXIT << endl;
            exitItemNumber = i;
         }


         //get selection
         int selection = swansonInput::GetInt( NUM_IN , 1 , menuItems.size() + demoAllItem + exitMenuItem );

         //execute selection
         if(selection == demoItemNumber){
            for ( int i = 0 ; i < menuItems.size() ; i++ )
               menuItems.at(i).ItemSelected();
         } else if (selection == exitItemNumber){
            menuRepeat=false;
         }
         else{
            menuItems.at( selection - 1 ).ItemSelected();
         }

      } while ( menuRepeat );
   }

};

#endif /*MENU_HPP_ */
