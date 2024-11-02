#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>
#include <thread>

struct Card { // The structure of the playing card
    sf::Sprite sprite;
    int8_t power;
};

int main() {
    static sf::Texture cards[52]; // Textures of playing cards

    cards[0].loadFromFile("Images\\1.png"); // Loading textures from the Images folder
    cards[1].loadFromFile("Images\\2.png");
    cards[2].loadFromFile("Images\\3.png");
    cards[3].loadFromFile("Images\\4.png");
    cards[4].loadFromFile("Images\\5.png");
    cards[5].loadFromFile("Images\\6.png");
    cards[6].loadFromFile("Images\\7.png");
    cards[7].loadFromFile("Images\\8.png");
    cards[8].loadFromFile("Images\\9.png");
    cards[9].loadFromFile("Images\\10.png");
    cards[10].loadFromFile("Images\\11.png");
    cards[11].loadFromFile("Images\\12.png");
    cards[12].loadFromFile("Images\\13.png");
    cards[13].loadFromFile("Images\\14.png");
    cards[14].loadFromFile("Images\\15.png");
    cards[15].loadFromFile("Images\\16.png");
    cards[16].loadFromFile("Images\\17.png");
    cards[17].loadFromFile("Images\\18.png");
    cards[18].loadFromFile("Images\\19.png");
    cards[19].loadFromFile("Images\\20.png");
    cards[20].loadFromFile("Images\\21.png");
    cards[21].loadFromFile("Images\\22.png");
    cards[22].loadFromFile("Images\\23.png");
    cards[23].loadFromFile("Images\\24.png");
    cards[24].loadFromFile("Images\\25.png");
    cards[25].loadFromFile("Images\\26.png");
    cards[26].loadFromFile("Images\\27.png");
    cards[27].loadFromFile("Images\\28.png");
    cards[28].loadFromFile("Images\\29.png");
    cards[29].loadFromFile("Images\\30.png");
    cards[30].loadFromFile("Images\\31.png");
    cards[31].loadFromFile("Images\\32.png");
    cards[32].loadFromFile("Images\\33.png");
    cards[33].loadFromFile("Images\\34.png");
    cards[34].loadFromFile("Images\\35.png");
    cards[35].loadFromFile("Images\\36.png");
    cards[36].loadFromFile("Images\\37.png");
    cards[37].loadFromFile("Images\\38.png");
    cards[38].loadFromFile("Images\\39.png");
    cards[39].loadFromFile("Images\\40.png");
    cards[40].loadFromFile("Images\\41.png");
    cards[41].loadFromFile("Images\\42.png");
    cards[42].loadFromFile("Images\\43.png");
    cards[43].loadFromFile("Images\\44.png");
    cards[44].loadFromFile("Images\\45.png");
    cards[45].loadFromFile("Images\\46.png");
    cards[46].loadFromFile("Images\\47.png");
    cards[47].loadFromFile("Images\\48.png");
    cards[48].loadFromFile("Images\\49.png");
    cards[49].loadFromFile("Images\\50.png");
    cards[50].loadFromFile("Images\\51.png");
    cards[51].loadFromFile("Images\\52.png");

    static sf::Texture chip[5]; // Chip textures

    chip[0].loadFromFile("Images\\c1.png");
    chip[1].loadFromFile("Images\\c10.png");
    chip[2].loadFromFile("Images\\c100.png");
    chip[3].loadFromFile("Images\\c1000.png");
    chip[4].loadFromFile("Images\\max.png");

    static sf::Texture back;
    static sf::Texture hit;
    static sf::Texture dob;
    static sf::Texture stand;
    static sf::Texture clear;
    static sf::Texture place;
    static sf::Texture easy;
    static sf::Texture medium;
    static sf::Texture hard;
    static sf::Texture yes;
    static sf::Texture no;

    back.loadFromFile("Images\\back.png");
    hit.loadFromFile("Images\\hit.png");
    dob.loadFromFile("Images\\double.png");
    stand.loadFromFile("Images\\stand.png");
    clear.loadFromFile("Images\\clear.png");
    place.loadFromFile("Images\\place.png");
    easy.loadFromFile("Images\\easy.png");
    medium.loadFromFile("Images\\medium.png");
    hard.loadFromFile("Images\\hard.png");
    yes.loadFromFile("Images\\yes.png");
    no.loadFromFile("Images\\no.png");

    std::vector<sf::Sprite> schip; // Chip sprite vector
    schip.reserve(5);

    for (int i = 0; i < 5; ++i) { // Initialization of chip sprite coordinates
        sf::Sprite s(chip[i]);
        s.setPosition(525 + (75 * i), 400);
        schip.push_back(s);
    }
    // A vector of pairs of card textures and strengths
    std::vector<std::pair<sf::Texture&, int8_t>> Cards = {
        {cards[0], 1}, {cards[1], 2}, {cards[2], 3}, {cards[3], 4},
        {cards[4], 5}, {cards[5], 6}, {cards[6], 7}, {cards[7], 8},
        {cards[8], 9}, {cards[9], 10}, {cards[10], 11}, {cards[11], 12},
        {cards[12], 13}, {cards[13], 1}, {cards[14], 2}, {cards[15], 3},
        {cards[16], 4}, {cards[17], 5}, {cards[18], 6}, {cards[19], 7},
        {cards[20], 8}, {cards[21], 9}, {cards[22], 10}, {cards[23], 11},
        {cards[24], 12}, {cards[25], 13}, {cards[26], 1}, {cards[27], 2},
        {cards[28], 3}, {cards[29], 4}, {cards[30], 5}, {cards[31], 6},
        {cards[32], 7}, {cards[33], 8}, {cards[34], 9}, {cards[35], 10},
        {cards[36], 11}, {cards[37], 12}, {cards[38], 13}, {cards[39], 1},
        {cards[40], 2}, {cards[41], 3}, {cards[42], 4}, {cards[43], 5},
        {cards[44], 6}, {cards[45], 7}, {cards[46], 8}, {cards[47], 9},
        {cards[48], 10}, {cards[49], 11}, {cards[50], 12}, {cards[51], 13}
    };

    std::vector<Card> player; // A vector of player cards
    player.reserve(10);
    std::vector<Card> enemy; // A vector of dealer cards
    enemy.reserve(10);

    static sf::Sprite sback(back); // Sprite of the back of the cards

    static sf::Font font; // Font
    font.loadFromFile("Images\\arial.ttf"); // Downloading the font

    static sf::Text yourcards; // Creation of text sprites
    yourcards.setFont(font);
    yourcards.setString("Your cards:");
    yourcards.setCharacterSize(56);
    yourcards.setFillColor(sf::Color::White);
    yourcards.setPosition(30, 820);

    static sf::Text dealercards;
    dealercards.setFont(font);
    dealercards.setString("Dealer's cards:");
    dealercards.setCharacterSize(56);
    dealercards.setFillColor(sf::Color::White);
    dealercards.setPosition(30, 3);

    static sf::Text nowbet;
    nowbet.setFont(font);
    nowbet.setCharacterSize(56);
    nowbet.setFillColor(sf::Color::White);
    nowbet.setPosition(500, 300);

    static sf::Text balance;
    balance.setFont(font);
    balance.setCharacterSize(56);
    balance.setFillColor(sf::Color::White);
    balance.setPosition(30, 5);

    static sf::Text enemybalance;
    enemybalance.setFont(font);
    enemybalance.setCharacterSize(56);
    enemybalance.setFillColor(sf::Color::White);
    enemybalance.setPosition(30, 80);

    static sf::Text maxbet;
    maxbet.setFont(font);
    maxbet.setCharacterSize(56);
    maxbet.setFillColor(sf::Color::White);
    maxbet.setPosition(30, 155);

    static sf::Text bet;
    bet.setFont(font);
    bet.setCharacterSize(56);
    bet.setFillColor(sf::Color::White);
    bet.setPosition(30, 480);

    static sf::Text blackjack;
    blackjack.setFont(font);
    blackjack.setString("Blackjack!");
    blackjack.setCharacterSize(56);
    blackjack.setFillColor(sf::Color::Blue);
    blackjack.setPosition(900, 400);

    static sf::Text won;
    won.setFont(font);
    won.setString("Won!");
    won.setCharacterSize(56);
    won.setFillColor(sf::Color::Blue);
    won.setPosition(900, 400);

    static sf::Text lost;
    lost.setFont(font);
    lost.setString("Lost!");
    lost.setCharacterSize(56);
    lost.setFillColor(sf::Color::Red);
    lost.setPosition(900, 400);

    static sf::Text draw;
    draw.setFont(font);
    draw.setString("Draw!");
    draw.setCharacterSize(56);
    draw.setFillColor(sf::Color::Yellow);
    draw.setPosition(900, 400);

    static sf::Text bust;
    bust.setFont(font);
    bust.setString("Bust!");
    bust.setCharacterSize(56);
    bust.setFillColor(sf::Color::Red);
    bust.setPosition(900, 400);

    static sf::Text s21;
    s21.setFont(font);
    s21.setString("21!");
    s21.setCharacterSize(56);
    s21.setFillColor(sf::Color::Blue);
    s21.setPosition(900, 400);

    static sf::Text choice;
    choice.setFont(font);
    choice.setString("Select a difficulty");
    choice.setCharacterSize(76);
    choice.setFillColor(sf::Color::White);
    choice.setPosition(230, 180);

    static sf::Text logo;
    logo.setFont(font);
    logo.setString("Blackjack");
    logo.setCharacterSize(76);
    logo.setFillColor(sf::Color::Red);
    logo.setPosition(330, 40);

    static sf::Text text_power_of_player;
    text_power_of_player.setFont(font);
    text_power_of_player.setCharacterSize(56);
    text_power_of_player.setFillColor(sf::Color::Blue);
    text_power_of_player.setPosition(1350, 430);

    static sf::Text text_power_of_dealer;
    text_power_of_dealer.setFont(font);
    text_power_of_dealer.setCharacterSize(56);
    text_power_of_dealer.setFillColor(sf::Color::Red);
    text_power_of_dealer.setPosition(1350, 370);

    static sf::Text sround;
    sround.setFont(font);
    sround.setCharacterSize(56);
    sround.setFillColor(sf::Color::White);
    sround.setPosition(900, 3);

    static sf::Sprite bplace(place);
    bplace.setPosition(600, 600);

    static sf::Sprite bclear(clear);
    bclear.setPosition(600, 500);

    static sf::Sprite bhit(hit);
    bhit.setPosition(1250, 600);

    static sf::Sprite bstand(stand);
    bstand.setPosition(1200, 700);

    static sf::Sprite bdouble(dob);
    bdouble.setPosition(1175, 800);

    static sf::Sprite beasy(easy);
    beasy.setPosition(160, 300);

    static sf::Sprite bmedium(medium);
    bmedium.setPosition(372, 305);

    static sf::Sprite bhard(hard);
    bhard.setPosition(678, 300);

    static sf::Sprite byes(yes);
    byes.setPosition(320, 290);

    static sf::Sprite bno(no);
    bno.setPosition(511, 290);

    static sf::Text victory;
    victory.setFont(font);
    victory.setString("Victory!");
    victory.setCharacterSize(76);
    victory.setFillColor(sf::Color::Blue);
    victory.setPosition(355, 40);

    static sf::Text defeat;
    defeat.setFont(font);
    defeat.setString("Defeat!");
    defeat.setCharacterSize(76);
    defeat.setFillColor(sf::Color::Red);
    defeat.setPosition(355, 40);

    static sf::Text endmessage;
    endmessage.setFont(font);
    endmessage.setString("Play again?");
    endmessage.setCharacterSize(76);
    endmessage.setFillColor(sf::Color::White);
    endmessage.setPosition(290, 170);

    sback.setPosition(30, 80);

    int16_t money = 0; // Player's money
    int16_t enemymoney = 0; // Dealer's money
    int16_t max = 1000; // Limits on the bet
    int16_t nbet = 0; // Bet
    std::size_t round = 1; // Rounds

    bool life = false; // Player life indicator
    bool move = true; // Player click indicator 
    bool show_power = true; // Show power of cards indicator 
    bool betprocess = true; // Bet progress indicator
    bool game = true; // Game indicator

    std::random_device rd; // Random number generator
    std::mt19937 g(rd());

    sf::Image icon; // Creating and downloading icons for windows
    icon.loadFromFile("Images/ace.png");

    while(game) 
    {// Difficulty selection window
        sf::RenderWindow beg(sf::VideoMode(1000, 563), "Blackjack", sf::Style::Close);
        beg.setFramerateLimit(60);
        beg.setIcon(32, 32, icon.getPixelsPtr());
        while (beg.isOpen())
        {
            sf::Event event;
            while (beg.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    beg.close();
                    game = false;
                }
            }

            beg.clear(sf::Color(0, 64, 0, 0)); // Display sprites
            beg.draw(logo);
            beg.draw(choice);
            beg.draw(beasy);
            beg.draw(bmedium);
            beg.draw(bhard);
            beg.display();
            // Choice of difficulties
            if (move && event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
            {
                int x = sf::Mouse::getPosition(beg).x;
                int y = sf::Mouse::getPosition(beg).y;

                if ((x >= 160 && x <= 342) && (y >= 300 && y <= 387)) { // Easy difficulty
                    money = 8000;
                    enemymoney = 2000;
                    show_power = true;
                    life = true;
                    move = false;
                }
                else if ((x >= 372 && x <= 648) && (y >= 305 && y <= 376)) { // Medium difficulty
                    money = 5000;
                    enemymoney = 5000;
                    show_power = true;
                    life = true;
                    move = false;
                }
                else if ((x >= 678 && x <= 850) && (y >= 300 && y <= 377)) { // Hard difficulty
                    money = 2000;
                    enemymoney = 8000;
                    show_power = false;
                    life = true;
                    move = false;
                }
            }
            if (!move && event.type == sf::Event::MouseButtonReleased) { move = true; }

            if (life) {
                round = 1;
                balance.setString("Your balance: " + std::to_string(money));
                enemybalance.setString("Dealer's balance: " + std::to_string(enemymoney));
                sround.setString("Round: " + std::to_string(round));
                beg.close();
            }
        }

        while (life) 
        {// Game window
            sf::RenderWindow window(sf::VideoMode(1440, 900), "Blackjack", sf::Style::Close);
            window.setFramerateLimit(60);
            window.setIcon(32, 32, icon.getPixelsPtr());

            bool bj = false; // Player's blackjack indicator
            bool ebj = false; // Dealer's blackjack indicator

            int8_t beginhit = 0;
            int8_t beginenemyhit = 0;
            int8_t hit = 2;
            int8_t enemyhit = 2;
            int8_t power = 0;
            int8_t enemypower = 0;
            int8_t show = 0;
            int8_t partofgame = 0;
            int8_t countace = 0;
            int8_t countenemyace = 0;

            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        game = false;
                        life = false;
                    }
                }

                window.clear(sf::Color(0, 64, 0, 0));

                if (betprocess) { // The bet process
                    if (std::min(money, enemymoney) > 1000) { max = 1000; }
                    else { max = std::min(money, enemymoney); }
                    maxbet.setString("Max bet: " + std::to_string(max));

                    for (int i = 0; i < 5; ++i) { window.draw(schip[i]); }
                    nowbet.setString("Place your bet: " + std::to_string(nbet));

                    window.draw(nowbet); // Display sprites
                    window.draw(balance);
                    window.draw(enemybalance);
                    window.draw(maxbet);
                    window.draw(bclear);
                    window.draw(bplace);
                    window.draw(sround);
                    window.display();
                    // Choice of clicking on a chip
                    if (move && event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
                    {
                        int x = sf::Mouse::getPosition(window).x;
                        int y = sf::Mouse::getPosition(window).y;

                        if ((x >= 525 && x <= 575) && (y >= 400 && y <= 450) 
                                && ((x - 550) * (x - 550) + (y - 425) * (y - 425) <= 625) && nbet + 1 < max)
                        {
                            ++nbet;
                            move = false;
                        } 
                        else if ((x >= 600 && x <= 650) && (y >= 400 && y <= 450) 
                                && ((x - 625) * (x - 625) + (y - 425) * (y - 425) <= 625) && nbet + 10 <= max) 
                        {
                            nbet += 10;
                            move = false;
                        } 
                        else if ((x >= 675 && x <= 725) && (y >= 400 && y <= 450) 
                                && ((x - 700) * (x - 700) + (y - 425) * (y - 425) <= 625) && nbet + 100 <= max)
                        {
                            nbet += 100;
                            move = false;
                        } 
                        else if ((x >= 750 && x <= 800) && (y >= 400 && y <= 450) 
                                && ((x - 775) * (x - 775) + (y - 425) * (y - 425) <= 625) && nbet + 1000 <= max) 
                        {
                            nbet += 1000;
                            move = false;
                        } 
                        else if ((x >= 825 && x <= 875) && (y >= 400 && y <= 450) 
                            && ((x - 850) * (x - 850) + (y - 425) * (y - 425) <= 625)) 
                        {
                            nbet = max;
                            move = false;
                        } 
                        else if ((x >= 600 && x <= 794) && (y >= 500 && y <= 572) && nbet > 0) { 
                            nbet = 0;
                            move = false;
                        } 
                        else if ((x >= 600 && x <= 806) && (y >= 600 && y <= 678) && nbet > 0) {
                            move = false;
                            betprocess = false;
                            enemybalance.setPosition(30, 405);
                            balance.setPosition(30, 330);

                            if (!player.empty()) { player.clear(); }
                            if (!enemy.empty()) { enemy.clear(); }

                            std::shuffle(Cards.begin(), Cards.end(), g); // Shuffle vector of tuples

                            for (std::size_t i = 0; i < 10; ++i) { // Filling player's vector
                                Card temp;
                                sf::Sprite st(Cards[i].first);
                                temp.power = Cards[i].second;
                                st.setPosition(30 + (160 * i), 600);
                                temp.sprite = st;
                                player.push_back(temp);
                            }

                            for (std::size_t i = 0; i < 10; ++i) { // Filling dealer's vector
                                Card temp;
                                sf::Sprite st(Cards[i + 10].first);
                                temp.power = Cards[i + 10].second;
                                st.setPosition(30 + (160 * i), 80);
                                temp.sprite = st;
                                enemy.push_back(temp);
                            }

                            bet.setString("Bet: " + std::to_string(nbet));

                            bj = false;
                            ebj = false;

                            beginhit = 0;
                            beginenemyhit = 0;
                            hit = 2;
                            enemyhit = 2;
                            power = 0;
                            enemypower = 0;
                            show = 0;
                            partofgame = 0;
                            countace = 0;
                            countenemyace = 0;
                        }
                    }
                    if (!move && event.type == sf::Event::MouseButtonReleased) { move = true; }
                }

                else if (!betprocess) { // The process of fighting with a dealer
                    for (int i = 0; i < hit; ++i) { 
                        window.draw(player[i].sprite);
                    }

                    for (int i = 0; i < enemyhit; ++i) {
                        if (show == 0 && i == 0) { 
                            window.draw(sback);
                        } else { 
                            window.draw(enemy[i].sprite);
                        }
                    }

                    window.draw(balance); // Display sprites
                    window.draw(enemybalance);
                    window.draw(yourcards);
                    window.draw(dealercards);
                    window.draw(bet);
                    window.draw(bhit);
                    window.draw(sround);

                    if (show_power && beginhit != 0) { window.draw(text_power_of_player); }
                    if (show_power && partofgame == 3) { window.draw(text_power_of_dealer); }

                    if (2 * nbet <= max && nbet != 0) { window.draw(bdouble); }
                    window.draw(bstand);

                    if (show == 1) { window.draw(blackjack); } // Rendering end-of-battle sprites
                    else if (show == 2) { window.draw(lost); }
                    else if (show == 3) { window.draw(won); }
                    else if (show == 4) { window.draw(draw); }
                    else if (show == 5) { window.draw(s21); }
                    else if (show == 6) { window.draw(bust); }

                    window.display();

                    if (partofgame == 3) { // The end of the battle 
                        std::this_thread::sleep_for(std::chrono::seconds(5)); // Pause 5 seconds

                        balance.setPosition(30, 5);
                        enemybalance.setPosition(30, 80);
                        balance.setString("Your balance: " + std::to_string(money));
                        enemybalance.setString("Dealer's balance: " + std::to_string(enemymoney));
                        sround.setString("Round: " + std::to_string(++round));
                        nbet = 0;
                        move = true;
                        bj = false;
                        ebj = false;
                        betprocess = true;
                        if (money <= 0 || enemymoney <= 0) { // Checking the availability of money
                            sround.setPosition(340, 420);
                            sround.setString("Rounds: " + std::to_string(--round));
                            life = false;
                            window.close();
                            break;
                        }
                    }
                    // Choosing to continue the fight
                    if (move && event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
                    {
                        int x = sf::Mouse::getPosition(window).x;
                        int y = sf::Mouse::getPosition(window).y;

                        if ((x >= 1250 && x <= 1358) && (y >= 600 && y <= 673) && partofgame == 0) { 
                            ++hit;
                            move = false;
                        } 
                        else if ((x >= 1200 && x <= 1409) && (y >= 700 && y <= 777) && partofgame == 0) { 
                            partofgame = 1;
                            move = false;
                        } 
                        else if ((x >= 1175 && x <= 1425) && (y >= 800 && y <= 873) && partofgame == 0 && 2 * nbet <= max) {
                            nbet *= 2;
                            hit++;
                            bet.setString("Bet: " + std::to_string(nbet));
                            partofgame = 1;
                            move = false;
                        }
                    }
                    if (!move && event.type == sf::Event::MouseButtonReleased) { move = true; }

                    for (int i = beginhit; i < hit; ++i) { // Calculation of player's cards strengths
                        if (player[i].power == 1 && power + 11 <= 21) { 
                            ++countace;
                            power += 11;
                        } else if (player[i].power == 1 && power + 11 > 21) { 
                            ++power;
                        }

                        if (player[i].power >= 10) { 
                            power += 10;
                        } else if (player[i].power < 10 && player[i].power > 1) { 
                            power += player[i].power;
                        }

                        if (i < 2 && power == 21) { 
                            bj = true;
                            break;
                        } else if (countace > 0 && power > 21) { 
                            power -= 10;
                            --countace;
                        }
                    }
                    beginhit = hit;
                    text_power_of_player.setString(std::to_string(power));

                    for (int i = beginenemyhit; i < enemyhit; ++i) { // Calculation of dealer's cards strengths
                        if (enemy[i].power == 1 && enemypower + 11 <= 21) { 
                            ++countenemyace;
                            enemypower += 11;
                        } else if (enemy[i].power == 1 && enemypower + 11 > 21) {
                            ++enemypower;
                        }

                        if (enemy[i].power >= 10) {
                            enemypower += 10;
                        } else if (enemy[i].power < 10 && enemy[i].power > 1) {
                            enemypower += enemy[i].power;
                        }

                        if (i < 2 && enemypower == 21) { 
                            ebj = true;
                            break;
                        } else if (countenemyace > 0 && enemypower > 21) { 
                            enemypower -= 10;
                            --countenemyace;
                        }
                    }
                    beginenemyhit = enemyhit;
                    text_power_of_dealer.setString(std::to_string(enemypower));

                    if (partofgame == 0) { // During the battle process
                        if (bj && !ebj) { // A case of blackjack at the player
                            bet.setString("Bet: " + std::to_string(nbet));
                            blackjack.setFillColor(sf::Color::Blue);
                            show = 1;
                            money += (3 * nbet / 2);
                            enemymoney -= (3 * nbet / 2);
                            partofgame = 3;
                        }
                        else if (ebj && !bj) { // A case of blackjack at the dealer
                            bet.setString("Bet: " + std::to_string(nbet));
                            blackjack.setFillColor(sf::Color::Red);
                            show = 1;
                            enemymoney += (3 * nbet / 2);
                            money -= (3 * nbet / 2);
                            partofgame = 3;
                        }
                        else if (ebj && bj) { // A case of blackjack for both
                            show = 4;
                            nbet = 0;
                            partofgame = 3;
                        }
                        else if (power == 21) { // A case of 21 points for a player
                            s21.setFillColor(sf::Color::Blue);
                            show = 5;
                            money += nbet;
                            enemymoney -= nbet;
                            partofgame = 3;
                        }
                        else if (power > 21) { // A case of player bust
                            bust.setFillColor(sf::Color::Red);
                            show = 6;
                            enemymoney += nbet;
                            money -= nbet;
                            partofgame = 3;
                        }
                    }

                    else if (partofgame == 1) { // The stand or double button is pressed
                        if (power == 21) { // A case of 21 points for a player
                            s21.setFillColor(sf::Color::Blue);
                            show = 5;
                            money += nbet;
                            enemymoney -= nbet;
                            partofgame = 3;
                        }
                        else if (power > 21) { // A case of player bust
                            bust.setFillColor(sf::Color::Red);
                            show = 6;
                            enemymoney += nbet;
                            money -= nbet;
                            partofgame = 3;
                        }
                        else if (enemypower < 17) { ++enemyhit; } // The dealer takes cards

                        else {
                            if (enemypower > 21) { // A case of dealer bust
                                bust.setFillColor(sf::Color::Blue);
                                show = 6;
                                enemymoney -= nbet;
                                money += nbet;
                                partofgame = 3;
                            }
                            else if (enemypower < power) { // The dealer has fewer points
                                show = 3;
                                enemymoney -= nbet;
                                money += nbet;
                                partofgame = 3;
                            }
                            else if (enemypower == 21) { // A case of 21 points at the dealer
                                s21.setFillColor(sf::Color::Red);
                                show = 5;
                                enemymoney += nbet;
                                money -= nbet;
                                partofgame = 3;
                            }
                            else if (enemypower > power) { // The dealer has more points
                                show = 2;
                                enemymoney += nbet;
                                money -= nbet;
                                partofgame = 3;
                            }
                            else if (enemypower == power) { // The dealer has the same number of points
                                show = 4;
                                nbet = 0;
                                partofgame = 3;
                            }
                        }
                    }
                }
            }

            if (!life && game) { // Game result window
                sf::RenderWindow endwindow(sf::VideoMode(1000, 563), "Blackjack", sf::Style::Close);
                endwindow.setFramerateLimit(60);
                endwindow.setIcon(32, 32, icon.getPixelsPtr());
                while (endwindow.isOpen()) 
                {
                    sf::Event event;
                    while (endwindow.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed) {
                            endwindow.close();
                            game = false;
                        }
                    }

                    endwindow.clear(sf::Color(0, 64, 0, 0));

                    if (money <= 0) { endwindow.draw(defeat); }
                    else { endwindow.draw(victory); }

                    endwindow.draw(endmessage); // Display sprites
                    endwindow.draw(byes);
                    endwindow.draw(bno);
                    endwindow.draw(sround);
                    endwindow.display();
                    // Selecting a new game or exiting the game
                    if (move && event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
                    {
                        int x = sf::Mouse::getPosition(endwindow).x;
                        int y = sf::Mouse::getPosition(endwindow).y;

                        if ((x >= 320 && x <= 471) && (y >= 290 && y <= 364)) { // New game
                            sround.setPosition(900, 3);
                            move = false;
                            endwindow.close();
                            break;
                        }
                        else if ((x >= 511 && x <= 620) && (y >= 290 && y <= 367)) { // Quit the game
                            game = false;
                            move = false;
                            endwindow.close();
                            break;
                        }
                    }
                    if (!move && event.type == sf::Event::MouseButtonReleased) { move = true; }
                }
            }
        }
    }
    return 0;
}