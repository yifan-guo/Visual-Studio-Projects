// generate a random dice file for the boggle pgm

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main ()
{

  ofstream fout;
  fout.open("boggle-in.txt");
  if (fout.fail()) {
    cout << "Unable to open boggle-in.txt for writing." << endl;
    exit(99);
  }

  ifstream fin;
  fin.open("boggle-dice.txt");
  if (fin.fail()) {
    cout << "Unable to open boggle-dice.txt for reading." << endl;
    exit(99);
  }

  char dice[16][6];
  bool used[16];

  for (int m=0;m<16;m++) {
    used[m] = false;
    for (int n=0;n<6;n++) {
      fin >> dice[m][n];
    }
  }

  fin.close();


  cout << "\nThis program will generate a random boggle-in.txt file." << endl;
  cout << "Enter a random integer (entering the same integer will" << endl;
  cout << "generate the same boggle-in.txt file): ";
  int tmp;
  cin >> tmp;
  srand(tmp);  // seed the random number generator

  cout << "\nThe boggle-in.txt file now contains:\n " << endl;

  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {

      // pick a random, unused die
      int die = rand()%16;
      while (used[die]) die = rand()%16;
      used[die] = true;

      // pick a random face of the die
      int face = rand()%6;

      //cout << "DEBUG:: using die #" << die << " and face " << face << endl;

      char ch = dice[die][face];
      fout << ch;
      cout << ch;
    }
    fout << endl;
    cout << endl;
  }

  fout.close();
  cout << endl;

  cout << "Press enter to end program.";
  cin.get();
  cin.get();

  return 0;

}
