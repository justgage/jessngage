/***********************************************************************
* Program:
*    Assignment 12, Spellcheck
*    Brother Burton, CS241
* Author:
*    Craig McEwen
* Summary: 
*    This will load a file of words and check the word bank to see if 
*    it is still in there
*
*    Estimated:  2.0 hrs   
*    Actual:     3.0 hrs
*      it was easy just had a typo
************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>
using namespace std;

void fillWords(vector<string> &words)
{
   set<string> unorganizedWords;
   string fileName;
   cout << "Enter word bank file: ";
   cin >> fileName;
   ifstream fin(fileName.c_str());

   if (fin.fail())
   {
      cout << "Error in reading file\n";
      return;
   }
   //Read in the file
   while (!fin.eof())
   {
      string temp;
      fin >> temp;
      unorganizedWords.insert(temp);
   }
   //Organize into vector
   for (set<string>::iterator it = unorganizedWords.begin();
        it != unorganizedWords.end(); it++)
   {
      words.push_back(*it);
   }
   fin.close();
   cout << "Word bank loaded.\n\n";
   
}

void binarySearch(vector<string> & words, string looking, int start, int end)
{
   int midIndex = (end - start)/2 + start;

   string midValue = words[midIndex];
   
   if (start > end)
   {
      bool find;
      string term = looking;
      int i = midIndex;
      int check = 0;
      do
      {
         string substr = words[i].substr(0, looking.size());
         find = false;
         if (substr == term)
         {
            if (check == 0)
            {
               cout << "Incorrect spelling\n";
               cout << "Matching words:\n";
            }
            find = true;
            cout << "  " << words[i] << endl;
            i++;
            check++;
         }
         if (check == 0)
         {
            cout << "Incorrect spelling\n";
            cout << "Matching words:\n";
         }
      }
      while (find);
      cout << endl;
      return;
   }
   if (midValue == looking)
   {
      bool find;
      cout << "Correct spelling\n" << "Matching words:\n";
      string term = words[midIndex];
      int i = midIndex;
      do
      {
         string substr = words[i].substr(0, term.size());
         find = false;
         if (substr == term)
         {
            find = true;
            cout << "  " << words[i] << endl;
            i++;
         }
      }
      while (find);
      cout << endl;
      return;
   }
   else if (looking < midValue)
   {
      //left side
      int newStart = start;
      int newEnd = midIndex - 1;

      binarySearch(words, looking, newStart, newEnd);
   }
   else 
   {
      //Look on right side
      int newStart = midIndex + 1;
      int newEnd = end;

      binarySearch(words, looking, newStart, newEnd);
      
   }
}

void search(vector<string> &words, string looking)
{
   binarySearch(words, looking, 0, words.size()-1);
}

void askWord(vector<string> &words)
{
   string looking;
   do
   {
      cout << "Enter word: ";
      cin >> looking;
      if (looking != "quit")
      {
         search(words, looking);
      }
      else
      {
         cout << "Goodbye\n";
      }
   }
   while (looking != "quit");
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   vector<string> words;
   fillWords(words);
   askWord(words);
   return 0;
}
