/*************************************************************
 * 1. Name:
 *      Brighton Gold, Austin Jesperson
 * 2. Assignment Name:
 *      Practice 04: Contaiers
 * 3. Assignment Description:
 *      Work with a list and a vector
 * 4. What was the hardest part? Be as specific as possible.
 *      Figuring out the right this to for maximum efficiency.
 *       I don't think I found it though. I also had to use sites like
 *       https://www.codingninjas.com/studio/library/different-ways-to-reverse-a-vector
 *       https://stackoverflow.com/questions/571394/how-to-find-out-if-an-item-is-present-in-a-stdvector#:~:text=You%20can%20use%20the%20find,if%20they%20match%20or%20not.
 *       https://stackoverflow.com/questions/5218713/one-liner-to-convert-from-listt-to-vectort#:~:text=You%20can%20only%20create%20a,the%20list%20to%20the%20vector.
 * 
 *       for help understanding lists and vectors and how to copy them and reverse them. 
 * 
 * 5. How long did it take for you to complete the assignment?
 *      One hour for everything
 **************************************************************/

#include "testContainers.h"
#include <string>
#include <list>
#include <algorithm>

using namespace std;

list<string> arrayToList(string a[], int num)
{
   list<string> resultList;
   for (int i = 0; i < num; i++)
   {
      resultList.push_back(a[i]); //iterate through array and then add to list. 
   }
   return resultList;
}

/*****************************
 * ARRAY TO LIST BACKWARDS
 *****************************/
list<string> arrayToListBackwards(string a[], int num)
{
   list<string> resultList = arrayToList(a, num);

   resultList.reverse();   // discovered the reverse function which will auto reverse a list.
   return resultList;      // Not very effcient I believe it is o(n). used also for the vector
}

/*****************************
 * LIST TO VECTOR
 *****************************/
vector<string> listToVector(const list<string>& l)
{
   vector<string> newVector;
   for (auto item : l)
   {
      newVector.push_back(item);
   }
   return newVector;
}

/*****************************
 * LIST TO VECTOR BACKWARDS
 *****************************/
vector<string> listToVectorBackwards(const list<string>& l)
{
   vector<string> newVector = listToVector(l);  // call list to vector to make it a vecotor
   reverse(newVector.begin(), newVector.end()); //reverse it and return it
   return newVector;
}

/*****************************
 * FIND ELEMENT IN VECTOR
 *****************************/
bool findElementInVector(const vector<string>& v, const string& element)
{
   if (find(v.begin(), v.end(), element) != v.end())
   {
      return true;
   }

   else {
      return false;
   }
}

/*****************************
 * MAIN
 *****************************/
int main()
{
   TestCollection().run();
   return 0;
}
