

#include <iostream>
#include <string>

using namespace std;

int main()
{

	//test!!!!
	setlocale(LC_ALL, "");

	char tekst[65] = {"\0"};

	fgets(tekst, 65, stdin);

	char tab[4][4][4] = {};



	int licznik=0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				tab[i][j][k] = tekst[licznik];

				licznik++;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				
				cout << tab[i][j][k];
				
			}
			cout << " ";
		}
		cout << endl;
	}

}

