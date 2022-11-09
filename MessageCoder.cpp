/*
znane błędy/braki:
    -brak obsługi znaków specyficznych dla języka(np. polskich ą,ę,ś,ć itd)
    -brak zabezpieczeń przed nielegalnym/błędnym wpisem danych przez użytkownika
    -brak systemu kodującego(obecnie tylko zamiana na wartości numeryczne nieszyfrowane)
    -mało informacji dla użytkownika o tym co ma robić, użytkownik który nie miał wcześniej styczności z programem może mieć problemy
*/



#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    string wiadomosc;
    // enkodowanie czy dekodowanie -> deklaracja
    int opcja;
    //wyświetlenie "menu"
    cout << "Wybierz co chcesz zrobić" << endl << "1 - Enkoduj" << endl << "2 - Dekoduj" << endl << "Każda inna opcja spowoduje wyjście z programu" << endl << "Twój wybór: ";
    cin >> opcja;
    cout << "Wpisz wiadomość: ";
    //zczytanie stringu włącznie ze spacjami
    cin.ignore();
    getline(cin, wiadomosc, '\n');
    //uzyskanie długości wiadomości
    int dlugoscWiadomosci = (int)wiadomosc.length();
    //enkodowanie czy dekodowanie -> uzycie
    switch (opcja)
    {
    default: return 0;
    // enkodowanie
    case 1:
        //loop przez cały string
        for (int i = 0; i < dlugoscWiadomosci; i++)
        {
            //uzyskanie wartości int dla każdego char w stringu
            //wyświetlenie wartości numerycznej wraz ze znakiem rozdzielającym
            cout << (int)wiadomosc[i] << ".";
        }
        break;
    // dekodowanie
    case 2:
        //zmienne pomocnicze
        int temp = 0;
        bool dodatnia = true;
        int pozycja = 0;
        //loop przez cały string
        for (int i = 0; i < dlugoscWiadomosci; i++)
        {
            //switch w zależności od wartości int każdego char w stringu
            switch ((int)wiadomosc[i])
            {
            //dla cyfr
            default:
                //dodanie cyfry "na koniec" liczby
                // cyfra 0 jako char ma wartość 48, cyfra 1 ma wartość 49, itd
                temp *= 10;
                temp += (int)wiadomosc[i]-48;
                break;
            //jeśli znajdziemy znak rozdzielający
            case (int)'.':
                //sprawdzenie czy liczba jest dodatnia czy ujemna
                if (!dodatnia)
                    temp = -temp;
                //wyświetlenie wartości alfanumerycznej liczby
                cout << (char)temp;
                //reset temp
                temp = 0;
                //przejście na następną  pozycję w tablicy
                pozycja++;
                //reset znaku liczby
                dodatnia = true;
                break;
            //jeśli znajdziemy znak -
            //moży wystąpić tylko zaraz po znaku rozdzielającym
            //zmienia znak następnej liczby
            case (int)'-':
                dodatnia = false;
                break;
            }
        }
        break;
    }
    return 0;
}


