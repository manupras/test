//============================================================================
// Name        : cSocket.cpp
// Author      : Manu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include<stdio.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<arpa/inet.h>
using namespace std;

void * get_in_addr(struct sockaddr * sa) {
	if (sa->sa_family == AF_INET) {
		return &(((sockaddr_in *) sa)->sin_addr);
	}
	return &(((struct sockaddr_in6 *) sa)->sin6_addr);
}

int main() {
	cout << "cSocket" << endl; // prints cSocket
	int status;
	struct addrinfo hints, *res;
	int listener;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	status = getaddrinfo(NULL, "8888", &hints, &res);
	if (status != 0) {
		cerr << "get address info error" << gai_strerror(status) << endl;
	}
	//create socket and check in error occurred
	listener = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (listener < 0) {
		cerr << "socket error" << gai_strerror(listener) << endl;
	}

	status = bind(listener, res->ai_addr, res->ai_addrlen);
	if (status < 0) {
		cerr << "bind error" << gai_strerror(status) << endl;
	}

	status = listen(listener, 10);
	if (status < 0) {
		cerr << "listen error" << gai_strerror(status) << endl;
	}
	//free the res linked list after we are done with it
	freeaddrinfo(res);
	int new_conn_fd;
	struct sockaddr_storage client_addr;
	socklen_t addr_size;
	char s[INET6_ADDRSTRLEN];
	//calculate the size of the data structure
	addr_size = sizeof client_addr;
	cout << "I am now accepting the connections....." << endl;
	while (1) {
		//accept a new connection and return back the socket descriptor
		new_conn_fd = accept(listener, (sockaddr*) &client_addr,
				(socklen_t*) &addr_size);
		if (new_conn_fd < 0) {
			cerr << "accept:" << gai_strerror(new_conn_fd) << endl;
			continue;
		}
		inet_ntop(client_addr.ss_family, get_in_addr((sockaddr*) &client_addr),
				s, sizeof s);
		cout << "I am not connected to" << s << endl;
		status = send(new_conn_fd, "Welcome", 7, 0);
		if (status == -1) {
			close(new_conn_fd);
			_exit(4);
		}
	}
	close(new_conn_fd);
	return 0;
}
