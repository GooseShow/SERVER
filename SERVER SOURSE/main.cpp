#include <iostream>
#include <vector>
#include "server.hpp"
#include "getdata.hpp"
#include <cryptopp/hex.h>
#include "md5hash.hpp"
#include <string.h>

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>

using namespace std;

void help(){
	cout << "enter -h for help;\nenter -fp for the path to the database with clients;\nenter -lp for the path to the log file;\nenter -p for the port\n";
}

int main(int argc, const char* argv[]){
    string fpath = "/home/danila/coursework/coursework/data.txt";
    int port = 33333;
    string lpath = "log.txt";
    for (int i = 0; i < argc; i++){
    	if (strcmp("-h", argv[i]) == 0)
    		help();
    	if (strcmp("-fp", argv[i]) == 0) 
    		fpath = argv[i+1];
    	if (strcmp("-lp", argv[i]) == 0) 
    		lpath = argv[i+1];
    	if (strcmp("-p", argv[i]) == 0) 	
    		port = atoi(argv[i+1]);
    }
    if (argc == 0) help();
    server srvr = server(fpath, port, lpath);
    while (true){
    srvr.accepting_connection();
    if (srvr.authentication() == true)
		  srvr.handling();
 	}
}
