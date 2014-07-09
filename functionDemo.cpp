/***********************************************************
 * Author: Brandon Swanson
 * Date Created: 06-29-2014
 * Last Modification Date: 06-29-2014
 * Filename: functionDemo.cpp
 *
 * Overview: This will be showcase of all of the various computational
 * functions described in assignment 2
 *
 * Input:
 *
 * Output:
 *
 ***********************************************************/

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <climits>
#include <list>
#include "myFunctions.hpp"
#include "menu.hpp"

using namespace std;

void OneLetterAtATime ( string my_str );
void FormatName ();
void RandomNumbers ();
void CompareStringsManually ();
void BetterRandom ();
void MilesPerGallon ();
void SelectFinalist ();

int main (int argc , char* argv[] ) {
  // const int NUMBER_OF_SELECTIONS = 7;
  // const int PLAY_ALL = NUMBER_OF_SELECTIONS + 1;
   //const int QUIT = NUMBER_OF_SELECTIONS + 2;

  // bool playAll = false;
   //int selectionNumber;
   //string prompt;

   swansonUtil::SeedRandom();

   cout << "int max: " << INT_MAX << endl;
   cout << "welcome to assignment 2 exercise components, "
         << "I have a great variety of functionality to show you";

   Menu myMenu("wich would you like to see now:");
   //myMenu.demoAllItem=true;
  // myMenu.exitMenuItem=true;
   //myMenu.menuRepeat=true;

   myMenu.addItem(FormatName,"format a name","","format more names");
   myMenu.addItem(RandomNumbers,"random Numbers","","more random numbers");
   myMenu.addItem(BetterRandom,"better random","","more random numbers");
   myMenu.addItem(MilesPerGallon,"miles per gallon","","compute more mpg");
   myMenu.addItem(SelectFinalist,"select finalist","","select more finalist");

   myMenu.runFromCommandLine(argc,argv);

   myMenu.showMenu();

   /*do {
      if ( !playAll ) {
         cout << endl << "wich would you like to see now:" << endl
               << "[1] o-n-e l-e-t-t-e-r a-t a t-i-m-e" << endl
               << "[2] format a name" << endl << "[3] Random Numbers" << endl
               << "[4] Compare Strings" << endl << "[5] Better Random Numbers"
               << endl << "[6] Miles Per Gallon from Litters" << endl
               << "[7] Select Winning Finalist" << endl
               << "[8] DEMONSTRATE ALL FUNCTIONS (from 1-7)" << endl
               << "[9] QUIT THIS PROGRAM";

         selectionNumber = swansonInput::GetInt ( "choose by number:" , 1 ,
               NUMBER_OF_SELECTIONS + 2 );
      }

      if ( playAll && selectionNumber <= NUMBER_OF_SELECTIONS )
         selectionNumber++;
      if ( playAll && selectionNumber > NUMBER_OF_SELECTIONS )
         selectionNumber = QUIT;
      if ( selectionNumber == PLAY_ALL ) {
         selectionNumber = 1;
         playAll = true;
      }

      do {
         switch (selectionNumber) {
         case 1:
            prompt = "print more strings";
            OneLetterAtATime (
                  swansonInput::GetString ( "please enter a string: " ) );
            break;
         case 2:
            prompt = "format more names";
            FormatName ();
            break;
         case 3:
            prompt = "make more random numbers";
            RandomNumbers ();
            break;
         case 4:
            prompt = "compare more strings";
            CompareStringsManually ();
            break;
         case 5:
            prompt = "make more random numbers";
            BetterRandom ();
            break;
         case 6:
            prompt = "calculate more mileages";
            MilesPerGallon ();
            break;
         case 7:
            prompt = "select more finalists";
            SelectFinalist ();
            break;
         default:
            selectionNumber = QUIT;
            break;
         }
      } while ( selectionNumber != QUIT && swansonInput::yesNo ( prompt ) );

   } while ( selectionNumber != QUIT );*/

   cout << endl << "thank you, come again soon" << endl;
}

//////////////////////////////////////////////
///PROBLEM SEVEN////FINALISTS/////////////////
//////////////////////////////////////////////

void SelectFinalist () {
   const int NUM_FINALIST = 25;
   const int NUM_WINNERS = 4;
   int finalistsSelected[NUM_WINNERS];

   cout << endl << "We are about to select " << NUM_WINNERS
         << " winners out of " << NUM_FINALIST << " finalists";

   swansonUtil::GetMappedRandomInts ( finalistsSelected , 1 , NUM_FINALIST ,
         NUM_WINNERS );

   cout << endl << "Finalist selected are: ";
   for ( int i = 0 ; i < NUM_WINNERS ; ++i ) {
      cout << finalistsSelected[i] << ((i < NUM_WINNERS - 1) ? ", " : "");
   }
}

//////////////////////////////////////////////
///PROBLEM SIX//////MILES PER GALLON//////////
//////////////////////////////////////////////
const float GALLON_PER_LITER = 0.264179;
float milesPerGallon ( float littersUsed , float milesTraveled );
void MilesPerGallon () {

   cout << "This piece of code will tell you how many miles per gallon"
         << "your car gets \nif you measure your gas consumption in litters";

   float milesTraveled = swansonInput::GetFloat (
         "How many miles did you travel (xx.xx):" );
   float littersUsed = swansonInput::GetFloat (
         "How many litters of gas did you use (xx.xx):" );
   float milesPerGallonAchieved = milesPerGallon ( littersUsed ,
         milesTraveled );

   // Only display two places after the decimal point form Savitch, pg. 31
   cout.setf ( ios::fixed );
   cout.setf ( ios::showpoint );
   cout.precision ( 2 );

   cout << "your cars MPG:" << milesPerGallonAchieved << endl;

}

