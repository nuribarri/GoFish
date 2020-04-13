#include <iostream>
#include <fstream>

#include "card.h"
#include <string>

using namespace std;

int main ()
{
   ofstream oFile;
   oFile.open("test.out");
   oFile << "Output test!!!" << endl;
   
   
   Card c;
  
   for (int s = Card::spades; s <= Card::diamonds; s++)
      cout << s << endl;
 
   cout << c << endl;

   for (int i = 0; i < 4; i++) {
      Card c2(4,(Card::Suit) i );
      cout << "in for - " << c2.toString() << endl;
   }


   cout << "Hello World! in c++" << endl;

   int foo = 42;
   cout << "to string test... " << to_string(foo) << endl;

   int foo2 = 11;

   switch (foo) 
   {
      case 12: cout << "s12" << endl;
               break;
      case 42: cout << "s42" << endl;
               break;
      case 92: cout << "s92" << endl;
               break;
   }
               
   cout << "foo  - " << foo << " " << foo2 << endl;

   oFile.close();
}