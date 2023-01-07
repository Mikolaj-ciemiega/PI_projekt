#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stddef.h>

using namespace std;

void quarterround(char* y0, char* y1, char* y2, char* y3)
{
    *y1 = *y1 ^ ((*y0 + *y3) << 7);
    *y2 = *y2 ^ ((*y1 + *y0) << 9);
    *y3 = *y3 ^ ((*y2 + *y1) << 13);
    *y0 = *y0 ^ ((*y3 + *y2) << 18);
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
    /*
        quarterround(&y[0], &y[1], &y[2], &y[3]);
        quarterround(&y[5], &y[6], &y[7], &y[4]);
        quarterround(&y[10], &y[11], &y[8], &y[9]);
        quarterround(&y[15], &y[12], &y[13], &y[14]);*/
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
    /*
        quarterround(&x[0], &x[4], &x[8], &x[12]);
        quarterround(&x[5], &x[9], &x[13], &x[1]);
        quarterround(&x[10], &x[14], &x[2], &x[6]);
        quarterround(&x[15], &x[3], &x[7], &x[11]);*/
}

void doubleround(char* x)
{
    columnround(x);
    rowround(x);
}

char littleendian(char input, int i)
{
    return (input << (i * 8));
}

void hash_salsa(char* wsk_tabK, char* wsk_output)
{
    char words[16][4], coppy_words[16][4];
    int licznik = 0;

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            words[i][j] = *wsk_tabK;
            coppy_words[i][j] = *wsk_tabK;
            wsk_tabK++;
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
            *wsk_output = words[i][j];
            wsk_output++;
        }
    }

}

int main()
{
    char tabK[4][4][4] = { { {'e', 'x', 'p', 'a'}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {'n', 'd', ' ', '3'}, {33, 33, 33, 33}, {33, 33, 33, 33}},
                           { {33, 33, 33, 33}, {33, 33, 33, 33}, {'2', '-', 'b', 'y'}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {'t', 'e', ' ', 'k'}} };
    char* wsk_tabK;
    wsk_tabK = &tabK[0][0][0];

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

    char output[4][4][4] = {};
    char* wsk_output = &output[0][0][0];

    hash_salsa(wsk_tabK, wsk_output);

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

