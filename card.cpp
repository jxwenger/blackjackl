//card.cpp
//by Jack Wenger
#include "card.h"
#include <string>
card::card(){}
card::card(int v,int s,std::string n){
  st = s;
  val=v;
  txt=n;
}
card::~card(){}
int card::suit(){
  return st;
}
int card::value(){
  return val;
}
std::string card::name(){
  return txt;
}

int st;
int val;
std::string txt;