float milesPerGallon ( float littersUsed , float milesTraveled ) {
   float gallonsUsed, milesPerGallon;
   gallonsUsed = littersUsed * GALLON_PER_LITER;
   milesPerGallon = milesTraveled / gallonsUsed;
   return milesPerGallon;
}

//////////////////////////////////////////////
///PROBLEM FIVE/////BETTER RANDOM NUMBERS/////
//////////////////////////////////////////////

void BetterRandom () {
   int min, max;
   int myRandom;

   cout << "Tell me a range and I will give you a random number!";
   min = swansonInput::GetInt ( "What is the lowest number allowed:" );
   max = swansonInput::GetInt ( "What is the highest number allowed:" , min ,
   INT_MAX );

   myRandom = swansonUtil::GetRandomInRange ( min , max );

   cout << endl << "The random number generated is:" << myRandom;
}

//////////////////////////////////////////////
///PROBLEM FOUR/////COMPARE STRING MANUALLY///
//////////////////////////////////////////////
bool compare ( string stringOne , string stringTwo );

void CompareStringsManually () {
   string stringInOne, stringInTwo;
   cout << endl << "this little peice of code is going to check two strings"
         << "Letter-by-Letter";

   stringInOne = swansonInput::GetString ( "Give me a string:" );
   stringInTwo = swansonInput::GetString ( "Ok, now give me another:" );

   if ( compare ( stringInOne , stringInTwo ) ) {
      cout << endl << "these strings are the same";
   } else {
      cout << endl << "these strings are different";
   }
}

bool compare ( string stringOne , string stringTwo ) {
   if ( stringOne.size () != stringTwo.size () ) {
      return false;
   } else {
      for ( int i = 0 ; i < stringOne.size () ; i++ ) {
         if ( stringOne.at ( i ) != stringTwo.at ( i ) ) {
            return false;
         }
      }
   }
   return true;
}
//////////////////////////////////////
///PROBLEM THREE/////RANDOM NUMBERS///
//////////////////////////////////////

void RandomNumbers () {

   cout << "here are some random numbers (0-99): ";
   for ( int i = 0 ; i < 10 ; i++ ) {
      cout << rand () % 100 << " ";
   }
   cout << endl;
}

//////////////////////////////////////
///PROBLEM TWO////ARRANGE NAMES///////
//////////////////////////////////////

string getProperName ();

void FormatName () {
   //formatName local Variables
   list<string> namesSeperated;
   string fullNameUnformated;
   string firstName, middleName, lastName;
   char middleInitial;

   fullNameUnformated = getProperName ();
   swansonString::SeperateWords ( fullNameUnformated , namesSeperated );

   while ( !(namesSeperated.size () == 2 || namesSeperated.size () == 3) ) {
      cout << endl << "It seems you have given me too few or too many names";
      fullNameUnformated = getProperName ();
      swansonString::SeperateWords ( fullNameUnformated , namesSeperated );
   }

   if ( namesSeperated.size () == 2 ) {
      firstName = namesSeperated.front ();
      lastName = namesSeperated.back ();

      cout << endl << lastName << " " << firstName;

   } else if ( namesSeperated.size () == 3 ) {
      firstName = namesSeperated.front ();
      namesSeperated.pop_front ();
      middleName = namesSeperated.front ();
      namesSeperated.pop_front ();
      lastName = namesSeperated.front ();
      namesSeperated.pop_front ();

      middleInitial = middleName.at ( 0 );

      cout << endl << lastName << " " << middleInitial << ". " << firstName;
   }

}

string getProperName () {
   char permitedChars[] = { ' ', '.' };
   string name;

   name = swansonInput::GetString ( "Please tell me your full name: " );

   while ( !swansonString::AllLetters ( name , permitedChars , 2 ) ) {
      cout << "Im sorry, try to keep it to only letters";
      name = swansonInput::GetString ( "Please tell me your full name: " );
   }

   return name;

}

//////////////////////////////////////
///PROBLEM ONE////////////////////////
//////////////////////////////////////

void OneLetterAtATime ( string my_str ) {

   /********************************************************
    ******Function Paramater-ized for ease of encapsulation
    ********************************************************
    //TODO add parameter, use safe string get // 6/29 13:15
    cout << "GIVE ME A STRING";
    string my_str;
    //cin >> my_str; //changed to getLine 6/29 13:00 as per step g.
    //getline(cin,my_str); //allowed for multiple word input 6/29 13:10
    **********************************************************/

   if ( my_str.empty () ) {  //TODO check for null pointer
      cout << endl << "there is something wrong with this string";
      return;
   }

   ////////////////////////////
   ///PRINT ONE CHAR AT A TIME/
   ////////////////////////////
   cout << endl << "here it is forwards: ";
   for ( int i = 0 ; i < my_str.length () ; i++ ) {
      cout << my_str.at ( i ) << ((i != my_str.length () - 1) ? "-" : "");
   }

   cout << endl << "here it is backwards: ";
   for ( int i = my_str.length () - 1 ; i >= 0 ; i-- ) {
      cout << my_str.at ( i ) << ((i != 0) ? "-" : "");
   }

   ////////////////////////////
   ///COUNT LETTERS////////////
   ////////////////////////////

   int numLetters = 0;
   for ( int i = 0 ; i < my_str.length () ; i++ ) {
      if ( swansonString::IsALetter ( my_str.at ( i ) ) ) {
         numLetters++;
      }
   }
   cout << endl << "this string has " << numLetters << " letters" << endl;

   cout << "by a loop this string"
         << ((swansonString::AllLetters ( my_str ) ? " is " : " is not "))
         << "all letters";
   cout << endl << "by a length comparison this string"
         << ((my_str.length () == numLetters ? " is " : " is not "))
         << "all letters";

}

