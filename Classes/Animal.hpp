#include <string>


enum Targets{SmallAnimal, MediumAnimal, BigAnimal};

class Animal{

public:
    std::string name;
protected:
    bool isDead;
    unsigned short health;
    unsigned short hunger;
    unsigned short thrist;
    unsigned short stamina;

public: 
    Animal();
    Animal( std::string name1 );
    void sleep();
    virtual void move();
    virtual void seek_food();
    void seek_water();

    unsigned short get_health() const;
    unsigned short get_hunger() const;
    unsigned short get_thrist() const;
    unsigned short get_stamina() const;

    void set_health(unsigned short new_health);
    void set_hunger(unsigned short new_hunger);
    void set_thrist(unsigned short new_thrist);
    void set_stamina(unsigned short new_stamina);

    virtual std::string to_string() const;
protected:
    bool checkDeath() const;
};

class Cat : public Animal{
    Targets target;
public:
    void seek_target();
    void seek_food();
    std::string to_string() const;
};

class Bird : public Animal{
    bool isFlying;
public:
    void start_fly();
    void stop_fly();
    void seek_food();
    void move();
    std::string to_string();

};
