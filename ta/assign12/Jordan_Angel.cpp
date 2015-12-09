/**********************************************************************
* Program:
*    
*    Brother Burton, CS241
* Author:
*    Jordan
* Summary:
*    This program
*
**********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/**********************************************************************
* Main Description: 
* Inputs:           
* Outputs:          
* Return:           
**********************************************************************/
void loop(vector<string>words)
{
   while(true)
   {
      string word;
      cout << "Enter word: ";
      cin >> word;
      if (word == "quit")
      {
         cout << "Goodbye\n";
         return;
      }

      if(find(words.begin(),words.end(), word) != words.end())
      {
         cout << "Correct spelling\n";
      }
      else
      {
         cout << "Incorrect spelling\n";
      }
      vector <string> matches;
      for(int i = 0; i < words.size(); i++)
      {
         if(words[i].find(word) == 0)
         {
            matches.push_back(words[i]);
         }
         
      }
      cout << "Matching words:\n";
      for(int i = 0; i < matches.size(); i++)
      {
         cout << "  " << matches[i] << endl;
      }
      cout << endl;
   }
}





vector <string> readfile(string fileName)
{
   ifstream fin(fileName.c_str()); // must but .c_str() to convert string to array
   if(fin.fail())
   {
      return vector<string>();
   }
   vector<string> words;
   string wordInput;
   while(fin>>wordInput)
   {
      words.push_back(wordInput);
      
      
      //    if(words == wordInput)
      // cout << "correct spelling" << endl;
   }


   
   fin.close();
   return words;
   
}
int main()
{
   
   string fileName;
   cout << "Enter word bank file: ";
   cin >> fileName;
   
   
   vector <string> words = readfile(fileName);
   if(words.size() == 0)
      return 1;
   cout << "Word bank loaded.\n\n";
   sort(words.begin(), words.end());

   loop(words);      
   return 0;
}
