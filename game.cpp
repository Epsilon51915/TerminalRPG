#include "game.hpp"

using namespace std;

//----------------------------------[Constructor]-----------------------------------------------
Game::Game()
{
    encounters_ = 0;
    text_speed_ = 2000ms;
    Player player;
    Enemy enemy;
}

//----------------------------------[Setters]---------------------------------------------------
void Game::setPlayer(Player p)
{
    player_ = p;
}

Player Game::getPlayer()
{
    return player_;
}

//----------------------------------[Sleep For + Related Functions]-----------------------------
chrono::duration <double, milli> Game::getTextSpeed()
{   
    return text_speed_;
}

void Game::sleepFor()
{
    this_thread::sleep_for(text_speed_);
}

//----------------------------------[Intro Functions]-------------------------------------------
void Game::displayIntro()
{
    cout << R"str(
    |   |                                                         |   |
    |   |                                                         |   |
    |   |                                                         |   |
   /    |                                                         |    \
   |   /                                                           \    |
   |   |                                                            |   |
  /    |                                                            |    \
  |   /                                                              \    |
  |   |                                                               |   |
  |   |---[]---[]---[]---[]---[]---[]---[]---[]---[]---[]---[]---[]---|   |
  |   |                                                               |   |
 /    | Terminal RPG - A Terminal - Based RPG. If you can believe it. |   |
 |   /                 (Aren't all RPG's terminal?)                    \   \
 |   |-----------------------------------------------------------------|   |
 |   |                                                                 |   |
 |   |                                                                 |   |
 |   |                                                                 |   |
/    |                                                                 |   |
|   /                                                                   \   \
|   |                                                                   |   |
|   |                                                                   |   |
|   |                                                                   |   |
|   |                                                                   |   |
|   |                                                                   |   |
)str";
    sleepFor();
}

void Game::displayLore()
{
    cout << "Yeah there's a king in a castle doing shady stuff probably." << endl;
    sleepFor();
    cout << "Probably planning on raising taxes again." << endl;
    sleepFor();
    cout << "Or hosting a badmitton tournament." << endl;
    sleepFor();
    cout << "You should stop him. Maybe. I don't care." << endl << endl;
    sleepFor();
}

string Game::promptAndGetName()
{
    string name;
    cout << "What is your name?" << endl;
    getline(cin, name);
    cout << endl;
    return name;
}

int Game::selectScreen(){

    int input;
    string temp;

    do
    {
    cout << endl << endl << "Options: " << endl;
    cout << "[1. Start Game]" << "     [2. About]" << endl;
    cout << endl;
    cout << "[3. Patreon(?)]" << "     [4. Close Game]" << endl;
    cout << endl;
    getline(cin, temp);
    input = stoi(temp); // FIX THIS <-----
    cout << endl;
    switch (input)
        {
        case 1:
            cout << "Beginning game!!" << endl << endl;
            sleepFor();
            break;

        case 2:
            cout << "This is a small RPG created by a bored CSCI student" << endl;
            sleepFor();
            cout << "spanning X lines of C++ code, this is a tiny passion project" << endl;
            sleepFor();
            cout << "that has no purpose besides proving to myself that I can" << endl;
            sleepFor();
            cout << "do this. With that being said, enjoy!" << endl;
            sleepFor();
            break;

        case 3:
            text_speed_ = 750ms;
            cout << "My Patreon is" << endl;
            sleepFor();
            cout << "up your ass!" << endl;
            sleepFor();
            text_speed_ = 2000ms;
            break;

        case 4:
            text_speed_ = 500ms;
            cout << "Exiting program . . ." << endl;
            sleepFor();
            cout << ". . ." << endl;
            sleepFor();
            cout << ". . ." << endl;
            sleepFor();
            return input;
            break;
        
        default:
            cout << "It seems like you're not good with numbers!" << endl;
            sleepFor();
            cout << "Don't worry, a lot of people aren't!" << endl;
            sleepFor();
            cout << "So we can try this again." << endl;
            sleepFor();
            cout << "You've got this!" << endl;
            sleepFor();
            break;
        }
    } while(input !=  1);

    return input;
}

