#include <iostream>
#include <string>

using namespace std;

int badsymbol[256];

void preprocess(string pattern){
  for(int i=0; i<256; i++)
    badsymbol[i] = pattern.length();

  for(int i=0; i<pattern.length()-1; i++){
    badsymbol[pattern.at(i)] = pattern.length()-i-1;
  }
}

int horspool(string text, string pattern){
  preprocess(pattern);
  int start = pattern.length()-1;

  int check;
  while(start < text.length()){

    for(check = start; (start-check) < pattern.length(); check--){
      if(pattern.at(pattern.length()-(start-check)-1) != text.at(check))
        break;
    }

    if((start-check) >= pattern.length())
      return start-pattern.length()+1;

    start = start + (badsymbol[text.at(start)]);
  }
  return -1;
}

int main(){
  string text = "hellomanipal";
  string pattern = "manp";
  cout<<horspool(text, pattern);
  return 0;
}
