#define DFLT_REPEART "would you like to do that again"
#define QUIT "EXIT PROGRAM"
#define SHOW_ALL "DEMONSTRATE ALL FUNCTIONS"
#define NUM_IN "Please choose by number:"

#include <iostream>
#include <string>
#include <vector>
#include "myFunctions.h"
#include "menu2.hpp"

using namespace std;

MenuItem::MenuItem ( void (*itemFunction) () , string itemTitle ,
      string itemIntro , string itemRepeatprompt = DFLT_REPEART ) {
   itemRepeat = true;
   hasIntro = true;
   title = itemTitle;
   intro = itemIntro;
   repeatpromt = itemRepeatprompt;
   myFunction = itemFunction;
}
void MenuItem::ItemSelected(){
   do {
      if(hasIntro) cout << endl << intro << endl;
      myFunction();
   } while (itemRepeat && swansonInput::yesNo(repeatpromt));
}

/////////////////////////////////////////////////////////////////////////////

void Menu::repeatStop(){
   menuRepeat=false;
}

Menu::Menu(string intro): menuIntro(intro), menuRepeat(false){}

void Menu::addItem(MenuItem item){
   menuItems.push_back(item);
}

void Menu::showMenu(bool withIntro=true){
   if(withIntro) cout << endl << menuIntro << endl;
   for (int i = 1; i < menuItems.size(); i++) {
      cout << "[" << i+1 << "] ";
      cout << menuItems.at(i).title;
      cout << endl;
   }
   int selection=swansonInput::GetInt(NUM_IN,1,menuItems.size());
   menuItems.at(selection-1).ItemSelected();
}

void Menu::addExitMenu(){
   MenuItem exit(repeatStop,"Exit Menu"," ");
}
