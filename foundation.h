#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <vector>
#include <stack>
//#include "cards.h" // Ensure cards.h is included
using namespace std;
using namespace sf;

class foundation {
private:
	stack<cards*> flipped;
	stack<cards*> unflipped;
	stack<cards*> temp_flipped;
	stack<cards*> temp_unflipped;
	int xpos=0;
	int ypos=0;
	int xpos2=0;
	int ypos2=0;
public:
	foundation() {

	}
	void set_position(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void add_card_unflipped(cards* c) {
		unflipped.push(c);
	}
	void add_card_flipped(cards* c) {
		flipped.push(c);
		flipped.top()->set_flipped(true);
	}
	void draw(RenderWindow& window) {
		xpos2 = xpos;
		ypos2 = ypos;
		while (!unflipped.empty()) {
			unflipped.top()->set_position(xpos2, ypos2);
			unflipped.top()->draw(window);
			temp_unflipped.push(unflipped.top());
			unflipped.pop();
			ypos2 += 40;
		}
		while (!flipped.empty()) {
			flipped.top()->set_position(xpos2, ypos2);
			flipped.top()->draw(window);
			temp_flipped.push(flipped.top());
			flipped.pop();
			ypos2 += 40;
		}
		while (!temp_unflipped.empty()) {
			unflipped.push(temp_unflipped.top());
			temp_unflipped.pop();
		}
		while (!temp_flipped.empty()) {
			flipped.push(temp_flipped.top());
			temp_flipped.pop();
		}
	}

};
