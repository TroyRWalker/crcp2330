//everything is read correctly, I just ran out of time to make a 
//table to convert the command into the correct binary number
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string convertToBinary(int);
string determineComp(string);




int main(int argc, char* argv[]) {
  //std::cout << "Hello World!\n";
  ifstream inFile(argv[1]);
    //ifstream inFile("MaxL.asm");

  
  if(!inFile){
    cout << "There was a problem reading the file!" << endl;
  }

  // string code;
  // getline(inFile, code);
  // cout << code << endl;
  
  while(!inFile.eof()){
  string code;
  string command;
  bool aCmd = false;
  getline(inFile, code);
 
  if(code[0] == '@'){
    //cout << "This is an A command!" << endl;
    aCmd = true;
  }

  if(aCmd){
    stringstream binaryNumber(code.substr(1));
    int codeAsNum;
    binaryNumber >> codeAsNum;
    // string temp = convertToBinary(10);
    // cout << temp;
    //cout << codeAsNum;


    cout << convertToBinary(codeAsNum) << endl;
  //  command = code.substr(1);
   // cout << command << endl;




  }
  else{
    string cCmd = "111";
    string a = "";
    string comp = "";
    string dest = "";
    string jump = "";
    int indexOfEquals = 0;
    int indexOfJump = 0;
    for(int i = 0; i < code.size(); i++){
      if(code[i] == '='){
        indexOfEquals = i;
    
  }
    }
    if(indexOfEquals != 0){
    //cout << indexOfEquals << endl;
    for(int i = 0; i < indexOfEquals; i++){
     // cout << i << endl;
      dest += code[i];
    
  
    }
    //cout << dest;
    for(int i = indexOfEquals + 1; i < code.size(); i++){
     // cout << i << endl;
      comp += code[i];
        if(code[i] == 'A'){
        a = "0";
    
  }
      if(code[i] == 'M'){
        a = "1";
    
  }
    
  
    }
    //cout << comp << endl;

    }else{
    for(int i = 0; i < code.size(); i++){
      if(code[i] == ';'){
        indexOfJump = i;
    
  }
    }
    for(int i = 0; i < indexOfJump; i++){
      //cout << i << endl;
      comp += code[i];
    
  
    }

    //cout << comp;

    for(int i = indexOfJump; i < code.size(); i++){
      //cout << i << endl;
      jump += code[i];
    
  
    }

    //cout << jump << endl;
}



    //cout << indexOfEquals << endl;


  //cout << "Comp: "  << determineComp(comp) << endl;
cout << cCmd << a << determineComp(comp) <<endl;
  }



  //cout << code << endl;
  //int i = 0;
   // while(code[0] != '@'){
   //      //cout << "Helloooo";
   //     inFile >> command;
       
   // }
        
  //cout << code << endl;
    
  };

 
  
  
  
  
}

string convertToBinary(int integerNumber){
  string binaryNumber = "";

  while(integerNumber != 0){
    string binaryHolder = "";
    if( integerNumber % 2 == 0){
        binaryHolder = "0";
        binaryHolder.append(binaryNumber);
        binaryNumber = binaryHolder;
    }else{
      binaryHolder = "1";
        binaryHolder.append(binaryNumber);
        binaryNumber = binaryHolder;
    }
    integerNumber = integerNumber / 2;
    //cout << binaryNumber << endl;
  }

  while(binaryNumber.size() != 16){
        string binaryHolder = "0";
        binaryHolder.append(binaryNumber);
        binaryNumber = binaryHolder;
  }

  return binaryNumber;  
}
string determineComp(string comp){
  //cout << "entering comp: " << comp << endl;
  if(comp == "0"){
    return "101010";
  }
  if(comp == "1"){
    return "111111";
  }
  if(comp == "-1"){
    return "111010";
  }
  if(comp == "D"){
    return "001100";
  }
  if(comp == "A"){
    return "110000";
  }
  if(comp == "M"){
    return "110000";
  }
  if(comp == "!D"){
    return "001101";
  }
  if(comp == "!A"){
    return "110011";
  }
  if(comp == "!M"){
    return "110011";
  }
  if(comp == "D+1"){
    return "011111";
  }
  if(comp == "A+1"){
    return "110111";
  }
  if(comp == "M+1"){
    return "110111";
  }
  if(comp == "D-1"){
    return "001110";
  }
  if(comp == "A-1"){
    return "110010";
  }
  if(comp == "M-1"){
    return "110010";
  }
  if(comp == "D+A"){
    return "000010";
  }
  if(comp == "D+M"){
    return "000010";
  }
  if(comp == "D-A"){
    return "010011";
  }
  if(comp == "D-M"){
    return "010011";
  }
  if(comp == "A-D"){
    return "000111";
  }
  if(comp == "M-D"){
    return "000111";
  }
  if(comp == "D&A"){
    return "000000";
  }
  if(comp == "D&M"){
    return "000000";
  }
  if(comp == "D|A"){
    return "010101";
  }
  if(comp == "D|M"){
    return "010101";
  }
  return "Something went wrong";
}

