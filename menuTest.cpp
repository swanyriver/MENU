#include <iostream>
//#include "menu.h"

#include <vector>
#include "myFunctions.h"

using namespace std;


#define DFLT_REPEART "would you like to do that again"
#define QUIT "EXIT PROGRAM"
#define SHOW_ALL "DEMONSTRATE ALL FUNCTIONS"
#define NUM_IN "Please choose by number:"

class MenuItem {
private:
   string title, intro, repeatpromt;
   void (*myFunction) ();
public:
   bool repeat;
   bool hasIntro;
   string GetTitle(){ return title;}
   MenuItem ( void (*itemFunction) () , string itemTitle , string itemIntro ,
         string itemRepeatprompt = DFLT_REPEART ) {
      repeat = true;
      hasIntro = true;
      title = itemTitle;
      intro = itemIntro;
      repeatpromt = itemRepeatprompt;
      myFunction = itemFunction;
   }

   void ItemSelected(){
      do {
         if(hasIntro) cout << endl << intro << endl;
         myFunction();
      } while (repeat && swansonInput::yesNo(repeatpromt));
   }
};

class Menu {
private:
   vector<MenuItem> menuItems;
   string menuIntro;
   bool menuRepeat;

public:
   void repeatOff(){
        menuRepeat = false;
     }
   Menu(string intro){
      menuIntro = intro;
      menuRepeat=true;
   }
   void addItem(MenuItem item){
      menuItems.push_back(item);
   }
   void addExitMenu(){
      /*MenuItem exitMenu(repeatOff,"exit menu","hello");
      exitMenu.repeat=false;
      exitMenu.hasIntro=false;
      addItem(exitMenu);*/
   }
   void showMenu(bool withIntro=true){
      do {
         if(withIntro) cout << endl << menuIntro << endl;
         for (int i = 0; i < menuItems.size(); i++) {
            cout << "[" << i+1 << "] ";
            cout << menuItems.at(i).GetTitle();
            cout << endl;
         }
         int selection=swansonInput::GetInt(NUM_IN,1,menuItems.size());
         menuItems.at(selection-1).ItemSelected();
      } while (menuRepeat);

   }

};

//////////////////////////////////////





void hello(){
   cout << endl <<"hello function";
}
void goodbye(){
   cout << endl <<"goodbye function";
}
void love(){
   cout << endl << "i love you";
}



int main(){

   MenuItem helloItem(hello,"hello","lest say hello","hello again");
   MenuItem goodbyeItem(goodbye,"goodbye","now we say goodbye");
   goodbyeItem.repeat=false;
   MenuItem loveItem(love,"love","love");
   loveItem.hasIntro=false;



   Menu myMenu("welcome to the menu");
   myMenu.addItem(helloItem);
   myMenu.addItem(goodbyeItem);
   myMenu.addItem(loveItem);
   //myMenu.addExitMenu();
/*
   MenuItem exitMenu(myMenu.repeatOff,"exit menu","hello");
      exitMenu.repeat=false;
      exitMenu.hasIntro=false;
      myMenu.addItem(exitMenu);*/

   myMenu.showMenu();

}
