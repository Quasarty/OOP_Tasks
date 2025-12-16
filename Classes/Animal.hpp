#pragma once

#include <string>
#include <random>

// Перечислимый тип для размеров добычи
enum Targets{SmallAnimal, MediumAnimal, BigAnimal};

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
    /**
     * @brief Создает экземпляр класса Animal
     * 
     * @param name1 имя животного 
     */
    Animal( std::string name1 = "");

    /**
     * @brief Действие сна животного
     * 
     * @return std::string выходное сообщение
     */
    std::string sleep();
    
    /**
     * @brief Действие движения животного
     * 
     * @return std::string выходное сообщение
     */
    virtual std::string move();

    /**
     * @brief Действие поиска еды животного
     * 
     * @return std::string выходное сообщение
     */
    virtual std::string seek_food();
    
    /**
     * @brief Действие поиска воды животного
     * 
     * @return std::string выходное сообщение
     */
    std::string seek_water();
    
    
    /**
     * @brief Геттер поля здоровья
     * 
     * @return int
     */
    int get_health() const;

    /**
     * @brief Геттер поля сытости
     * 
     * @return int
     */
    int get_hunger() const;

    /**
     * @brief Геттер поля жажды
     * 
     * @return int
     */
    int get_thrist() const;

    /**
     * @brief Геттер поля энергии
     * 
     * @return int
     */
    int get_stamina() const;

    /**
     * @brief Сеттер поля здоровья
     * 
     * @param new_health
     */
    void set_health(int new_health);

    /**
     * @brief Сеттер поля сытости
     * 
     * @param new_hunger 
     */
    void set_hunger(int new_hunger);

    /**
     * @brief Сеттер поля жажды
     * 
     * @param new_thrist 
     */
    void set_thrist(int new_thrist);

    /**
     * @brief Сеттер поля энергии
     * 
     * @param new_stamina 
     */
    void set_stamina(int new_stamina);

    /**
     * @brief Прибавляет значение к полю здоровья
     * 
     * @param change_health
     */
    void add_health(int change_health);

    /**
     * @brief Прибавляет значение к полю сытости
     * 
     * @param change_health
     */
    void add_hunger(int change_hunger);

    /**
     * @brief Прибавляет значение к полю жажды
     * 
     * @param change_health
     */
    void add_thrist(int change_thrist);

    /**
     * @brief Прибавляет значение к полю энергии
     * 
     * @param change_health
     */
    void add_stamina(int change_stamina);
    
    /**
     * @brief возвращает информацию о животном в виде строки
     * 
     * @return std::string 
     */
    virtual std::string to_string() const;
protected:

    /**
     * @brief Проверяет здоровье, если оно равно 0, то ствит isDead = true
     * 
     * @return true if isDead
     * @return false if !isDead
     */
    bool checkDeath();

    /**
     * @brief Отнимает здоровье, если присутствует голод и жажда
     * 
     * @return std::string выходное сообщение
     */
    std::string checkHungerThrist();

    /**
     * @brief Проверяет, может ли животное совершить действие, отнимает здоровье, если присутствует голод и жажда, проверяет здоровье
     * 
     * @return std::string выходное сообщение  
     */
    std::string checkActionCondtions();
};

class Cat : public Animal{
    Targets target;
public:

    /**
     * @brief Создает экземпляр класса Cat
     * 
     * @param name1 имя кошки
     */
    Cat(std::string name1 = "");
    
    /**
     * @brief Действие поиска добычи кошки
     * 
     * @return std::string выходное сообщение
     */
    std::string seek_target();

    /**
     * @brief Действие охоты кошки
     * 
     * @return std::string выходное сообщение
     */
    std::string seek_food() override;

    /**
     * @brief возвращает информацию о кошке в виде строки
     * 
     * @return std::string 
     */
    std::string to_string()  const override;
};

class Bird : public Animal{
    bool isFlying;
public:

    /**
     * @brief Создает экземпляр класса Bird
     * 
     * @param name1 имя птицы
     */
    Bird(std::string name1 = "");

    /**
     * @brief Действие начала полета
     * 
     * @return std::string выходное сообщение
     */
    std::string start_fly();

    /**
     * @brief Действие конца полета
     * 
     * @return std::string выходное сообщение
     */
    std::string stop_fly();

    /**
     * @brief Действие движения птицы
     * 
     * @return std::string выходное сообщение
     */
    std::string move() override;

    /**
     * @brief возвращает информацию о птице в виде строки
     * 
     * @return std::string 
     */
    std::string to_string() const override;

};

/**
 * @brief Возвращает случайное целое число от 1 до 100 
 * 
 * @return int  
 */
int rand_percent();
