//Adam Sanden
//CSCI 490
//BlackJack player.h
#ifndef PLAYER_H
#define PLAYER_H

// I think I did actually fix splitting, during finals week, which can be seen in the test.cpp file
//but I would have to rewrite large portions of Blackjack.cpp to fully check if its working

#include "hand.h"
#include <iostream>
#include <memory>
#include <vector>

// Player Class
class Player {
private:
    std::vector<Hand*> m_p_hands; // Each player can have multiple hands after splitting
    bool m_p_bust;
    bool m_p_blackjack;
public:
    // Constructor
    Player(bool p_bust, bool p_blackjack);

    ~Player();

    /// @brief allow access to player hands vector
    /// @return vector of player's hand objects
    const std::vector<Hand*>& get_hands();

    bool get_p_bust();

    bool get_p_blackjack();

    /// @brief takes a passed pointer to a card object and inserts it into the desired hand
    /// @param hand_i //hand index
    /// @param card //pointer to card object
    void give_card_to_hand(int hand_i, Card* card);

    /// @brief checks if splitting is possible by checking hand size and if the rank of both cards is the same
    /// @return returns flag to allow splitting
    bool can_split();
    

    /// @brief splits player's hand of 2 cards into 2 hands that hold 1 card
    void split();


    /// @brief prints out all of player's hands
    void print_hands();

};

#endif