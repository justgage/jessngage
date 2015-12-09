/***********************************************************************
* Program:
*    Assignment 12, Spelling 
*    Brother Burton, CS241
* Author:
*    Eric Jessop
* Summary: 
*    Find words from a file location prompted from the user and display
*    whether the word is spelled correctly. Then display words that
*    have the matching partial spelling. If the user enters the word "quit",
*    then the program ends.
*
*    Estimated:  5.0 hrs   
*    Actual:     6.0 hrs
*      I had to fix my segmentation fault at the end of my partial search.
*      I had it iterating one past the end of the list. I also had trouble
*      making the end index point return when the word was some random letters.
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <fstream>

using namespace std;

/**************************************************************
 * Function: promptFile
 * Description: Ask for word bank file name
 **************************************************************/
void promptFile(string &file)
{
   cout << "Enter word bank file: ";
   cin >> file;
}

/**************************************************************
 * Function: promptWord
 * Description: Ask for a word 
 **************************************************************/
void promptWord(string &word)
{
   cout << "\nEnter word: ";
   cin >> word;
}

/**************************************************************
 * Function: readFile
 * Description: Reads in a list from a file into a set.
 **************************************************************/
void readFile(string file, set<string> &wordSet, vector<string> &wordVect)
{
   ifstream fin(file.c_str());

   if (fin.fail())
   {
      cout << "Error reading file: " << file << endl;
      return;
   }

   // Add words from file into a set to organize it into a binary tree
   string word;
   while (fin >> word)
   {
      wordSet.insert(word);
   }

   // Put ordered words into a vector
   for(set<string>::iterator it = wordSet.begin();
       it != wordSet.end();
       it++)
      wordVect.push_back(*it);

   cout << "Word bank loaded.\n";

   fin.close();
}

/**************************************************************
 * Function: binarySearch
 * Description: Use a binary search for a word
 **************************************************************/
int binarySearch(vector<string> &wordVect, string word, int start, int end)
{
   if(start > end)
   {
      cerr << "Word not found in list\n";
      // negative value is a flag showing that the word not in the list
      return -start;    
   }
   else
   {
      int midIndex = (end - start) / 2 + start;
      cerr << "start: " << start << ", mid: " << midIndex << ", end: " << end << endl;
      string midWord = wordVect[midIndex];
      cerr << "Comparing \"" << midWord << "\" and \"" << word << "\""<< endl;

      if(midWord == word)
      {
         // it matched
         return midIndex;
      }
      else if(word < midWord)
      {
         // Look on the left side
         int newStart = start;
         int newEnd = midIndex - 1;
         cerr << "Looking to the left side\n";
         return binarySearch(wordVect, word, newStart, newEnd);
      }
      else // word > midWord
      {
         // Look on the right side
         int newStart = midIndex + 1;
         int newEnd = end;
         cerr << "Looking to the right side\n";
         return binarySearch(wordVect, word, newStart, newEnd);
      }
   }
}
/**************************************************************
 * Function: getSubWords
 * Description: start from the closest word and look for matching part
 **************************************************************/
int getSubWords(vector<string> &wordVect, string word, int start)
{
   // start from the closest index word match, where the word should be.
   for(int i = abs(start); i < wordVect.size(); i++)
   {
      cerr << "start: " << abs(start) << ", end: "
           << wordVect.size() << endl;
      if(wordVect[i].size() < word.size())  // if next word is smaller
         return i;                          // return the word index
      else
      {
         for(int j = 0; j < word.size(); j++)
            if(wordVect[i][j] != word[j])    // if letter doesn't match
               return i;                     // return the word index
      }
   }
   
   return wordVect.size();        // its the last word
}

/**************************************************************
 * Function: display
 * Description: Displays a list of integers, one per line.
 **************************************************************/
void displayMatches(vector<string> &wordVect, int start, int end)
{
   cerr << "start: " << abs(start) << ", end: " << end << endl;

   // Was it in the word list? If so, is was correctly spelled.
   if(start >= 0)
      cout << "Correct spelling\n";
   else
      cout << "Incorrect spelling\n";

   cout << "Matching words:\n";

   // show the matching partial words or nothing if no matches
   if(start < end)
      for(int i = abs(start); i < end; i++)
         cout << "  " << wordVect[i] << endl;
}

/**************************************************************
 * Function: main
 * Description: The driver function for the program.
 **************************************************************/
int main()
{
   set<string> wordSet;
   vector<string> wordVect;
   
   // get the word bank file name
   string file;
   promptFile(file);

   // Read words from file into lists
   readFile(file, wordSet, wordVect);
   
   string word;
   do
   {
      // ask for a word to find
      promptWord(word);
      
      if (word != "quit")
      {
         // search for matching words using binary search = O(log(n))
         int indexStart = binarySearch(wordVect, word, 0, wordVect.size() - 1);

         // search for patial word matches
         int indexEnd = getSubWords(wordVect, word, indexStart);
         cerr << "found the end index: " << indexEnd << endl;
         
         // display matching words and partial word matches
         displayMatches(wordVect, indexStart, indexEnd);
      }
   }
   while(word != "quit");

   cout << "Goodbye\n";

   return 0;
}


