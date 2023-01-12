#ifndef SALSA20_H
#define SALSA20_H

#include <iostream>
#include <string>

class Salsa20
{
public:
    Salsa20();
    ~Salsa20();

    void text_insert_into_table(char(*table)[4][4], char* text);
    void user_input_encrypt(char* table);
    void user_input_decrypt(char text[]);
    void user_key_input(char* table);
    void put_linekey_into_table(char* input, char* key);
    void merge_tables_into_string(char(*table)[4][4], char(*string));
    void asci(char(*table)[4][4]);
    void XOR_function(char(*tabKey)[4][4], char(*tabText)[4][4], char(*tabEncrypted)[4][4]);
    void quarterround(char* y0, char* y1, char* y2, char* y3);

private:
    char key[18];
    char text[64];
    char(*tabKey)[4][4];
    char(*tabText)[4][4];
    char(*tabEncrypted)[4][4];
};

#endif




