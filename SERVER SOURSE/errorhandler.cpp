#include "errorhandler.hpp"

using namespace std;

errorhandler::errorhandler(const string lpath,
    		 const char* why,
    		 const int exitCode = 1,
    		 bool critical = false){
    		 
    	// критичность ошибки
		string crtcl;
		if (critical == true)
			crtcl = "true";
		else
			crtcl = "false";
		
		// время ошибки
   		auto now = std::chrono::system_clock::now();
		time_t dt = std::chrono::system_clock::to_time_t(now);
		string dtime = ctime(&dt);
	
		// вывод ошибки в консоль 
   		cerr << " ERR time: " << dtime << " ERR INFO: " << why << "; critical: " << crtcl << "\n";
   		
   		// Запись в журнал
   		logger(lpath, why, dtime, crtcl);
   		
   		// завершение программы 
		if (critical == true)
			exit(exitCode);
}	

void errorhandler::logger(const string lpath,
    		 	  const char* why,
    		 	  const string dtime,
    		 	  const string critical){
 				ofstream out(lpath, std::ios::app);
				if (out.is_open()){
    					out << " ERR time: " << dtime << " ERR INFO: " << why << "; critical: " << critical << endl << endl;
				}
				else{
					cerr << " ERR time: " << dtime << " ERR INFO: " << why << "; critical: " << critical << "\n";
					exit(5);
				}
				out.close(); 
}


