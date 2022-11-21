
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string.h>

#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    //TEKST

    char tekst[65] = { "\0" };
    cout << "podaj tekst\n";
    fgets(tekst, 64, stdin);

    char tab[4][4][4] = {};



    int licznik2 = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                tab[i][j][k] = tekst[licznik2];

                licznik2++;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {

                cout << tab[i][j][k];

            }
            cout << " ";
        }
        cout << endl;
    }


    //klucz
    char klucz[17] = {};
    cout << "wpisz klucz" << endl;
    fgets(klucz, 17, stdin);




    char tabK[4][4][4] = { { {'e', 'x', 'p', 'a'}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {'n', 'd', ' ', '1'}, {33, 33, 33, 33}, {33, 33, 33, 33}},
                           { {33, 33, 33, 33}, {33, 33, 33, 33}, {'6', '-', 'b', 'y'}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {'t', 'e', ' ', 'k'}} };

    int licznik = 0;




    //aaaabbbbccccdddd


    for (int i = 0; i < 4; i++) {

        tabK[0][1][i] = klucz[licznik];
        tabK[2][3][i] = klucz[licznik];
        licznik++;
    }

    for (int i = 0; i < 4; i++) {

        tabK[0][2][i] = klucz[licznik];
        tabK[3][0][i] = klucz[licznik];
        licznik++;
    }

    for (int i = 0; i < 4; i++) {

        tabK[0][3][i] = klucz[licznik];
        tabK[3][1][i] = klucz[licznik];
        licznik++;
    }

    for (int i = 0; i < 4; i++) {

        tabK[1][0][i] = klucz[licznik];
        tabK[3][2][i] = klucz[licznik];
        licznik++;
    }







    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {


                cout << tabK[i][j][k];


                licznik++;
            }
            cout << "|";
        }
        cout << endl;
    }


    cout << endl << "część z tekstem:" << endl;







    /*
    string Tekst = "abcd";
    string Klucz = "23sd";
    string TekstE = "0000";
    string TekstD = "0000";

    for (int i = 0; i < 4; i++) {

        //TekstE
        TekstE[i] = ((Tekst[i] - '0') ^ (Klucz[i] - '0')) + '0';


    }
    //odwracamy - dekrypcja

    for (int i = 0; i < 4; i++) {


        TekstD[i] = ((TekstE[i] - '0') ^ (Klucz[i] - '0')) + '0';


    }


    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    cout << "Tekst= " << Tekst << endl;
    cout << "Klucz= " << Klucz << endl;
    cout << "Tekst po enkrypcji XOR-em= " << TekstE << endl;
    cout << "Tekst po de-enkrypcji XOR-em= " << TekstD << endl;
    */
    return 0;
}


