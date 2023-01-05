



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

    //WPISYWANIE TEKSTU



    char tekst[65] = { "\0" };
    cout << "podaj tekst\n";
    fgets(tekst, 64, stdin);

    char tabT[4][4][4] = {};



    int licznik2 = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                tabT[i][j][k] = tekst[licznik2];

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

                cout << tabT[i][j][k];

            }
            cout << " ";
        }
        cout << endl;
    }


    //WPISYWANIE KLUCZA
    char klucz[17] = {};
    cout << "wpisz klucz" << endl;
    fgets(klucz, 17, stdin);




    char tabK[4][4][4] = { { {'e', 'x', 'p', 'a'}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {'n', 'd', ' ', '1'}, {33, 33, 33, 33}, {33, 33, 33, 33}},
                           { {33, 33, 33, 33}, {33, 33, 33, 33}, {'6', '-', 'b', 'y'}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {'t', 'e', ' ', 'k'}} };

    int licznik = 0;




    


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


    cout << endl << "Enkrypcja:" << endl;





    //ENKRYPCJA

    char tabE[4][4][4] = {};







    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {




                tabE[i][j][k] = ((tabT[i][j][k] - '0') ^ (tabK[i][j][k] - '0')) + '0';

            }

        }

    }


    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {


                cout << tabE[i][j][k];



            }
            cout << "|";
        }
        cout << endl;
    }


    //DEKRYPCJA
    cout << endl << "Dekrypcja:" << endl;


    char tabD[4][4][4] = {};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {




                tabD[i][j][k] = ((tabE[i][j][k] - '0') ^ (tabK[i][j][k] - '0')) + '0';

            }

        }

    }


    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {


                cout << tabD[i][j][k];



            }
            cout << "|";
        }
        cout << endl;
    }




   
    return 0;
}


