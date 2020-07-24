#include "sdlsource.h"


GameClient::GameClient() {
    cout << "init game client" << endl;
    this->socketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (this->socketFD == -1) {
      perror("cannot create socket");
      exit(EXIT_FAILURE);
    } else {
        cout << "We have a socket!!!" << endl;
    }
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    
    sa.sin_family = AF_INET;
    sa.sin_port = htons(7000);
    inet_pton(AF_INET, "127.0.0.1", &sa.sin_addr);
    
    if(connect(this->socketFD, (struct sockaddr*) &sa, sizeof(sa)) == -1){
        perror("Connection failure");
        close(this->socketFD);
        exit(EXIT_FAILURE);
    } else {
        cout << "We have a connection!!!" << endl;
    }
}

void GameClient::writeMessage(char msg[1024]){
    cout << "Writing messaage: " << msg << endl;
    write(this->socketFD, msg, 1024);
}
