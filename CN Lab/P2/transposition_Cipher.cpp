// transposition cipher

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void encrypt()
{
    cout << "Enter Key : ";
    int key;
    string s;
    cin >> key;
    cin.get();
xx:
    cout << "Enter string : ";
    getline(cin, s);
    for (char c : s)
    {
        if (!isalpha(c))
        {
            if (c != 32)
            {
                cout << "wrong input.Please try again.\n";
                goto xx;
            }
        }
    }
    int col = s.size() / key + 1;
    vector<vector<char> > encrypt(col, vector<char>(key, 'X'));
    int z = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < key; j++)
        {
            while (s[z] == 32)
            {
                z++;
            }
            if ((s[z] >= 'a' and s[z] <= 'z') or (s[z] >= 'A' and s[z] <= 'Z'))
            {
                encrypt[i][j] = s[z];
            }

            if (s[z] != 0)
            {
                z++;
            }
        }
    }

    string ans = "";
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans += encrypt[j][i];
        }
    }

    cout << ans << endl;
}

void decrypt()
{
    cout << "Enter Key : ";
    int key;
    string s;
    cin >> key;
    cin.get();
xx:
    cout << "Enter string : ";
    getline(cin, s);
    for (char c : s)
    {
        if (!isalpha(c))
        {
            if (c != 32)
            {
                cout << "wrong input.Please try again.\n";
                goto xx;
            }
        }
    }
    int col = s.size() / key;
    vector<vector<char> > encrypt(col, vector<char>(key));
    int z = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (s[z] == 32)
            {
                z++;
            }

            encrypt[j][i] = s[z];
            if (s[z] != 0)
            {
                z++;
            }
        }
    }

    string ans = "";
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < key; j++)
        {
            if (encrypt[i][j] != 'X')
            {
                ans += encrypt[i][j];
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    int ch;
    while (1)
    {
    xy:
        cout << "1. Encryption.\n";
        cout << "2. Decryption.\n";
        cout << "3. Exit.\n";
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            encrypt();
            break;

        case 2:
            decrypt();
            break;

        case 3:
            return 0;

        default:
            cout << "Wrong input . Please try again \n";
            goto xy;
        }
    }
    return 0;
}