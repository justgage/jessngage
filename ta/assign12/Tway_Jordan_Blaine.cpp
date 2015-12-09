/*******************************************************
 * Assignment: Assignment 12, Spelling
 * Instructor: Brother Burton
 * Author Name: Jordan Tway
 *
 *******************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

string promptFile()
{
   string name;
   
   cout << "Enter word bank file: ";
   getline(cin, name);

   return name;  
}

void readFile(string fileName, set<string> &words)
{
   
   ifstream fin(fileName.c_str());

   if(fin.fail())
   {
      cout << "ERROR READING FILE\n";
      return;
   }
   else
   {
      string word;
      while(fin >> word)
      {
         words.insert(word);
      }
      cout << "Word bank loaded.\n\n";
   }
}

string promptWord()
{
   string temp;
   cout << "Enter word: ";
   getline(cin, temp);

   return temp;
}

void findMatchingWords(vector<string> &words, long &index, string &word)
{
   string subWord;

   cout << "Matching words:\n";
   
   do
   {
      subWord = words[index].substr(0, word.size());
      cout << words[index] << endl;
      index++;
   }
   while(subWord.compare(word) == 0);
}

void findWords(string &word, vector<string> &words)
{
   bool isFound = false;
   long start, mid, end;
   string subWord;
   mid = 0;
   start = 0;
   end = words.size() - 1;
   
   while(!isFound && start <= end)
   {
      //find middle index
      mid = ((end - start) / 2) + start;

      subWord = words[mid].substr(0, word.size());
     
      if(words[mid] == word)
      {         
         cout << "Correct Spelling\n";
         isFound = true;
         findMatchingWords(words, mid, word);
      }

      //change start or end points
      if(word < words[mid])
      {
         end = mid;
      }
      else if(word > words[mid])
      {
         start = mid;
      }
   }
}

int main()
{
   //declare needed variables
   string userWord, fileName;
   set<string> wordTree;
   vector<string> wordList;

   //get file from user
   fileName = promptFile();

   //read in file to set for auto sorting
   readFile(fileName, wordTree);

   //put words into vector for easy access
   set<string>::iterator it = wordTree.begin();
   while(it != wordTree.end())
   {
      wordList.push_back((*it));
      ++it;
   }

   //get a word from user and continue process until they want to quit
   do
   {
      userWord = promptWord();
      if(userWord != "quit")
      {
         findWords(userWord, wordList);
      }
   }
   while(userWord != "quit");

   cout << "Goodbye\n";
   
   return 0;
}
