#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

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

void hash_salsa(char* wsk_imput, char* wsk_output)
{
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
        cout << endl;
    };
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

    cout << "output" << endl;

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((int)words[i][j] < 0)
            {
                words[i][j] = words[i][j] * -1;
            }

            *wsk_output = words[i][j] + 32;

            wsk_output++;
        }
        cout << endl;
    }

}

int main()
{
    char imput[4][4][4] = { { {'e', 'x', 'p', 'a'}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {'n', 'd', ' ', '3'}, {33, 33, 33, 33}, {33, 33, 33, 33}},
                           { {33, 33, 33, 33}, {33, 33, 33, 33}, {'2', '-', 'b', 'y'}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {'t', 'e', ' ', 'k'}} };

    char output[4][4][4] = {};


    char* wsk_output = &output[0][0][0], *wsk_imput=&imput[0][0][0];

    hash_salsa(wsk_imput, wsk_output);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << output[i][j][k];
            }
            cout << "|";
        }
        cout << endl;
    }

}
