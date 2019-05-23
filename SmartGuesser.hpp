#include "Guesser.hpp"


class SmartGuesser:public bullpgia::Guesser{

public:

string final_result; //holds the right guess
string temp_string;
int index, index_to_return;//index - current index to modify, index_to_return - index to return after exist from pgia state
char stopped_on; // keeps char that represent the number before going to pgia state
uint num_of_completed_chars;// num of chars that had "bull"
bool pgia_state;// pgia state 


SmartGuesser(){final_result=""; temp_string=""; index=0;num_of_completed_chars=0; pgia_state=false; index_to_return=0;}

void startNewGame(int length) override ;

string guess() override;

void learn(const string& reply) override  ;


}; //end SmartGuesser class.

