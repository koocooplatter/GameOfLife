#include "Header.h"
#include <ctime>

// A bunch of text is just placeholder - can write exact text later
// Price values up for discussion

const int BROKEN_ARM = 100, RADIO_CONTEST = 100, NEW_SHIRT = 20, PANTS_POCKET = 15,
          CHOICE1 = 1, CHOICE2 = 2, CHOICE3 = 3, CHOICE4 = 4, CHOICE5 = 5,
          MIN_SAVINGS_INT = 5, MED_SAVINGS_INT = 10, MAX_SAVINGS_INT = 15,
          CONCERTS = 45;
const double MIN_SAVINGS = .05, MED_SAVINGS = .1, MAX_SAVINGS = .15,
             MOVIES = 26.25, NETFLIX = 7.99, AMAZON = 10.99, AMAFLIX = 18.98;

void randomEvent(double &userTotal)
{
   int randEvent;
   srand(unsigned(time(NULL)));

   cout << "Time for a random event!" << endl;

   /* If we decide to add more random events, we'd have to come up with a new method of selecting random
      events. It'd be too much to hardcode for every single value. */

   randEvent = rand() % 4; // Generates 0 - 3

   if (randEvent == 0) // If health insurance is a thing, there could be two possibilities here
   {
      cout << "Oops, you broke your arm. That's going to cost you $" << BROKEN_ARM << "." << endl;
      userTotal -= BROKEN_ARM;
   }
   else if (randEvent == 1)
   {
      cout << "You won a radio contest! $" << RADIO_CONTEST << " in the bank." << endl;
      userTotal += RADIO_CONTEST;
   }
   else if (randEvent == 2)
   {
      cout << "Can't wear a shirt with giant chocolate stains on it. $" << NEW_SHIRT << " for a new shirt." << endl;
      userTotal -= NEW_SHIRT;
   }
   else
   {
      cout << "Hey, there's $" << PANTS_POCKET << " in your pocket!" << endl;
      userTotal += PANTS_POCKET;
   }
}

void savings(double &userTotal)
{
   int savingsAmt;
   bool check = false;

   cout << "Potential amount of monthly income to set aside:" << endl
        << "1.) " << MIN_SAVINGS_INT << "%" << endl
        << "2.) " << MED_SAVINGS_INT << "%" << endl
        << "3.) " << MAX_SAVINGS_INT << "%" << endl << endl
        << "How much would you like to set aside? ";
   cin >> savingsAmt;

   while (!check)
   {
      if (savingsAmt == MIN_SAVINGS_INT || savingsAmt == CHOICE1)
      {
         cout << MIN_SAVINGS_INT << "% of your monthly income will be set aside for savings!" << endl;
         userTotal -= (userTotal * MIN_SAVINGS);
         check = true;
      }
      else if (savingsAmt == MED_SAVINGS_INT || savingsAmt == CHOICE2)
      {
         cout << MED_SAVINGS_INT << "% of your monthly income will be set aside for savings!" << endl;
         userTotal -= (userTotal * MED_SAVINGS);
         check = true;
      }
      else if (savingsAmt == MAX_SAVINGS_INT || savingsAmt == CHOICE3)
      {
         cout << MAX_SAVINGS_INT << "% of your monthly income will be set aside for savings!" << endl;
         userTotal -= (userTotal * MAX_SAVINGS);
         check = true;
      }
      else
      {
         cout << "Sorry, that's not a valid choice. Please enter one of the valid amounts: ";
         cin >> savingsAmt;
      }
   }
}

void entertainment(double &userTotal)
{
   int entertainmentAmt;
   bool check = false;

   cout << "Potential amount to spend on entertainment monthly: " << endl
        << "1.) Three trips to the movie theater per month: $" << MOVIES << endl
        << "2.) Two concerts per month: $" << CONCERTS << endl
        << "3.) Netflix: $" << NETFLIX << endl
        << "4.) Amazon: $" << AMAZON << endl
        << "5.) Netflix + Amazon: $" << AMAFLIX << endl << endl
        << "How much would you like to spend on entertainment per month? ";
   cin >> entertainmentAmt;

   while (!check)
   {
      if (entertainmentAmt == MOVIES || entertainmentAmt == CHOICE1)
      {
         cout << "$" << MOVIES << " will be set aside for entertainment each month!" << endl;
         userTotal -= MOVIES;
         check = true;
      }
      else if (entertainmentAmt == CONCERTS || entertainmentAmt == CHOICE2)
      {
         cout << "$" << CONCERTS << " will be set aside for entertainment each month!" << endl;
         userTotal -= CONCERTS;
         check = true;
      }
      else if (entertainmentAmt == NETFLIX || entertainmentAmt == CHOICE3)
      {
         cout << "$" << NETFLIX << " will be set aside for entertainment each month!" << endl;
         userTotal -= NETFLIX;
         check = true;
      }
      else if (entertainmentAmt == AMAZON || entertainmentAmt == CHOICE4)
      {
         cout << "$" << AMAZON << " will be set aside for entertainment each month!" << endl;
         userTotal -= AMAZON;
         check = true;
      }
      else if (entertainmentAmt == AMAFLIX || entertainmentAmt == CHOICE5)
      {
         cout << "$" << AMAFLIX << " will be set aside for entertainment each month!" << endl;
         userTotal -= AMAFLIX;
         check = true;
      }
      else
      {
         cout << "Sorry, that's not one of the valid choices. Please make a valid choice: ";
         cin >> entertainmentAmt;
      }
   }
}