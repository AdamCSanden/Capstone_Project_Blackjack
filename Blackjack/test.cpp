#include "card.h"
#include "deck.h"
#include <iostream>
#include "hand.h"
#include "player.h"
#include "dealer.h"



// test flip functionality
/*int main() {
    Card* test_card = new Card(C_Rank::ACE, C_Suit::SPADES, false);
    test_card->print_card();
    test_card->flip_card();
    test_card->print_card();
    free(test_card);


    return 0;
}*/

//shuffle test
/*int main() {
    Deck deck;
    std::cout << "Original deck:\n";
    deck.print_deck();

    std::cout << "\nShuffling deck...\n";
    deck.shuffle();

    std::cout << "Shuffled deck:\n";
    deck.print_deck();

    std::cout << "\nDealing a card...\n";
    Card* dealt_card = deck.deal_card();
    dealt_card->print_card();
    free(dealt_card);

    return 0;
}*/


/*int main() {
    Deck deck;
    
    deck.print_deck();

    std::cout << "\nShuffling deck...\n";
    deck.shuffle();

    std::cout << "Shuffled deck:\n";
    deck.print_deck();

    std::cout << "\nDealing a card...\n";
    Card* dealt_card = deck.deal_card();
    dealt_card->print_card();
    free(dealt_card);

    return 0;
}*/

//test for hand functionality
/*int main() {
    Hand hand;

    // Create some cards
    Card* card1 = new Card (C_Rank::ACE, C_Suit::SPADES, true);
    Card* card2 = new Card (C_Rank::KING, C_Suit::HEARTS, true);
    Card* card3 = new Card (C_Rank::SEVEN, C_Suit::DIAMONDS, false);

    // Add cards to the hand
    hand.rec_card(card1);
    hand.rec_card(card2);
    hand.rec_card(card3);

    // Display the hand
    std::cout << "Hand:\n";
    hand.printHand();

    // Calculate and display the hand value
    std::cout << "\nValue of hand: " << hand.calculate_value() << std::endl;

    hand.~Hand();

    

    return 0;
}*/

int main() {
    
    Player player(false,false);

    // Create some cards
    Card* card1 = new Card(C_Rank::EIGHT, C_Suit::SPADES, true);
    Card* card2 = new Card(C_Rank::EIGHT, C_Suit::HEARTS, true);

    // Add cards to the player's hand
    player.give_card_to_hand(0, card1);
    player.give_card_to_hand(0, card2);

    // Display the player's hand
    std::cout << "Player's hands before split:\n";
    player.print_hands();

    // Check if splitting is possible
    if (player.can_split()) {
        std::cout << "Splitting the hand...\n";
        player.split();
    } else {
        std::cout << "Cannot split the hand.\n";
    }

    // Display the player's hands after splitting
    std::cout << "Player's hands after split:\n";
    player.print_hands();

    std::cout<<"checking bust flag: "<< player.get_p_bust()<< std::endl;
    std::cout<<"checking blackjack flag: "<< player.get_p_blackjack()<< std::endl;


    delete(card1);
    delete(card2);

    return 0;
}

/*int main() {
    Dealer dealer(false);

    // Simulate dealing cards to the dealer
    Card* card1 = new Card (C_Rank::TEN, C_Suit::HEARTS, true);
    Card* card2 = new Card (C_Rank::SIX, C_Suit::SPADES, true);
    Card* card3 = new Card (C_Rank::FIVE, C_Suit::DIAMONDS, true);

    // Add cards to the dealer's hand
    dealer.add_dealer_card(card1);
    dealer.add_dealer_card(card2);

    // Print the dealer's hand and action
    dealer.print_dealer_hand();
    std::cout << "Dealer's action: " << dealer.determine_action() << "\n";

    // Simulate adding another card and check action again
    dealer.add_dealer_card(card3);
    dealer.print_dealer_hand();
    std::cout << "Dealer's action: " << dealer.determine_action() << "\n";
    std::cout << "checking bust flag: "<< dealer.get_d_bust() << std::endl;




    return 0;
}*/