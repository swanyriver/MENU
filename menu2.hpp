/***********************************************************
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
 * ***********************************************************/

#ifndef MENU_HPP_
#define MENU_HPP_


#include <string>
#include <vector>
using namespace std;

class MenuItem {
private:
   void (*myFunction) ();
public:
   string title, intro, repeatpromt;
   bool itemRepeat;
   bool hasIntro;

   MenuItem ( void (*itemFunction) () , string itemTitle , string itemIntro ,
         string itemRepeatprompt = DFLT_REPEART );

   void ItemSelected();
};

class Menu {
private:
   vector<MenuItem> menuItems;
   string menuIntro;

   void RepeatStop();

public:


   bool menuRepeat;

   Menu(string intro);

   void addItem(MenuItem item);

   void showMenu(bool withIntro=true);

   void addExitMenu();

};

#endif /* MENU_HPP_ */
