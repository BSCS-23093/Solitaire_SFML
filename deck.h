#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <vector>
#include "cards.h"
using namespace sf;

class card_deck {
private:
    vector<cards*> deck;
    int size = 52;
public:
    card_deck() {
        //

        string a = "textures/heart/1_heart.png";
        string b = "textures/diamond/1_diamond.png";
        string c = "textures/ace/1_ace.png";
        string d = "textures/spade/1_spade.png";
        for (int i = 1; i <= 9; i++) {
            cards* Hearts = new cards(i, "Hearts", a, "red");
            add_card(Hearts);
            cards* Diamonds = new cards(i, "Diamonds", b, "red");
            add_card(Diamonds);
            cards* Aces = new cards(i, "Aces", c, "black");
            add_card(Aces);
            cards* Spade = new cards(i, "Spades", d, "black");
            add_card(Spade);
            a.replace(15, 1, to_string(i + 1));
            b.replace(17, 1, to_string(i + 1));
            c.replace(13, 1, to_string(i + 1));
            d.replace(15, 1, to_string(i + 1));

            //
            //de.add_card(cards(i, "Hearts", a, "red"));
            //de.add_card(cards(i, "Diamonds", b, "red"));
            //de.add_card(cards(i, "Aces", c, "black"));
            //de.add_card(cards(i, "Spades", d, "black"));
            //a.replace(15, 1, to_string(i + 1));
            //b.replace(17, 1, to_string(i + 1));
            //c.replace(13, 1, to_string(i + 1));
            //d.replace(15, 1, to_string(i + 1));
            //
        }

        string a2 = "textures/heart/10_heart.png";
        string b2 = "textures/diamond/10_diamond.png";
        string c2 = "textures/ace/10_ace.png";
        string d2 = "textures/spade/10_spade.png";
        for (int i = 0; i <= 3; i++) {
            cards* Hearts2 = new cards(i + 10, "Hearts", a2, "red");
            add_card(Hearts2);
            cards* Diamonds2 = new cards(i + 10, "Diamonds", b2, "red");
            add_card(Diamonds2);
            cards* Aces2 = new cards(i + 10, "Aces", c2, "black");
            add_card(Aces2);
            cards* Spade2 = new cards(i + 10, "Spades", d2, "black");
            add_card(Spade2);
            a2.replace(16, 1, to_string(i + 1));
            b2.replace(18, 1, to_string(i + 1));
            c2.replace(14, 1, to_string(i + 1));
            d2.replace(16, 1, to_string(i + 1));
        }

        /*
        string a = "textures/heart/1_heart.png";
        string b = "textures/diamond/1_diamond.png";
        string c = "textures/ace/1_ace.png";
        string d = "textures/spade/1_spade.png";
        for (int i = 1; i <= 9; i++) {
            deck.push_back(cards(i, "Hearts", a, "red"));
            deck.push_back(cards(i, "Diamonds", b, "red"));
            deck.push_back(cards(i, "Aces", c, "black"));
            deck.push_back(cards(i, "Spades", d, "black"));
            a.replace(15, 1, to_string(i+1));
            b.replace(17, 1, to_string(i+1));
            c.replace(13, 1, to_string(i+1));
            d.replace(15, 1, to_string(i+1));
        }
        a = "textures/heart/10_heart.png";
        b = "textures/diamond/10_diamond.png";
        c = "textures/ace/10_ace.png";
        d = "textures/spade/10_spade.png";
        for (int i = 1; i <= 4; i++) {
            deck.push_back(cards(i, "Hearts", a, "red"));
            deck.push_back(cards(i, "Diamonds", b, "red"));
            deck.push_back(cards(i, "Aces", c, "black"));
            deck.push_back(cards(i, "Spades", d, "black"));
            a.replace(16, 1, to_string(i));
            b.replace(18, 1, to_string(i));
            c.replace(14, 1, to_string(i));
            d.replace(16, 1, to_string(i));
        }
        */
    }
	bool is_empty() {
		return deck.empty();
	}
    void shuffle() {
        srand(time(0));
        for (int i = 0; i < deck.size(); i++) {
            int random = rand() % deck.size();
            swap(deck[i], deck[random]);
        }
    }
    void display(RenderWindow& window) {
        for (int i = 0, k = 0; i < deck.size(); i++, k += 30) {
            deck[i]->set_position(100, 140);
            deck[i]->draw(window);
            //k = k % 800;
        }
    }
    //displaying not working fine displays white rectangle instead of loaded texture
    void draw(RenderWindow& window) {
        for (int i = 0; i < deck.size(); i++) {
            deck[i]->draw(window);
        }
    }
	void get_size() {
		cout << deck.size() << endl;
	}
    void add_card(cards* c) {
        deck.push_back(c);
    }
	void add_card_unflipped(cards* c) {
        c->set_flipped(false);
        deck.push_back(c);
	}
    void remove_card_last() {
        //deck.pop_back();
    }
    void get_sprite(int i) {
        deck[i]->get_sprite();
    }
	bool isEmpty() {
		return deck.empty();
	}
    cards* get_card() {
		if (deck.empty())
			return nullptr;
        cards* temp = deck.back();
        deck.pop_back();
        return temp;
    }
	cards* get_card2() {
        if (deck.empty())
            return nullptr;
        cards* temp = deck.back();
        return temp;
	}
    cards* operator[](int i) const {
        return deck[i];
    }
};
