#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string convertToBinary(int);



int main(int argc, char* argv[]) {
  std::cout << "Hello World!\n";
  ifstream inFile(argv[1]);
    //ifstream inFile("MaxL.asm");

  
  if(!inFile){
    cout << "There was a problem reading the file!" << endl;
  }

  // string code;
  // getline(inFile, code);
  // cout << code << endl;
  
  //while(!inFile.eof()){
  string code;
  string command;
  bool aCmd = false;
  getline(inFile, code);
  if(code[0] == '@'){
    cout << "This is an A command!" << endl;
    aCmd = true;
  }

  if(aCmd){
    stringstream binaryNumber(code.substr(1));
    int codeAsNum;
    binaryNumber >> codeAsNum;
    // string temp = convertToBinary(10);
    // cout << temp;
    //cout << codeAsNum;


    cout << convertToBinary(0);
  //  command = code.substr(1);
   // cout << command << endl;




  }
  //cout << code << endl;
  //int i = 0;
   while(code[0] != '@'){
        //cout << "Helloooo";
       inFile >> command;
       
   }
        
  //cout << code << endl;
    
  //};

 
  
  
  
  
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
    cout << binaryNumber << endl;
  }

  while(binaryNumber.size() != 16){
        string binaryHolder = "0";
        binaryHolder.append(binaryNumber);
        binaryNumber = binaryHolder;
  }

  return binaryNumber;  
}