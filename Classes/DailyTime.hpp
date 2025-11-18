// Модуль класса времени суток
// Автор: Андрей кожевников

#pragma once

#include <string>

/**
 * @brief Класс времени суток, содержащий часы, минуты, секунды
 * 
 */
class DailyTime{

    //Количество часов в диапозоне 0 <= hour <= 23
    unsigned short hour;

    //Количество минут в диапозоне 0 <= minute <= 59
    unsigned short minute;

    //Количество секунд в диапозоне 0 <= second <= 59
    unsigned short second;

public:

    /**
     * @brief Создает объект с полями, равными 0
     * 
     */
    DailyTime();

    /**
     * @brief Создает объект с заданным количеством часов
     * 
     * @param hour час
     */
    DailyTime(unsigned short hour);
    
    /**
     * @brief Создает объект с заданным количеством часов, минут
     * 
     * @param hour час
     * @param minute минута
     */
    DailyTime(unsigned short hour, unsigned short minute);
    
    /**
     * @brief Создает объект с заданным количеством часов, минут, секунд
     * 
     * @param hour час
     * @param minute минута
     * @param second секунда
     */
    DailyTime(unsigned short hour, unsigned short minute, unsigned short second);


    /**
     * @brief Геттер поля часов
     * 
     * @return unsigned short 
     */
    unsigned short get_hour() const;
    
    /**
     * @brief Геттер поля минут
     * 
     * @return unsigned short 
     */
    unsigned short get_minute() const;
    
    /**
     * @brief Геттер поля секунд
     * 
     * @return unsigned short 
     */ 
    unsigned short get_second() const;

    /**
     * @brief Сеттер поля часов
     * 
     * @param new_hour устанавливаемый час
     * @exception invalid_argument, если 0 <= new_hour <= 23
     */
    void set_hour(unsigned short new_hour);
    
    /**
     * @brief Сеттер поля минут
     * 
     * @param new_minute устанавливаемая минута
     * @exception invalid_argument, если 0 <= new_minute <= 59
     */
    void set_minute(unsigned short new_minute);
    
    /**
     * @brief Сеттер поля секунд
     * 
     * @param new_minute устанавливаемая секунда
     * @exception invalid_argument, если 0 <= new_second <= 59
     */
    void set_second(unsigned short new_second);

    /**
     * @brief Прибавляет часы
     * 
     * @param new_hour количество часов
     */
    void add_hour(unsigned short new_hour);
    
    /**
     * @brief Прибавляет минуты
     * 
     * @param new_minute количество минут
     */
    void add_minute(unsigned short new_minute);
    
    /**
     * @brief Прибавляет секунды
     * 
     * @param new_second количество секунд
     */
    void add_second(unsigned short new_second);

    /**
     * @brief Переводит время в строку в формате ЧЧ:ММ:СС
     * 
     * @return std::string
     */
    std::string to_string() const;

    /**
     * @brief Прибавляет к текущему времени суток другое
     * 
     * @param add_time добавляемое время суток
     * @return DailyTime& 
     */
    DailyTime& operator +=(const DailyTime& add_time);

    /**
     * @brief Записывает данные объекта в бинарный файл
     * 
     * @param file_name название файла
     * @exception runtime_error, если не удалось открыть файл 
     */
    void to_bin_file(std::string file_name) const;

    /**
     * @brief Записывает данные объекта из бинарного файла
     * 
     * @param file_name название файла
     * @exception runtime_error, если не удалось открыть файл 
     */
    void from_bin_file(std::string file_name);
};

/**
 * @brief Складывает два времени суток и возвращает их сумму
 * 
 * @param time1 первое время суток
 * @param time2 второе время суток
 * @return DailyTime 
 */
DailyTime operator+(const DailyTime& time1, const DailyTime& time2);
