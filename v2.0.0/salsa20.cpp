

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <iomanip>


#include "salsa20.h"

Salsa20::Salsa20()
{

}

void Salsa20::text_insert_into_table(char(*table)[4][4], char* text)
{
    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                table[i][j][k] = text[counter];
                counter++;
            }
        }
    }
}

void Salsa20::user_input_encrypt(char* table)
{
    cout << "wpisz tekst" << endl;
    fgets(table, 64, stdin);
}

void Salsa20::user_input_decrypt(char text[])
{
    string line;
    cout << "wpisz tekst do dekrypcji:";
    getline(cin, line);
    int counter = 0;
    string ascii_code = "";
    for (char c : line) {
        if (c != ':') {
            ascii_code += c;
        }
        else {
            int ascii_val = stoi(ascii_code);
            text[counter] = (char)ascii_val;
            ascii_code = "";
            counter++;
        }
    }
}

void Salsa20::user_key_input(char* table)
{
    cout << "wpisz klucz" << endl;
    getchar();
    fgets(table, 18, stdin);
    table[strlen(table) - 1] = 0;
}

void Salsa20::put_linekey_into_table(char* input, char* key)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            *(input + 4 + (4 * i) + j) = *key;
            *(input + 44 + (4 * i) + j) = *key;
            key++;
        }
    }
}

void Salsa20::merge_tables_into_string(char(*table)[4][4], char(*string))
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                string[k + 4 * j + 4 * 4 * i] = table[i][j][k];
            }
        }
    }
}

void Salsa20::asci(char(*table)[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << (int)table[i][j][k] << ":";
            }
        }
    }
}

void Salsa20::XOR_function(char(*tabKey)[4][4], char(*tabText)[4][4], char(*tabEncrypted)[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                tabEncrypted[i][j][k] = ((((tabText[i][j][k])) ^ ((tabKey[i][j][k]))));
            }
        }
    }
}

void Salsa20::quarterround(char* y0, char* y1, char* y2, char* y3)
{
    char x0 = *y0 + *y3, x1 = 0, x2 = 0, x3 = 0;

    *y1 = *y1 ^ ((x0) <<= 7);

    x1 = *y1 + *y0;
    *y2 = *y2 ^ ((x1) <<= 7);

    x2 = *y2 + *y1;
    *y3 = *y3 ^ ((x2) <<= 7);
}

