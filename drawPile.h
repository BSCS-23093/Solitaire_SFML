#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <stack>
using namespace std;
using namespace sf;

//could also try sending deck as reference
class drawPile {
private:
	vector<cards*> f;
	int xpos = 100;
	int ypos = 440;
public:
	drawPile() {
		cards* c = new cards(0, "drawPile", "textures/empty.png", "black");
		c->set_position(xpos, ypos);
		c->set_flipped(true);
		f.push_back(c);
	}
	void add_card(cards* c) {
		c->set_position(xpos, ypos);
		c->set_flipped(true);
		f.push_back(c);
	}
	cards* get_top_card() {
		if (f.empty())
			return nullptr;
		else
		    return f.front();
	}
	cards* get_last_card() {
		if (f.empty())
			return nullptr;
		else
			return f.back();
	}
	void remove_card() {
		if (!f.empty()) {
			//f.erase(f.end()-1);
			f.erase(f.end()-1);
		}
	}
	void draw(RenderWindow& window) {
		//only display top 3 cards of vector if cards are less than 3 then only display them
		if (f.size() < 3) {
			int k = 0;
			//for (int i = f.size(); i >= 0; i--) {
			for (int i = 0; i < f.size(); i++){
			f[i]->set_position(xpos, ypos + (20 * k));
				f[i]->draw(window);
				k++;
			}
		}
		else {
			int k = 0;
			//for (int i = f.size(); i >= f.size() - 2; i--) {
			for (int i = f.size() - 3; i < f.size(); i++) {
				f[i]->set_position(xpos, ypos + (20 * k));
				f[i]->draw(window);
				k++;
			}
		}
	}
};