bool Game::getAllEnemies()
{
    ifstream is;
    is.open("Enemies.txt");
    vector<Enemy> all_enemies;
    string separator;
    string token;

    if(is.fail())
    {
        return false;
    }
    getline(is, separator);
    getline(is, separator);

    Enemy temporary;

    while(getline(is, separator))
    {
        stringstream splitter(separator);
        getline(splitter, token, ',');
        temporary.setEnemyName(token);

        getline(splitter, token, ',');
        temporary.setEnemyHP(stoi(token));

        getline(splitter, token, ',');
        temporary.setEnemyATK(stoi(token));
        
        getline(splitter, token, ',');
        temporary.setEnemyDEF(stoi(token));

        getline(splitter, token, ',');
        temporary.setEnemySPD(stoi(token));

        getline(splitter, token, ',');
        temporary.setEnemyMGKATK(stoi(token));

        getline(splitter, token, ',');
        temporary.setEnemyMGKDEF(stoi(token));

        getline(splitter, token, ',');
        temporary.setEnemyLVL(stoi(token));

        getline(splitter, token, ',');
        temporary.setEnemyID(stoi(token));

        getline(splitter, token);
        temporary.setEnemyDescription(token);

        all_enemies.push_back(temporary);
    }

    all_enemies_ = all_enemies;
    return true;
}

void Game::setSeed(int seed)
{
    srand(seed);
}

//-----------------------------------[Game Functions]-------------------------------------------
bool Game::menu()
{
    cout << "[1. Travel]            [2. Check Stats]" <<  endl;
    cout << "[3. Check Items]       {4. Monster Catalogue}" << endl;
    cout << "[5. Settings]          [6. Exit Game]" << endl;
    cout << "Select an Option: ";
    int player_selection;
    int choice;
    cin >> player_selection;
    cout << endl;
    switch (player_selection)
    {
    case 1:
        cout << "Beginning travels..." << endl;
        sleepFor();
        if(!travel())
        {
            // Call DEATH fucntion
            deathGameOver();
            return false;
        }
        if (player_.getPlayerAreaInt() == 5)
        {
            return true;
        }
        // Check if player area is post-castle. If so, end the game.
        break;

    case 2:
        cout << "Checking stats..." << endl;
        sleepFor();
        player_.getStats();
        sleepFor();
        break;

    case 3:
        cout << "Opening inventory..." << endl;
        sleepFor();
        player_.displayInventory();
        sleepFor();
        break;

    case 4:
        cout << "Dusting off the Monster Catalogue..." << endl;
        sleepFor();
        displayMonsterCataloguePage(displayMonsterCatalogueMenu());
        break;

    case 5:
        cout << "Opening Settings..." << endl;
        sleepFor();
        choice = showSettings();
        sleepFor();
        if (choice == 1)
        {
            changeSettings(choice);
        }
        else{};
        break;

    case 6:
        cout << "Exiting game..." << endl;
        text_speed_ = 500ms;
        sleepFor();
        cout << ". . ." << endl;
        sleepFor();
        cout << ". . ." << endl;
        sleepFor();
        cout << ". . ." << endl;
        return false;
        break;

    default:
        cout << "Error Message. Don't be a moron." << endl;
        cin.clear();
        cin.ignore();
        break;
    }
    return true;
}

string Game::processString(const string& text)
{
    string output{text};
    output = regex_replace(output, regex{"%name%"}, player_.getName());
    return output;
}

int Game::displayMonsterCatalogueMenu()
{
    int area;
    do
    {
    cout << "[Area 1: Plains]" << endl;
    cout << "[Area 2: Forest]" << endl;
    cout << "[Area 3: Mountain]" << endl;
    cout << "[Area 4: Castle]" << endl;
    cout << "Select an area: ";
    cin >> area;
    if(area < 1 || area > 4)
    {
        cout << "Nope." << endl;
        cin.clear();
        cin.ignore();
    }
    } while (area < 1 || area > 4);
    cout << endl;
    return area;
}

