#include <vector>
#include <iostream>
#include <string>
#include "SFML/Network.hpp"

class Debuger{
sf::TcpSocket socket;
public:
  Debuger();
  //void log(int nr_line, char * fun_name, char * file_name, char * comment);
  //void log(int nr_line, char * fun_name, char * file_name, std::string comment);
  void log(std::string comment);
  //void log(char * comment);
  //template <typename T>
  //void log(std::vector<T>);

};
Debuger::Debuger(){
  sf::IpAddress ip_adress;
  ip_adress= ip_adress.getLocalAddress();
  unsigned short port = 3072;

  if( socket.connect( ip_adress, port ) != sf::Socket::Done )
  {
    std::cerr << "Debuger is not run.\n";
  }
}
void Debuger::log(std::string comment){
  if( socket.send( comment.c_str(), comment.size()) != sf::Socket::Done )
  {
    std::cerr << "Server not linked\n";
  }
}
