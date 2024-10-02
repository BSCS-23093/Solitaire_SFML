#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <stack>
#include "cards.h"
using namespace std;
using namespace sf;

//could also try sending deck as reference
class drawPile {
private:
	stack<cards*> f;
	int xpos;
	int ypos;
public:
	drawPile() {
	}
	void add_card(cards* c) {
		c->set_position(xpos, ypos);
		f.push(c);
	}
	cards* get_top_card() {
		return f.top();
	}
	void draw(RenderWindow& window) {
		f.top()->draw(window);
	}
};
