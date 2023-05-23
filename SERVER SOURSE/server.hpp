/**
* @file server.hpp
* @author Гусев Д. А.
* @version 1.0
* @brief Класс, управляющий работой сервера
* @date 23.05.2023
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <cstdlib> // exit() - стандартные функции Си
#include <cstring> // strcpy(), strlen() - строки Си
#include <unistd.h> // close() - стандартные функции Unix
#include <netinet/in.h> //sockaddr_in and include <sys/socket.h>
#include <arpa/inet.h> // inet_addr()
#include <string>
#include <iostream>
#include "getdata.hpp"
#include "md5hash.hpp"
#include "errorhandler.hpp"
#include <map>
#include <stdlib.h>
#include <bitset>

using namespace std;
/**
 * @brief Класс, управляющий работой сервера
 */
class server
{
private:
	//!Путь к файлу с логом
    string lp;
	//!Сокет
    int sckt;
	//!Действующее соединение с клиентом
    int wrkr;
	//!Ответ от клиента
    int rc;
	//!Буфер
    char *buf = new char[4096];
	//!Данные клиента "ID:PASS"
    map <string, string> userdata;

public:
	/**
	* @brief конструктор класса
	* @param fpath путь к файлу с ID:PASS
	* @param port порт сервера
	* @param lpath путь к файлу с  журналом
	*/
	server(string fpath,
	       int port,
	       string lpath);
	/**
	* @brief Запуск сервера и бинд порта
	* @param port Порт сервера
	* @param address localhost
	* @return sckt Сокет
	*/
	int start(int port,
		  char* address);
	/**
	* @brief Ожидание клиента и принятие соединения
	* @return wrkr Действующее соединение с клиентом
	*/
	int  accepting_connection();
	/**
	* @brief Авторизация пользователя
	* @return Возвращает bool значение true, если авторизация удалась, false, если не удалась
	*/
	bool authentication();
	/**
	* @brief Обработка веторов
	* @return Возвращает bool значение true, если обработка удалась, false, если не удалась
	*/
	bool handling();
};
