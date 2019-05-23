#pragma once
#include<iostream>

using std::string;


namespace bullpgia{

class Chooser{

public:

virtual string choose(uint i) = 0; //pure virtual fun -> class Chooser - abstract

};//end class Chooser

}//end namespace bullpgia