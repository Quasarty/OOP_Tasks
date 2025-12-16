#pragma once

#include <string>
#include <random>

enum Targets{SmallAnimal, MediumAnimal, BigAnimal};

//TODO: NoTarget в Targets; move не показывает смерть/дамаг от голода; 

class Animal{

public:
    std::string name;
    bool isDead;
protected:
    int health;
    int hunger;
    int thrist;
    int stamina;

public: 
    Animal( std::string name1 = "");
    std::string sleep();
    virtual std::string move();
    virtual std::string seek_food();
    std::string seek_water();

    int get_health() const;
    int get_hunger() const;
    int get_thrist() const;
    int get_stamina() const;

    void set_health(int new_health);
    void set_hunger(int new_hunger);
    void set_thrist(int new_thrist);
    void set_stamina(int new_stamina);

    void add_health(int change_health);
    void add_hunger(int change_hunger);
    void add_thrist(int change_thrist);
    void add_stamina(int change_stamina);
    
    virtual std::string to_string() const;
protected:
    bool checkDeath();
    std::string checkHungerThrist();
    std::string checkActionCondtions();
};

class Cat : public Animal{
    Targets target;
public:
    Cat(std::string name1 = "");
    std::string seek_target();
    std::string seek_food() override;
    std::string to_string()  const override;
};

class Bird : public Animal{
    bool isFlying;
public:
    Bird(std::string name1 = "");
    std::string start_fly();
    std::string stop_fly();
    std::string move() override;
    std::string to_string() const override;

};

int rand_percent();
