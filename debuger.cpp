#include "debuger.h"
#include <iostream>
#include <string>

Debuger::Debuger(){
sf::TcpSocket socket;
    sf::IpAddress ip_adress;
    ip_adress= ip_adress.getLocalAddress();
    unsigned short port = 3072;

    if( socket.connect( ip_adress, port ) != sf::Socket::Done )
    {
        std::cerr << "Debuger is not run.";
    }

}
void Debuger::log(std::string comment){
    if( socket.send( comment.c_str(), comment.size()) != sf::Socket::Done )
    {
        std::cerr << "Server not linked\n";
    }

}
