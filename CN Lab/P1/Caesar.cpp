#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    cout << "Enter the input line:\n";

    char msg[100];

    cin.getline(msg, 100);

    int choice, key;
    cout << "Enter the key: ";
    cin >> key; 

    char ch;

    for (int i = 0; msg[i] != '\0'; ++i)
    {
        ch = msg[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }

    // printf("Ciphered message: %s", msg);
    
    cout << "Ciphered message is: " << msg <<endl;
    cout << "\nDo you want to decipher it? \n1. yes \n2. no \n";
    cin >> choice;
    if (choice == 1)
    {
        char ch;
        for (int i = 0; msg[i] != '\0'; ++i)
        {
            ch = msg[i];
            if (ch >= 'a' && ch <= 'z')
            {
                ch = ch - key;
                if (ch < 'a')
                {
                    ch = ch + 'z' - 'a' + 1;
                }
                msg[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch - key;
                if (ch < 'A')
                {
                    ch = ch + 'Z' - 'A' + 1;
                }
                msg[i] = ch;
            }
        }
        cout << "Deciphered message: " << msg;
    }
    else if (choice == 2)
    {
        cout << "You selected not to decipher.";
    }
}