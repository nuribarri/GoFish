// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <ctime>
#include <vector>


using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int Winner(Player &p1, Player &p2);


int main( )
{

    Player p1("Nathaniel");
    Player p2("Claudio");



    cout << "Let's play Go Fish!\n" << endl;
    cout << "Player 1 is " << p1.getName() << endl;
    cout << "Player 2 is " << p2.getName() << endl << endl;

    int numCards = 7;

    Deck d;                              //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;



    Card p1Request, p2Request;

    bool sameRank;
    Card p1NewBook;

    p1Request = p1.chooseCardFromHand();
    cout << p1.getName() << " asks - Do you have any " << p1Request.getRank() << "'s?" << endl;

    sameRank = p2.sameRankInHand(p1Request);

    if(sameRank){
        p1NewBook =p2.removeCardFromHand(p1Request);          // removes card from player 2

        p1.addCard(p1NewBook);                          // adds it to player 1's hand
        p1.bookCards(p1Request ,p1NewBook);
    }

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    cout << p1.getName() <<" has : " << p1.showBooks() << endl;
    cout << p2.getName() <<" has : " << p2.showBooks() << endl;





    return EXIT_SUCCESS;

//    Deck d;
//    d.shuffle();
//
//    Card c = d.dealCard();
//    cout << "deal test " << c << endl;
//    cout << endl;
//
//    Player p("Joe");
//    cout << p.getName() << endl;
//    p.addCard(c);
//    p.addCard(d.dealCard());
//    cout << p.showHand() << endl;
//
//
//    int numCards = 5;
//
//    vector <Card> cards;
//
//    srand((unsigned)time(0));  //seed the random number generator
//
//    for (int i = 0; i < numCards; i++) {
//        int rank = (rand() % 13) + 1;
//        int suit = (rand() % 4);
//        Card c(rank,(Card::Suit)suit);
//        cout << "rank - " << rank << "  "  << c <<  endl;
//        cards.push_back(c);
//    }
//
//    for (int i = 0; i < cards.size(); i++)
//        cout << cards.at(i)<< endl;
//
//    cards.erase(cards.begin()+2);
//
//    cout <<"after"<<endl;
//
//    for (int i = 0; i < cards.size(); i++)
//        cout << cards[i] << endl;
//
//    return EXIT_SUCCESS;
}




int Winner(Player &p1, Player &p2){

    if(p1.getBookSize() + p2.getBookSize() == 26){

        if(p1.getBookSize() > p2.getBookSize()){
            return 1;
        }
        return 2;
    }
    return 0;
}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



