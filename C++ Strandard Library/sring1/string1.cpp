//string/string1.cpp

#include <iostream>
#include <string>
using namespace std;

int main (int argc, char* argv[])
{
    string filename, basename, extname, tmpname;
    const string suffix("tmp");

    //for each command_line argument (which is an ordinary C-string)
    for (int i = 1; i < argc; ++i){
        filename = argv[i];
        
        //search period in filename
        string::size_type idx = filename.find('.');
        if (idx == string::npos){
	    //filename dose not contain any period
	    tmpname = filename + ',' + suffix;
	}
        else {
	    //split filename into basename and extension
	    //- base name contains all characters before the period
	    //- extension name contains all characters after the period
	    basename = filename.substr(0, idx);
	    extname = filename.substr(idx+1);
	    if (extname.empty()) {
	        //contains period but no extesion: append tmp
		tmpname = filename;
	        tmpname += suffix;
	    }
	    else if (extname == suffix) {
	        //replace extension temp with xxx
		tmpname = filename;
	        tmpname.replace(idx+1, extname.size(), "xxx");
	    }
	    else {
	        //replace any extension with tmp
		tmpname = filename;
	        tmpname.replace(idx+1, string::npos, suffix);
	    }
	}
    
        //print filename and temporary name
	cout << filename << "=>" << tmpname << endl;
    }

}
