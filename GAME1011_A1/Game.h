// Game.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class GameObject {
protected:
    string name;
    int health;
public:
    GameObject(string n, int h);
    virtual void NormalAttack() = 0;
    string getName() const;
    int getHealth() const;
    void setHealth(int h);
    virtual ~GameObject() {}
};

class Player : public GameObject {
public:
    Player(string n, int h);
    virtual void SpecialAttack() = 0;
    void NormalAttack() override;
};

class Enemy : public GameObject {
public:
    Enemy(string n, int h);
    virtual void TauntPlayer() = 0;
    void NormalAttack() override;
};

class Wizard : public Player {
public:
    static string specialAttackName;
    int specialAttackAmount;
    Wizard(string n);
    void SpecialAttack() override;
};

class Knight : public Player {
public:
    static string specialAttackName;
    int specialAttackAmount;
    Knight(string n);
    void SpecialAttack() override;
};

class Orc : public Enemy {
public:
    static string speciesName;
    static string taunts[];
    Orc();
    void TauntPlayer() override;
};

class Undead : public Enemy {
public:
    static string speciesName;
    static string taunts[];
    Undead();
    void TauntPlayer() override;
};

#endif // GAME_H
#pragma once
