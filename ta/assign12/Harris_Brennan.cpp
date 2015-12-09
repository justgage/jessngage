/***********************************************************************
* Program:
*    Assignment 12, Spelling
*    Brother Burton, CS241
* Author:
*    Brennan Harris
* Summary:
*    program that takes uses a word bank to run spellchecking on
*    a user-supplied word. the user-supplied word is also matched with
*    entries in the word bank for which the supplied word is a
*    substring
*
*    p.s. - testBed wasn't working for me, so i just submitted it
*    after running styleChecker. the behavior worked as described in
*    the outline
************************************************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

/***********************************************************************
 * prompts for a word bank location
 ***********************************************************************/
string promptFile()
{
   string fileName;
   cout << "Enter word bank file: ";
   cin >> fileName;

   return fileName;
}

/***********************************************************************
 * prompts for a word to be checked against the bank
 ***********************************************************************/
string askWord()
{
   string word;
   cout << "Enter word: ";
   cin >> word;

   return word;
}

/***********************************************************************
 * performs a binary search on a sorted list and returns an index value
 ***********************************************************************/
int binarySearch(vector<string> searchVec, string askedWord, int min, int max)
{
   int mid;
   while (max >= min)
   {
      mid = (min + max) / 2;

      if (searchVec[mid] < askedWord)
         min = mid + 1;
      else if (searchVec[mid] > askedWord)
         max = mid - 1;

      else
         return mid;
   }
   
   if (min < max)
      return min;
   else
      return max;
}

/***********************************************************************
 * find matching words starting at the index location returned by the
 * binary search above
 ***********************************************************************/
void matchingWords(int index, string askedWord, vector<string> searchVec)
{
   cout << "Matching words:" << endl;
   int sizeAskedWord = askedWord.size();
   while (searchVec[index].substr(0, sizeAskedWord) == askedWord)
   {
      cout << searchVec[index] << endl;
      index++;
   }
   index++;
   while (searchVec[index].substr(0, sizeAskedWord) == askedWord)
   {
      cout << searchVec[index] << endl;
      index++;
   }
   cout << endl;
}

/***********************************************************************
 * prompts for word bank, sorts it, then prompts for a word, and
 * compares if it's on the list, then returns matching words
 ***********************************************************************/
int main()
{
   set<string> wordList;
   string fileName = promptFile();
   ifstream fin(fileName.c_str());
   if (fin.fail())
   {
      cout << "bad file path!" << endl;
   }
   else
   {
      string word;

      while (fin >> word)
      {
         wordList.insert(word);
      }

      vector<string> searchVec;

      for (set<string> :: iterator it = wordList.begin();
          it != wordList.end();
          ++it)
      {
         searchVec.push_back(*it);
      }

      cout << "Word bank loaded.\n" << endl;

      string askedWord = "asdf";
      int index;
   
      while (askedWord != "quit")
      {
         askedWord = askWord();
         if (askedWord != "quit")
         {
            index = binarySearch(searchVec, askedWord, 0, searchVec.size());

            if (askedWord == searchVec[index])
            {
               cout << "Correct spelling" << endl;
            }
            else
            {
               cout << "Incorrect spelling" << endl;
            }
            matchingWords(index, askedWord, searchVec);
         }
      }

      cout << "Goodbye\n";
   }
   
   return 1;
}