void Game::displayMonsterCataloguePage(int area)
{
    switch(area)
    {
        case 1:
        cout << "Plains Enemies:" << endl;
        cout << "*----*----*----*----*----*----*----*" << endl;
        for(int i = 0; i < 5; i++)
        {
            cout << "Name: " << all_enemies_[i].getEnemyName() << endl;
            cout << "HP: " << all_enemies_[i].getEnemyHP() << endl;
            cout << "ATK: " << all_enemies_[i].getEnemyATK() << endl;
            cout << "DEF: " << all_enemies_[i].getEnemyDEF() << endl;
            cout << "SPD: " << all_enemies_[i].getEnemySPD() << endl;
            cout << "MGK_ATK: " << all_enemies_[i].getEnemyMGKATK() << endl;
            cout << "MGK_DEF: " << all_enemies_[i].getEnemyMGKDEF() << endl;
            cout << "LVL: " << all_enemies_[i].getEnemyLVL() << endl;
            cout << processString(all_enemies_[i].getEnemyDescription()) << endl;
            cout << "*----*----*----*----*----*----*----*" << endl;
        }
            break;

        case 2:
        cout << "Forest Enemies:" << endl;
        cout << "*----*----*----*----*----*----*----*" << endl;
        for(int i = 1; i < 3; i++)
        {
            cout << "Name: " << all_enemies_[i].getEnemyName() << endl;
            cout << "HP: " << all_enemies_[i].getEnemyHP() << endl;
            cout << "ATK: " << all_enemies_[i].getEnemyATK() << endl;
            cout << "DEF: " << all_enemies_[i].getEnemyDEF() << endl;
            cout << "SPD: " << all_enemies_[i].getEnemySPD() << endl;
            cout << "MGK_ATK: " << all_enemies_[i].getEnemyMGKATK() << endl;
            cout << "MGK_DEF: " << all_enemies_[i].getEnemyMGKDEF() << endl;
            cout << "LVL: " << all_enemies_[i].getEnemyLVL() << endl;
            cout << processString(all_enemies_[i].getEnemyDescription()) << endl;
            cout << "*----*----*----*----*----*----*----*" << endl;
        }
        for(int i = 5; i < 9; i++)
        {
            cout << "Name: " << all_enemies_[i].getEnemyName() << endl;
            cout << "HP: " << all_enemies_[i].getEnemyHP() << endl;
            cout << "ATK: " << all_enemies_[i].getEnemyATK() << endl;
            cout << "DEF: " << all_enemies_[i].getEnemyDEF() << endl;
            cout << "SPD: " << all_enemies_[i].getEnemySPD() << endl;
            cout << "MGK_ATK: " << all_enemies_[i].getEnemyMGKATK() << endl;
            cout << "MGK_DEF: " << all_enemies_[i].getEnemyMGKDEF() << endl;
            cout << "LVL: " << all_enemies_[i].getEnemyLVL() << endl;
            cout << processString(all_enemies_[i].getEnemyDescription()) << endl;
            cout << "*----*----*----*----*----*----*----*" << endl;
        }
            break;

        case 3:
        cout << "Mountain Enemies:" << endl;
        cout << "*----*----*----*----*----*----*----*" << endl;
        for(int i = 2; i < 3; i++)
        {
            cout << "Name: " << all_enemies_[i].getEnemyName() << endl;
            cout << "HP: " << all_enemies_[i].getEnemyHP() << endl;
            cout << "ATK: " << all_enemies_[i].getEnemyATK() << endl;
            cout << "DEF: " << all_enemies_[i].getEnemyDEF() << endl;
            cout << "SPD: " << all_enemies_[i].getEnemySPD() << endl;
            cout << "MGK_ATK: " << all_enemies_[i].getEnemyMGKATK() << endl;
            cout << "MGK_DEF: " << all_enemies_[i].getEnemyMGKDEF() << endl;
            cout << "LVL: " << all_enemies_[i].getEnemyLVL() << endl;
            cout << processString(all_enemies_[i].getEnemyDescription()) << endl;
            cout << "*----*----*----*----*----*----*----*" << endl;
        }
        for(int i = 6; i < 7; i++)
        {
            cout << "Name: " << all_enemies_[i].getEnemyName() << endl;
            cout << "HP: " << all_enemies_[i].getEnemyHP() << endl;
            cout << "ATK: " << all_enemies_[i].getEnemyATK() << endl;
            cout << "DEF: " << all_enemies_[i].getEnemyDEF() << endl;
            cout << "SPD: " << all_enemies_[i].getEnemySPD() << endl;
            cout << "MGK_ATK: " << all_enemies_[i].getEnemyMGKATK() << endl;
            cout << "MGK_DEF: " << all_enemies_[i].getEnemyMGKDEF() << endl;
            cout << "LVL: " << all_enemies_[i].getEnemyLVL() << endl;
            cout << processString(all_enemies_[i].getEnemyDescription()) << endl;
            cout << "*----*----*----*----*----*----*----*" << endl;
        }
        for(int i = 9; i < 14; i++)
        {
            cout << "Name: " << all_enemies_[i].getEnemyName() << endl;
            cout << "HP: " << all_enemies_[i].getEnemyHP() << endl;
            cout << "ATK: " << all_enemies_[i].getEnemyATK() << endl;
            cout << "DEF: " << all_enemies_[i].getEnemyDEF() << endl;
            cout << "SPD: " << all_enemies_[i].getEnemySPD() << endl;
            cout << "MGK_ATK: " << all_enemies_[i].getEnemyMGKATK() << endl;
            cout << "MGK_DEF: " << all_enemies_[i].getEnemyMGKDEF() << endl;
            cout << "LVL: " << all_enemies_[i].getEnemyLVL() << endl;
            cout << processString(all_enemies_[i].getEnemyDescription()) << endl;
            cout << "*----*----*----*----*----*----*----*" << endl;
        }
            break;

        case 4:
        cout << "Castle Enemies:" << endl;
        cout << "*----*----*----*----*----*----*----*" << endl;
        for(int i = 14; i < 22; i++)
        {
            cout << "Name: " << all_enemies_[i].getEnemyName() << endl;
            cout << "HP: " << all_enemies_[i].getEnemyHP() << endl;
            cout << "ATK: " << all_enemies_[i].getEnemyATK() << endl;
            cout << "DEF: " << all_enemies_[i].getEnemyDEF() << endl;
            cout << "SPD: " << all_enemies_[i].getEnemySPD() << endl;
            cout << "MGK_ATK: " << all_enemies_[i].getEnemyMGKATK() << endl;
            cout << "MGK_DEF: " << all_enemies_[i].getEnemyMGKDEF() << endl;
            cout << "LVL: " << all_enemies_[i].getEnemyLVL() << endl;
            cout << processString(all_enemies_[i].getEnemyDescription()) << endl;
            cout << "*----*----*----*----*----*----*----*" << endl;
        }
            break;
    }
}

