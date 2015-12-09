/***********************************************************************
 * Program:
 *    Assignment 12, Spelling
 *    Brother Burton, CS241
 * Author:
 *    Jared Thurman
 * Summary:
 *   This program was an attempt to help a user to get suggjestions to
 *   to spelling errors or exrat words.
 * ***********************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

/******************************************************
* Void loadWords
* This function read in the file of words
******************************************************/
void loadWords(char filename[], vector<string> &words)
{
   ifstream input(filename);
   string data;
   
   if (input.fail())
   {
      bool x = true;
      
      while (x)
      {
         cout << "Error reading file " << "\"" << filename << "\"" << endl;
         cout << "Enter word bank file: ";
         cin >> filename;
         
         ifstream input(filename);
         string data;
         
         if (!input.fail())
         {
            
            while (!input.eof())
            {
               input >> data;
               words.push_back(data);
            }
            x = false;
         }
      }
   }
   else
   {
      while (!input.eof())
      {
         input >> data;
         words.push_back(data);
      }
   }
   
   // cout << "Word bank loaded." << endl;
   // cout << endl;
   
   input.close();
}

/******************************************************
 * set<string> sortWords
 *        This function sorts and sets the word file. 
 *********       *********************************************/

set<string> sortWords(vector<string> &words, set<string> wordTree)
{
   sort(words.begin(), words.end());
   
   for (int i = 0; i < words.size(); i++)
   {
      wordTree.insert(words[i]);
   }
   
   cout << "Word bank loaded." << endl;
   cout << endl;
   
   
   return wordTree;
}

/******************************************************
* Void checkWord 
* This function attempts to tell the user if they have
* incorrect, or correct spelling and then tries to 
* to find other matches. 
******************************************************/

void checkWord(vector<string> words, set<string> wordTree, string word)
{
   bool x = true;
   bool y = true;
   
   while (x)
   {
      
      cout << "Enter word: ";
      cin >> word;
      
      set<string>::iterator it;
      
      it = wordTree.find(word);
      
      if (it == wordTree.end())
      {
         cout << "Incorrect spelling" << endl;
      }
      else
      {
         cout << "Correct spelling" << endl;
      }
      
      cout << "Matching words: " << endl;
      
      // This is my attempt to implament the macthing words.
      // Im sure that I over looked somthing and made it way
      // more compicated then it needed to be. 
      
      /*while (y)
        {
           for (int i = 0; i < word.size(); i++)
           {
             for (int j = 0; i < (*it).size(); j++)
                {
                   if (word[i] == (*it)[j])
                   {
                   cout << *it << endl;
        
                   }
                   else
                {
             y = false;
           }
         }
       }
        
       *it++;
     }*/
            
      cout << endl;
      if (word == "quit")
      {
         cout << "Goodbye" << endl;
         x = false;
      }
   }
}

/******************************************************
* int main
* This is the main driver
******************************************************/

int main()
{
   vector<string> words;
   set<string> wordTree;
   
   char filename[256];
   string word;
   
   cout << "Enter word bank file: ";
   cin >> filename;
   
   
   loadWords(filename, words);
   wordTree = sortWords(words, wordTree);
   checkWord(words, wordTree, word);
   
}

