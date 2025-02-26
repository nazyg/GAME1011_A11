// Game.cpp
#include "Game.h"

// GameObject implementation
GameObject::GameObject(string n, int h) : name(n), health(h) {}
string GameObject::getName() const { return name; }
int GameObject::getHealth() const { return health; }
void GameObject::setHealth(int h) { health = h; }

// Player implementation
Player::Player(string n, int h) : GameObject(n, h) {}
void Player::NormalAttack() { cout << getName() << " performs a normal attack!" << endl; }

// Enemy implementation
Enemy::Enemy(string n, int h) : GameObject(n, h) {}
void Enemy::NormalAttack() { cout << getName() << " performs a normal attack!" << endl; }

// Wizard implementation
string Wizard::specialAttackName = "Fireball";
Wizard::Wizard(string n) : Player(n, 100), specialAttackAmount(50) {}
void Wizard::SpecialAttack() { cout << getName() << " uses " << specialAttackName << " dealing " << specialAttackAmount << " damage!" << endl; }

// Knight implementation
string Knight::specialAttackName = "Power Slash";
Knight::Knight(string n) : Player(n, 120), specialAttackAmount(40) {}
void Knight::SpecialAttack() { cout << getName() << " uses " << specialAttackName << " dealing " << specialAttackAmount << " damage!" << endl; }

// Orc implementation
string Orc::speciesName = "Orc";
string Orc::taunts[] = { "Grrr! You weakling!", "I'll crush you!" };
Orc::Orc() : Enemy(speciesName, 80) {}
void Orc::TauntPlayer() { cout << getName() << ": " << taunts[rand() % 2] << endl; }

// Undead implementation
string Undead::speciesName = "Undead";
string Undead::taunts[] = { "You cannot kill the dead!", "Your soul is mine!" };
Undead::Undead() : Enemy(speciesName, 70) {}
void Undead::TauntPlayer() { cout << getName() << ": " << taunts[rand() % 2] << endl; }

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

    Player* player = (choice == 1) ? static_cast<Player*>(new Wizard(playerName)) : static_cast<Player*>(new Knight(playerName));

    cout << "\nYour Character: " << player->getName() << endl;
    cout << "Class: " << (choice == 1 ? "Wizard" : "Knight") << endl;
    cout << "Default Health: " << player->getHealth() << endl;

    cout << "\nAre you ready? (Press any key to continue)";
    cin.ignore();
    cin.get();

    Enemy* enemy = (rand() % 2 == 0) ? static_cast<Enemy*>(new Orc()) : static_cast<Enemy*>(new Undead());

    cout << "\nAn enemy appears: " << enemy->getName() << "!" << endl;

    // Battle sequence
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
