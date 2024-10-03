#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <stack>
using namespace std;
using namespace sf;

class tableau {
private:
	stack<cards*> f;
	int xpos;
	int ypos;
public:
	tableau(string a, int xpos, int ypos,string b) {
	    cards* c = new cards(0,a, "textures/empty.png", b);
		c->set_position(xpos, ypos);
		c->set_flipped(true);
		f.push(c);
	}
	void add_card(cards* c) {
		f.push(c);
	}
	void set_position(int x, int y) {
		xpos = x;
		ypos = y;
	}
	bool check_valid_move(cards* c) {
		if (f.top()->get_value() == c->get_value() - 1 && f.top()->get_suit() == c->get_suit()) {
			//if (f.top()->get_suit() == c->get_suit())
			return true;
		}
		else {
			return false;
		}
	}
	cards* get_top_card() {
		return f.top();
	}
	void draw(RenderWindow& window) {
		f.top()->draw(window);
	}
};
