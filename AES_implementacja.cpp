// Tworzenie_Kluczy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>





/*
strona pokazująca implementację kodu szyfrującego AES do c++
 https://programmer.group/c-implementation-of-aes-encryption-algorithms.html


 strona tłumaczaca działanie AES
 https://cybernews.com/resources/what-is-aes-encryption/



 1. dzielenie tekstu na bloki po 16 bajtów (16 liter)
 2. Utworzenie klucza (np. makowiec)
 3. wykonanie kilku operacji matematycznych dla każdego z bajtów klucza, rozszerzając go
 4. dodanie (binarne) rozszerzonego klucza do każdego z bloków (1 poziom szyfrowania)
 5. odjecia od każdego bloku wartości z predefiniowanej tabeli (Rijndael S-box)
 6. tasowanie wierszy i kolumn w kazdym bloku
 7. ponowne dodanie rozszerzonego glucza do bloków
 8. całość powtarzamy 10 (lub wiecej) razy 

 */





using namespace std;


int main()
{
    cout << "Test\n";

}


