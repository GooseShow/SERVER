#include "getdata.hpp"

using namespace std;

getdata::getdata(const string lpath){
	lp = lpath;
}

map <string, string> getdata::get(string fpath){
    map <string, string> userdata;
    string line;
    ifstream in(fpath);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            int position = line.find(':');
            string ID;
            string password;
            for (int n = 0; n < position; n++)
                ID += line[n];
            for (int n = position+1; n < line.length(); n++)
                password += line[n];
            userdata[ID] = password;
        }
    }
    else
    	errorhandler(lp, "failed open client base file", 4, true);
    in.close();
    return userdata;
}


