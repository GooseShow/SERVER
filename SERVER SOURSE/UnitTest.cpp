#include <UnitTest++/UnitTest++.h>
#include "server.hpp"
#include "server.cpp"
#include "errorhandler.hpp"
#include "errorhandler.cpp"
#include "getdata.hpp"
#include "getdata.cpp"
#include "md5hash.hpp"
#include "md5hash.cpp"

using namespace std;
struct things_fixture{
 server * pointer;
 things_fixture(){
 pointer = new server();
 }
 ~things_fixture(){
 delete pointer;
 }
};
SUITE(PROVERKI)
{
 TEST_FIXTURE(things_fixture, no_log_file){
 pointer->log_name =
"log2.txt";
 pointer->data_name =
"data.txt";
 CHECK_THROW(pointer->start(data_name, 33333,
 log_name);
 	}
 TEST_FIXTURE(things_fixture, no_data_file){
 pointer->log_name="log.txt";
 pointer->data_name="data2.txt";
 CHECK_THROW(pointer->start(data_name, 33333,
 log_name);
	}
 TEST_FIXTURE(things_fixture, no_user){
 pointer->log_name="log.txt";
 pointer->data_name="data_no_user.txt";
 CHECK_THROW(pointer->start(data_name, 33333,
 log_name);
	}
 TEST_FIXTURE(things_fixture, no_password){
 pointer->log_name="log.txt";
 pointer->data_name="data_no_password.txt";
 CHECK_THROW(pointer->start(data_name, 33333,
 log_name);
	}
 TEST_FIXTURE(things_fixture, no_data_file){
 pointer->log_name="log.txt";
 pointer->data_name="data.txt";
 CHECK_THROW(pointer->start(data_name, 2,
 log_name);
	}

}
