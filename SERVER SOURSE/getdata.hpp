/**
* @file getdata.hpp
* @author Гусев Д. А.
* @version 1.0
* @brief Класс, обрабатывающий файл с ID:PASS клиентов
* @date 23.05.2023
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "errorhandler.hpp"

using namespace std;
/**
 * @brief Класс, обрабатывающий файл с ID:PASS клиентов
 */
class getdata
{
private:
    //!Путь к файлу с журналом
    string lp;
public:
    /**
    * @brief конструктор класса
    * @param lpath Путь к файлу с журналом
    */
    getdata(const string lpath);
    /**
    * @brief Запись ID:PASS в словарь
    * @param fpath Путь к файлу с ID:PASS клиентов
    * @return userdata ID:PASS
    */
    map<string, string> get(string fpath);
};