bool Game::travel()
{
    encounters_++;
    if(encounters_ == 10 && player_.getPlayerArea() == "Plains")
    {
        encounters_ = 0;
        player_.changePlayerArea();
        // Get Boss Enemy
        cout << "You have made it to the Forest area!" << endl;
        sleepFor();
    }
    else if(encounters_ == 15 && player_.getPlayerArea() == "Forest")
    {
        encounters_ = 0;
        player_.changePlayerArea();
        // Get Boss Enemy
        cout << "You have made it to the Mountains area!" << endl;
        sleepFor();
    }
    else if(encounters_ == 20 && player_.getPlayerArea() == "Mountains")
    {
        encounters_ = 0;
        player_.changePlayerArea();
        // Get Boss Enemy
        cout << "You have made it to the Castle area!" << endl;
        sleepFor();
    }
    else if(encounters_ == 20 && player_.getPlayerArea() == "Castle")
    {
        encounters_ = 0;
        // Get Boss Enemy
        cout << "Congratulations, you have completed the game!" << endl;
        sleepFor();
        player_.changePlayerArea();
        // Call game over - WIN - function
    }
    else
    {
        switch(player_.getPlayerAreaInt())
        {
            case 1:
                // Get random enemy from plains
                getPlainsEnemy();
                randomiseEnemyStats();
                // Combat
                // Check if player died (if died, return false)
                if(combat())
                {
                    // Check for level up
                    if(player_.checkForLevelUp())
                    {
                        player_.levelUp();
                    }
                }
                else
                {
                    return false;
                }
                break;

            case 2:
                getForestEnemy();
                randomiseEnemyStats();

                if(combat())
                {
                    // Check for level up
                    if(player_.checkForLevelUp())
                    {
                        player_.levelUp();
                    }
                }
                else
                {
                    return false;
                }
                break;

            case 3:
                getMountainEnemy();
                randomiseEnemyStats();

                if(combat())
                {
                    // Check for level up
                    if(player_.checkForLevelUp())
                    {
                        player_.levelUp();
                    }
                }
                else
                {
                    return false;
                }
                break;

            case 4:
                getCastleEnemy();
                randomiseEnemyStats();

                if(combat())
                {
                    // Check for level up
                    if(player_.checkForLevelUp())
                    {
                        player_.levelUp();
                    }
                }
                else
                {
                    return false;
                }
                break;
        }
    }
    return true;
}

int Game::getRandomNumber()
{
    return rand();
}

void Game::deathGameOver()
{
    sleepFor();
    sleepFor();
    cout << "You have died!" << endl;
    sleepFor();
    cout << "Final stats: " << endl;
    sleepFor();
    player_.getStats();
    sleepFor();
}

