//Adam Sanden
//CSCI 490
//BlackJack hand.h
#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <vector>



class Hand {
private:
    std::vector<Card*> m_hand;
    
    //is_split should always be initialized to false
    bool m_is_split;

public:

    Hand();
    //~Hand();

    //setter and getter for split flag
    void set_is_split();
    bool get_is_split();
   
    // Add a card to the hand
    void rec_card(Card* h_card);

    //returns first card in hand
    Card* extract_card();

     // Method to get a const reference to the vector of cards
    const std::vector<Card*>& get_hand();

    // Calculate the value of the hand
    int calculate_hand_value();

    int calculate_true_value();

    // Print the cards in the hand
    void print_hand();
};




#endif