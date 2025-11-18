// Модуль класса времени суток
// Автор: Андрей кожевников

#include <stdexcept>
#include <format>
#include <string>
#include <fstream>
#include "DailyTime.hpp"

#include <assert.h>
#include <iostream>
// #include <exception>


/**
 * @brief Создает объект с полями, равными 0
 * 
 */
DailyTime::DailyTime() : hour(0), minute(0), second(0) {}

/**
 * @brief Создает объект с заданным количеством часов
 * 
 * @param hour час
 */
DailyTime::DailyTime(unsigned short hour) : minute(0), second(0) {
    set_hour(hour);
}

/**
 * @brief Создает объект с заданным количеством часов, минут
 * 
 * @param hour час
 * @param minute минута
 */
DailyTime::DailyTime(unsigned short hour, unsigned short minute) : second(0) {
    set_hour(hour);
    set_minute(minute);
}

/**
 * @brief Создает объект с заданным количеством часов, минут, секунд
 * 
 * @param hour час
 * @param minute минута
 * @param second секунда
 */
DailyTime::DailyTime(unsigned short hour, unsigned short minute, unsigned short second) {
    set_hour(hour);
    set_minute(minute);
    set_second(second);
}


/**
 * @brief Геттер поля часов
 * 
 * @return unsigned short 
 */
unsigned short DailyTime::get_hour() const{
    return hour;
} 

/**
 * @brief Геттер поля минут
 * 
 * @return unsigned short 
 */
unsigned short DailyTime::get_minute() const{
    return minute;
} 

/**
 * @brief Геттер поля секунд
 * 
 * @return unsigned short 
 */ 
unsigned short DailyTime::get_second() const{
    return second;
} 

/**
 * @brief Сеттер поля часов
 * 
 * @param new_hour устанавливаемый час
 * @exception invalid_argument, если 0 <= new_hour <= 23
 */
void DailyTime::set_hour(unsigned short new_hour){
    if (new_hour > 23)
        throw std::invalid_argument("0 <= new_hour <= 23");
    hour = new_hour;
}

/**
 * @brief Сеттер поля минут
 * 
 * @param new_minute устанавливаемая минута
 * @exception invalid_argument, если 0 <= new_minute <= 59
 */
void DailyTime::set_minute(unsigned short new_minute){
    if (new_minute > 59)
        throw std::invalid_argument("0 <= minute <= 59");
    minute = new_minute;
}

/**
 * @brief Сеттер поля секунд
 * 
 * @param new_minute устанавливаемая секунда
 * @exception invalid_argument, если 0 <= new_second <= 59
 */
void DailyTime::set_second(unsigned short new_second){
    if (new_second > 59)
        throw std::invalid_argument("0 <= second <= 59");
    second = new_second;
}

/**
 * @brief Прибавляет часы
 * 
 * @param new_hour количество часов
 */
void DailyTime::add_hour(unsigned short new_hour){
    hour = (hour + new_hour) % 24;
}

/**
 * @brief Прибавляет минуты
 * 
 * @param new_minute количество минут
 */
void DailyTime::add_minute(unsigned short new_minute){
    add_hour((minute + new_minute) / 60);
    minute = (minute + new_minute) % 60;
}

/**
 * @brief Прибавляет секунды
 * 
 * @param new_second количество секунд
 */
void DailyTime::add_second(unsigned short new_second){
    add_minute((second + new_second) / 60);
    second = (second + new_second) % 60;
}

/**
 * @brief Переводит время в строку в формате ЧЧ:ММ:СС
 * 
 * @return std::string
 */
std::string DailyTime::to_string() const {
    return std::format("{:02d}:{:02d}:{:02d}", hour, minute, second);
}

/**
 * @brief Прибавляет к текущему времени суток другое
 * 
 * @param add_time добавляемое время суток
 * @return DailyTime& 
 */
DailyTime& DailyTime::operator +=(const DailyTime& add_time){
    add_hour( add_time.get_hour() );
    add_minute( add_time.get_minute() );
    add_second( add_time.get_second() );
    return *this;
}

/**
 * @brief Записывает данные объекта в бинарный файл
 * 
 * @param file_name название файла
 * @exception runtime_error, если не удалось открыть файл 
 */
void DailyTime::to_bin_file(std::string file_name) const{
    std::fstream file(file_name, std::ios::out | std::ios::trunc | std::ios::binary);
    
    if ( !file.is_open() )
        throw(std::runtime_error("Ошибка: не удалось открыть файл"));

    file.write((char*)&hour, sizeof(unsigned short));
    file.write((char*)&minute, sizeof(unsigned short));
    file.write((char*)&second, sizeof(unsigned short));

    file.close();
}

/**
 * @brief Записывает данные объекта из бинарного файла
 * 
 * @param file_name название файла
 * @exception runtime_error, если не удалось открыть файл 
 */
void DailyTime::from_bin_file(std::string file_name){
    std::fstream file(file_name, std::ios::in | std::ios::binary);

    if ( !file.is_open() )
        throw(std::runtime_error("Ошибка: не удалось открыть файл"));

    file.read((char*)&hour, sizeof(unsigned short));
    file.read((char*)&minute, sizeof(unsigned short));
    file.read((char*)&second, sizeof(unsigned short));

    file.close();
} 


/**
 * @brief Складывает два времени суток и возвращает их сумму
 * 
 * @param time1 первое время суток
 * @param time2 второе время суток
 * @return DailyTime 
 */
DailyTime operator+(const DailyTime& time1, const DailyTime& time2){
DailyTime new_time = time1;
new_time += time2;
return new_time;
}

