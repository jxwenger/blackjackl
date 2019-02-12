//deck.cpp
//by Jack Wenger
//object to create a deck of cards
#include "card.h"
#include "deck.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

deck::deck(){
  cards=init();
}
deck::deck(int n){
  numDecks=n;
  cards=init();
}
deck::~deck(){}

//deal one hand
vector<card> deck::deal(int numDrawn){
  vector<card> hand;
  hand.push_back(draw(numDrawn));
  hand.push_back(draw(numDrawn+1));
  return hand;
}
card deck::draw(int num){
   return cards[num];
}
void deck::shuffle(){
  vector<card> temp=init();
  cards.clear();
  int sz=temp.size();
  int num;
  for(int y=0; y<sz-1;y++){
  srand(time(NULL));
  num=rand()%temp.size();
  cards.push_back(temp[num]);
  temp.erase(temp.begin()+num);
}
//for(int x=0;x<cards.size();x++)
//cout<<cards[x].name()<<endl;
}
//add cards to deck
vector<card> deck::init(){
  vector<card> ret;
  cards.clear();
  for(int x=0;x<numDecks;x++){
  ret.push_back(card(2,1,"Two of Hearts"));
ret.push_back(card(3,1,"Three of Hearts"));
ret.push_back(card(4,1,"Four of Hearts"));
ret.push_back(card(5,1,"Five of Hearts"));
ret.push_back(card(6,1,"Six of Hearts"));
ret.push_back(card(7,1,"Seven of Hearts"));
ret.push_back(card(8,1,"Eight of Hearts"));
ret.push_back(card(9,1,"Nine of Hearts"));
ret.push_back(card(10,1,"Ten of Hearts"));
ret.push_back(card(10,1,"Jack of Hearts"));
ret.push_back(card(10,1,"Queen of Hearts"));
ret.push_back(card(10,1,"King of Hearts"));
ret.push_back(card(11,1,"Ace of Hearts"));
ret.push_back(card(2,2,"Two of Diamonds"));
ret.push_back(card(3,2,"Three of Diamonds"));
ret.push_back(card(4,2,"Four of Diamonds"));
ret.push_back(card(5,2,"Five of Diamonds"));
ret.push_back(card(6,2,"Six of Diamonds"));
ret.push_back(card(7,2,"Seven of Diamonds"));
ret.push_back(card(8,2,"Eight of Diamonds"));
ret.push_back(card(9,2,"Nine of Diamonds"));
ret.push_back(card(10,2,"Ten of Diamonds"));
ret.push_back(card(10,2,"Jack of Diamonds"));
ret.push_back(card(10,2,"Queen of Diamonds"));
ret.push_back(card(10,2,"King of Diamonds"));
ret.push_back(card(11,2,"Ace of Diamonds"));
ret.push_back(card(2,3,"Two of Clubs"));
ret.push_back(card(3,3,"Three of Clubs"));
ret.push_back(card(4,3,"Four of Clubs"));
ret.push_back(card(5,3,"Five of Clubs"));
ret.push_back(card(6,3,"Six of Clubs"));
ret.push_back(card(7,3,"Seven of Clubs"));
ret.push_back(card(8,3,"Eight of Clubs"));
ret.push_back(card(9,3,"Nine of Clubs"));
ret.push_back(card(10,3,"Ten of Clubs"));
ret.push_back(card(10,3,"Jack of Clubs"));
ret.push_back(card(10,3,"Queen of Clubs"));
ret.push_back(card(10,3,"King of Clubs"));
ret.push_back(card(11,3,"Ace of Clubs"));
ret.push_back(card(2,4,"Two of Spades"));
ret.push_back(card(3,4,"Three of Spades"));
ret.push_back(card(4,4,"Four of Spades"));
ret.push_back(card(5,4,"Five of Spades"));
ret.push_back(card(6,4,"Six of Spades"));
ret.push_back(card(7,4,"Seven of Spades"));
ret.push_back(card(8,4,"Eight of Spades"));
ret.push_back(card(9,4,"Nine of Spades"));
ret.push_back(card(10,4,"Ten of Spades"));
ret.push_back(card(10,4,"Jack of Spades"));
ret.push_back(card(10,4,"Queen of Spades"));
ret.push_back(card(10,4,"King of Spades"));
ret.push_back(card(11,4,"Ace of Spades"));
}
return ret;
}
void deck::display(){
  for(int x=0;x<cards.size();x++)
   cout<<cards[x].name()<<endl;
}
vector<card> cards;
int numDecks;
