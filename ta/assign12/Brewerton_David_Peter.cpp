/***********************************************************************
* Program:
*    Assignment 12, Spellcheck
*    Brother Burton, CS241
* Author:
*    David Brewerton
* Summary: 
*    To sort a bank of words into the program, and then be able to search for words
************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
using namespace std;

/**********************************************************************
 * Function: sort
 * Purpose: to sort the file into the program
 ***********************************************************************/
void sort(char filename[], set <string> &myWords, vector <string> &words)
{
   ifstream fin(filename);
   
   if (fin.fail())
   {
      cout << "Failure";
      return;
   }
   else
   {
      cout << "Word bank loaded." << endl;
   }
   string word;
   while (fin >> word)
   {
      myWords.insert(word);
   }
   fin.close();
   for (set <string>::iterator it = myWords.begin(); it != myWords.end(); it++)
   {
      words.push_back(*it);
   }
}

/**********************************************************************
 * Function: prompt
 * Purpose: to get the filename
 ***********************************************************************/
void prompt(char filename[])
{
   cout << "Enter word bank file: ";
   cin >> filename;
   //cin.ignore();
}


/**********************************************************************
 * Function: Check
 * Purpose: To see if the word is inside the word list
 ***********************************************************************/
void check(set <string> &myWords, vector <string> &words)
{
   string word;
   while (word != "quit")
   {
      cout << "Enter word: ";
      cin >> word;
      bool inSet = false;
      if (word == "quit")
      {
         cout << "Goodbye\n";
         break;
      }
      /*for (set <string>::iterator it = myWords.begin(); it != myWords.end(); it++)
      {
         if (myWords.find(word) == it)
         {
            cout << "Correct spelling" << end;
            inSet = true;
         }
         else
         {
            break;
         }
      }
      if (inSet == false)
      {
         cout << "Incorrect spelling" << endl;
      }*/
      set<string>:: iterator it;
      it = myWords.find(word);
      if(it != myWords.end())
      {
         char letter;
         if (word.size() == 1)
         {
            letter = word.at(0);
         }
         else
         {
            letter = word.at(word.size()-2);
         }
         //letter = word.at(0);
         cout << "Correct spelling" << endl;
         inSet = true;
         cout << "Matching words:\n";
         while (letter == it->at(it->size()-2))
         {
         cout << "  " << *it << endl;
         it++;
         }
      }
      else
      {
         cout << "Incorrect spelling" << endl;
         cout << "Matching words:\n";
         char letter;
         char letter2;
         if (word.size() == 1)
         {
            letter = word.at(0);
         }
         else
         {
            letter2 = word.at(0);
            letter = word.at(word.size()-1);
         }
         vector<string>:: iterator it;
         for (it = words.begin(); it != words.end(); it++)
         {
            if (word.compare(*it) < 0 && word.at(0) == it->at(0))
            {
               break;
            }
         }
         while (word.compare(*it) < 0 && (letter == it->at(it->size()-1) || letter2 == it->at(0)))
         {
         cout << "  " << *it << endl;
         it++;
         }
      }
   cout << endl;
      
   }
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   vector <string> words;
   set <string> myWords;
   char filename[256];
   
   prompt(filename);
   sort(filename, myWords, words);
   cout << endl;
   check(myWords, words);

   return 0;
}


