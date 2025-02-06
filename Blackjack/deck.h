//Adam Sanden
//CSCI 490
//BlackJack Deck.h

//header guards 
#ifndef DECK_H
#define DECK_H


//#include <iostream>
#include <vector>
#include <algorithm> // for std::shuffle
#include <random>    // for std::random_device and std::mt19937
#include "card.h" 

class Deck {
private:
    std::vector<Card*> m_deck;

public:
    // Constructor
    Deck();
    //destructor
    ~Deck();

    // Shuffle the deck using Mersenne twister algorithm
    void shuffle();

    // Print the deck
    //only exists for testing purposes and won't be used in the actual game
    void print_deck();

    // Deal a card (removes from the deck and returns the card)
    Card* deal_card(); 
};


#endif