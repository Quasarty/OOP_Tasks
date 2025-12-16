#include "Animal.hpp"
#include <format>
#include <string>
#include <exception>

#include <iostream>

static const int STAMINA_ACTION_COST = 10; 
static const int HT_ACTION_COST = 5;
static const int SLEEP_HT_COST = 10;
static const int SEEK_FAIL_CHANCE = 20;
static const int HT_GAIN = 30;

Animal::Animal(std::string name1) : name(name1), health(100), hunger(100), thrist(100), stamina(100), isDead(false) {}

int Animal::get_health() const{ return health; }
int Animal::get_hunger() const{ return hunger; }
int Animal::get_thrist() const{ return thrist; }
int Animal::get_stamina() const{ return stamina; }

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

std::string Animal::checkActionCondtions(){
    if ( checkDeath() )
        return "Животное погибло";

    if (stamina < STAMINA_ACTION_COST)
        return "Животное слишком устало, чтобы двигаться дальше";

    std::string ht_text = checkHungerThrist();
    if ( checkDeath() )
        return ht_text+"Животное погибло";    
    return "";
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

    add_hunger(-SLEEP_HT_COST);
    add_thrist(-SLEEP_HT_COST);
    add_stamina(+60);

    if ( (hunger >= 80) and (thrist >= 80) ){
        add_health(+15);
        return ht_text+"Животное отдохнуло. Сытость и отсутсвие жажды придало ему сил. Здоровье и энергия восстановлены";
    }
    return ht_text+"Животное отдохнуло. Энергия восстановлена";
}

std::string Animal::move(){
    std::string condition_text = checkActionCondtions();

    if ( (stamina < STAMINA_ACTION_COST) or isDead)
        return condition_text;
    
    add_hunger(-HT_ACTION_COST);
    add_thrist(-HT_ACTION_COST);
    add_stamina(-STAMINA_ACTION_COST);
    return "Животное двигается дальше. Энергия потрачена";
}

std::string Animal::seek_food(){
    std::string condition_text = checkActionCondtions();

    if ( (stamina < STAMINA_ACTION_COST) or isDead)
        return condition_text;

    int percent = rand_percent();

    add_thrist(-HT_ACTION_COST);
    add_stamina(-STAMINA_ACTION_COST);

    if (percent <= SEEK_FAIL_CHANCE){
        add_health(-20);
        add_hunger(HT_GAIN/2);
        return "Животное нашло немного еды. Во время дальнейших поисков был встречен хищник. В погоне животное немного поранилось. Голод восстановлен, здоровье понижено";
    }
    add_hunger(HT_GAIN);

    return "Животное нашло еду. Голод восстановлен";
}

std::string Animal::seek_water(){
    std::string condition_text = checkActionCondtions();

    if ( (stamina < STAMINA_ACTION_COST) or isDead)
        return condition_text; 

    int percent = rand_percent();
        
    add_hunger(-HT_ACTION_COST);
    add_stamina(-STAMINA_ACTION_COST);

    if (percent <= SEEK_FAIL_CHANCE){
        add_thrist(HT_GAIN/2);
        return "Животное нашло ручей. Жажда восстановлена";
    }
    add_thrist(HT_GAIN);
    return "Животное нашло озеро. Жажда восстановлена";
}

std::string Animal::to_string() const{
    return std::format("Имя: {}\nЗдоровье: {}\nГолод: {}\nЖажда: {}\nЭнергия: {}", name, health, hunger, thrist, stamina);
}

Cat::Cat(std::string name1) : Animal(name1) {
    target = (Targets)-1;
}

std::string Cat::seek_target(){
    std::string condition_text = checkActionCondtions();

    if ( (stamina < STAMINA_ACTION_COST) or isDead)
        return condition_text;
    
    int percent = rand_percent();
    
    add_stamina(-STAMINA_ACTION_COST);

    if (percent <= 20){
        target = BigAnimal;
        return "Была найдена крупная добыча";
    }
    if (percent <= 50){
        target = MediumAnimal;
        return "Была найдена средняя добыча";
    }
    target = SmallAnimal;
    return "Была найдена мелкая добыча";
}

std::string Cat::seek_food(){
    if (target == -1)
        return "Добыча отсутствует";

    std::string condition_text = checkActionCondtions();

    if ( (stamina < STAMINA_ACTION_COST) or isDead)
        return condition_text; 

    int percent = rand_percent();

    add_stamina(-STAMINA_ACTION_COST);

    switch (target){
        case SmallAnimal:{
            add_hunger(HT_GAIN);
            if (percent <= 10){
                add_health(-10);
                target = (Targets)-1;
                return "Охота прошла не совсем успешно. Во время погони животное запнулось и поцарапалось. Здоровье понижено, голод восстановлен";
            }
            target = (Targets)-1;
            return "Охота прошла успешно. Голод восстановлен";}
        case MediumAnimal:{
            add_hunger(HT_GAIN*2);
            if (percent <= 30){
                add_health(-20);
                target = (Targets)-1;
                return "Охота была нелёгкой. Животное получило ранение. Здоровье понижено, голод восстановлен";
            } 
            target = (Targets)-1;
            return "Охота прошла успешно. Голод восстановлен";
        }
        case BigAnimal:{
            add_hunger(HT_GAIN*3);
            if (percent <= 50){
                add_health(-40);
                target = (Targets)-1;
                return "Охота почти провалилась. Животное получило серьезные раны. Здоровье понижено, голод восстановлен";
            }
            target = (Targets)-1;
            return "Охота прошла успешно. Голод восстановлен";
        }
        default:{
            return "Добыча отсутствует";
        }
    }
    
}

