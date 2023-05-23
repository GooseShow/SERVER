#include "server.hpp"

using namespace std;


server::server(string fpath, int port, string lpath)
{	
	lp = lpath;
	char* ip="127.0.0.1";
	
	// закрузга логинов и паролей
	userdata = getdata(lp).get(fpath);
	
	// запуск сервера
        sckt = start(port, ip);
	
}

int server::start(int port, char* address){
    // подготовить структуру с адресом нашей программы (сервера)
	sockaddr_in* selfAddr = new (sockaddr_in);
	selfAddr->sin_family = AF_INET; 
	selfAddr->sin_port = htons(port);
	selfAddr->sin_addr.s_addr = inet_addr(address); 
	//создать сокет
	int sckt = socket(AF_INET, SOCK_STREAM, 0); // TCP
	// связать сокет с адресом
	int rc = bind(sckt, (const sockaddr*)selfAddr, sizeof(sockaddr_in));
	if (rc == -1)
		errorhandler(lp, "failed to bind socket", 1, true);
	// поставить сокет в режим ожидания соединения
	listen(sckt, 3);
	cout << "The server start" << endl;
    return sckt;
}

int  server::accepting_connection(){
    // подготовить структуру с адресом "на той стороне" (клиента)
	sockaddr_in* remoteAddr = new (sockaddr_in);
	remoteAddr->sin_family = AF_INET; // интернет протокол IPv4
	remoteAddr->sin_port = 0;
	remoteAddr->sin_addr.s_addr = 0; // локальный адрес 12
	// Принять соединение
	sockaddr_in * client_addr = new sockaddr_in;
	socklen_t len = sizeof(sockaddr_in);
	wrkr = accept(sckt, (sockaddr*)(client_addr), &len);
	cout << "The server accepted the connection" << endl;
    return wrkr;
}

bool server::authentication(){
	md5h crypt;
	string err = "ERR";
	string ok = "OK";
	// идентификация 
    	rc = recv(wrkr, buf, sizeof(buf), 0);
    	buf[rc] = '\0';
    	string ID(buf);
	if (userdata.count(ID) == 1){
		strcpy(buf, crypt.salt.c_str());
        	send(wrkr, buf, crypt.salt.length(), 0);
        	}
    	else{
		strcpy(buf, err.c_str());
        	send(wrkr, buf, sizeof(buf), 0);
        	close(wrkr);	
		errorhandler(lp, "invalid client id", 2, false);
        	return false;
    	}
	cout << "The client has been identified" << endl;	
	// аунтификация
    	rc = recv(wrkr, buf, 4096, 0);
    	buf[rc] = '\0';
    	string message(buf);
	if (message != crypt.hash(userdata[ID])){
		strcpy(buf, err.c_str());
		send(wrkr, buf, err.length(), 0);
		close(wrkr);
		errorhandler(lp, "invalid password", 3, false);
        return false;
		}
	strcpy(buf, ok.c_str());
	rc = send(wrkr, buf, ok.length(), 0);
	buf[rc] = '\0';
	cout << "The client has been authenticated" << endl;
	return true;
}

bool server::handling(){
	uint32_t vectors_quantity;
	uint32_t vector_size;
	int64_t vector;
    	// принимаеми количесво векторов
	recv(wrkr, &vectors_quantity, sizeof(vectors_quantity), 0);
	for (int i = 0; i < vectors_quantity; i++){
		long int sum = 0;
		recv(wrkr, &vector_size, sizeof(vector_size), 0);
		//cout << "numb = " << numb << endl; 
		for (int j = 0; j < vector_size; j++){
			recv(wrkr, &vector, sizeof(vector), 0);
			//cout << "vect = " << vect << endl; 
			sum += vector;
		}
	int64_t answer;
	answer = sum/vector_size;
	send(wrkr, &answer, sizeof(answer), 0);
	}
	return true;
};
