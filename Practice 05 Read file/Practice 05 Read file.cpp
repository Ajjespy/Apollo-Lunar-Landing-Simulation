#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int displayBalance(double balance)
{
   cout << "Account balance: $" << balance << endl;
   return 0;
}

double readBalance(string fileName)
{
   ifstream fin;
   double balance;
   fin.open(fileName.c_str());
   if (fin.fail())
   {
      cout << "Unable to open data.txt\n";
      balance = 0;
   }
   else
   {
      string line;
      getline(fin, line);
      balance = stod(line);
   }
   fin.close();
   displayBalance(balance);
   return balance;
}

double updateBalance(double balance)
{
   double change;
   cout << "Change: ";
   cin >> change;
   balance += change;
   displayBalance(balance);
   return balance;
}

int writeBalance(string fileName, double balance)
{
   ofstream fout;
   fout.open(fileName.c_str());
   if (fout.fail())
   {
      cout << "Unable to write balance to data.txt\n";
   }
   else
   {
      cout << "Balance successfully written to data.txt\n";
      fout << balance;
   }
   fout.close();
   return 0;
}

int main()
{
   double balance;
   balance = readBalance("data.txt");
   balance = updateBalance(balance);
   writeBalance("data.txt", balance);
}
