
#include "PhoneticFinder.hpp"
//#include <string>
#include <iostream>
using namespace std;
namespace phonetic{

string find(string text, string w){
    
    size_t found =  text.find(w);
    string temp = "";
    int count = 0;
    for (int i = found ; text[i] != ' ' && i < text.length() ; i++){
        count++;
    }

    if(count > w.length()){
        throw runtime_error("'"+w+"'" + " is not a full word in the sentence");
    }
    
    if (found != -1){
        return w;
    }
   return "none";
}
}
