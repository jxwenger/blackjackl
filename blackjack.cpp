//prject.cpp
//by Jack Wenger
//program to run a text based blackjack game for up to five players
#include <iostream>
using namespace std;
#include "card.h"
#include "deck.h"
#include <string>
#include <vector>
int play(deck d, vector<card> hand);
int handValue(vector<card> hand);
int dealerPlay(deck d, vector<card> hand);
int compare(int plrtype, int plrVal, int dealer);
int payout(int winCode, int bet);
vector<vector<card> > deal(deck d, int plyr);

int numDrawn;


int main(){
  cout<<"how many people are playing? "<<endl;
  int numPlayers;
  numDrawn=0;
  int numDecks=1;
  cin>>numPlayers;
  while(numPlayers>5){
    cout<<"Maximum 5 players"<<endl;
    cin>>numPlayers;
  }
  deck d(numDecks);
  char cont='y';
  vector<float> money;
  for(int x=0;x<numPlayers;x++){
    money.push_back(100);
  }
//take in bets
while(cont=='y'){
vector<int> bets;
int bet;
for(int x=0;x<numPlayers;x++){
  cout<<"Plaver "<<x+1<<" How much would you like to bet? "<<endl;
  cin>>bet;
  while(bet>money[x]){
    cout<<"You do not have that much money, enter valid bet"<<endl;
    cin>>bet;
  }
  bets.push_back(bet);
}
d.shuffle();
//burn first card
d.draw(numDrawn);
numDrawn++;
// deal hands
vector<vector<card> > hands;
hands=deal(d, numPlayers);
char choice;
vector<int> insurance;
vector<int> handtype;//code for comparing hand results
//take insurance bets
for(int x=0;x<numPlayers;x++){
  cout<<"Player "<< x+1<<endl;
  //if(hands[numPlayers][0].value()==11){
    cout<<"Dealer is showing an ace, would you like to buy insurance?[i]"<<endl;
    cin>>choice;
    if(choice=='i'){
    int bet2;
    cout<<"How much would you like to bet?"<<endl;
    cin>>bet2;
    while(bet2>bets[x]/2){
      cout<<"Bet may not be more than half of the original"<<endl;
      cin>>bet2;
    }
    while(bet2>money[x]-bets[x]){
      cout<<"You do not have that much money, enter valid bet"<<endl;
      cin>>bet2;
    }
    insurance.push_back(bet2);
    //}
  }
  //else
    //insurance.push_back(0);
    //store player hand results
  if(handValue(hands[x])==21){
    cout<<"BlackJack!"<<endl;
    handtype.push_back(2);
  }
  else{
    cout<<endl;
    handtype.push_back(play(d, hands[x]));
  }
  cout<<endl;
  }
  int dealerVal=dealerPlay(d,hands[numPlayers]);
  for(int x=0;x<numPlayers;x++){
    int code, pay;
    //payout for split
    if(handtype[x]>9){
      code = compare(handtype[x]%10,handValue(hands[x]),dealerVal);
      pay = payout(code,bets[x]);
      code = compare(handtype[x]/10,handValue(hands[x]),dealerVal);
      pay += payout(code,bets[x]);
    }
    //payout for rest
    else{
    code = compare(handtype[x],handValue(hands[x]),dealerVal);
    pay = payout(code,bets[x]);
    }
    if(handtype[x]==5)
      money[x]+=pay/2;
    else if(handtype[x]==3||handtype[x]==4)
    money[x]+=pay*2;
    else
    money[x]+=pay;
    if(insurance[x]!=0){
      if(dealerVal==22)
      money[x]+=insurance[x]*2;
      else
      money[x]-=insurance[x];
    }
    cout<< "Player "<<x+1<<" now has $"<<money[x]<<endl;
    if(money[x]<=0){
      cout<<"You are out of money, go sleep it off in an alley"<<endl;
      cout<<"Player "<<x+2<<" is now player "<<x+1;
      money.erase(money.begin()+x);
      x--;
      numPlayers--;
    }
  }
  cout<<"Would you like to play again [y],[n]"<<endl;
  cin>>cont;

}
  return 0;
}
//allow users to play game
  int play(deck d, vector<card> hand){
    char choice;
    cout<< "Would you like to hit[h], stay[s], split[p], double[d], or surrender[u]?"<<endl;
    cin>>choice;
    switch(choice){
    case 'h':
    while(choice == 'h'){
    card c = d.draw(numDrawn);
    numDrawn++;
    cout<<c.name()<<endl;
    hand.push_back(c);
    if(handValue(hand)>21){
      cout<<"You are bust"<<endl;
      return 0;
    }
    else{
      cout<<"would you like to hit again[h], or stay[s]?"<<endl;
      cin>>choice;
      //choice='s';
    }
    }
    cout<<"Your hand value: " <<handValue(hand)<<endl;
    return 1;
    break;
    case 's':
    cout<<"Your hand value: " <<handValue(hand)<<endl;
    return 1;
    break;
    case 'p':
    if(hand[0].value()==hand[1].value()){
    vector<card> hand2, hand3;
    hand2.push_back(hand[0]);
    hand2.push_back(d.draw(numDrawn));
    numDrawn++;
    hand3.push_back(hand[1]);
    hand3.push_back(d.draw(numDrawn));
    numDrawn++;
    cout<<"Hand 1\n"<<hand2[0].name()<<"\n"<<hand2[1].name()<<"\nHand 2\n"<<hand3[0].name()<<"\n"<<hand3[1].name()<<endl;
    //recursice calls for the two new a hands
    int v1= play(d, hand);
    int v2=play(d, hand2);
    return v1*10+v2;
  }
    else
    cout<<"You must have matching cards to split"<<endl;
    break;
    case 'd':
    hand.push_back(d.draw(numDrawn));
    numDrawn++;
    cout<<hand[2].name()<<endl;
    if(handValue(hand)<21)
    return 3;
    else{
      cout<<"You are bust"<<endl;
      return 4;
      }
    break;
    case 'u':
    return 5;
    break;
    default:
    return 1;
}
  return 0;
}
//deal in all players and the dealer
vector<vector<card> > deal(deck d, int plyr){
  vector<vector<card> > hands;
  for(int x=0;x<plyr;x++){
    hands.push_back(d.deal(numDrawn));
    numDrawn+=2;
    cout<<"Player "<<x+1<<"\n"<<hands[x][0].name()<<"\n"<<hands[x][1].name()<<endl;
  }
  //dealer
  hands.push_back(d.deal(numDrawn));
  numDrawn+=2;
  cout<<"Dealer shows "<<hands[plyr][0].name()<<endl;
  return hands;
}
//calculate the total number of points for a hand
int handValue(vector<card> hand){
  int ret=0;
  int numAces=0;
  for(int x=0;x<hand.size();x++){
    if(hand[x].value()<11)
    ret+=hand[x].value();
    else if(hand[x].value()==11){
      ret+=11;
      numAces++;
    }
  }
  while(ret>21&&numAces>0){
    ret-=10;
    numAces--;
  }
  return ret;
}
//dealer rules, always stay on 17
int dealerPlay(deck d, vector<card> hand){
  if(handValue(hand)==21){
    cout<<"dealer has blackjack"<<endl;
    return 22;
}
  while(handValue(hand)<17){
  hand.push_back(d.draw(numDrawn));
  numDrawn++;
}
  if(handValue(hand)<22){
    cout<<"Dealer has " <<handValue(hand)<<endl;
  return handValue(hand);
  }
  else{
    cout<<"Dealer busts"<<endl;
  return 0;
}
  return 0;
}
//compare hand types
int compare(int plrtype, int plrVal, int dealer){
  /*
  3= tie
  2 = player blackjack
  1= player win
  0 = dealer win */
  if(dealer==22){
  if(plrtype==2)
  return 3;
  else
  return 0;
  }
  else if(plrtype==0||plrtype==4||plrtype==5)
  return 0;
  else if(plrtype==2)
  return 2;
  else if(dealer>plrVal)
  return 0;
  else if(dealer==plrVal)
  return 3;
  else
  return 1;
  return 0;
}
//determine how much to pay
int payout(int winCode, int bet){
  switch(winCode){
    case 0:
    return bet*-1;
    break;
    case 1:
    return bet;
    case 2:
    return bet*1.5;
    case 3:
    return 0;
  }
  return 0;
}
