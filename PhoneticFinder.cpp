
#include "PhoneticFinder.hpp"
//#include <string>
#include <iostream>
using namespace std;
namespace phonetic{

string find(string text, string w){
    size_t found =  text.find(w);
    if (found != -1){
        return w;
    }
   return "none";
}
}
