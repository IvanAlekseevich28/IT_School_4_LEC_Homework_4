#include <iostream>
#include <ctype.h>
#include <string.h>
#include <math.h>
using namespace std;

unsigned short symbolToDigit(char symbol)
{
    char digit[10] = {'0', '1', '2', '3', '4','5', '6','7', '8','9'};
    for (unsigned short i = 0; i < 10; i++)
        if (symbol == digit[i]) return i;
}

int main()
{
    cout << "Enter goddamned number but not abracadabra: " << endl;
    char word[20];
    gets(word);
    unsigned int size = strlen(word);
    bool boolshit(0);


    if (word[0] != '-' and !isdigit(word[0])) boolshit++;
    for (unsigned int i = 1; i < size; i++)
        boolshit += !isdigit(word[i]);
    cout << boolshit << endl << endl;


    int number(0);
    if (!boolshit)
    {
        if (word[0] == '-')
        {
            unsigned short* Anumber = new unsigned short[size - 1];
            for (int i = 1; i < size; i++)
            Anumber[size -1 -i]  = symbolToDigit(word[i]);
            for (int i = 0; i < size - 1; i++)
                number += Anumber[i] * (int)pow(10, i);
            number *= -1;
            delete [] Anumber;
        }else{
            unsigned short* Anumber = new unsigned short[size];
            for (int i = size - 1; i >=0; i--)
                Anumber[i]  = symbolToDigit(word[size -1 -i]);
            for (unsigned short i = 0; i < size; i++)
                number += Anumber[i] * (int)pow(10, i);
            delete [] Anumber;
        }

        cout << number << endl;
    }
    return 0;
}
