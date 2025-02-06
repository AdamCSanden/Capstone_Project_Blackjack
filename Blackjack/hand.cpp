//Adam Sanden
//CSCI 490
//BlackJack hand.cpp
#include "hand.h"

//just so I'm not using a magic constant
#define FACE_VALUE 10

    /// @brief constructor just needs to initialize hand vector 
    Hand::Hand(){
        std::vector<Card*> m_hand;
    }

    /*Hand::~Hand(){
        //loop that deletes all card pointers from hand
        for (int i = 0; i < (int)m_hand.size(); i++) {
            Card* temp = m_hand.back();
            m_hand.pop_back();
            delete(temp);
        }
    }*/

    //toggle the flag to true to make sure the hand can only split once
    void Hand::set_is_split(){
        m_is_split = true;
    }

    bool Hand::get_is_split(){
        return m_is_split;
    }

    // Add a card dealt from deck to a player's hand
    void Hand::rec_card(Card* h_card) {
        m_hand.insert(m_hand.begin(), h_card);
    }
    

    const std::vector<Card*>& Hand::get_hand(){
        return m_hand;
    }

    //returns first card in hand
    Card* Hand::extract_card(){//assuming this function will not be called while hand is empty
            Card* taken_card = m_hand.back();
            m_hand.pop_back();
            return taken_card;
    }


    // Calculate the value of the hand
    int Hand::calculate_hand_value() {
        
        int total_value = 0;

        //keep track of number of aces to change their value later on
        int numAces = 0;

        for (int i = 0; i < (int)m_hand.size(); i++) {
            Card* temp = m_hand.back();
            m_hand.pop_back();
            C_Rank rank = temp->get_rank();
            //if facedown put card back into hand and don't count it
            if(temp->get_face_up() == false){
                m_hand.insert(m_hand.begin(), temp);
                continue;
            }
            //if ace value is 11 or 1 depending on if value breaks 21
            if (rank == C_Rank::ACE) {
                ++numAces;//keep track of number of aces in hand
                // Assume Ace value is 11 unless total over 21
                total_value += 11; 
            } else if (rank == C_Rank::JACK || rank == C_Rank::QUEEN || rank == C_Rank::KING) {
                total_value += FACE_VALUE;//use predefined constant
            }else {
                total_value += static_cast<int>(rank);
            }
            //put card back into hand
            m_hand.insert(m_hand.begin(), temp);
        }

        

        // if total exceeds 21 and hand has ace subtract 10 from total
        while (total_value > 21 && numAces > 0) {
            //subtract 10 from value if 
            total_value -= 10; 
            --numAces;
        }

        return total_value;
    }

    //made this at the last minute because I realized I couldn't calculate next action for dealer properly without
    //flipping the hole card to get its value and then flipping it back to not reveal it to the player.
    //used to calculate dealer's next action
    int Hand::calculate_true_value() {
        
        int total_value = 0;

        //keep track of number of aces to change their value later on
        int numAces = 0;

        for (int i = 0; i < (int)m_hand.size(); i++) {
            Card* temp = m_hand.back();
            bool flipped = false;
            if(!temp->get_face_up()){//check if card is face down
                temp->flip_card();
                flipped = true;
            }
            m_hand.pop_back();
            C_Rank rank = temp->get_rank();
            //if ace value is 11 or 1 depending on if value breaks 21
            if (rank == C_Rank::ACE) {
                ++numAces;//keep track of number of aces in hand
                // Assume Ace value is 11 unless total over 21
                total_value += 11; 
            } else if (rank == C_Rank::JACK || rank == C_Rank::QUEEN || rank == C_Rank::KING) {
                total_value += FACE_VALUE;//use predefined constant
            }else {
                total_value += static_cast<int>(rank);
            }
            if(flipped){
                temp->flip_card();
            }
            //put card back into hand
            m_hand.insert(m_hand.begin(), temp);
        }

        

        // if total exceeds 21 and hand has ace subtract 10 from total
        while (total_value > 21 && numAces > 0) {
            //subtract 10 from value if 
            total_value -= 10; 
            --numAces;
        }

        return total_value;
    }

    

    // Print the cards in the hand
    
    void Hand::print_hand() {
        for (const auto& card : m_hand) {
             card->print_card();
        }
    }