//-----------------------------------[Combat Functions]-----------------------------------------
void Game::getPlainsEnemy()
{
    int random = getRandomNumber() % 100;
    if(player_.getLVL() <= 2)
    {
        if(random > 95) // 96 - 100 -> 5%
        {
            enemy_ = all_enemies_[4];
        }
        else if(random > 65) // 66 - 95 -> 30%
        {
            enemy_ = all_enemies_[3];
        }
        else if(random > 55) // 56 - 65 -> 10%
        {
            enemy_ = all_enemies_[2];
        }
        else if(random > 35) // 36 - 55 -> 20%
        {
            enemy_ = all_enemies_[1];  
        }
        else // 0 - 35 -> 35%
        {
            enemy_ = all_enemies_[0];
        }
    }
    else
    {
        if(random > 85) // 86 - 100 -> 15%
        {
            enemy_ = all_enemies_[4];
        }
        else if(random > 60) // 61 - 85 -> 25%
        {
            enemy_ = all_enemies_[3];
        }
        else if(random > 40) // 41 - 60 -> 20%
        {
            enemy_ = all_enemies_[2];
        }
        else if(random > 20) // 21 - 40 -> 20%
        {
            enemy_ = all_enemies_[1];  
        }
        else // 0 - 20 -> 20%
        {
            enemy_ = all_enemies_[0];
        }
    }
}

void Game::getForestEnemy()
{
    int random = getRandomNumber() % 100;
    // 1, 2, 5, 6, 7, 8
    if(player_.getLVL() <= 3)
    {
        if(random < 15) // 0 - 14 -> 15%
        {
            enemy_ = all_enemies_[1];
        }  
        else if(random < 30) // 15 - 29 -> 15%
        {
            enemy_ = all_enemies_[2];
        }
        else if(random < 40) // 30 - 39 -> 10%
        {
            enemy_ = all_enemies_[5];
        }
        else if(random < 75) // 40 - 74 -> 35%
        {
            enemy_ = all_enemies_[6];
        }
        else if(random < 95) // 75 - 94 -> 20%
        {
            enemy_ = all_enemies_[7];
        }
        else // 96 - 100 -> 5%
        {
            enemy_ = all_enemies_[8];
        }
    }
    else
    {
        if(random < 10) // 0 - 9 -> 10%
        {
            enemy_ = all_enemies_[1];
        }  
        else if(random < 20) // 10 - 19 -> 10%
        {
            enemy_ = all_enemies_[2];
        }
        else if(random < 45) // 20 - 44 -> 25%
        {
            enemy_ = all_enemies_[5];
        }
        else if(random < 60) // 45 - 59 -> 15%
        {
            enemy_ = all_enemies_[6];
        }
        else if(random < 90) // 60 - 89 -> 20%
        {
            enemy_ = all_enemies_[7];
        }
        else // 90 - 100 -> 10%
        {
            enemy_ = all_enemies_[8];
        }
    }
}

void Game::getMountainEnemy()
{
    // 2, 6, 9, 10, 11, 12, 13
    int random = getRandomNumber() % 100;
    if(player_.getLVL() <= 5)
    {
        if(random < 15) // 0 - 14 -> 15% (L. rock)
        {
            enemy_ = all_enemies_[2];
        }
        else if(random < 35) // 15 - 34 -> 20% (Spider)
        {
            enemy_ = all_enemies_[6];
        }
        else if(random < 65) // 35 - 64 -> 30% (R. Snake)
        {
            enemy_ = all_enemies_[10];
        }
        else if(random < 75) // 65 - 74 -> 10% (Golem)
        {
            enemy_ = all_enemies_[11];
        }
        else if(random < 90) // 75 - 89 -> 15% (Skeleton Climber)
        {
            enemy_ = all_enemies_[12];
        }
        else if (random < 98) // 90 - 97 -> 8% (O. Feast)
        {
            enemy_ = all_enemies_[13];
        }
        else // 98 - 99 -> 2% (Boulder)
        {
            enemy_ = all_enemies_[9];
        }
    }
    else
    {
        if(random < 10) // 0 - 9 -> 10%
        {
            enemy_ = all_enemies_[2];
        }
        else if(random < 20) // 10 - 19 -> 10%
        {
            enemy_ = all_enemies_[6];
        }
        else if(random < 35) // 20 - 34 -> 15%
        {
            enemy_ = all_enemies_[10];
        }
        else if(random < 55) // 25 - 54 -> 20%
        {
            enemy_ = all_enemies_[11];
        }
        else if(random < 75) // 55 - 74 -> 20%
        {
            enemy_ = all_enemies_[12];
        }
        else if (random < 98) // 75 - 97 -> 23%
        {
            enemy_ = all_enemies_[13];
        }
        else // 98 - 99 -> 2%
        {
            enemy_ = all_enemies_[9];
        }
    }
}

