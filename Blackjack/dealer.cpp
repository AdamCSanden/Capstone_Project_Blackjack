//Adam Sanden
//CSCI 490
//BlackJack dealer.cpp
#include "dealer.h"


Dealer::Dealer(bool d_bust){
    Hand m_d_hand;
    m_d_bust = d_bust;
}

//call hand destructor
/*Dealer::~Dealer(){
    m_d_hand.~Hand();
}*/


bool Dealer::get_d_bust(){
    return m_d_bust;
}

void Dealer::set_d_bust(){
    m_d_bust = true;
    
}

void Dealer::add_dealer_card(Card* card) {
        m_d_hand.rec_card(card);

    }

    // Get the dealer's hand value
    int Dealer::get_hand_value() {
        int value = m_d_hand.calculate_hand_value();
        return value;
         
    }

    //used to find hidden total hand value for dealer's hand
    int Dealer::get_true_hand_value() {
        int value = m_d_hand.calculate_true_value();
        return value;
         
    }


    // Determine the dealer's next action
    char Dealer::determine_action() {
        int value = get_true_hand_value();
        if (value < 17) {
            return 'h';//dealer must hit if hand value is 16 or under
        } else {
            return 's';//dealer must stand if hand value
        }
    }

    void Dealer::reveal_hole_card(){
        Card* temp = m_d_hand.extract_card();
        if(!temp->get_face_up()){
            temp->flip_card();
        }
        m_d_hand.rec_card(temp);

    }

    // Print the dealer's hand
    void Dealer::print_dealer_hand() {
        std::cout << "Dealer's hand:\n";
        m_d_hand.print_hand();
        //std::cout << "Dealer value: " << get_hand_value() << "\n";
    }