#pragma once
#include <string>
#include "calculate.hpp"

using std::string;

namespace bullpgia{

class Guesser{

public:

uint length;

virtual string guess() = 0;//declaring guess as pure virtual -> class Guess becomes abstract

virtual void startNewGame(int length){
    this->length=length;
}

virtual void learn(const string& reply){

}

virtual ~Guesser(){}// we want the compiler free the right destructor, because dtors are function alike. 

};//end class Guesser

}//end namespace bullpgia