void Game::getCastleEnemy()
{
    // 14 - 20 (-1 is weird college student, ID'd at 14)
    int random = getRandomNumber() % 100;
    if(player_.getLVL() <= 7)
    {
        if(random < 22 && random > 0) // 1 - 21 -> 21% 
        {
            enemy_ = all_enemies_[15];
        }
        else if(random < 44) // 22 - 43 -> 22%
        {
            enemy_ = all_enemies_[16];
        }
        else if(random < 66) // 44 - 65 -> 22%
        {
            enemy_ = all_enemies_[17];
        }
        else if(random < 88) // 66 - 87 -> 22%
        {
            enemy_ = all_enemies_[18];
        }
        else if(random > 0) // 88 - 99 -> 12%
        {
            enemy_ = all_enemies_[20];
        }
        else // 0 -> 1%
        {
            enemy_ = all_enemies_[14];
        }
    }
    else
    {
        if(random == 0) // 0 -> 1%
        {
            enemy_ = all_enemies_[14];
        }
        else if(random < 10) // 1 - 9 -> 9%
        {
            enemy_ = all_enemies_[15];
        }
        else if(random < 20) // 10 - 19 -> 10%
        {
            enemy_ = all_enemies_[16];
        }
        else if(random < 30) // 20 - 29 -> 10%
        {
            enemy_ = all_enemies_[17];
        }
        else if(random < 40) // 30 - 39 -> 10%
        {
            enemy_ = all_enemies_[18];
        }
        else if(random < 65) // 40 - 64 -> 25%
        {
            enemy_ = all_enemies_[19];
        }
        else if(random < 80) // 65 - 79 -> 15%
        {
            enemy_ = all_enemies_[20];
        }
        else // 80 - 99 -> 20%
        {
            enemy_ = all_enemies_[21];
        }
    }
}

void Game::randomiseEnemyStats()
{
    int random;
    for(int i = 0; i < 6; i++)
    {
        random = getRandomNumber() % 100;
        switch(player_.getPlayerAreaInt())
        {
            case 1:
                if(random < 25)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() + 1);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() + 1);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() + 1);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() + 1);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() + 1);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() + 1);
                            break;
                    }
                }
                else if(random < 50)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() - 1);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() - 1);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() - 1);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() - 1);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() - 1);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() - 1);
                            break;
                    }
                }
                else{}
                break;

            case 2:
                if(random < 10)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() - 2);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() - 2);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() - 2);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() - 2);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() - 2);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() - 2);
                            break;
                    }
                }
                else if(random < 30)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() - 1);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() - 1);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() - 1);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() - 1);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() - 1);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() - 1);
                            break;
                    }
                }
                else if(random < 55)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() + 1);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() + 1);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() + 1);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() + 1);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() + 1);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() + 1);
                            break;
                    }
                }
                else if(random < 70)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() + 2);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() + 2);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() + 2);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() + 2);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() + 2);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() + 2);
                            break;
                    }
                }
                else{}
                break;

            case 3:
                if(random < 8)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() - 2);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() - 2);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() - 2);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() - 2);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() - 2);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() - 2);
                            break;
                    }
                }
                else if(random < 28)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() - 1);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() - 1);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() - 1);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() - 1);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() - 1);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() - 1);
                            break;
                    }
                }
                else if(random < 63)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() + 1);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() + 1);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() + 1);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() + 1);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() + 1);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() + 1);
                            break;
                    }
                }
                else if(random < 85)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() + 2);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() + 2);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() + 2);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() + 2);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() + 2);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() + 2);
                            break;
                    }
                }
                else{}
                break;

            case 4:
                if(random < 5)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() - 3);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() - 3);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() - 3);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() - 3);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() - 3);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() - 3);
                            break;
                    }
                }
                else if(random < 15)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() - 2);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() - 2);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() - 2);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() - 2);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() - 2);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() - 2);
                            break;
                    }
                }
                else if(random < 40)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() - 1);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() - 1);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() - 1);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() - 1);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() - 1);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() - 1);
                            break;
                    }
                }
                else if(random < 65)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() + 1);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() + 1);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() + 1);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() + 1);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() + 1);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() + 1);
                            break;
                    }
                }
                else if(random < 80)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() + 2);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() + 2);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() + 2);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() + 2);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() + 2);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() + 2);
                            break;
                    }
                }
                else if(random < 90)
                {
                    switch(i)
                    {
                        case 0:
                            enemy_.setEnemyHP(enemy_.getEnemyHP() + 3);
                            break;

                        case 1:
                            enemy_.setEnemyATK(enemy_.getEnemyATK() + 3);
                            break;

                        case 2:
                            enemy_.setEnemyDEF(enemy_.getEnemyDEF() + 3);
                            break;

                        case 3:
                            enemy_.setEnemySPD(enemy_.getEnemySPD() + 3);
                            break;

                        case 4:
                            enemy_.setEnemyMGKATK(enemy_.getEnemyMGKATK() + 3);
                            break;

                        case 5:
                            enemy_.setEnemyMGKDEF(enemy_.getEnemyMGKDEF() + 3);
                            break;
                    }
                }
                else{}
                break;
        }   
    }
    if(enemy_.getEnemyATK() < 0)
    {
        enemy_.setEnemyATK(0);
    }
    if(enemy_.getEnemyDEF() < 0)
    {
        enemy_.setEnemyDEF(0);
    }
    if(enemy_.getEnemySPD() < 0)
    {
        enemy_.setEnemySPD(0);
    }
    if(enemy_.getEnemyMGKATK() < 0)
    {
        enemy_.setEnemyMGKATK(0);
    }
    if(enemy_.getEnemyMGKDEF() < 0)
    {
        enemy_.setEnemyMGKDEF(0);
    }
}

