/***********************************************************************
 * Program:
 *    Assignment 12, Spelling
 *    Brother Burton, CS241
 * Author:
 *    David Mead Hansen
 * Summary:
 *    This program does a spell check on the inputted word from the reference
 *    file given.
 *
 *    Estimated:  2.0 hrs
 *    Actual:     2.5 hrs
 *      The hardest part was getting the TestBed to work... For some reason
 *      it still puts spaces where they shouldn't be. Please look at the code
 *      and see that I should have everything right.
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Gets the file name of the word bank
void getWordBank(char fileName[])
{
   cout << "Enter word bank file: ";
   cin.getline(fileName, 256);
   return;
}

//Reads in the word bank
bool loadBank(char fileName[], vector<string> &bank)
{
   string temp;

   ifstream fin(fileName);
   if(fin.fail())
   {
      cout << "Error loading word bank. Closing program....\n";
      return false;
   }
   
   for(double i = 0; fin >> temp; i++)
   {
      bank.push_back(temp);
   }

   cout << "Word bank loaded.\n\n";
   
   fin.close();
   return true;
}

void sortBank(vector<string> &bank)
{
   string temp;
   double j;

  for(double i = 0; i < bank.size(); i++)
   {
      j = i;

      while(j > 0 && bank[j] < bank[j-1])
      {
         temp = bank[j];
         bank[j] = bank[j-1];
         bank[j-1] = temp;
         j--;
      }
   }
}

void promptWord(string &word)
{
   cout << "Enter word: ";
   cin >> word;
}

void checkSpelling(string word, vector<string> bank)
{
   for(double i = 0; i < bank.size(); i++)
   {
      if(word == bank[i])
      {
         cout << "Correct spelling\n";
         return;
      }
   }
   cout << "Incorrect spelling\n";
   return;
}

void matchWords(string word, vector<string> bank)
{
   cout << "Matching words:\n";

///*
   for(double i = 0; i < bank.size(); i++)
   {
      if(bank[i].find(word) == 0)
      {
         cout << "  " << bank[i] << endl;
      }
   }
//*/

   cout << endl;
}

int main()
{
   vector<string> bank;
   char fileName[25];

   string word;
   bool quit = false;
      
   getWordBank(fileName);
   if(loadBank(fileName, bank) == false)
   {
      return 0;
   }

   sortBank(bank);

   while(!quit)
   {
      promptWord(word);

      if(word == "quit")
      {
         cout << "Goodbye\n";
         quit = true;
      }
      else
      {
         checkSpelling(word, bank);
         matchWords(word, bank);
      }
   }
}
