#include "SmartGuesser.hpp"
#include<iostream>
#include<string>


void SmartGuesser::startNewGame(int length){
this->length=length;
//reset variables

final_result=""; 
temp_string="";
index=0, index_to_return=0;
num_of_completed_chars=0;
pgia_state=false;

//initialize strings with '/' - one place before numbers in ASCII table
for (int i = 0; i < length; i++)
{
temp_string+='/';
final_result+='/';
}//end for
}//end startNewGame function

string SmartGuesser::guess(){

if(num_of_completed_chars==length){ //if got legth Bulls.
    return final_result;
}

else if(pgia_state){ //we the have to right char - trying to seek for the right index

   while(true){
        if(final_result[++index]=='/') //try to modify only chars that not numbers
        break;
   }

   temp_string[index]=stopped_on; // update the value the caused the pdia state

return temp_string;
}

else { //existing from bull and there can be two states:

//first - need to return and modify an index after finishing the bull state
        if(final_result.at(index_to_return)=='/'&&num_of_completed_chars>0){ 
            
            temp_string.at(index_to_return)=++stopped_on; // continue right where stopped before pgia state
            index=index_to_return;// updating the current index
        }
//second - got a Bull not after pgia state - regular state

    else
      temp_string.at(index)++;
      
   return temp_string;
}

}

void SmartGuesser::learn(const string& reply){

if(reply.at(0)==(char)num_of_completed_chars+48+1){//castring num_of_completed_char - to char value +1 
//checking if it is a Bull state

    final_result[index]=temp_string[index];// updating the result string
    num_of_completed_chars++;
    index=final_result.find_first_of('/'); // finding next first char in result that need to guess
    pgia_state=false;

 
}//end if

else if(reply.at(2)=='1'){ //if it's not Bull - maybe it's a Pgia

    if(!pgia_state){//first time we get pgia
         if((length-num_of_completed_chars) < (temp_string[index]-48+1)){//check if it worth to seek for Pgia
                pgia_state=true;// Pgia state start
                index_to_return=index;//after finishing with Pgia - continue from where we stopped
                stopped_on=temp_string[index];//keep the value that we stopped on
                temp_string[index]='/';//current index outputs Pgia and not Bull - need to initialize it
         }
}
else//not the first time we get Pgia
    temp_string[index]='/';//not the index that we want so initilize it.
} 
}


