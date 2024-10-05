//#include<SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "deck.h"
#include "foundation.h"
#include "drawPile.h"
#include "tableau.h"
#include <iostream>
#include <string>
#include <vector>

//adding undo funtionality
void undo(foundation& t1, foundation& t2, foundation& t3, foundation& t4, foundation& t5, foundation& t6, foundation& t7, foundation& d, drawPile& p, int& moves, int& score, stack<foundation>& undostack1, stack<foundation>& undostack2, stack<foundation>& undostack3, stack<foundation>& undostack4, stack<foundation>& undostack5, stack<foundation>& undostack6, stack<foundation>& undostack7) {
    if (score > 0) {
        score--;
        moves -= 5;
        if (!undostack1.empty()) {
            t1.undo(undostack1.top());
            undostack1.pop();
        }
        if (!undostack2.empty()) {
            t2.undo(undostack2.top());
            undostack2.pop();
        }
        if (!undostack3.empty()) {
            t3.undo(undostack3.top());
            undostack3.pop();
        }
        if (!undostack4.empty()) {
            t4.undo(undostack4.top());
            undostack4.pop();
        }
        if (!undostack5.empty()) {
            t5.undo(undostack5.top());
            undostack5.pop();
        }
        if (!undostack6.empty()) {
            t6.undo(undostack6.top());
            undostack6.pop();
        }
        if (!undostack7.empty()) {
            t7.undo(undostack7.top());
            undostack7.pop();
        }
    }
}
//adding redo functionality


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
void cardReversal(foundation& t1, foundation& t2, foundation& t3, foundation& t4, foundation& t5, foundation& t6, foundation& t7, int& foundation_selector, cards* temp) {
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
    int level = 0; // 1 = easy, 2 = hard
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
    ///
    int x = 0;
    int x2 = 0;
    ///
	stack<foundation> undoStack1;
	stack<foundation> undoStack2;
	stack<foundation> undoStack3;
	stack<foundation> undoStack4;
	stack<foundation> undoStack5;
	stack<foundation> undoStack6;
	stack<foundation> undoStack7;
	stack<foundation> undoStackD;
	stack<drawPile> undoStackP;
	stack<int> undoStackM;
	stack<int> undoStackS;
    ///////////////////////////////////////////////////////////////////////////
    card_deck de;
    drawPile p;
    cards* t = new cards(0, "Empty", "textures/empty.png", "red");
    t->set_flipped(true);
    t->set_position(100, 440);
    cards* td = new cards(0, "Empty", "textures/empty.png", "red");
    td->set_flipped(true);
    td->set_position(100, 140);
    //srand(time(0));
    //
    cards* a1 = new cards(0, "Empty", "textures/empty.png", "red");
    a1->set_flipped(true);
    a1->set_position(400, 140);
    cards* a2 = new cards(0, "Empty", "textures/empty.png", "red");
    a2->set_flipped(true);
    a2->set_position(650, 140);
    cards* a3 = new cards(0, "Empty", "textures/empty.png", "red");
    a3->set_flipped(true);
    a3->set_position(900, 140);
    cards* a4 = new cards(0, "Empty", "textures/empty.png", "red");
    a4->set_flipped(true);
    a4->set_position(1150, 140);
    cards* a5 = new cards(0, "Empty", "textures/empty.png", "red");
    a5->set_flipped(true);
    a5->set_position(1400, 140);
    cards* a6 = new cards(0, "Empty", "textures/empty.png", "red");
    a6->set_flipped(true);
    a6->set_position(1650, 140);
    cards* a7 = new cards(0, "Empty", "textures/empty.png", "red");
    a7->set_flipped(true);
    a7->set_position(1900, 140);
    //
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
    //
	undoStack1.push(t1);
	undoStack2.push(t2);
	undoStack3.push(t3);
	undoStack4.push(t4);
	undoStack5.push(t5);
	undoStack6.push(t6);
	undoStack7.push(t7);
    //

    tableau d1("Hearts", 2300, 140, "red");
    tableau d2("Diamonds", 2300, 410, "red");
    tableau d3("Aces", 2300, 680, "black");
    tableau d4("Spades", 2300, 950, "black");
    foundation d;
    int foundation_selector = 0;
    int selector = 0;
	Texture A12;
	A12.loadFromFile("textures/12.png");
	Sprite CD;
	CD.setTexture(A12);
	CD.setPosition(2300, 720);
	CD.scale(0.3, 0.3);
    //
    Texture A22;
    A22.loadFromFile("textures/22.png");
    Sprite CD2;
    CD2.setTexture(A22);
    CD2.setPosition(2300, 450);
    CD2.scale(0.3, 0.3);
    //
    //
    Texture A33;
    A33.loadFromFile("textures/33.png");
    Sprite CD3;
    CD3.setTexture(A33);
    CD3.setPosition(2300, 990);
    CD3.scale(0.3, 0.3);
    //
    //
    Texture A44;
    A44.loadFromFile("textures/44.png");
    Sprite CD4;
    CD4.setTexture(A44);
    CD4.setPosition(2300, 190);
    CD4.scale(0.3, 0.3);
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
    int moves = 0, score = 0;
    //
    while (window.isOpen())
    {
        if (mode == 3) {
            if (d1.get_top_card()->get_value() == 13 && d2.get_top_card()->get_value() == 13 && d3.get_top_card()->get_value() == 13 && d4.get_top_card()->get_value() == 13)
            {
                cout << "You win!" << endl;
                //sf::sleep(sf::seconds(5));
                window.close();
                main();
            }
        }
        //
        if (!undoStack1.empty() ) {
            foundation ur1 = undoStack1.top();
            if (ur1.undo_store(t1)) {
                undoStack1.push(ur1);
            }
        }
		if (!undoStack2.empty() ) {
			foundation ur2 = undoStack2.top();
			if (ur2.undo_store(t2)) {
				undoStack2.push(ur2);
			}
		}
        if (!undoStack3.empty() ) {
            foundation ur3 = undoStack3.top();
            if (ur3.undo_store(t3)) {
                undoStack3.push(ur3);
            }
        }
        if (!undoStack4.empty() ) {
            foundation ur4 = undoStack4.top();
            if (ur4.undo_store(t4)) {
                undoStack4.push(ur4);
            }
        }
        if (!undoStack5.empty() ) {
            foundation ur5 = undoStack5.top();
            if (ur5.undo_store(t5)) {
                undoStack5.push(ur5);
            }
        }
        if (!undoStack6.empty() ) {
            foundation ur6 = undoStack6.top();
            if (ur6.undo_store(t6)) {
                undoStack6.push(ur6);
            }
        }
        if (!undoStack7.empty()) {
            foundation ur7 = undoStack7.top();
            if (ur7.undo_store(t7)) {
                undoStack7.push(ur7);
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
        if (moves < 10 && moves >= 0)
            moves_str.insert(0, "0");
        if (score < 10 && score >=0)
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
            //
            /*
            if (de.isEmpty()) {
                de.add_card(p.get_last_card());
                //de.add_card(p.get_top_card());
                p.remove_card();
            }
            */
            //
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
                        level = 1;
                        time = clock.restart();
                    }
                    else if (mousePosition2.x > 568 && mousePosition2.x < 1436 && mousePosition2.y > 835 && mousePosition2.y < 1042 && mode == 2)
                    {
                        A.loadFromFile("textures/game.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        mode = 3;
                        level = 2;
                        time = clock.restart();
                    }
                    sf::Vector2i mp = sf::Mouse::getPosition(window);
                    if (mode == 3) {
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
                    if (mousePosition.x > 650 && mousePosition.x < 798 && mousePosition.y>140 && mousePosition.y < 450)
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
                    else if (mousePosition.x > 1900 && mousePosition.x < 2048 && mousePosition.y>140 && mousePosition.y < 320)
                    {
                        isSpriteSelected = true;
                        foundation_selector = 7;
                        if (t7.get_top_card() != nullptr) {
                            d.add_card_flipped(t7.get_top_card());
                        }
                        t7.remove_card();
                    }
                    //
                    if (mousePosition.x > 100 && mousePosition.x < 250 && mousePosition.y>140 && mousePosition.y < 350) {
                        if (de.get_card2() == nullptr) {
                            while (!p.empty()) {
                                //p.get_last_card()->set_flipped(true);
                                de.add_card_unflipped(p.get_last_card());
                                p.remove_card();
                                score++;
                            }
                            //cout << p.get_size() << endl;
                        }
                        else if (de.get_card2() != nullptr && level == 1) {
                            p.add_card(de.get_card());
                            //de.remove_card_last();
                            //de.get_size();
                            score++;
                            //cout <<p.get_size();
                        }
                        else if (de.get_card2() != nullptr && level == 2) {
                            for (int i = 0; i < 3; i++) {
                                if (de.get_card2() != nullptr) {
                                    p.add_card(de.get_card());
                                    //de.remove_card_last();
                                }
                            }
                            score++;
                            moves -= 10;
                        }
                    }
                    //
                    if (mousePosition.x > 100 && mousePosition.x < 248 && mousePosition.y>400 && mousePosition.y < 600) {
                        isSpriteSelected = true;
                        selector = 1;
                        if (p.get_last_card() != nullptr) {
                            d.add_card_flipped(p.get_last_card());
                        }
                        p.remove_card();
                        x = 1;
                    }
                }
                /*
                else if (evnt.mouseButton.button == sf::Mouse::Right)
                {
                    deagCard = true;
                }
                */
                else if (evnt.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePositionR = sf::Mouse::getPosition(window);
                    //if(t2.get_top_sprite().getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    //if (Card.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    if (mousePositionR.x > 400 && mousePositionR.x < 548 && mousePositionR.y>140 && mousePositionR.y < 450)
                    {
                        isSpriteSelected = true;
                        foundation_selector = 1;
                        if (t1.get_top_card() != nullptr) {
                            while (t1.get_top_card() != nullptr) {
                                d.add_card_flipped(t1.get_top_card());
                                t1.remove_card();
                            }
                        }
                        t1.remove_card();
                    }
                    else if (mousePositionR.x > 650 && mousePositionR.x < 798 && mousePositionR.y>140 && mousePositionR.y < 450)
                    {
                        isSpriteSelected = true;
                        foundation_selector = 2;
                        if (t2.get_top_card() != nullptr) {
                            while (t2.get_top_card() != nullptr) {
                                d.add_card_flipped(t2.get_top_card());
                                t2.remove_card();
                            }
                        }
                        t2.remove_card();
                    }
                    else if (mousePositionR.x > 900 && mousePositionR.x < 1098 && mousePositionR.y>140 && mousePositionR.y < 450)
                    {
                        isSpriteSelected = true;
                        foundation_selector = 3;
                        if (t2.get_top_card() != nullptr) {
                            while (t3.get_top_card() != nullptr) {
                                d.add_card_flipped(t3.get_top_card());
                                t3.remove_card();
                            }
                        }
                        t3.remove_card();
                    }
                    else if (mousePositionR.x > 1150 && mousePositionR.x < 1298 && mousePositionR.y>140 && mousePositionR.y < 450)
                    {
                        isSpriteSelected = true;
                        foundation_selector = 4;
                        if (t2.get_top_card() != nullptr) {
                            while (t4.get_top_card() != nullptr) {
                                d.add_card_flipped(t4.get_top_card());
                                t4.remove_card();
                            }
                        }
                        t4.remove_card();
                    }
                    else if (mousePositionR.x > 1400 && mousePositionR.x < 1548 && mousePositionR.y>140 && mousePositionR.y < 450)
                    {
                        isSpriteSelected = true;
                        foundation_selector = 5;
                        if (t2.get_top_card() != nullptr) {
                            while (t5.get_top_card() != nullptr) {
                                d.add_card_flipped(t5.get_top_card());
                                t5.remove_card();
                            }
                        }
                        t5.remove_card();
                    }
                    else if (mousePositionR.x > 1650 && mousePositionR.x < 1798 && mousePositionR.y>140 && mousePositionR.y < 450)
                    {
                        isSpriteSelected = true;
                        foundation_selector = 6;
                        if (t2.get_top_card() != nullptr) {
                            while (t6.get_top_card() != nullptr) {
                                d.add_card_flipped(t6.get_top_card());
                                t6.remove_card();
                            }
                        }
                        t6.remove_card();
                    }
                    else if (mousePositionR.x > 1900 && mousePositionR.x < 2048 && mousePositionR.y>140 && mousePositionR.y < 450)
                    {
                        isSpriteSelected = true;
                        foundation_selector = 7;
                        if (t2.get_top_card() != nullptr) {
                            while (t7.get_top_card() != nullptr) {
                                d.add_card_flipped(t7.get_top_card());
                                t7.remove_card();
                            }
                        }
                        t7.remove_card();
                    }
                }
            }
            if (evnt.type == sf::Event::KeyPressed)
            {
                if (evnt.key.code == sf::Keyboard::Space)
                {
                    cards* c = new cards(13, "Hearts", "textures/heart/1_heart.png", "red");
                    d1.add_card(c);
                    c = new cards(13, "Diamonds", "textures/diamond/1_diamond.png", "red");
                    d2.add_card(c);
                    c = new cards(13, "Aces", "textures/ace/1_ace.png", "black");
                    d3.add_card(c);
                    c = new cards(13, "Spades", "textures/spade/1_spade.png", "black");
                    d4.add_card(c);
                    // Replace sleep(1) with sf::sleep(sf::seconds(1));
                    //sf::sleep(sf::seconds(5));
                    x = 1;
                    moves--;
                    score--;
                }
				if (evnt.key.code == sf::Keyboard::U)
				{
					undo(t1, t2, t3, t4, t5, t6, t7, d, p, moves,score,undoStack1, undoStack2, undoStack3, undoStack4, undoStack5, undoStack6, undoStack7);
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
                            score++;
                            if (x == 1) {
                                moves += 10;
                                x = 0;
                            }
                            //}
                        //}
                        }
                        else if (mousePosition.x > 900 && mousePosition.x < 1048 && mousePosition.y>140 && mousePosition.y < 450 && (t3.move_valid(d.get_top_card()))) {
                            //if (t3.move_valid(d.get_top_card())) {
                                //if (d.get_top_card() != nullptr) {
                            t3.add_card_flipped(d.get_top_card());
                            //t2.reform();
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            if (x == 1) {
                                moves += 10;
                                x = 0;
                            }
                            //}
                        //}
                        }
                        else if (mousePosition.x > 1150 && mousePosition.x < 1298 && mousePosition.y>140 && mousePosition.y < 450 && (t4.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                            t4.add_card_flipped(d.get_top_card());
                            //t2.reform();
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            if (x == 1) {
                                moves += 10;
                                x = 0;
                            }
                            //}
                        }
                        else if (mousePosition.x > 1400 && mousePosition.x < 1548 && mousePosition.y>140 && mousePosition.y < 450 && (t5.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                            t5.add_card_flipped(d.get_top_card());
                            //t2.reform();
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            if (x == 1) {
                                moves += 10;
                                x = 0;
                            }
                            //}
                        }
                        else if (mousePosition.x > 1650 && mousePosition.x < 1798 && mousePosition.y>140 && mousePosition.y < 450 && (t6.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                            t6.add_card_flipped(d.get_top_card());
                            //t2.reform();
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            if (x == 1) {
                                moves += 10;
                                x = 0;
                            }
                            //}
                        }
                        else if (mousePosition.x > 1900 && mousePosition.x < 2048 && mousePosition.y>140 && mousePosition.y < 450 && (t7.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                            t7.add_card_flipped(d.get_top_card());
                            //t2.reform();
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            if (x == 1) {
                                moves += 10;
                                x = 0;
                            }
                            //}
                        }
                        else if (mousePosition.x > 650 && mousePosition.x < 798 && mousePosition.y>140 && mousePosition.y < 450 && (t2.move_valid(d.get_top_card()))) {
                            //if (d.get_top_card() != nullptr) {
                            t2.add_card_flipped(d.get_top_card());
                            //t2.reform();
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            if (x == 1) {
                                moves += 10;
                                x = 0;
                            }
                            //}
                        }
                        //
                        else if (mousePosition.x > 2300 && mousePosition.x < 2448 && mousePosition.y>140 && mousePosition.y < 320 && d1.check_valid_move(d.get_top_card())) {
                            d1.add_card(d.get_top_card());
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            moves += 10;
                        }
                        else if (mousePosition.x > 2300 && mousePosition.x < 2448 && mousePosition.y>410 && mousePosition.y < 590 && d2.check_valid_move(d.get_top_card())) {
                            d2.add_card(d.get_top_card());
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            moves += 10;
                        }
                        else if (mousePosition.x > 2300 && mousePosition.x < 2448 && mousePosition.y>680 && mousePosition.y < 860 && d3.check_valid_move(d.get_top_card())) {
                            d3.add_card(d.get_top_card());
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            moves += 10;
                        }
                        else if (mousePosition.x > 2300 && mousePosition.x < 2448 && mousePosition.y>950 && mousePosition.y < 1130 && d4.check_valid_move(d.get_top_card())) {
                            d4.add_card(d.get_top_card());
                            reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                            d.remove_card();
                            score++;
                            moves += 10;
                        }
                        //
                        else {
                            //t2.add_card_flipped(d.get_top_card());
                            cards* temp = d.get_top_card();
                            if (temp != nullptr) {
                                cardReversal(t1, t2, t3, t4, t5, t6, t7, foundation_selector, temp);
                                //t2.add_card_flipped(temp);
                            }
                            if (selector == 1) {
                                p.add_card(temp);
                                selector == 0;
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
                sf::Vector2i mousePositionRS = sf::Mouse::getPosition(window);
                if (evnt.mouseButton.button == sf::Mouse::Right)
                {
                    isSpriteSelected = false;
                    if (d.get_top_card() != nullptr) {
                        if (mousePositionRS.x > 650 && mousePositionRS.x < 798 && mousePositionRS.y>140 && mousePositionRS.y < 450 && (t1.move_valid(d.get_top_card()))) {
                            while (d.get_top_card() != nullptr) {
                                t1.add_card_flipped(d.get_top_card());
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                                score++;
                            }
                        }
                        else if (mousePositionRS.x > 650 && mousePositionRS.x < 798 && mousePositionRS.y>140 && mousePositionRS.y < 450 && (t2.move_valid(d.get_top_card()))) {
                            while (d.get_top_card() != nullptr) {
                                t2.add_card_flipped(d.get_top_card());
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                                score++;
                            }
                        }
                        else if (mousePositionRS.x > 900 && mousePositionRS.x < 1048 && mousePositionRS.y>140 && mousePositionRS.y < 450 && (t3.move_valid(d.get_top_card()))) {
                            while (d.get_top_card() != nullptr) {
                                t3.add_card_flipped(d.get_top_card());
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                                score++;
                            }
                        }
                        else if (mousePositionRS.x > 1150 && mousePositionRS.x < 1298 && mousePositionRS.y>140 && mousePositionRS.y < 450 && (t4.move_valid(d.get_top_card()))) {
                            while (d.get_top_card() != nullptr) {
                                t4.add_card_flipped(d.get_top_card());
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                                score++;
                            }
                        }
                        else if (mousePositionRS.x > 1400 && mousePositionRS.x < 1548 && mousePositionRS.y>140 && mousePositionRS.y < 450 && (t5.move_valid(d.get_top_card()))) {
                            while (d.get_top_card() != nullptr) {
                                t5.add_card_flipped(d.get_top_card());
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                                score++;
                            }
                        }
                        else if (mousePositionRS.x > 1650 && mousePositionRS.x < 1798 && mousePositionRS.y>140 && mousePositionRS.y < 450 && (t6.move_valid(d.get_top_card()))) {
                            while (d.get_top_card() != nullptr) {
                                t6.add_card_flipped(d.get_top_card());
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                                score++;
                            }
                        }
                        else if (mousePositionRS.x > 1900 && mousePositionRS.x < 2048 && mousePositionRS.y>140 && mousePositionRS.y < 450 && (t7.move_valid(d.get_top_card()))) {
                            while (d.get_top_card() != nullptr) {
                                t7.add_card_flipped(d.get_top_card());
                                reform_selector(t1, t2, t3, t4, t5, t6, t7, foundation_selector);
                                d.remove_card();
                                score++;
                            }
                        }
                        else {
                            while (d.get_top_card() != nullptr) {
                                cards* temp = d.get_top_card();
                                if (temp != nullptr) {
                                    cardReversal(t1, t2, t3, t4, t5, t6, t7, foundation_selector, temp);
                                }
                                d.remove_card();
                            }
                        }
                        foundation_selector = 0;
                    }
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
            a1->draw(window);
            a2->draw(window);
            a3->draw(window);
            a4->draw(window);
            a5->draw(window);
            a6->draw(window);
            a7->draw(window);
            t1.draw(window);
            t2.draw(window);
            t3.draw(window);
            t4.draw(window);
            t5.draw(window);
            t6.draw(window);
            t7.draw(window);
            window.draw(CD);
            window.draw(CD2);
            window.draw(CD3);
            window.draw(CD4);
            d1.draw(window);
            d2.draw(window);
            d3.draw(window);
            d4.draw(window);
			
            td->draw(window);
            t->draw(window);
            d.draw2(window);
            p.draw(window);
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

    return 0;
}
