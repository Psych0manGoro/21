#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

//functions
void playGame();
void genNewDeck(int deck[]);
void shuffleDeck(int deck[]);
void dealDeck(int deck[]);
int arraySum(vector<int> & arr);

int main(){
  std::random_device rd;
  srand(time(0));
  
  cout << "Welcome Clancy, Lets play a game:\n";
  playGame();
  return 0;
}

void genNewDeck(int* deck){
    for (int i = 0; i < 11; i++){
      deck[i] = i + 1;
    }
 }

 void shuffleDeck(int deck[]){
  std::shuffle(deck, deck + 11, std::mt19937(std::random_device{}()));
}

void dealDeck(int deck[]){
  vector<int> player_deck;
	vector<int> hoffman_deck;

  int deckPosition = 0;

  player_deck.push_back(deck[deckPosition++]);
  hoffman_deck.push_back(deck[deckPosition++]);

  player_deck.push_back(deck[deckPosition++]);
  hoffman_deck.push_back(deck[deckPosition++]);
}

int arraySum(vector<int> & arr){
  int sum = 0;

  for (int i = 0; i < arr.size(); i++){
    sum += arr[i];
  }

  return sum;

  //std::accumulate(int, arr[i]);
} 

 
void playGame(<vector>player_deck & <vector>hoffman_deck){
  int deck[11];
  genNewDeck(deck);
  
  //TODO: Make sure to add turn system.

  //shuffle
  shuffleDeck(deck);
  //deal the deck
  dealDeck(deck);
/*
  vector<int> player_deck;
	vector<int> hoffman_deck;

  int deckPosition = 0;

  player_deck.push_back(deck[deckPosition++]);
  hoffman_deck.push_back(deck[deckPosition++]);

  player_deck.push_back(deck[deckPosition++]);
  hoffman_deck.push_back(deck[deckPosition++]);
*/

  //TODO Need to abstract my output to a method to display current game data.
  cout << "Player: "
         << player_deck[0] << " " //TODO: error: ‘player_deck’ was not declared in this scope <- Make sure to figure out why the print statements don't work for bopth player deck and hoffman_deck.
         << player_deck[1] << '\n';

  cout << "Hoffman: "
      << hoffman_deck[0]
      << "[CARD]\n";

  int player_total = arraySum(player_deck);
  int hoffman_total = arraySum(hoffman_deck);

  string choice;

  //Player Logic
  while (player_total < 21) {
    std::cout << "Hit or Stay?";
    std::cin >> choice;
    if (choice == "Hit") {
      player_deck.push_back(deck[deckPosition++]); //TODO: 'deckPosition’ was not declared in this scope, not declared in the method need to find out how to get deckPosition or an alternative to get the position of the deck.
    }
    else {
      break;
    }
  }

  //CPU Turn Logic
  while (hoffman_total < 17){
    hoffman_deck.push_back(deck[deckPosition++]);
    if(hoffman_total >= 17){
      break;
    }
  }

  //determine winner
  if (player_total > 21) {
    std::cout << "Loser";
  }
  else if (hoffman_total > 21) {
    std::cout << "Winner";
  }
  else if (player_total > hoffman_total) {
    std::cout << "Winner";
  }
  else if (player_total < hoffman_total) {
    std::cout << "Loser";
  }
  else {
    std::cout << "Tied";
  }
}