bool Game::combat()
{
    /*
        1. Compare speeds. Higher speed goes first If tie, roll random number for who attacks first.
        2. Unit 1 attacks. Get damage -> deal damage to Unit 2
        3. Check if Unit 2 is dead. If yes, end battle. If no, continue battle.
        4. Unit 2 attacks. Get damage -> deal damage to Unit 1
        NOTE: If the player uses a potion/flask/sand puch, their turn is over. Do NOT let them attack.
        5. Check if Unit 1 is dead. If yes, end battle. If no, continue battle.
        6. Loop from step 1.
    */

    cout << "A " << enemy_.getEnemyName() << " appears!" << endl;
    sleepFor();

    bool battle_over = false;
    bool ran_away = false;
    int random;

    battle_exp_ = (enemy_.getEnemyHP() + enemy_.getEnemyATK() + enemy_.getEnemyDEF() + enemy_.getEnemySPD() + enemy_.getEnemyMGKATK() + enemy_.getEnemyMGKDEF() + enemy_.getEnemyLVL());

    do
    {
        random = getRandomNumber() % 100;
        if(enemy_.getEnemySPD() < player_.getSPD() || (enemy_.getEnemySPD() == player_.getSPD() && random < 50)) // Player goes first
        {
            if(playerTurn())
            {
                if(enemy_.getEnemyHP() <= 0)
                {
                    battle_over = true; 
                }
            }
            else
            {
                battle_over = true;
                ran_away = true;
            }
            
            if(!battle_over)
            {
                enemyTurn();
                if(player_.getHP() <= 0)
                {
                    return false;
                }
            }
        }
        else if(player_.getSPD() < enemy_.getEnemySPD() || (enemy_.getEnemySPD() == player_.getSPD() && random >= 50)) // Enemy goes first
        {
            enemyTurn();
            if(player_.getHP() <= 0)
            {
                return false;
            }
            
            if(playerTurn())
            {
                if(enemy_.getEnemyHP() <= 0)
                {
                    battle_over = true; 
                }
            }
            else
            {
                battle_over = true;
                ran_away = true;
            }
        }
    } while (!battle_over);

    if(!ran_away)
    {
        // Give EXP/Item rewards
        cout << "You defeated a " << enemy_.getEnemyName() << "!" << endl;
        sleepFor();
        cout << "You gained " << battle_exp_ << " exp!" << endl;
        sleepFor();
        player_.setEXP(player_.getEXP() + battle_exp_);
    }
    else{}
    return true;
}

bool Game::playerTurn()
{
    int damage = 0;
    string choice;
    int int_choice;
    // Player attacks. Later add implementation for item usage.
    do
    {
    cout << "[1. Physical Attack]   [2. Magical Attack]" << endl;
    cout << "[3. Items]             [4. Run Away]" << endl;
    getline(cin, choice);
    sleepFor();
    if(choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "I should just forfeit your turn. That's what you deserve for being a moron." << endl;
        sleepFor();
        cin.clear();
        cin.ignore();
        choice = "";
    }
    else
    {
        int_choice = stoi(choice);
        switch(int_choice)
        {
            case 1:
                damage = player_.getATK() - (enemy_.getEnemyDEF() / 2);
                if(damage < 0)
                {
                    damage = 0;
                }
                enemy_.setEnemyHP(enemy_.getEnemyHP() - damage);
                cout << "You dealt " << damage << " damage to " << enemy_.getEnemyName() << "!!" << endl;
                break;

            case 2:
                damage = player_.getMGK_ATK() - (enemy_.getEnemyMGKDEF() / 2);
                if(damage < 0)
                {
                    damage = 0;
                }
                enemy_.setEnemyHP(enemy_.getEnemyHP() - damage);
                cout << "You dealt " << damage << " damage to " << enemy_.getEnemyName() << "!!" << endl;
                break;

            case 3:
                cout << "Sorry, I haven't built the item implementation yet." << endl;
                sleepFor();
                cout << "And because of that, you DID kinda just lose your turn. Sorry." << endl;
                sleepFor();
                cout << "Good Luck!!!" << endl;
                break;

            case 4:
                // Call run away function
                if(runAway())
                {
                    return false;
                }
                break;
        }
    }
    } while(int_choice < 1 || int_choice > 4);
    sleepFor();
    return true;
}

