#include<iostream>
#include<string.h>
#include<ws2tcpip.h>
#include<sstream>
#include<ctime>
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
	// Initialize Winsock

	WSAData wd;
	int val = WSAStartup(MAKEWORD(2, 2), &wd);

	if (val != 0) {
		cout << "ERROR : Can't Initialize Winsock" << endl;
		cout << "Error # : " << WSAGetLastError();
		return 0;
	}

	cout << "Winsock Initialized Successfully" << endl;

	// Initialize Socket

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == INVALID_SOCKET) {
		cout << "ERROR : Can't Initialize Socket" << endl;
		cout << "Error # : " << WSAGetLastError();
		return 0;
	}

	cout << "Socket Initialized Successfully" << endl;


	// Bind an IP Address and port to the socket.

	sockaddr_in list;

	list.sin_addr.S_un.S_addr = INADDR_ANY;
	list.sin_family = AF_INET;
	list.sin_port = htons(PORT);

	int bVal = bind(sock, (sockaddr*)&list, sizeof(list));

	if (bVal == SOCKET_ERROR) {
		cout << "ERROR : Can't bind socket to the Local Address" << endl;
		cout << "Error # : " << WSAGetLastError();
		return 0;
	}

	cout << "Successfully Bound Socket" << endl;

	cout << "-------------------------SERVER-------------------------" << endl;

	// Put socket to listening mode.

	int lsn = listen(sock, 10);

	if (lsn == SOCKET_ERROR) {
		cout << "ERROR : Can't listen" << endl;
		cout << "Error # : " << WSAGetLastError();
		return 0;
	}
    string ts;
	fd_set sockSet;

	FD_ZERO(&sockSet);
	FD_SET(sock, &sockSet);

	while (true) {
		fd_set temp = sockSet;
		int sVal = select(0, &temp, NULL, NULL, NULL);

		if (sVal == SOCKET_ERROR) {
			cout << "ERROR : Error in Select Function" << endl;
			cout << "Error # : " << WSAGetLastError();
			return 0;
		}

		for (int i = 0; i < sVal; i++) {
			SOCKET tSock = temp.fd_array[i];

			if (tSock == sock) {
				SOCKET cSocket = accept(sock, NULL, NULL);
				FD_SET(cSocket, &sockSet);
				cout << "Connected to Client # : " << cSocket << endl;
                nt();
				stringstream ss;
				ss << "WELCOME CLIENT # : " << cSocket;
				string msg = ss.str();
				send(cSocket, msg.c_str(), msg.length() + 1, 0);
			}

			else {
				char buf[1023];
				ZeroMemory(buf,1023);
				char snd[1023];
				ZeroMemory(snd,1023);
				
				int bRec = recv(tSock, buf, 1024, 0);
				
				if (bRec == SOCKET_ERROR) {
					cout << "Disconnecting Client # : " << tSock << endl;
					closesocket(tSock);
				}
				
				
				cout << "CLIENT # "<< tSock << " : "<< string(buf, 0, bRec) << endl;
				nt();
				
				cout << "ENTER REPLY : " ;
				cin.getline(snd, 1023);
				send(tSock, snd, strlen(snd) + 1, 0);
                nt();
                
               
				

			}
		}
	}

	// Close Winsock.

	WSACleanup();


	return 0;
}
