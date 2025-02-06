//Adam Sanden
//CSCI 490
//BlackJack blackjack.cpp

//#include "player.h"
#include "deck.h"
#include "dealer.h"
#include "hand.h"

/*
I apologize in advance for this file being a mess. I didn't start coding this until the day before it was due
I had all of the classes working and independently tested the day before, but when I put it all together i realized
the player class was not able to calculate the score, in trying to fix it I broke the spitting mechanic in the player class
as a result I'm scrapping that whole class at the eleventh hour and just going to use the hand class instead
the code here is a mess because I'm scrambling to get something resembling blackjack working before the presentation tomorrow
or I guess its technically today now.
*/

//Spliting broke on me the day before presentation and I don't know how to fix it
//scrapped entire player class because splitting doesn't work anyway and I'm basically out of time

//update splitting might be fixed


bool debug= false;
std::string actions(int dealt){
	if(dealt == 2){ 
		//if(split==true){
		//	return "Actions: Hit(h), Stand(s), Double Down(d), Split(p)";
        return "Actions: Hit(h), Stand(s), Double Down(d)";
	}
    return "Actions: Hit(h), Stand(s)"; 
}



int main(){

	char play;
	
	double bet;
	double min_bet = 1.00;
	std::string buffer = std::string(80,'~');

    
	std::cout<<"Would you like to play to Blackjack (y/n).\n";
	std::cin >> play;


	std::cout<<buffer<<std::endl;

    //I know this should be separated up into functions, but I ran out of time

    //cut out the outermost while loop
	//while(play == 'y'){
        char action = 'n';//initialize action to something
        //play = 'w';
        //reset to false at the beginning of each 
        bool double_down = false;
        int cur_value = 0;
		//flag to break out of action loop if hand value surpasses 21
		bool bust = false;
		//flag to stand if opening player's opening hand is exactly 21
		bool blackjack = false;

        int dealt = 0;//keeps track of how many cards are dealt to the player
		std::cout<<"creating deck.\n";
		Deck card_deck;
		std::cout<<"shuffling deck\n";
		card_deck.shuffle();

		std::cout << "place your bet. (minimum bet is " << min_bet << "$)\n";
		std::cin >> bet;
		//Player player(false,false);//initialize bust flag and blackjack flags to false
        Hand player; 
		Dealer dealer(false);//initialize bust flag to false
		Card* player_temp1 = card_deck.deal_card();
		player.rec_card(player_temp1);
		if(debug){
            std::cout<<"Player's hand: \n";
			player.print_hand();
            cur_value = player.calculate_hand_value();
            std::cout<<"\nplayer value: " << cur_value << "\n\n"; 
            std::cout<<"\n\n";
		}
		Card* dealer_temp1 = card_deck.deal_card();
        dealer_temp1->flip_card();
        //dealer hole card
		dealer.add_dealer_card(dealer_temp1);
		if(debug){
			dealer.print_dealer_hand();
            std::cout << "Dealer value: " << dealer.get_hand_value() << "\n";
            std::cout<<"\n\n";
		}
		dealt++;

		Card* player_temp2 = card_deck.deal_card();
		player.rec_card(player_temp2);
        dealt++;
        std::cout<<"Player's hand: \n";
		player.print_hand();
        cur_value = player.calculate_hand_value();
        std::cout<<"player value: " << cur_value << "\n\n"; 
        //player.calculate_hand_value();

        std::cout<<"\n\n";

        //if the initial player hand has a value of 21 its blackjack
        if(player.calculate_hand_value() == 21){
            blackjack = true;
        }

		Card* dealer_temp2 = card_deck.deal_card();
		//dealer_temp2->flip_card();
		dealer.add_dealer_card(dealer_temp2);
		dealer.print_dealer_hand();
        std::cout << "Dealer value: " << dealer.get_hand_value() << "\n";
        std::cout<<"\n\n";
		

		std::string temp_action_string;
		//temp_action_string = actions(dealt, player.can_split());
        temp_action_string = actions(dealt);
		//actions(dealt, player.can_split());
        actions(dealt);
		while(action != 's' && bust != true && blackjack != true){
            //std::cout << temp_action_string << "\n\n";
            if(double_down == true){
                std::cout << "player must stand after doubling down";
                break;
            }
            temp_action_string = actions(dealt);
            std::cout << temp_action_string << "\n\n";
            std::cin >> action;
            if(action == 'h'){
                Card* player_temp_loop = card_deck.deal_card();
		        player.rec_card (player_temp_loop);
                dealt++;
                int temp_value = player.calculate_hand_value();
                std::cout<<"Player's hand: \n";
                player.print_hand();
                std::cout<<"\n";
                std::cout<<"Player's value: "<< temp_value <<std::endl;
                if (temp_value >= 22){
                    bust = true;
                    std::cout<<"the player busts\n\n";
                    break;
                }
                
            }
            if(action == 's'){
                break;
            }
            
            //double bet, hit, set double down flag to true
            if(action == 'd'){
                bet = bet * 2;
                std::cout<<"Double Down! \nPlayer doubles their bet and only takes 1 more card.\n";
                std::cout<<"new bet: " << bet << "\n\n";
                double_down = true;
                Card* player_temp_loop = card_deck.deal_card();
		        player.rec_card (player_temp_loop);
                dealt++;
                int temp_value = player.calculate_hand_value();
                std::cout<<"Player's hand: \n";
                player.print_hand();
                std::cout<<"\n";
                std::cout<<"Player's value: "<< temp_value <<std::endl;
                if (temp_value >= 22){
                    bust = true;
                    std::cout<<"the player busts\n\n";
                    break;
                }
            }
            //unset action
            action = 'n';
		}
        std::cout<<buffer<<std::endl;
        std::cout<<"its now the dealer's turn. \n\n";

        while (dealer.get_d_bust() == false){
            char dealer_action = 'n';//initialize to impossible value
            dealer_action = dealer.determine_action();
            if(dealer_action == 'h'){
                std::cout<< "the dealer hits\n";
                Card* temp_dealer_card = card_deck.deal_card();
                dealer.add_dealer_card(temp_dealer_card);
                dealer.print_dealer_hand();
                std::cout << "Dealer value: " << dealer.get_hand_value() << "\n";
                if(dealer.get_true_hand_value() > 21){
                    dealer.set_d_bust();
                }
                std::cout << "\n\n";

            }
            if(dealer_action == 's'){
                std::cout<< "the dealer stands\n\n";
                break;
            }

        }
        std::cout<<buffer<<std::endl;
        std::cout << "showing final hands\n\n";
        std::cout << "player: ";
        player.print_hand();
        std::cout<<"\n";
        player.calculate_hand_value();
         std::cout<<"\n\n";

        dealer.reveal_hole_card();
        dealer.print_dealer_hand();
         std::cout<<"\n";
        dealer.get_true_hand_value();
        std::cout<<"\n\n";

        int final_dealer_val = dealer.get_true_hand_value();
        int final_player_val = player.calculate_hand_value();
        std::cout<<"player value: "<< final_player_val<< " dealer value: " << final_dealer_val << std::endl;
        if (final_player_val == 21 && blackjack == true){
            std::cout << "Blackjack! player wins!\n";
            bet = bet * 1.5;
            std::cout << "player receives: " << bet << "$\n";  
        }else if(bust == true && dealer.get_d_bust() == true){
            std::cout << "both bust its a tie!\n";
            std::cout << "player keeps: " << bet << "$\n";
        } else if (bust == true) {
           std::cout<< "Player Busts! Dealer wins!\n";
           std::cout << "player lost: " << bet << "$\n";
        } else if (dealer.get_d_bust()) {
            std::cout<< "Dealer Busts! Player wins!\n";
            bet = bet * 1.5;
            std::cout << "player receives: " << bet << "$\n";
        } else if (final_dealer_val > final_player_val){
            std::cout << "The dealer wins!\n";
            std::cout << "player lost: " << bet << "$\n";
        } else if( final_dealer_val < final_player_val){
            std::cout << "The player wins!\n";
            bet = bet * 1.5;
            std::cout << "player receives: " << bet << "$\n";
        }else if (final_player_val == final_dealer_val){
            std::cout << "Push; its a tie!\n";
            std::cout << "player keeps: " << bet << "$\n";
        } else {
            std::cout<<"error\n";
        }




		//std::cout<<"Would you like to play to play again? (y/n).\n";
		//std::cin >> play;
        //std::cout<<play;

    //I found out that calling the destructor manually causes seg faulting,
    //which luckily a friend pointed that out to me before I presented it at the poster showcase  
       // if(play == 'n'){
            // player.~Hand();
            //dealer.~Dealer();
		    //card_deck.~Deck();
         //   break;
        //}
       

	//}


	//card_deck.~Deck(); 

    std::cout<<"Thanks for playing, shutting down\n";
	return 0;
}
