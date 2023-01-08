#include <iostream>
#include <cstring>

using namespace std;

void key_filling(char* input, char* key)
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

int main()
{
    char key[17] = {};
    cout << "wpisz klucz" << endl;
    fgets(key, 17, stdin);

    char imput[4][4][4] = { { {'e', 'x', 'p', 'a'}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {'n', 'd', ' ', '3'}, {'a', 'b', 'c', 'd'}, {'a', 'b', 'c', 'd'}},
                           { {0, 0, 0, 0}, {0, 0, 0, 0}, {'2', '-', 'b', 'y'}, {1, 2, 3, 4}},
                           { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {'t', 'e', ' ', 'k'}} };

    char* wsk_imput = &imput[0][0][0], * wsk_key = &key[0];

    key_filling(wsk_imput, wsk_key);

}
