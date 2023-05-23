/**
* @file errorhandler.hpp
* @author Гусев Д. А.
* @version 1.0
* @brief Обработчик ошибок
* @date 23.05.2023
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;
/**
 * @brief Обработчик ошибок
 */
class errorhandler
{
private:
    /**
   * @brief Запись ошибки в журнал
   * @param lpath Путь к файлу с журналом
   * @param why Содержание ошибки
   * @param dtime Время ошибки
   * @param critical Критичность ошибки
   */
    void logger(const string lpath,
    	   const char* why,
    	   const string dtime,
    	   const string critical);
public:
    /**
    * @brief Конструктор класса
    * @param lpath Путь к файлу с журналом
    * @param why Содержание ошибки
    * @param exitCode Код ошибки
    * @param critical Критичность ошибки
    */
    errorhandler(const string lpath,
    		 const char* why,
    		 const int exitCode,
    		 bool critical); 
};

