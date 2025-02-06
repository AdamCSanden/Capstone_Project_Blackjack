//Adam Sanden
//CSCI 490
//BlackJack player.cpp

#include "player.h"

// Constructor: Start with one hand
 Player::Player(bool p_bust, bool p_blackjack) {
    m_p_hands.push_back(new Hand());  // Allocate raw pointer for the first hand
    m_p_bust = p_bust;
    m_p_blackjack = p_blackjack;
}

Player::~Player() {
    for (Hand* hand : m_p_hands) {
        delete hand;
    }
    m_p_hands.clear();
}

    // Access player's hands
    const std::vector<Hand*>& Player::get_hands() {
    return m_p_hands;
}

    // Add a card to a specific hand
   void Player::give_card_to_hand(int hand_i, Card* card) {
    if (hand_i >= 0 && hand_i < static_cast<int>(m_p_hands.size())) {
        m_p_hands[hand_i]->rec_card(card);
    } else {
        std::cerr << "Invalid hand index!" << std::endl;
    }
}
    
    // Check if the player's first hand can be split
   bool Player::can_split() {
    if (m_p_hands.size() != 1) return false;  // Splitting only allowed on the initial hand
    Hand* first_hand = m_p_hands[0];
    const std::vector<Card*> cur_hand = first_hand->get_hand();
    return cur_hand.size() == 2 && cur_hand[0]->get_rank() == cur_hand[1]->get_rank();
}
    
    bool Player::get_p_bust(){
        return m_p_bust;
    }

    bool Player::get_p_blackjack(){
        return m_p_blackjack;

    }

    // Split the player's first hand into two hands
void Player::split() {
    if (!can_split()) {
        std::cerr << "Cannot split hand!" << std::endl;
        return;
    }

    Hand* first_hand = m_p_hands[0];
    const std::vector<Card*>& temp_hands = first_hand->get_hand();

    // Create two new hands with one card each
    Hand* newHand1 = new Hand();
    Hand* newHand2 = new Hand();

    newHand1->rec_card(temp_hands[0]);
    newHand2->rec_card(temp_hands[1]);

    // Replace the original hand with the two new hands
    delete first_hand;  // Free memory of the original hand
    m_p_hands.clear();
    m_p_hands.push_back(newHand1);
    m_p_hands.push_back(newHand2);
}


    // Print all hands
    void Player::print_hands() {
    for (size_t i = 0; i < m_p_hands.size(); ++i) {
        std::cout << "Hand " << i + 1 << ":\n";
        m_p_hands[i]->print_hand();
        std::cout << "Value: " << m_p_hands[i]->calculate_hand_value() << "\n\n";
    }
}