void Game::enemyTurn()
{
    int damage;
    int random = getRandomNumber() % 100;
    // Enemy attacks. If enemy is a rock/college student, do unique battle.
    if(enemy_.getEnemyName() == "Small Rock" || enemy_.getEnemyName() == "Medium Rock" || enemy_.getEnemyName() == "Large Rock")
    {
        cout << enemy_.getEnemyName() << " just sat there. You know. Because it's a rock. Why are you fighting a rock again?" << endl;
    }
    else if(enemy_.getEnemyName() == "Boulder")
    {
        cout << "One must imagine " << player_.getName() << " trying to beat the shit out of a boulder." << endl;
    }
    else if(enemy_.getEnemyName() == "Weird College Student")
    {
        cout << "The kid ran away. Weird." << endl;
        enemy_.setEnemyHP(0);
    }
    else
    {
        if(random < 50)
        {
            damage = enemy_.getEnemyATK() - (player_.getDEF() / 2);
            if(damage < 0)
            {
                damage = 0;
            }
        }
        else
        {
            damage = enemy_.getEnemyMGKATK() - (player_.getMGK_DEF() / 2);
            if(damage < 0)
            {
                damage = 0;
            }
        }
        cout << enemy_.getEnemyName() << " attacked you and dealt " << damage << " damage!" << endl;
        player_.setHP(player_.getHP() - damage);
    }
}

bool Game::runAway()
{
    int random = getRandomNumber() % 100;
    int runAwayFactor = -(player_.getSPD() - enemy_.getEnemySPD());
    if(player_.getSPD() > enemy_.getEnemySPD())
    {
        return true;
    }
    if(runAwayFactor == 0)
    {
        if(random < 50)
        {
            return true;
        }
    }
    else if(runAwayFactor < 5)
    {
        if(random < 35)
        {
            return true;
        }
    }
    else if(runAwayFactor < 10)
    {
        if(random < 25)
        {
            return true;
        }
    }
    else
    {
        if(random < 10)
        {
            return true;
        }
    }

    return false;
}

//-----------------------------------[Settings]-------------------------------------------------
int Game::showSettings()
{
    string choice;
    int int_choice = 0;
    cout << "Text Speed: " << fixed << setprecision(1) <<  text_speed_.count() / 1000 << " seconds." << endl;
    sleepFor();
    do
    {
        cout << "[1. Edit Settings]" << endl;
        cout << "[2. Close]" << endl;
        getline(cin, choice);
        if(choice != "1" && choice != "2")
        {
            cout << "Nope. Try again." << endl;
            sleepFor();
        }
    } while (choice != "1" && choice != "2");
    int_choice = stoi(choice);
    return int_choice;
}

void Game::changeSettings(int choice)
{
    if(choice == 1)
    {
        do
        {
        cout << endl <<"Changing text speed:" << endl;
        cout << "Select an option to change your text speed." << endl;
        cout << "[1. 0s]" << endl;
        cout << "[2. .5s]" << endl;
        cout << "[3. 1s]" << endl;
        cout << "[4. 1.5s]" << endl;
        cout << "[5. 2s]" << endl;
        cout << "[6. 3s]" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            text_speed_ = 0ms;
            break;

        case 2:
            text_speed_ = 500ms;
            break;

        case 3:
            text_speed_ = 1000ms;
            break;

        case 4:
            text_speed_ = 1500ms;
            break;

        case 5:
            text_speed_ = 2000ms;
            break;

        case 6:
            text_speed_ = 3000ms;
            break;

        default:
            cout << "Man you should really go to a math class. Or kindergarten. That's where you learn numbers." << endl;
            sleepFor();
            break;
        }
        } while (choice < 1 || choice > 6);

        sleepFor();
        cout << "Text speed changed." << endl;
        sleepFor();

    }
}
