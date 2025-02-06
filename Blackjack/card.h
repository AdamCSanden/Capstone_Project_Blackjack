//Adam Sanden
//CSCI 490
//BlackJack card.h

//header guards
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

/*enumerated types for Rank and Suit*/
enum class C_Rank {
    ACE = 1, //start from 1 instead of 0
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, 
};

enum class C_Suit {
    HEARTS, DIAMONDS, CLUBS, SPADES
};

// Card class definition
class Card {
private:
    C_Rank m_rank;//rank portion of the card
    C_Suit m_suit;//suit portion of the card
    bool m_face_up;//whether card is face up or face down; used for hole card

public:
    // Constructor
    Card(C_Rank r, C_Suit s, bool fu) : m_rank(r), m_suit(s), m_face_up(fu) {}

    // Get the rank of the card
    C_Rank get_rank();

    // Get the suit of the card
    C_Suit get_suit();

    // Get the state of the card
    bool get_face_up();

    //changes state of card
    void flip_card();

    // Convert rank to string
    std::string rank_to_string();

    // Convert suit to string
    std::string suit_to_string();

    // Get a string representation of the card
    void print_card(); 
};

#endif