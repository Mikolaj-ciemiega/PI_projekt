
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string.h>

#include <iomanip>
using namespace std;

int main()
{



    // Wpisywanie komendy
    string komenda;

    do {
        cout << "podaj komendę do wykonania (enkrypcja/dekrypcja)" << endl;
        cin >> komenda;



    } while (komenda != "enkrypcja" && komenda != "dekrypcja");

    if (komenda == "enkrypcja") {



        //WPISYWANIE KLUCZA PRZEZ UŻYTKOWNIKA
        char klucz[17] = {};
        cout << "wpisz klucz" << endl;
        getchar();
        fgets(klucz, 17, stdin);


        char tabK[4][4][4] = { { {'e', 'x', 'p', 'a'}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
                               { {1, 2, 3, 4}, {'n', 'd', ' ', '3'}, {33, 33, 33, 33}, {33, 33, 33, 33}},
                               { {33, 33, 33, 33}, {33, 33, 33, 33}, {'2', '-', 'b', 'y'}, {1, 2, 3, 4}},
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



        cout << "klucz:\n";
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {

                    cout << tabK[i][j][k];

                }
                cout << "|";
            }
            cout << endl;
        }



        /* //WYPISYWANIE KLUCZA W TABELI
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
        */


        // WPISYWANIE TEKSTU
        cout << endl;
        char tekst[65] = { "\0" };
        cout << "podaj tekst\n";
        getchar();
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


        /* // WYPISYWANIE TEKSTU W TABELI
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
        */

        //ENKRYPCJA

        cout << "Enkrypcja:" << endl << endl;



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



        cout << "enkrypcja: " << endl;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {


                    cout << tabE[i][j][k];



                }
                cout << "||";
            }
            cout << endl;
        }




        //WYPISYWANIE TEKSTU PO ENKRYPCJI
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {


                    cout << tabE[i][j][k];



                }

            }

        }




    }

    if (komenda == "dekrypcja") {

        setlocale(LC_ALL, "");
        //DEKRYPCJA =============================================
        cout << endl << "Dekrypcja:" << endl;
        char tekst[65] = { "\0" };
        char tabE[4][4][4] = {};


        int licznik2 = 0;

        cout << "Wpisz tekst zaenkryptowany" << endl;
        getchar();
        fgets(tekst, 64, stdin);










        // Wpisywanie tekstu do tabeli
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {




                    tabE[i][j][k] = tekst[licznik2];
                    licznik2++;
                }

            }

        }


        cout << "zaenkryptowane\n";
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {

                    cout << tabE[i][j][k];

                }
                cout << " ";
            }
            cout << endl;
        }


        // wpisywanie klucza do tabeli

        char klucz[17];

        cout << "wpisz klucz" << endl;

        //getchar();
        fgets(klucz, 17, stdin);

        cout << "klucz w tabeli:" << endl;
        char tabK[4][4][4] = { { {'e', 'x', 'p', 'a'}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
                               { {1, 2, 3, 4}, {'n', 'd', ' ', '1'}, {33, 33, 33, 33}, {33, 33, 33, 33}},
                               { {33, 33, 33, 33}, {33, 33, 33, 33}, {'6', '-', 'b', 'y'}, {1, 2, 3, 4}},
                               { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {' ', ' ', ' ', ' '}} };

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



        cout << "klucz:\n";
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {

                    cout << tabK[i][j][k];

                }
                cout << "|";
            }
            cout << endl;
        }


        /*
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
        */





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

        cout << endl << "dekrypcja:" << endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {


                    cout << tabD[i][j][k];



                }

            }

        }


    }




    /*

*/


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


