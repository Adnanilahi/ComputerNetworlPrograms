#include<iostream>
using namespace std;

int main()
{
    int i, j, yes = 0;
    string message;
    cout << "Enter the message to be encrypted:" << '\n';
    cin >> message;
    string key;
    cout << "Enter the key to be used:" << '\n';
    cin >> key;
    int mod = key.size();
    j = 0;
    for (i = key.size(); i < message.size(); i++)
    {
        key += key[j % mod];
        j++;
    }
    string answer = "";
    for (i = 0; i < message.size(); i++)
    {
        answer += (key[i] - 'A' + message[i] - 'A') % 26 + 'A';
    }
    cout << "The Encrypted message is: " << answer << '\n';
    message = answer;
    cout << "press 1 to decrypt and 0 to exit" << endl;
    cin >> yes;
    if (yes == 1)
    {
        for (i = key.size(); i < message.size(); i++)
        {
            key += key[j % mod];
            j++;
        }
        string answer = "";
        for (i = 0; i < message.size(); i++)
        {
            answer += (message[i] - key[i] + 26) % 26 + 'A';
        }
        cout << "The Decrypted message is: " << answer << '\n';
    }
    return 0;
}