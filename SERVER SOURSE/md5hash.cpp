#include "md5hash.hpp"
#include <cryptopp/hex.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <iostream>
#include <unistd.h> // для генератора соли
#include <ctime> // для генератора соли

using namespace std;


md5h::md5h(){
	salt = salt_generator();
	}
	

string md5h::hash(const string password){
	using namespace CryptoPP;
	
    // Создаем объект-"хэширователь" для MD5
    Weak::MD5 hash;

    // Что будем хэшировать
    std::string msg = salt + password;

    // куда запишем результат
    std::string digest;

    // создаем цепочку преобразования
    StringSource(msg, true,             // источник-стока
                 new HashFilter(hash,       // фильтр-"хеширователь"
                                new HexEncoder(     // кодировщик в строку цифр
                                //new Base64Encoder(   // альтернатива - кодировщик в base64
                                    new StringSink(digest))));  // строка-приемник
    return digest;
}
string md5h::salt_generator(){
	srand(time(NULL));
	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(16);
    for (int i = 0; i < 16; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp_s;
}
