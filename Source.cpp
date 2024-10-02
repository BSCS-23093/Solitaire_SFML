//#include<SFML/Graphics.hpp>
#include "deck.h"
#include "foundation.h"
#include "tableau.h"
#include <iostream>
#include <string>
#include <vector>
//using namespace sf;
void reform_selector(foundation& t1, foundation& t2, foundation& t3, foundation& t4, foundation& t5, foundation& t6, foundation& t7, int& foundation_selector) {
    if (foundation_selector == 1) {
        t1.reform();
    }
    else if (foundation_selector == 2) {
        t2.reform();
    }
    else if (foundation_selector == 3) {
        t3.reform();
    }
    else if (foundation_selector == 4) {
        t4.reform();
    }
	else if (foundation_selector == 5) {
		t5.reform();
	}
	else if (foundation_selector == 6) {
		t6.reform();
	}
    else if (foundation_selector == 7) {
        t7.reform();
    }
	//foundation_selector = 0;
}
void cardReversal(foundation& t1, foundation& t2, foundation& t3, foundation& t4, foundation& t5, foundation& t6, foundation& t7, int& foundation_selector,cards* temp) {
    if (foundation_selector == 1) {
        t1.add_card_flipped(temp);
    }
    else if (foundation_selector == 2) {
		t2.add_card_flipped(temp);
    }
    else if (foundation_selector == 3) {
		t3.add_card_flipped(temp);
    }
    else if (foundation_selector == 4) {
		t4.add_card_flipped(temp);
    }
    else if (foundation_selector == 5) {
		t5.add_card_flipped(temp);
    }
    else if (foundation_selector == 6) {
		t6.add_card_flipped(temp);
    }
    else if (foundation_selector == 7) {
		t7.add_card_flipped(temp);
    }
    //foundation_selector = 0;
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(2560, 1320), "Solitaire SFML", sf::Style::Close | sf::Style::Resize);
    window.setPosition(Vector2i(-10, 0));
    int mode = 0; // 0 = main menu, 1 = rules, 2 = difficulty selection, 3 = game
    sf::Music music;
    sf::Music musicTap;
    if (!music.openFromFile("textures/music/music_bg.ogg"))
    {
        std::cout << "Error loading music" << std::endl;
    }
    if (!musicTap.openFromFile("textures/music/musicTap.ogg"))
    {
        std::cout << "Error loading music" << std::endl;
    }
    if (mode == 0 || mode == 1 || mode == 2 || mode == 3) {
        music.setLoop(true);
        music.play();
    }
    ///////////////////////////////////////////////////////////////////////////
    card_deck de;
    //srand(time(0));
    de.shuffle();
    foundation t1, t2, t3, t4, t5, t6, t7;
    //add_tablues(de,t1,t2,t3,t4,t5,t6,t7);
    //
    //
    t1.add_card_flipped(de.get_card());
    t1.set_position(400, 140);
    de.remove_card_last();
    //
    //tableu t2;
    for (int i = 0; i < 1; i++) {
        t2.add_card_unflipped(de.get_card());
        t2.set_position(650, 140);
        de.remove_card_last();
    }
    t2.add_card_flipped(de.get_card());
    t2.set_position(650, 140);
    de.remove_card_last();
    //
    //tableu t3;
    for (int i = 0; i < 2; i++) {
        t3.add_card_unflipped(de.get_card());
        t3.set_position(900, 140);
        de.remove_card_last();
    }
    t3.add_card_flipped(de.get_card());
    t3.set_position(900, 140);
    de.remove_card_last();
    //
    //tableu t4;
    for (int i = 0; i < 3; i++) {
        t4.add_card_unflipped(de.get_card());
        t4.set_position(1150, 140);
        de.remove_card_last();
    }
    t4.add_card_flipped(de.get_card());
    t4.set_position(1150, 140);
    de.remove_card_last();
    //
    //tableu t5;
    for (int i = 0; i < 4; i++) {
        t5.add_card_unflipped(de.get_card());
        t5.set_position(1400, 140);
        de.remove_card_last();
    }
    t5.add_card_flipped(de.get_card());
    t5.set_position(1400, 140);
    de.remove_card_last();
    //
    //tableu t6;
    for (int i = 0; i < 5; i++) {
        t6.add_card_unflipped(de.get_card());
        t6.set_position(1650, 140);
        de.remove_card_last();
    }
    t6.add_card_flipped(de.get_card());
    t6.set_position(1650, 140);
    de.remove_card_last();
    //
    //tableu t7;
    for (int i = 0; i < 6; i++) {
        t7.add_card_unflipped(de.get_card());
        t7.set_position(1900, 140);
        de.remove_card_last();
    }
    t7.add_card_flipped(de.get_card());
    t7.set_position(1900, 140);
    de.remove_card_last();
    //
    tableau d1("Hearts", 2300, 140);
    tableau d2("Diamonds", 2300, 410);
    tableau d3("Aces", 2300, 680);
    tableau d4("Spades", 2300, 950);
	cards* c = new cards(13, "Hearts", "textures/empty.png", "red");
	foundation d;
    int foundation_selector = 0;
	//d1.add_card(c);
	//d2.add_card(c);
	//d3.add_card(c);
	//d4.add_card(c);

    //
    /*
    a = "textures/heart/10_heart.png";
    b = "textures/diamond/10_diamond.png";
    c = "textures/ace/10_ace.png";
    d = "textures/spade/10_spade.png";
    for (int i = 1; i <= 4; i++) {
        de.add_card(cards(i, "Hearts", a, "red"));
        de.add_card(cards(i, "Diamonds", b, "red"));
        de.add_card(cards(i, "Aces", c, "black"));
        de.add_card(cards(i, "Spades", d, "black"));
        a.replace(16, 1, to_string(i));
        b.replace(18, 1, to_string(i));
        c.replace(14, 1, to_string(i));
        d.replace(16, 1, to_string(i));
    }
    */
    /////////////////////////////////////////////////////////////////////////////

    /*
    cards c(1, "Hearts");
    c.load("textures/ace/1_ace.png");
    c.set_sprite();
    c.set_position(300, 300);
    */
    /*
    cards c(1, "Hearts", "textures/ace/1_ace.png", "red");
    c.load("textures/ace/1_ace.png");
    c.set_sprite();
    c.set_position(300, 300);
    */
    /*
    Texture B;
    B.loadFromFile("textures/ace/1_ace.png");

    Sprite Card(B);
    Card.setPosition(100, 50);
    */
    Texture C;
    C.loadFromFile("textures/ace/1_ace.png");
    Sprite Card;
    Card.setTexture(C);
    int cardx = 100;
    int cardy = 50;
    Card.setPosition(cardx, cardy);
    //
    //C.loadFromFile("textures/backside.png");
    //Sprite Card2(C);
    //Card2.setPosition(100, 50);
    //
    Texture A;
    A.loadFromFile("textures/main.png");

    Sprite Backg(A);
    Backg.setPosition(0, -80);
    Font Lato;
    Lato.loadFromFile("textures/Lato/Lato-Black.ttf");

    Text NG("NEW GAME", Lato, 50);
    NG.setPosition(540, 60);
    NG.setFillColor(sf::Color::White);
    Text LG("LOAD GAME", Lato, 50);
    LG.setPosition(535, 170);
    LG.setFillColor(sf::Color::White);
    bool isSpriteSelected = false;;
    bool deagCard = false;
    float max_x = 500;
    //--------------
    //
    Clock clock;
    Time time;
    int moves = 10, score = 5;
    //
    while (window.isOpen())
    {
        if (mode == 3) {
            if (d1.get_top_card()->get_value() == 13 && d2.get_top_card()->get_value() == 13 && d3.get_top_card()->get_value() == 13 && d4.get_top_card()->get_value() == 13)
            {
                cout << "You win!" << endl;
                window.close();
            }
        }
        //
        //clock with how much time has passed hh:min:sec format
        time = clock.getElapsedTime();
        int seconds = time.asSeconds();
        int minutes = seconds / 60;
        int hours = minutes / 60;
        seconds = seconds % 60;
        minutes = minutes % 60;
        hours = hours % 24;
        if (seconds == 60)
            seconds /= 60;
        if (minutes == 60)
            minutes = 0;
        if (hours == 24)
            hours = 0;
        //cout << hours << ":" << minutes << ":" << seconds << endl;
        std::string hours_str = std::to_string(hours);
        if (hours < 10)
            hours_str.insert(0, "0");
        std::string minutes_str = std::to_string(minutes);
        if (minutes < 10)
            minutes_str.insert(0, "0");
        std::string seconds_str = std::to_string(seconds);
        if (seconds < 10)
            seconds_str.insert(0, "0");
        string time_str = hours_str + ":" + minutes_str + ":" + seconds_str;
        Text clockTimer(time_str, Lato, 80);
        clockTimer.setPosition(300, 25);
        clockTimer.setFillColor(sf::Color::Black);
        //

        //score and moves
        string moves_str = to_string(moves);
        string score_str = to_string(score);
        if (moves < 10)
            moves_str.insert(0, "0");
        if (score < 10)
            score_str.insert(0, "0");

        Text movesText(moves_str, Lato, 80);
        movesText.setPosition(2300, 35);
        movesText.setFillColor(sf::Color::Black);
        Text scoreText(score_str, Lato, 80);
        scoreText.setPosition(2300, 1200);
        scoreText.setFillColor(sf::Color::Black);

        //

        sf::Event evnt;

        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();

            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                if (evnt.mouseButton.button == sf::Mouse::Left)
                {
                    //
                    if (mode == 0 || mode == 1 || mode == 2 || mode == 3) {
                        musicTap.play();
                    }
                    //
                    cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
                    //want to change background color of the sprite when clicked
                    sf::Vector2i mousePosition2 = sf::Mouse::getPosition(window);
                    if (mousePosition2.x > 568 && mousePosition2.x < 1436 && mousePosition2.y > 525 && mousePosition2.y < 737 && mode == 0)
                    {
                        A.loadFromFile("textures/mode.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        mode = 2;
                    }
                    else if (mousePosition2.x > 568 && mousePosition2.x < 1436 && mousePosition2.y > 835 && mousePosition2.y < 1042 && mode == 0)
                    {
                        A.loadFromFile("textures/rules.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        mode = 1;
                    }
                    else if (mousePosition2.x > 2037 && mousePosition2.x < 2462 && mousePosition2.y > 1190 && mousePosition2.y < 1290 && mode == 1)
                    {
                        A.loadFromFile("textures/main.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        mode = 0;
                    }
                    else if (mousePosition2.x > 568 && mousePosition2.x < 1436 && mousePosition2.y > 525 && mousePosition2.y < 737 && mode == 2)
                    {
                        A.loadFromFile("textures/game.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        mode = 3;
                        time = clock.restart();
                    }
                    else if (mousePosition2.x > 568 && mousePosition2.x < 1436 && mousePosition2.y > 835 && mousePosition2.y < 1042 && mode == 2)
                    {
                        A.loadFromFile("textures/game.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        mode = 3;
                        time = clock.restart();
                    }
                    sf::Vector2i mp = sf::Mouse::getPosition(window);
					if (mode == 3){
						if (mp.x > 100 && mp.x < 250 && mp.y > 140 && mp.y < 370)
						{
							de.remove_card_last();
						}
					}
                    // Check if the mouse click is inside the sprite
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    //if(t2.get_top_sprite().getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    //if (Card.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    if (mousePosition.x > 400 && mousePosition.x < 548 && mousePosition.y>140 && mousePosition.y < 450)
                    {
                        isSpriteSelected = true;
                        foundation_selector = 1;
                        if (t1.get_top_card() != nullptr) {
                            d.add_card_flipped(t1.get_top_card());
                        }
                        t1.remove_card();
                    }
                    if(mousePosition.x>650 && mousePosition.x<798 && mousePosition.y>140 && mousePosition.y < 450)
                    {
                        isSpriteSelected = true;
						foundation_selector = 2;
                        if (t2.get_top_card() != nullptr) {
                            d.add_card_flipped(t2.get_top_card());
                        }
                        t2.remove_card();
					}
					else if (mousePosition.x > 900 && mousePosition.x < 1048 && mousePosition.y>140 && mousePosition.y < 450)
					{
						isSpriteSelected = true;
						foundation_selector = 3;
						if (t3.get_top_card() != nullptr) {
							d.add_card_flipped(t3.get_top_card());
						}
						t3.remove_card();
					}
					else if (mousePosition.x > 1150 && mousePosition.x < 1298 && mousePosition.y>140 && mousePosition.y < 450)
					{
						isSpriteSelected = true;
						foundation_selector = 4;
						if (t4.get_top_card() != nullptr) {
							d.add_card_flipped(t4.get_top_card());
						}
						t4.remove_card();
					}
					else if (mousePosition.x > 1400 && mousePosition.x < 1548 && mousePosition.y>140 && mousePosition.y < 450)
					{
						isSpriteSelected = true;
						foundation_selector = 5;
						if (t5.get_top_card() != nullptr) {
							d.add_card_flipped(t5.get_top_card());
						}
						t5.remove_card();
					}
					else if (mousePosition.x > 1650 && mousePosition.x < 1798 && mousePosition.y>140 && mousePosition.y < 450)
					{
						isSpriteSelected = true;
						foundation_selector = 6;
						if (t6.get_top_card() != nullptr) {
							d.add_card_flipped(t6.get_top_card());
						}
						t6.remove_card();
					}
					else if (mousePosition.x > 1900 && mousePosition.x < 2048 && mousePosition.y>140 && mousePosition.y < 450)
					{
						isSpriteSelected = true;
						foundation_selector = 7;
						if (t7.get_top_card() != nullptr) {
							d.add_card_flipped(t7.get_top_card());
						}
						t7.remove_card();
					}

                }
                else if (evnt.mouseButton.button == sf::Mouse::Right)
                {
                    deagCard = true;
                }
            }
			if (evnt.type == sf::Event::KeyPressed)
			{
				if (evnt.key.code == sf::Keyboard::Space)
				{
                   // d4.add_card(c);
					moves--;
					score--;
				}
			}

            if (evnt.type == sf::Event::MouseButtonReleased)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (evnt.mouseButton.button == sf::Mouse::Left)
                {
					isSpriteSelected = false;
                    if (d.get_top_card() != nullptr) {
                        if (mousePosition.x > 400 && mousePosition.x < 548 && mousePosition.y>140 && mousePosition.y < 450 && (t1.move_valid(d.get_top_card()))) {
                            //if (t3.move_valid(d.get_top_card())) {
                                //if (d.get_top_card() != nullptr) {
                            t1.add_card_flipped(d.get_top_card());
                            //t2.reform();
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            //}
                        //}
                        }
                        if (mousePosition.x > 900 && mousePosition.x < 1048 && mousePosition.y>140 && mousePosition.y < 450 && (t3.move_valid(d.get_top_card()))) {
                            //if (t3.move_valid(d.get_top_card())) {
                                //if (d.get_top_card() != nullptr) {
                                t3.add_card_flipped(d.get_top_card());
                                //t2.reform();
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                                //}
                            //}
                        }
                        else if (mousePosition.x > 1150 && mousePosition.x < 1298 && mousePosition.y>140 && mousePosition.y < 450 && (t4.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                                t4.add_card_flipped(d.get_top_card());
                                //t2.reform();
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                            //}
                        }
                        else if (mousePosition.x > 1400 && mousePosition.x < 1548 && mousePosition.y>140 && mousePosition.y < 450 && (t5.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                                t5.add_card_flipped(d.get_top_card());
                                //t2.reform();
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                            //}
                        }
                        else if (mousePosition.x > 1650 && mousePosition.x < 1798 && mousePosition.y>140 && mousePosition.y < 450 && (t6.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                                t6.add_card_flipped(d.get_top_card());
                                //t2.reform();
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                            //}
                        }
                        else if (mousePosition.x > 1900 && mousePosition.x < 2048 && mousePosition.y>140 && mousePosition.y < 450 && (t7.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                                t7.add_card_flipped(d.get_top_card());
                                //t2.reform();
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                            //}
                        }
                        else if (mousePosition.x > 650 && mousePosition.x < 798 && mousePosition.y>140 && mousePosition.y < 450 && (t2.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                                t2.add_card_flipped(d.get_top_card());
                                //t2.reform();
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                            //}
                        }
                        else {
                            //t2.add_card_flipped(d.get_top_card());
                            cards* temp = d.get_top_card();
                            if (temp != nullptr) {
                                cardReversal(t1, t2, t3, t4, t5, t6, t7, foundation_selector, temp);
                                //t2.add_card_flipped(temp);
                            }
                            d.remove_card();
                        }
                    //
                    }
                    /*
                    else {
						//t2.add_card_flipped(d.get_top_card());
						cards* temp = d.get_top_card();
                        if (temp != nullptr) {
                            cardReversal(t1, t2, t3, t4, t5, t6, t7, foundation_selector,temp);
                            //t2.add_card_flipped(temp);
                        }
                        d.remove_card();
                    }
                    */
                    foundation_selector = 0;
                }
            }
        }

        if (isSpriteSelected)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            d.set_position(static_cast<float>(mousePosition.x) - 50, static_cast<float>(mousePosition.y) - 65);
		}
        if (deagCard)
        {
            sf::Vector2f position = Card.getPosition();
            position.x += 5;
            //Card.setPosition(position);
			
            //t2.get_top_card()->set_position(position.x,position.y);
			if (position.x >= max_x)
                deagCard = false;
        }
        window.clear();
        window.draw(Backg);
        /*
        window.draw(NG);
        window.draw(LG);
        window.draw(Card);
        */
        //window.clear();
        if (mode == 3) {
            //de.display(window);
            de.display(window);
            window.draw(clockTimer);
            window.draw(movesText);
            window.draw(scoreText);
            t1.draw(window);
            t2.draw(window);
            t3.draw(window);
            t4.draw(window);
            t5.draw(window);
            t6.draw(window);
            t7.draw(window);
            d1.draw(window);
            d2.draw(window);
            d3.draw(window);
            d4.draw(window);
			d.draw(window);
            //window.draw(Card);
            //d.display(window);
            //c.draw(window);
        }
        //de.display(window);
        //c.display(window);
        window.display();
    }

    return 0;
}
