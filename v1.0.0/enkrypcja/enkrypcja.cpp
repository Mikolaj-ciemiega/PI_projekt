#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <iomanip>

using namespace std;

void text_insert_into_table(char(*table)[4][4], char* text)
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

void user_input_encrypt(char* table) 
{
    cout << "wpisz tekst" << endl;
    fgets(table, 64, stdin);
}

void user_input_decrypt(char text[]) 
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

void user_key_input(char* table) 
{
    cout << "wpisz klucz" << endl;
    getchar();
    fgets(table, 18, stdin);
    table[strlen(table) - 1] = 0;
}

void put_linekey_into_table(char* input, char* key)
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

void merge_tables_into_string(char(*table)[4][4], char(*string)) 
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

void asci(char(*table)[4][4]) 
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

void XOR_function(char(*tabKey)[4][4], char(*tabText)[4][4], char(*tabEncrypted)[4][4]) {

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

void quarterround(char* y0, char* y1, char* y2, char* y3)
{
    char x0 = *y0 + *y3, x1 = 0, x2 = 0, x3 = 0;

    *y1 = *y1 ^ ((x0) <<= 7);

    x1 = *y1 + *y0;
    *y2 = *y2 ^ ((x1) <<= 9);

    x2 = *y2 + *y1;
    *y3 = *y3 ^ ((x2) <<= 13);

    x3 = *y3 + *y2;
    *y0 = *y0 ^ ((x3) <<= 18);
}

void rowround(char* y)
{
    for (int i = 0; i < 4; i++)
    {
        quarterround(y + i, y + i + 4, y + i + 8, y + i + 12);
        quarterround(y + i + 20, y + i + 24, y + i + 28, y + i + 16);
        quarterround(y + i + 40, y + i + 44, y + i + 32, y + i + 36);
        quarterround(y + i + 60, y + i + 48, y + i + 52, y + i + 56);
    }
}

void columnround(char* x)
{
    for (int i = 0; i < 4; i++)
    {
        quarterround(x + i, x + i + 16, x + i + 32, x + i + 48);
        quarterround(x + i + 20, x + i + 36, x + i + 52, x + i + 4);
        quarterround(x + i + 40, x + i + 56, x + i + 8, x + i + 24);
        quarterround(x + i + 60, x + i + 12, x + i + 28, x + i + 44);
    }
}

void doubleround(char* x)
{
    columnround(x);
    rowround(x);
}

char littleendian(char input, int j)
{
    return (input <<= j);
}

void hash_salsa(char* wsk_imput)
{

    char* wsk_output = wsk_imput;
    char words[16][4], coppy_words[16][4];
    int licznik = 0;

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            words[i][j] = *wsk_imput;
            coppy_words[i][j] = *wsk_imput;
            wsk_imput++;

        }
    }

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            words[i][j] = littleendian(coppy_words[i][j], j);
        }
    }

    char* wsk_words = &words[0][0];

    doubleround(wsk_words);

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            words[i][j] = littleendian((words[i][j] + coppy_words[i][j]) % (int)pow(2, 32), j);
        }
    }

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            *wsk_output = words[i][j] + 32;

            wsk_output++;
        }
    }

}

int main()
{
    string user_command;
    do {
        cout << "give command" << endl;
        cin >> user_command;
    } while (user_command != "encrypt" && user_command != "decrypt");
   
    char lineKey[18] = {};
    user_key_input(lineKey);

    char tabKey[4][4][4] = { { {'e', 'x', 'p', 'a'}, {66, 66, 66, 66}, {66, 66, 66, 66}, {66, 66, 66, 66}},
                           { {66, 66, 66, 66}, {'n', 'd', ' ', '3'}, {'a', 'b', 'c', 'd'}, {'a', 'b', 'c', 'd'}},
                           { {66, 66, 66, 66}, {66, 66, 66, 66}, {'2', '-', 'b', 'y'}, {66, 66, 66, 66}},
                           { {66, 66, 66, 66}, {66, 66, 66, 66}, {66, 66, 66, 66}, {'t', 'e', ' ', 'k'}} };

    put_linekey_into_table(tabKey[0][0], lineKey);
    hash_salsa(tabKey[0][0]);
 
    char text[512] = {};

    if (user_command == "encrypt") {
        user_input_encrypt(text);
    }
    else {
        user_input_decrypt(text);
    }

    char tabText[4][4][4] = {};
    text_insert_into_table(tabText, text);
 
    char tabEncrypted[4][4][4] = {};
    XOR_function(tabKey, tabText, tabEncrypted);

    char tabOutput[65] = {};
    merge_tables_into_string(tabEncrypted, tabOutput);
   
    if (user_command == "encrypt") {
        cout << endl << endl << "ZAKODOWANE ASCII:  ";
        asci(tabEncrypted);
    }else{
        cout << "OUTPUT: " << tabOutput;
    }
}