std::string Cat::to_string() const{
    std::string target_str;
    switch (target){
        case SmallAnimal: {target_str = "Мелкое животное"; break;}
        case MediumAnimal: {target_str = "Среднее животное"; break;}
        case BigAnimal: {target_str = "Крупное животное"; break;}
        default: {target_str = "Добыча отсутствует"; break;}
    }
    return Animal::to_string() + std::format("\nТекущая добыча: {}", target_str);
}

Bird::Bird(std::string name1) : Animal(name1), isFlying(false) {}

std::string Bird::start_fly(){
    if (isFlying)
        return "Животное уже летает"; 
    isFlying = true;
    return "Животное взмывает вверх";
}

std::string Bird::stop_fly(){
    if (!isFlying)
        return "Животное уже на земле"; 
    isFlying = false;
    return "Животное приземляется на землю";
}


std::string Bird::move(){
    std::string condition_text = checkActionCondtions();

    if ( (stamina < STAMINA_ACTION_COST) or isDead)
        return condition_text;
    
    add_hunger(-HT_ACTION_COST);
    add_thrist(-HT_ACTION_COST);
    
    if (isFlying){
        add_stamina(-2 * STAMINA_ACTION_COST);
        return "Животное летит дальше. Энергия потрачена";
    }   
    else{
        add_stamina(-STAMINA_ACTION_COST);
        return "Животное двигается дальше. Энергия потрачена";
    }
}

std::string Bird::to_string() const{
    std::string fly_str;
    if (isFlying)
        fly_str = "Да";
    else    
        fly_str = "Нет";
    return Animal::to_string() + std::format("\nЛетает: {}", fly_str);
}

int main(){
    std::cout << "Выберите персонажа:\nКошка: 1\nПтица: 2\n";
    int player_choise;
    std::cin >> player_choise;
    switch (player_choise){
        case 1:{
            Cat anml("Silly Cat");
            enum CatActions{exit, move, sleep, seek_water, seek_target, seek_food, to_string};
            std::string cat_controls = "\nКоманды\nВыход: 0\nДвигаться дальше: 1\nСпать: 2\nИскать воду: 3\nИскать добычу: 4\nОхотится: 5\nИнформация: 6\n";
            do {
                std::cout << cat_controls;
                int choise;
                std::cin >> choise;
                switch (choise){
                case move:
                    std::cout << anml.move() << "\n"; 
                    break;

                case sleep:
                    std::cout << anml.sleep() << "\n";
                    break;

                case seek_food:
                    std::cout << anml.seek_food() << "\n";
                    break;

                case seek_target:
                    std::cout << anml.seek_target() << "\n";
                    break;

                case seek_water:
                    std::cout << anml.seek_water() << "\n";
                    break;

                case to_string:
                    std::cout << anml.to_string() << "\n";
                    break;
                
                case exit:
                    std::exit(0);
                    break;    

                default:
                    std::cout << "Неизвестная команда" << "\n";
                    break;
                }
            } while (!anml.isDead);
            break;}
        case 2:{
            Bird anml("Big Bird");
            enum BirdActions{exit, move, sleep, seek_water, seek_food, start_fly, stop_fly, to_string};
            std::string bird_controls = "\nКоманды\nВыход: 0\nДвигаться дальше: 1\nСпать: 2\nИскать воду: 3\nИскать еду: 4\nНачать полет: 5\nЗакончить полет: 6\nИнформация: 7\n";
            do {
                std::cout << bird_controls;
                int choise;
                std::cin >> choise;
                switch (choise){
                case move:
                    std::cout << anml.move() << "\n"; 
                    break;

                case sleep:
                    std::cout << anml.sleep() << "\n";
                    break;

                case seek_food:
                    std::cout << anml.seek_food() << "\n";
                    break;

                case start_fly:
                    std::cout << anml.start_fly() << "\n";
                    break;

                case stop_fly:
                    std::cout << anml.stop_fly() << "\n";
                    break;

                case seek_water:
                    std::cout << anml.seek_water() << "\n";
                    break;

                case to_string:
                    std::cout << anml.to_string() << "\n";
                    break;
                
                case exit:
                    std::exit(0);
                    break;    

                default:
                    std::cout << "Неизвестная команда" << "\n";
                    break;
                }
            } while (!anml.isDead);
            break;}
        default:
            std::cout << "Некорректный ввод";
            break;
    }

    // do {
    //     std::cout << cat_controls;
    //     int choise;
    //     std::cin >> choise;
    //     switch (choise){
    //     case move:
    //         std::cout << anml.move() << "\n"; 
    //         break;

    //     case sleep:
    //         std::cout << anml.sleep() << "\n";
    //         break;

    //     case seek_food:
    //         std::cout << anml.seek_food() << "\n";
    //         break;

    //     case seek_target:
    //         std::cout << anml.seek_target() << "\n";
    //         break;

    //     case seek_water:
    //         std::cout << anml.seek_water() << "\n";
    //         break;

    //     case to_string:
    //         std::cout << anml.to_string() << "\n";
    //         break;
        
    //     case exit:
    //         std::exit(0);
    //         break;    

    //     default:
    //         std::cout << "Неизвестная команда" << "\n";
    //         break;
    //     }
        

    // } while (!anml.isDead);
}