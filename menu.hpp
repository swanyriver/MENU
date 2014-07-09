/**********************************************************
 *
 *  Author: Brandon Swanson
 *
 *  Date Created: 07-06-2014
 *
 *  Last Modification Date: 07-07-2014
 *
 *  Filename: menu.hpp
 *
 *  Overview: Holds a list of Menu Items which contain output strings and a
 *  single void() function to be executed upon selection
 *
 *  Input: an integer from [1-Number of selections available]
 *
 *  Output:selected function is executed
 *
 * **********************************************************/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "myFunctions.hpp"
using namespace std;

//strings for menu
#define DFLT_REPEART "would you like to do that again"
#define EXIT "EXIT MENU"
#define SHOW_ALL "DEMONSTRATE ALL FUNCTIONS"
#define NUM_IN "Please choose by number:"

//items to be added to menu
class MenuItem {
private:
   void (*myFunction) ();
public:
   string title, intro, repeatpromt;
   bool itemRepeat;
   bool hasIntro;

   //constructor for menu item
   MenuItem ( void (*itemFunction) () , string itemTitle , string itemIntro ,
         string itemRepeatprompt = DFLT_REPEART ) {
      itemRepeat = true;
      hasIntro = true;
      title = itemTitle;
      intro = itemIntro;
      repeatpromt = itemRepeatprompt;
      myFunction = itemFunction;
   }

   //introduces and executes the function held by menu item
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

   bool menuRepeat; //controls if menu repeats
   bool demoAllItem, exitMenuItem; //include items for menu functions

   //constructor for menu
   Menu ( string intro ) :
         menuIntro( intro ), menuRepeat( true ), demoAllItem( true ), exitMenuItem(
               true ) {
   }

   //add an item to the menu
   void addItem ( MenuItem item ) {
      menuItems.push_back( item );
   }
   //constructs a menu item with passed parameters and defualts, adds it to menu
   void addItem ( void (*itemFunction) () , string itemTitle ,
         string itemIntro , string itemRepeatprompt = DFLT_REPEART ) {
      MenuItem addedItem( itemFunction , itemTitle , itemIntro ,
            itemRepeatprompt );
      addItem( addedItem );
   }

   //display menu options and prompt for selection
   void showMenu ( bool withIntro = true ) {
      int demoItemNumber = -1;
      int exitItemNumber = -1;
      do {
         ///////////display menu////////////////////
         if ( withIntro )
            cout << endl << menuIntro << endl;
         int i = 0;
         for ( ; i < menuItems.size() ; i++ ) {
            cout << "[" << i + 1 << "] ";
            cout << menuItems.at( i ).title;
            cout << endl;
         }
         ////////////display menu function items/////
         i++;
         if ( demoAllItem ) {
            cout << "[" << i << "] " << SHOW_ALL << endl;
            demoItemNumber = i;
            i++;
         }
         if ( exitMenuItem ) {
            cout << "[" << i << "] " << EXIT << endl;
            exitItemNumber = i;
         }

         //get selection//////////
         int selection = swansonInput::GetInt( NUM_IN , 1 ,
               menuItems.size() + demoAllItem + exitMenuItem );

         //execute selection
         if ( selection == demoItemNumber ) {
            for ( int i = 0 ; i < menuItems.size() ; i++ )
               menuItems.at( i ).ItemSelected();
         } else if ( selection == exitItemNumber ) {
            menuRepeat = false;
         } else {
            menuItems.at( selection - 1 ).ItemSelected();
         }

      } while ( menuRepeat ); //repeat menu
   }

   //used for passing in the number you wish selected
   void runFromCommandLine ( int argc , char* argv[] ) {

        for ( int i = 1 ; i < argc ; i++ ) {

           if ( swansonString::AllNumbers( argv[i] ) ) {

              int selectionNumber = strtol( argv[i] , NULL , 0 );

              if ( selectionNumber > 0
                    && selectionNumber
                          <= (menuItems.size() + demoAllItem + exitMenuItem) ){
                 menuItems.at( selectionNumber-1 ).ItemSelected();
              }

           }
        }
     }

};

#endif /*MENU_HPP_ */
