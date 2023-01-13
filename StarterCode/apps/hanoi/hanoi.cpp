#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

void moveDisks(int, int, int, int);
void printIt(int , int , int );

int main() {
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 3;
    //=============================
    auto start = chrono::steady_clock::now();           
    auto end = chrono::steady_clock::now();
    ofstream fileout;
    fileout.open("timeLog.txt");
    for (auto numdisks: {3,5,10,15,20,25,30,31,32,33}) {                      
        start = chrono::steady_clock::now();
        cout << "Numdisks: " << numdisks << endl;         
        fileout << "Numdisks: " << numdisks << "\t\t\t";
      moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
      cout << "Moved " << numdisks << " pegs"
           << " from peg " << FROMPEG
           << " to peg " << TOPEG << endl;
      end = chrono::steady_clock::now();
      chrono::duration<double> elapsed_seconds = end - start;
      cout << "\nTime (s)" << elapsed_seconds.count() << endl <<endl;
      fileout << "\nTime (s) " << elapsed_seconds.count() << endl;
    }
    fileout.close();

    //=============================
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
     if (num > 0) {
        moveDisks(num -1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num-1, tempPeg, toPeg, fromPeg);
     }
}

void printIt(int disk, int fromPeg, int toPeg) {
  // Do nothing for timing test, but otherwise
  cout<< "Move disk " << disk
      << " from pef " << fromPeg
      << " to peg " << toPeg << endl;
}
