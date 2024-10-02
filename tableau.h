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
	tableau(string a,int xpos,int ypos) {
		cards* c = new cards(1, "Hearts", "textures/empty.png", "red");
		c->set_position(xpos, ypos);
		c->set_flipped(true);
		f.push(c);
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
