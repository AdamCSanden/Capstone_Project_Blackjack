//Adam Sanden
//CSCI 490
//BlackJack card.cpp

#include "card.h"
      
    /********/
    /*getters*/
    /********/

    /// @return return enumerated rank of card
    C_Rank Card::get_rank(){
        return m_rank;
    }
    
    /// @return enumerated suit of card
    C_Suit Card::get_suit(){
        return m_suit;
    }
    
    /// @return returns whether card is face up or face down
    bool Card::get_face_up(){
        return m_face_up;
    }
    /// @brief toggles whether the card is face up or face down
    void Card::flip_card(){
        if (m_face_up == true)
            m_face_up = false;
        else if (m_face_up == false)
            m_face_up = true;
    }

    /// @brief converts enumerated rank into single character string 
    /// @return suit portion of printed card string
    std::string Card::rank_to_string(){
        std::string rnk;
        switch (m_rank) {
            case C_Rank::ACE: rnk = "A";
            break;
            case C_Rank::TWO: rnk = "2";
            break;
            case C_Rank::THREE: rnk = "3";
            break;
            case C_Rank::FOUR: rnk = "4";
            break;
            case C_Rank::FIVE: rnk = "5";
            break;
            case C_Rank::SIX: rnk = "6";
            break;
            case C_Rank::SEVEN: rnk = "7";
            break;
            case C_Rank::EIGHT: rnk = "8";
            break;
            case C_Rank::NINE: rnk = "9";
            break;
            case C_Rank::TEN: rnk = "10";
            break;
            case C_Rank::JACK: rnk = "J";
            break;
            case C_Rank::QUEEN: rnk = "Q";
            break;
            case C_Rank::KING: rnk = "K";
            break;
            default: rnk = "Invalid Rank";
        }
        return rnk;
    }


    /// @brief converts enumerated suit type to single character string
    /// @return suit portion of printed card string
    std::string Card::suit_to_string(){
        std::string sut;
        switch (m_suit) {
            case C_Suit::HEARTS: sut = "H";
            break;
            case C_Suit::DIAMONDS: sut = "D";
            break;
            case C_Suit::CLUBS: sut = "C";
            break;
            case C_Suit::SPADES: sut = "S";
            break;
            default: sut = "Invalid Suit";
        }
        return sut;
    }
    /// @brief prints card object
    void Card::print_card() {
    if(!m_face_up)
        //dealer's first card is meant to be hidden
        std::cout << "[**]";
    else
        std::cout << "[" <<  rank_to_string() << suit_to_string() << "]";
    }