//Adam Sanden
//CSCI 490
//BlackJack deck.cpp

#include "deck.h"
#include <vector>

/******************************
* Deck Class member functions *
*******************************/
    
    /// @brief creates a deck of 52 cards for each rank and suit combination
    Deck::Deck() {
        for (int s = (int)(C_Suit::HEARTS); s <= (int)(C_Suit::SPADES); ++s) {
            for (int r = (int)(C_Rank::ACE); r <= (int)(C_Rank::KING); ++r) {
                Card* temp = new Card((C_Rank) r, (C_Suit) s, true); 
                m_deck.push_back(temp);
            }
        }
    }
    /// @brief frees all card pointers in deck
    Deck::~Deck() {
        for (int i = 0; i < (int)m_deck.size(); i++) {
            Card* temp = m_deck.back();
            m_deck.pop_back();
            delete(temp);
        }
    }

    // Shuffle the deck using Mersenne twister algorithm
    void Deck::shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(m_deck.begin(), m_deck.end(), g);
    }

    // Print the deck
    //only exists for testing purposes and won't be used in the actual game
    void Deck::print_deck() {
        //for loop that reads every card in the deck and then reinserts
        //it back into the deck in the same order
        for (int i = 0; i < (int)m_deck.size(); i++) {
            Card* temp = m_deck.back();
            m_deck.pop_back();
            temp->print_card();
            m_deck.insert(m_deck.begin(), temp);
        }
    }

    // Deal a card (removes from the deck and returns the card)
    Card* Deck::deal_card() {
        if (m_deck.empty()) {
            throw std::runtime_error("No cards left to deal!");
        }
        Card* dealtCard = m_deck.back();
        m_deck.pop_back();
        return dealtCard;
    }
