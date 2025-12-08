#include "Animal.hpp"
#include <format>
#include <string>
#include <exception>


Animal::Animal(std::string name1 = "") : name(name1), health(100), hunger(100), thrist(100), stamina(100), isDead(false) {}

void Animal::set_health(int new_health){
    if ( (new_health > 100) or (new_health < 0) )
        throw std::invalid_argument("0 <= health <= 100"); 
    health = new_health;
}

void Animal::set_hunger(int new_hunger){
    if ( (new_hunger > 100) or (new_hunger < 0) )
        throw std::invalid_argument("0 <= hunger <= 100"); 
    hunger = new_hunger;
}

void Animal::set_thrist(int new_thrist){
    if ( (new_thrist > 100) or (new_thrist < 0) )
        throw std::invalid_argument("0 <= thrist <= 100"); 
    thrist = new_thrist;
}

void Animal::set_stamina(int new_stamina){
    if ( (new_stamina > 100) or (new_stamina < 0) )
        throw std::invalid_argument("0 <=stamina <= 100"); 
    stamina = new_stamina;
}

void Animal::add_health(int change_health){
    int add_health = health + change_health;
    if (add_health > 100)
        set_health(100);
    else if (add_health < 0)
        set_health(0);
    else
        set_health(add_health);
    
}

void Animal::add_hunger(int change_hunger){
    int add_hunger = hunger + change_hunger;
    if (add_hunger > 100)
        set_hunger(100);

    else if (add_hunger < 0)
        set_hunger(0);
    else
        set_hunger(add_hunger);
}

void Animal::add_thrist(int change_thrist){
    int add_thrist = thrist + change_thrist;
    if (add_thrist > 100)
        set_thrist(100);
    else if (add_thrist < 0)
        set_thrist(0);
    else
        set_thrist(add_thrist);
}

void Animal::add_stamina(int change_stamina){
    int add_stamina = stamina + change_stamina;
    if (add_stamina > 100)
        set_stamina(100);
    else if (add_stamina < 0)
        set_stamina(0);
    else
        set_stamina(add_stamina);
}

bool Animal::checkDeath(){
    if (isDead)
        return true;
    if (health == 0){
        isDead = true;
        return true;
    }
    return false;
}

std::string Animal::checkHungerThrist(){
    if ( (hunger <= 10) and (thrist <= 10) ){
        add_health(-10);
        return "Из-за голода и жажды состояние животного ухудшилось. Здоровье понижено. ";
    }
    if ( hunger <= 10 ){
        add_health(-5);
        return "Из-за голода состояние животного слегка ухудшилось. Здоровье понижено. ";
    }
    if ( thrist <= 10){
        add_health(-5);
        return "Из-за жажды состояние животного слегка ухудшилось. Здоровье понижено. ";
    }
    return "";
}

int rand_percent(){

    std::random_device rd;
    std::mt19937 gen( rd() );
    std::uniform_int_distribution<int> distr(1, 100);

    return distr(gen);

} 

std::string Animal::sleep(){
    std::string ht_text = checkHungerThrist();
    if ( checkDeath() )
        return ht_text+"Животное погибло";

    if ( (hunger >= 80) and (thrist >= 80) ){
        add_hunger(-10);
        add_thrist(-10);
        add_health(+15);
        add_stamina(+60);
        return ht_text+"Животное отдохнуло. Сытость и отсутсвие жажды придало ему сил. Здоровье и энергия восстановлены";
    }

    add_hunger(-10);
    add_thrist(-10);
    add_stamina(+60);
    return ht_text+"Животное отдохнуло. Энергия восстановлена";
}

std::string Animal::move(){
    if ( checkDeath() )
        return "Животное погибло";

    if (stamina < 10)
        return "Животное слишком устало, чтобы двигаться дальше";

    std::string ht_text = checkHungerThrist();
    if ( checkDeath() )
        return ht_text+"Животное погибло";
    
    add_hunger(-5);
    add_thrist(-5);
    add_stamina(-10);
    return "Животное двигается дальше. Энергия потрачена";
}

std::string Animal::seek_food(){
    int percent = rand_percent();
}