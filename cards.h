#include <iostream>
#include<SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

class cards {
private:
	string color;
	char value;
	string suit;
	bool flipped = false;
	string Path;
	Texture card_texture_bg;
	Sprite card_sprite_bg;
	Texture card_texture_fg;
	Sprite card_sprite_fg;
public:
	cards(int value, string suit, string path, string color) {
		this->value = value;
		this->suit = suit;
		this->color = color;
		this->Path = path;
		card_texture_bg.loadFromFile("textures/backside.png");
		card_sprite_bg.setTexture(card_texture_bg);

		load(path);
		set_sprite();
	}
	
	/*
	void display(RenderWindow& window) {
		if (flipped) {
			draw(window); // Corrected the call to the draw method with the required argument
		} else {
			if (value == 1)
				cout << "A" << suit << " ";
			else if (value == 11)
				cout << "J" << suit << " ";
			else if (value == 12)
				cout << "Q" << suit << " ";
			else if (value == 13)
				cout << "K" << suit << " ";
			else if (value > 1 && value < 11)
				cout << value + 0 << suit << " ";
		}
	}
	*/
	char get_value() {
		return value;
	}
	string get_color() {
		return color;
	}
	string get_suit() {
		return suit;
	}
	bool get_flipped() {
		return flipped;
	}
	void set_value(char value) {
		this->value = value;
	}
	void set_suit(string suit) {
		this->suit = suit;
	}
	void set_flipped(bool flipped) {
		this->flipped = flipped;
	}
	int get_position_x() {
		return card_sprite_bg.getPosition().x;
	}
	int get_position_y() {
		return card_sprite_bg.getPosition().y;
	}
	//
	bool operator==(const cards& c) const {
		return (value == c.value && suit == c.suit && color == c.color);
	}
	bool operator!=(const cards& c) const {
		return !operator==(c);
	}
	bool operator<(const cards& c) const {
		return (value < c.value && suit != c.suit && color != c.color);
	}
	bool operator>(const cards& c)const {
		return (value > c.value && suit != c.suit && color != c.color);
	}
	//
	void load(string address) {
		card_texture_fg.loadFromFile(address);
	}
	void set_sprite() {
		card_sprite_fg.setTexture(card_texture_fg);
	}
	void load_bg(string address) {
		card_texture_bg.loadFromFile(address);
	}
	void set_sprite_bg() {
		card_sprite_bg.setTexture(card_texture_bg);
	}
	void set_position(int x, int y) {
		card_sprite_bg.setPosition(x, y);
		card_sprite_fg.setPosition(x, y);
	}
	Sprite get_sprite() {
		if (!flipped)
			return card_sprite_bg;
		else
			return card_sprite_fg;
	}
	Texture get_texture() {
		if (!flipped)
			return card_texture_bg;
		else
			return card_texture_fg;
	}
	void draw(RenderWindow& window) {
		if (!flipped)
			window.draw(card_sprite_bg);
		else
			window.draw(card_sprite_fg);
	}
};
