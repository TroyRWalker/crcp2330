#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main(int argc, char* argv[]) {
  std::cout << "Hello World!\n";
  //ifstream inFile(argv[1]);
    ifstream inFile("MaxL.asm");

  
  if(!inFile){
    cout << "There was a problem reading the file!" << endl;
  }
  
  while(!inFile.eof()){
  string code;
  getline(inFile, code);
    cout << code
    
  }
 
  
  
  
  
}