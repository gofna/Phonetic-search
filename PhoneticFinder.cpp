
/**
 * AUTHORS: <Maor Ovadia and Gofna Ivry>
 * 
 * Date: 2020-03
 */

#include "PhoneticFinder.hpp"
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
        throw runtime_error("'"+w+"'" + " is not a full word in the sentence\n");
    }
    
    if (found != -1){
        return w;
    }
   return "none";
}
}
