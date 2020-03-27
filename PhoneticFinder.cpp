
/**
 * AUTHORS: <Maor Ovadia and Gofna Ivry>
 * 
 * Date: 2020-03
 */

#include "PhoneticFinder.hpp"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
namespace phonetic{

string find(string text, string word){

    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    
    bool b;
    string ans = ""; // from the text
    string temp; // after tolower
    for (int i = 0 ;i <= text.length() ; i++){
        if(text[i] == ' ' || i == text.length()){
            if(ans.length() == word.length()){
                temp = ans;
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                b = check(temp , word);
                cout << ans << " " << b << " " << word << endl;
                if(b == true ) return ans;
            }
            ans = "";
            temp ="";
        }
        else{
            ans += text[i];
        }
    }
    throw runtime_error("Did not find the word '" + word + "' in the text");
    return "";
}

bool check(string temp , string word ){
    for(int i = 0 ; i < temp.length() ; i++){
        if (temp[i] == word[i]){
            continue;
        }
        else if((temp[i] == 'v' || temp[i] == 'w') && (word[i] =  'v' || word[i] == 'w')){
            continue;
        }
        else if((temp[i] == 'b' || temp[i] == 'f' || temp[i] == 'p') && (word[i] =  'b' || word[i] == 'f' || word[i] == 'p')){
            continue;
        }
        else if((temp[i] == 'g' || temp[i] == 'j') && (word[i] =  'g' || word[i] == 'j')){
            continue;
        }        
        else if((temp[i] == 'c' || temp[i] == 'k' || temp[i] == 'q') && (word[i] =  'c' || word[i] == 'k' || word[i] == 'q')){
            continue;
        }
        else if((temp[i] == 's' || temp[i] == 'z') && (word[i] =  's' || word[i] == 'z')){
            continue;
        }
        else if((temp[i] == 'd' || temp[i] == 't') && (word[i] =  'd' || word[i] == 't')){
            continue;
        } 
        else if((temp[i] == 'o' || temp[i] == 'u') && (word[i] =  'o' || word[i] == 'u')){
            continue;
        } 
        else if((temp[i] == 'i' || temp[i] == 'y') && (word[i] =  'i' || word[i] == 'y')){
            continue;
        } 
        else{
            return false;
        }
    }
    return true;
}
}