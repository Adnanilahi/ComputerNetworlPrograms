#include<iostream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<ws2tcpip.h>
#include<string.h>
#include<ctime>
#include<sstream>
#pragma comment (lib,"ws2_32.lib")
using namespace std;
#define PORT 9000
void nt(){
	time_t now = time(0);
	tm *ltm = localtime(&now);	
	cout << "TIME # ";
	cout << ltm->tm_hour <<" : ";
	cout  << ltm->tm_min <<" : ";
	cout << ltm->tm_sec <<endl;
	 }
int main() {
    cout << endl << "----------------------------------------CLIENT-------------------------------------" << endl;
    // Initialize Winsock.

    WSAData wd;
    int val = WSAStartup(MAKEWORD(2, 2), &wd);
    if (val != 0) {
        cout << "ERROR : Can't Initialize Winsock" << endl;
        cout << "Error # : " << WSAGetLastError();
        return 0;
    }
    cout << "                                    WINSOCK STARTED" << endl;
    // Initialzie Socket.
    SOCKET cSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (cSocket == SOCKET_ERROR) {
        cout << "ERROR : Can't Initialize Socket" << endl;
        cout << "Error # : " << WSAGetLastError();
        return 0;
    }
    cout << "                                    SOCKET CREATED" << endl;
    // Connect to server.

    sockaddr_in aasif;

    aasif.sin_port = htons(PORT);
    aasif.sin_family = AF_INET;
    aasif.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    int cVal = connect(cSocket, (sockaddr*)&aasif, sizeof(aasif));
    if (cVal == SOCKET_ERROR) {
        cout << "ERROR : Can't Connect to Server" << endl;
        cout << "Error # : " << WSAGetLastError();
        return 0;
    }
   
    cout << "                          CONNECTED SUCCESSFULLY   " ;nt(); cout  <<endl;
	cout << "                               CONNECTED ON PORT : " << htons(aasif.sin_port) << endl;
	

    // Receiving Welcome Message

    char wmsg[1023];

    int wMsg = recv(cSocket, wmsg, 1023, 0);

    if (wMsg == SOCKET_ERROR) {
        cout << "ERROR : Error in receiving welcome message" << endl;
        return 0;
    }

    cout <<"                                " << string(wmsg, 0, wMsg) << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "                      HAVE A NICE CHAT WITH THE OTHER CLIENTS" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

    // Send & Receive Response.

    while (true) {
        
        char snd[1023];
        char rcv[1023];
        ZeroMemory(snd,1023);
        ZeroMemory(rcv,1023);
        cout << "ENTER TEXT : ";
        cin.getline(snd, 1023);
        int sd = send(cSocket, snd, strlen(snd) + 1, 0);
        nt();
        if (sd == SOCKET_ERROR) {
            cout << "ERROR : Can't Send Message" << endl;
            cout << "Error # : " << WSAGetLastError() << endl;
            return 0;
        }
		      
        int br = recv(cSocket, rcv, 1023, 0);
         
        cout << "SERVER : " << string(rcv, 0, br) << endl;
        nt();
        
        
        

    }

    // Close Socket.

    closesocket(cSocket);

    // Close Winsock.

    WSACleanup();

    return 0;
}

