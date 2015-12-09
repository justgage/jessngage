/***********************************************************************
* Program:
*    Assignment 12, Spelling
*    Brother Burton, CS241
* Author:
*    Allen Foster
* Summary:
*    Write a program to check the spelling of words and also suggest other
*    auto-completions of a word.
*
*    Estimated:  7.5 hrs   
*    Actual:     2.0 hrs
*      I dont quite understand how to get the sort function to work with
*      the data I retrieve from the file. I struggled to get the info
*      from the file into a data structure. I tried to get it into a set,
*      then to organize the set into a vector using a binary search tree.
*      However, getting the sort to even work was a struggle for me. If
*      I comment out the sort function, the basic functions seem to work,
*      but the sorting/implementing of data from another part in the
*      program is where I fell.
************************************************************************/
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
using namespace std;

/**************************************************************
 * Function: getFile
 * Description: Prompts user for the location of the txt file
 **************************************************************/
int getFile(string file)
{
   cout << "Enter word bank file: ";
   cin >> file;
   ifstream fin(file.c_str());

   if (fin.fail())
   {
      cout << "Error reading file: " << file << endl;
      return -1;
   }
   else
   {
      cout << "Word bank loaded." << endl;
   }
}

/**************************************************************
 * Function: readFile
 * Description: Sorts the information from the file into a set.
 *              It then moves the set info (using binary search
 *              method) into a vector to be more easily ready to
 *              look through.
 **************************************************************/
void readFile(string file, vector<string> &words, string word, string start, string end)
{
   set<string> bank;
   ifstream fin(file.c_str());
   string word;
   
   while (fin >> word)
   {
   bank.insert(word);
   }
   
   if (start > end)
   {
      cout << "Incorrect spelling";
      return -1;
   }

   string midIndex = (end - start) / 2 + start;
   string midValue = words[midIndex];

   if (midValue == word)
   {
      return midIndex;
   }
   else if (word < midValue)
   {
      string newStart = start;
      string newEnd = midIndex - 1;

      return binarySearch(words, word, newStart, newEnd);
   }
   else
   {
      string newStart = midIndex + 1;
      string newEnd = end;
      
      return binarySearch(words, word, newStart, newEnd);
   }
}

/**************************************************************
 * Function: enterWord
 * Description: Prompts user for a word to compare/search in the
 *              file
 **************************************************************/
void enterWord(string file)
{
   string word;
   cin.ignore();
   
   do
   {
      cout << "Enter word: ";
      getline (cin,word);
   }
   while(word != "quit");
   if(word == "quit")
   {
      cout << "Goodbye" << endl;
   }
}

/**************************************************************
 * Function: displayResults
 * Description: After reading through and sorting the file, this
 *              function looks at the word that the user entered,
 *              and looks through the vector of file info to give
 *              us possibilities.
 **************************************************************/
void displayResults(file, word)
{
   do
   {
      cout << word << endl;
   }
   while (word = word.file && word < end);
}
*/

/**************************************************************
 * Function: main
 * Description: The driver function for the program.
 **************************************************************/
int main()
{   
   string file;
   vector<string> words;
   string word;
   string start;
   string end;

   getFile(file);
   readFile(file, words, word, start, end);
   enterWord(file);
   displayResults(file, word);

   return 0;
}
