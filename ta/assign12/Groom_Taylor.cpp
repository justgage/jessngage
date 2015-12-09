/***********************************************************************
* Program:
*    Assignment 12, Spelling
*    Brother Burton, CS241
* Author:
*    Taylor Groom
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/

void fillArray(vector<string> &words, string fileName)
{
   set<string> wordSet;

   ifstream fin(fileName.c_str());

   if(fin.fail())
   {
      cout << "error loading file";
      return;
   }

   
   while(!fin.eof())
   {
      string temp;
      fin >> temp;
      wordSet.insert(temp);
   }      

   for (set<string>::iterator it = wordSet.begin();
        it != wordSet.end(); it++)
   {
      words.push_back(*it);
//      cout << *it << endl;
   }
   fin.close();
   cout << "Word bank loaded." << endl << endl;
}

void binarySearch(vector<string> &words, string lookUp, int start, int end)
{

   if(start > end)
   {
      cout << "Incorrect spelling" << endl;
      //cout << "Matching words:" << endl;
      return;
   }
   
   int midIndex = (end - start) / 2 + start;

   // cout << "start: " << start << ", mid: " << midIndex << ", end: " << end << endl;

   string midValue = words[midIndex];

//   cout << "Comparing mid value and num: ";
   
   if(midValue == lookUp)
   {
//Word is found in the list
      cout << "Correct spelling" << endl;
      // cout << "Matching words:" << endl;
      return;
   }
   else if(lookUp < midValue)
   {
      //Look to the smaller numbers
      int newStart = start;
      int newEnd = midIndex - 1;
      binarySearch(words, lookUp, newStart, newEnd);
   }
   else // num > midValue
   {
      //Look to the right side
      int newStart = midIndex + 1;
      int newEnd = end;
      binarySearch(words, lookUp, newStart, newEnd);  
   }
}

void likeWords(vector<string> &words, string lookUp)
{

   bool found = true;
//   cout << "In like words" << endl;
   int pos = 0;
   while (lookUp != words[pos].substr(0,lookUp.size()))
   {
      if(pos < words.size() - 1)
      {
         pos++;
         //cout << "less" << endl;
      }
      else
      {
//         cout << "more" << endl;
         found = false;
         cout << endl;
         return;
      }
   }
   
   while(found != false)
     {
        string substring = words[pos].substr(0, lookUp.size());
        if(substring == lookUp) 
        {
           found == true;
           cout << "  " << words[pos] << endl;
           pos++;
        }
        else
        {
           //cout << "Found nothing" << endl;
           cout << endl;
           found = false;
           return;
        }
     }
  
}

void search(vector<string> &words, string lookUp)
{

   binarySearch(words, lookUp, 0, words.size() - 1);
   return;
}

void promptWord(vector<string> words)
{
   string lookUp;
   int check;
   while(lookUp != "quit")
   {
      cout << "Enter word: ";
      cin >> lookUp;
      if (lookUp != "quit")
      {
         search(words, lookUp);  
         cout << "Matching words:" << endl;
         likeWords(words, lookUp);
      }
   }
}

int main()
{
   vector <string> words;
   string fileName;
   int check;
   
   cout << "Enter word bank file: ";
   cin >> fileName;
   fillArray(words, fileName);
   promptWord(words);
   cout << "Goodbye" << endl;
   
   return 0;
}
