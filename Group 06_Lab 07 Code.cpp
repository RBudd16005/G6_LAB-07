/**********************************************
 * Lab 07: Group 06
 * Authors: Charles Rich, Kwaku Appau-Nkansah,
 *  Jacob Muhlestein, Doug Barlow, Chad Smith,
 *  and Ryan Budd
 * Instructor: Brother Wilson
 * Description:
 *  COMPLETE LATER
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

void one(long number);
void two(long number);
void pass() { cout << "You pass :)\n"; }
void fail() { cout << "You've failed :(\n"; }
const char * passMessage = ":)";
const char * failMessage = ":(";

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{
   char text[8] = "*MAIN**";
   long number = 123456;
   void (*pointerFunction)() = fail;
   const char * message = failMessage;

   // display the initial values of the local variables
   cout << "main() : " << (void *)main << endl;
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   // call the other functions
   one(number + 111111);     // 234567

   // display the new values of the local variables
   cout << "main() - after\n";
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   return 0;
}

/************************************************
 * CONVERT TO STRING
 * Convert the data from p into a human-readable string
 * by removing all the unprintable characters and replacing
 * them with a dot
 ***********************************************/
string displayCharArray(const char * p)
{
   string output;
   for (int i = 0; i < 8; i++)
       output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
   return output;
}

/**********************************************
 * ONE : The next item on the call stack
 **********************************************/
void one(long number)               // 234567
{
   char text[8] = "**ONE**";

   cout << "one() : " << (void *)one << endl;
   cout << "\tmessage: " << (void *)failMessage << endl;
   cout << "\tfail():  " << (void *)fail        << endl;

   two(number + 111111);    // 345678
}

/**********************************************
 * TWO : The bottom of the call stack
 **********************************************/
void two(long number)              // 345678
{
   // start your display of the stack from this point
   long bow = number + 111111;     // 456789
   char text[8] = "**TWO**";
   long * pLong = NULL;
   char * pChar = NULL;

   // header for our table. Use these setw() offsets in your table
   cout << '[' << setw(2) << 'i' << ']'
        << setw(15) << "address"
        << setw(20) << "hexadecimal"
        << setw(20) << "decimal"
        << setw(18) << "characters"
        << endl;
   cout << "----+"
        << "---------------+"
        << "-------------------+"
        << "-------------------+"
        << "-----------------+\n";

   //Display the Stack
   long *a = &bow;
   char *c;
   for (long i = 99; i >= -4; i--)
   {
        c = reinterpret_cast<char*>(a + i);
        cout << '[' << setw(2) << i << ']'
             << setw(15) << a + i
             << setw(20) << (void*)a[i]
             << setw(20) << (int)a[i]
             << "  ";
        for(int i = 0; i < 8; i++)
        {
            if (c[i] != NULL)
            {
                cout << setw(2) << c[i];
            }
            else
            {
                cout << setw(2) << '.';
            }
        }
             cout << endl;
   }

   // change text in main() to "*main**"
   char *newMain;
   for(int i = 100; i > 0; i--)
   {
       if((int)a[i] == 1229016362)
       {
           newMain = reinterpret_cast<char*>(a + i);
           strcpy(newMain,"*main**");
           break;
       }
   }

   // change number in main() to 654321
   long *newNumber;
   for(int i = 100; i > 0 ; i--)
   {
       if((int)a[i] == 123456)
       {
           newNumber = a + i;
           break;
       }
   }
   *newNumber = 654321;

   // change pointerFunction in main() to point to pass
   long **newFunction;
   for(int i = 100; i > 0 ; i--)
   {
       if((int)a[i] == 4199794)
       {
           long *temp = a + i;
           newFunction = &temp;
           cout << *newFunction << endl;
           *newFunction = (long*)pass;
           cout << (char*)*newFunction << endl;
           break;
       }
   }

   // change message in main() to point to passMessage
   long *newMessage;
   long *b = &bow;
   for(int i = 100; i > 0 ; i--)
   {
       if((int)a[i] == 4214821)
       {

           newMessage = a+i;
           cout << newMessage << endl;
           break;
       }
   }

   ////////////////////////////////////////////////
}
