//Adam Sanden
//CSCI 490
//BlackJack dealer.h
#ifndef DEALER_H
#define DEALER_H

#include <vector>
#include "hand.h"
#include "card.h"




class Dealer {

private: 
   Hand m_d_hand;// The dealer has a single hand and can't split
   bool m_d_bust;

public:

    //constructor
    Dealer(bool d_bust);
    
    //destructor
   // ~Dealer();

    //access dealer's bust status
    bool get_d_bust();

    //set bust flag to true when dealer busts
    void set_d_bust();

    // Add a card to the dealer's hand
    void add_dealer_card(Card* card);

    // Get the dealer's hand value
    int get_hand_value();

    //shows actual dealer hand value
    int get_true_hand_value();

    // Determine the dealer's next action
    char determine_action();

    //flips hold code for final hand reveal
    void reveal_hole_card();

    // Print the dealer's hand
    void print_dealer_hand();
};



#endif
