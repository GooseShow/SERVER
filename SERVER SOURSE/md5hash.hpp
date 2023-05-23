/**
* @file md5Hash.hpp
* @author Гусев Д. А.
* @version 1.0
* @brief Класс, обрабатывабщий HASH MD5
* @date 23.05.2023
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <cryptopp/hex.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>

using namespace std;
/**
 * @brief Класс, обрабатывабщий HASH MD5
 */
class md5h
{
private:
	/**
	* @brief Генератор соли
	* @return tmp_s соль
	*/
	string salt_generator();
public:
	/**
	* @brief конструктор класса
	*/
	md5h();
	//!Соль
	string salt;
	/**
	* @brief Получение хеша от пароля
	* @param password пароль
	* @return digest хеш
	*/
	string hash(const string password);
};
