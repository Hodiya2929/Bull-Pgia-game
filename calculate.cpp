#include "calculate.hpp"


using namespace bullpgia;

namespace bullpgia{

const string calculateBullAndPgia(const string& choice, const string& guess){

std::string choice_cpy = choice, guess_cpy = guess; //manipulating the copy and not the real one

int bull=0, pgia=0; //counter for bull and pgia states

for(std::string::iterator it_guess = guess_cpy.begin(),it_choice=choice_cpy.begin();
it_guess!=guess_cpy.end(); ++it_guess, ++it_choice){//assumed that length of both string are equal.
//defining two iterators and comparing sequently the char, if equals - remove the equals char.
//from 35674 32579 we get 564 259

          if(*it_guess==*it_choice){
              bull++;
              it_guess=guess_cpy.erase(it_guess);
              it_choice=choice_cpy.erase(it_choice);
              it_choice--;it_guess--;
            }
}
//for all guess chars - if the remaining part of the choice contains the i char of guess - remove it and increase pgia var
for(std::string::iterator it_guess = guess_cpy.begin(),it_choice=choice_cpy.begin();it_guess!=guess_cpy.end(); ++it_guess, ++it_choice){
      if(choice_cpy.find(*it_guess)!=-1){
          pgia++;
          choice_cpy.erase(choice_cpy.find(*it_guess),1);
      }
}

string boolString = std::to_string(bull);
string pgiaString = std::to_string(pgia);

string result=boolString+","+pgiaString;
return result; //cpy ctor is called and the calling function gets the string value

}//end calc function
}//end namespace