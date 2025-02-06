blackjack: blackjack.o card.o deck.o hand.o player.o dealer.o
	g++ -o blackjack blackjack.o card.o deck.o hand.o player.o dealer.o
card.o: card.cpp card.h
	g++ -c -Wall -Wextra -pedantic -g -std=c++11 card.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c -Wall -Wextra -pedantic -g -std=c++11 deck.cpp
hand.o: hand.cpp hand.h card.h
	g++ -c -Wall -Wextra -pedantic -g -std=c++11 hand.cpp
player.o: player.cpp player.h hand.h 
	g++ -c -Wall -Wextra -pedantic -g -std=c++11 player.cpp
dealer.o: dealer.cpp dealer.h hand.h card.h
	g++ -c -Wall -Wextra -pedantic -g -std=c++11 dealer.cpp
blackjack.o: blackjack.cpp  deck.h hand.h dealer.h
	g++ -c -Wall -Wextra -pedantic -g -std=c++11 blackjack.cpp
clean: 
	rm blackjack.o card.o deck.o hand.o player.o dealer.o blackjack
 