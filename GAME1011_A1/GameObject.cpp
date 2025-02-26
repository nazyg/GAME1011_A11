#include <iostream>
#include <cstdlib> // For rand() function
#include <ctime>   // For srand()

using namespace std;

// Base class for all game objects (Pure Abstract)
class GameObject {
protected:
    string name;
    int health;

public:
    GameObject(string n, int h) : name(n), health(h) {}

    virtual void NormalAttack() = 0; // Pure Virtual Function

    // Getter for name
    string getName() const {
        return name;
    }

    // Getter and Setter for health (Accessors & Mutators)
    int getHealth() const {
        return health;
    }

    void setHealth(int h) {
        health = h;
    }
};

// Abstract Player class (inherits from GameObject)
class Player : public GameObject {
public:
    Player(string n, int h) : GameObject(n, h) {}

    virtual void SpecialAttack() = 0; // Pure Virtual Function

    void NormalAttack() override {
        cout << getName() << " performs a normal attack!" << endl;
    }
};

// Abstract Enemy class (inherits from GameObject)
class Enemy : public GameObject {
public:
    Enemy(string n, int h) : GameObject(n, h) {}

    virtual void TauntPlayer() = 0; // Pure Virtual Function

    void NormalAttack() override {
        cout << getName() << " performs a normal attack!" << endl;
    }
};

// Wizard class (inherits from Player)
class Wizard : public Player {
public:
    static string specialAttackName; // Static Special Attack Name
    int specialAttackAmount = 50;    // Special Attack Amount

    Wizard(string n) : Player(n, 100) {}

    void SpecialAttack() override {
        cout << getName() << " uses " << specialAttackName << " dealing " << specialAttackAmount << " damage!" << endl;
    }
};

// Define static variable
string Wizard::specialAttackName = "Fireball";

// Knight class (inherits from Player)
class Knight : public Player {
public:
    static string specialAttackName; // Static Special Attack Name
    int specialAttackAmount = 40;    // Special Attack Amount

    Knight(string n) : Player(n, 120) {}

    void SpecialAttack() override {
        cout << getName() << " uses " << specialAttackName << " dealing " << specialAttackAmount << " damage!" << endl;
    }
};

// Define static variable
string Knight::specialAttackName = "Power Slash";

// Orc class (inherits from Enemy)
class Orc : public Enemy {
public:
    static string speciesName; // Static species name
    static string taunts[];    // Array of taunts

    Orc() : Enemy(speciesName, 80) {}

    void TauntPlayer() override {
        cout << getName() << ": " << taunts[rand() % 2] << endl;
    }
};

// Define static variables
string Orc::speciesName = "Orc";
string Orc::taunts[] = { "Grrr! You weakling!", "I'll crush you!" };

// Undead class (inherits from Enemy)
class Undead : public Enemy {
public:
    static string speciesName; // Static species name
    static string taunts[];    // Array of taunts

    Undead() : Enemy(speciesName, 70) {}

    void TauntPlayer() override {
        cout << getName() << ": " << taunts[rand() % 2] << endl;
    }
};

// Define static variables
string Undead::speciesName = "Undead";
string Undead::taunts[] = { "You cannot kill the dead!", "Your soul is mine!" };

// Main game function
int main() {
    srand(time(0));

    cout << "Welcome! Choose your character class:\n";
    cout << "1 - Wizard\n";
    cout << "2 - Knight\n";

    int choice;
    cin >> choice;

    cout << "Enter your character's name: ";
    string playerName;
    cin >> playerName;

    Player* player;
    if (choice == 1)
        player = new Wizard(playerName);
    else
        player = new Knight(playerName);

    cout << "\nYour Character: " << player->getName() << endl;
    cout << "Class: " << (choice == 1 ? "Wizard" : "Knight") << endl;
    cout << "Default Health: " << player->getHealth() << endl;

    cout << "\nAre you ready? (Press any key to continue)";
    cin.ignore();
    cin.get();

    Enemy* enemy;
    if (rand() % 2 == 0)
        enemy = new Orc();
    else
        enemy = new Undead();

    cout << "\nAn enemy appears: " << enemy->getName() << "!" << endl;

    // Battle sequence (as per requirements)
    enemy->TauntPlayer();
    player->NormalAttack();
    enemy->TauntPlayer();
    player->SpecialAttack();
    enemy->NormalAttack();
    enemy->NormalAttack();
    player->SpecialAttack();
    enemy->TauntPlayer();
    player->SpecialAttack();

    cout << "\nEnemy has been defeated! Congratulations, you win!" << endl;

    delete player;
    delete enemy;

    return 0;
}

