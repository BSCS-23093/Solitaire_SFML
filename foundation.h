#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <vector>
#include <stack>
#include <queue>
//#include "cards.h" // Ensure cards.h is included
using namespace std;
using namespace sf;

class foundation {
private:
	vector<cards*> flipped;
	vector<cards*> unflipped;
	vector<cards*> temp_flipped;
	vector<cards*> temp_unflipped;
	int xpos = 0;
	int ypos = 0;
	int xpos2 = 0;
	int ypos2 = 0;
public:
	foundation() {

	}
	void set_position(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void add_card_unflipped(cards* c) {
		unflipped.push_back(c);
	}
	void clear() {
		flipped.clear();
		unflipped.clear();
	}
	void add_card_flipped(cards* c) {
		flipped.push_back(c);
		flipped.front()->set_flipped(true);
	}
	int get_size() {
		return flipped.size();
	}
	/*
	void remove_card() {
		if (!flipped.empty()) {
			flipped.pop_back();
		}
	}
	*/
	void remove_card() {
		if (!flipped.empty()) {
			flipped.erase(flipped.end() - 1);
		}
	}
	cards* get_top_card() {
		if (flipped.empty()) {
			return nullptr;
		}
		else {
			//return flipped.front();
			return flipped.back();
		}
	}
	cards* remove_last_card() {
		if (!flipped.empty()) {
			cards* temp = flipped.front();
			flipped.pop_back();
			return temp;
		}
		else {
			return nullptr;
		}
	}
	Sprite get_top_sprite() {
		if (!flipped.empty())
			return flipped.front()->get_sprite();
	}
	bool move_valid(cards* c) {
		if (flipped.empty()) {
			if (c->get_value() == 13) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			//if (c->get_value() == flipped.back()-1->get_value() && c->get_color() != flipped.back()->get_color()) {
			if (c->get_value() < flipped.back()->get_value() && c->get_color() != flipped.back()->get_color()) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	void reform() {
		if (!unflipped.empty() && flipped.empty()) {
			flipped.push_back(unflipped.back());
			unflipped.pop_back();
			flipped.front()->set_flipped(true);
		}
	}
	void draw(RenderWindow& window) {
		xpos2 = xpos;
		ypos2 = ypos;
		if (!unflipped.empty()) {
			for (int i = 0; i < unflipped.size(); i++) {
				unflipped[i]->set_position(xpos2, ypos2);
				unflipped[i]->draw(window);
				ypos2 += 40;
			}
		}
		if (!flipped.empty()) {
			for (int i = 0; i < flipped.size(); i++) {
				flipped[i]->set_position(xpos2, ypos2);
				flipped[i]->draw(window);
				ypos2 += 40;
			}
		}

		/*
		while (!unflipped.empty()) {
			unflipped.front()->set_position(xpos2, ypos2);
			unflipped.front()->draw(window);
			temp_unflipped.push_back(unflipped.front());
			unflipped.pop_back();
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
		*/
	}

};
