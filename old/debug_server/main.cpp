#include "ncurses.h"
#include <iostream>
#include "SFML/Network.hpp"

using namespace std;

int main() {
	sf::TcpListener listener;
	unsigned short port = 3072;

	if( listener.listen( port ) != sf::Socket::Done ) {
		cerr << "Nie mogę rozpocząć nasłuchiwania na porcie " << port << endl;
		exit( 1 );
	}

	size_t datasize =128;
    char data[1024];
    string a;

    cerr<<"=============   Client   =============\n";
    sf::TcpSocket client;
    listener.accept( client );
    cerr<<"=============Server Debug=============\n";
    cerr<<"=============   Start    =============\n";
    while( true)
    {
        size_t received;
        if( client.receive( data, datasize, received ) != sf::Socket::Done )
        {
            cerr << "Nie można odebrać danych!\n";
            getline(cin,a);
            exit( 1 );
        }
        else{
                for(int i=0;i<received;i++)
                    cout<<data[i];
        }

    }

	return 0;
}
