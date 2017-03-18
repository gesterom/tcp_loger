#include <iostream>
#include <string>
#include "SFML/Network.hpp"
#include "SFML/Network/IpAddress.hpp"

using namespace std;

int main()
{

    sf::TcpSocket socket;
    sf::IpAddress ip_adress;
    ip_adress= ip_adress.getLocalAddress();
    unsigned short port = 3072;
    system("gnome-terminal -e ./debug_server");
    system("sleep 2");

    if( socket.connect( ip_adress, port ) != sf::Socket::Done )
    {
        cerr << "Nie można połączyć się z " << ip_adress.toString() << endl;
        exit( 1 );
    }
    size_t datasize = 1024;
    string data;
    getline(cin,data);

    if( socket.send( data.c_str(), data.size()) != sf::Socket::Done )
    {

        cerr << "Nie można wysłać danych!\n";
        exit( 1 );
    }

    data="\n\n\nZamykam polaczenie narazie server :D\n";

    if( socket.send( data.c_str(), data.size() ) != sf::Socket::Done )
    {

        cerr << "Nie można wysłać danych!\n";
        exit( 1 );
    }
    return 0;
}
