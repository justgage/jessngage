/***********************************************************************
 * Program:
 *    Assignment 12, Spelling
 *    Brother Burton, CS241
 * Author:
 *    Brandon Bowers
 * Summary:
 *    supposed to read in a word bank.  Than take a users word and find
 *    that word in the world bank.  From that point the program will 
 *    output all the words similar to it.
 *
 *
 *    Estimated:  4.0 hrs
 *    Actual:     7.0 hrs
 *      I could not figure out a good way to find the word in the array.
 *      How it is now will tell if it has been found or not but I need
 *      to know where so I can display all the other words close to it
 ************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/**********************
 * reads in the file until there is no longer input
 *********************/
int readFile(string file, string word, vector<string> &words)
{
   ifstream fin(file.c_str());

   if (fin.fail())
   {
      cout << "Error reading file: " << file << endl;
      return -1;
   }
   int count;
   set <string> bank;

   while (fin >> word)
   {
      bank.insert(word);
      count ++;
   } 
   for (set<string>::iterator it = bank.begin(); it != bank.end(); it++)
      {
         words.push_back(*it);
      }
 
//checking to see if it sorted correctly
/*   for(int i=0; i<words.size(); ++i)
      cout << words[i] << endl;
*/   
   fin.close();

   return count;

}

/**********************
 * match finds a match from the vector and user input
 *********************/
int match(string userWord, vector<string> words)
{

   int match = 0;
  


     

//find the word in the vector
   if( binary_search(words.begin(), words.end(), userWord))
   {
      cout << "Correct spelling" << endl;
   }
   else
   {
      cout << "Incorrect spelling" << endl;
   }

//from matched word continue through loop till substr fails

   //string substr;
   // size_t pos = substr.find(userWord);
   //cout << pos;    




   
}

/***********************
 * main hold values and determines which functions will need
 * to be called
 **********************/
int main()
{
   string file;
   cout << "Enter file ";
   cin >> file;

   string word;
   string userWord;
   vector<string> words;
   
   int size = readFile(file, word, words);

   if (size > 0)
   {
      cout << "Word bank loaded" << endl;
      cout << endl;
      //prompt for a word
      //can move this if needed
      cout << "Enter word: ";
      cin >> userWord;

      match(userWord, words);
     

//call display?
   }

   return 0;
}
