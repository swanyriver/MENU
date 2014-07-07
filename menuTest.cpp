#include <iostream>
#include "menu.hpp"

//#include <vector>
//#include "myFunctions.h"

using namespace std;

//////////////////////////////////////



int lovenumber=6;

void hello(){
   cout << endl <<"hello function";
}
void goodbye(){
   cout << endl <<"goodbye function";
}
void love(){
   cout << endl << "i love you";
   lovenumber++;
   cout << "lovenumber=" << lovenumber;
}




int main(){

   MenuItem helloItem(hello,"hello","lest say hello","hello again");
   MenuItem goodbyeItem(goodbye,"goodbye","now we say goodbye");
   goodbyeItem.itemRepeat=false;
   MenuItem loveItem(love,"love","love");
   loveItem.hasIntro=false;




   Menu myMenu("welcome to the menu");
   myMenu.addItem(helloItem);
   myMenu.addItem(goodbyeItem);
   myMenu.addItem(loveItem);

   myMenu.demoAllItem=true;
   myMenu.exitMenuItem=true;
   myMenu.menuRepeat=true;

   myMenu.showMenu();

}
