#include <stdexcept>
#include <format>
#include <string>
#include <fstream>

#include <assert.h>
#include <iostream>
// #include <exception>

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
    DailyTime() : hour(0), minute(0), second(0) {}

    /**
     * @brief Создает объект с заданным количеством часов
     * 
     * @param hour час
     */

    DailyTime(unsigned short hour) : minute(0), second(0) {
        set_hour(hour);
    }
    /**
     * @brief Создает объект с заданным количеством часов, минут
     * 
     * @param hour час
     * @param minute минута
     */

    DailyTime(unsigned short hour, unsigned short minute) : second(0) {
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
    DailyTime(unsigned short hour, unsigned short minute, unsigned short second) {
        set_hour(hour);
        set_minute(minute);
        set_second(second);
    }


    /**
     * @brief Геттер поля часов
     * 
     * @return unsigned short 
     */
    unsigned short get_hour() const{
        return hour;
    } 
    
    /**
     * @brief Геттер поля минут
     * 
     * @return unsigned short 
     */
    unsigned short get_minute() const{
        return minute;
    } 
    
    /**
     * @brief Геттер поля секунд
     * 
     * @return unsigned short 
     */ 
    unsigned short get_second() const{
        return second;
    } 

    /**
     * @brief Сеттер поля часов
     * 
     * @param new_hour устанавливаемый час
     * @exception invalid_argument, если 0 <= new_hour <= 23
     */
    void set_hour(unsigned short new_hour){
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
    void set_minute(unsigned short new_minute){
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
    void set_second(unsigned short new_second){
        if (new_second > 59)
            throw std::invalid_argument("0 <= second <= 59");
        second = new_second;
    }

    /**
     * @brief Прибавляет часы
     * 
     * @param new_hour количество часов
     */
    void add_hour(unsigned short new_hour){
        hour = (hour + new_hour) % 24;
    }
    
    /**
     * @brief Прибавляет минуты
     * 
     * @param new_minute количество минут
     */
    void add_minute(unsigned short new_minute){
        add_hour((minute + new_minute) / 60);
        minute = (minute + new_minute) % 60;
    }
    
    /**
     * @brief Прибавляет секунды
     * 
     * @param new_second количество секунд
     */
    void add_second(unsigned short new_second){
        add_minute((second + new_second) / 60);
        second = (second + new_second) % 60;
    }

    /**
     * @brief Переводит время в строку в формате ЧЧ:ММ:СС
     * 
     * @return std::string
     */
    std::string to_string() const {
        return std::format("{:02d}:{:02d}:{:02d}", hour, minute, second);
    }

    /**
     * @brief Прибавляет к текущему времени суток другое
     * 
     * @param add_time добавляемое время суток
     * @return DailyTime& 
     */
    DailyTime& operator +=(const DailyTime& add_time){
        add_hour( add_time.get_hour() );
        add_minute( add_time.get_minute() );
        add_second( add_time.get_second() );
        return *this;
    }

    void to_bin_file(std::string file_name){
        std::fstream file(file_name, std::ios::out | std::ios::trunc | std::ios::binary);
       
        if ( !file.is_open() )
            throw(std::runtime_error("Ошибка: не удалось открыть файл"));

        file.write((char*)&hour, sizeof(unsigned short));
        file.write((char*)&minute, sizeof(unsigned short));
        file.write((char*)&second, sizeof(unsigned short));

        file.close();
    }

    void from_bin_file(std::string file_name){
        std::fstream file(file_name, std::ios::in | std::ios::binary);

        if ( !file.is_open() )
            throw(std::runtime_error("Ошибка: не удалось открыть файл"));

        file.read((char*)&hour, sizeof(unsigned short));
        file.read((char*)&minute, sizeof(unsigned short));
        file.read((char*)&second, sizeof(unsigned short));

        file.close();
    } 
};

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

int main(){

    //Создание статического объекта
    DailyTime time1;
    std::cout << time1.to_string() << "\n";
    std::cout << "\n";
    
    //Динамическое создание объекта
    DailyTime* time2 = new DailyTime(3, 12);
    std::cout << time2->to_string() << "\n";
    std::cout << "\n";
    
    //Создание статического массива
    DailyTime time_arr1[5]; //< Вызываются конструкторы
    for (std::size_t i = 0; i < 5; i++){
        time_arr1[i].add_hour( (i+1) * 2);
        std::cout << time_arr1[i].to_string() << "\n";    
    }
    std::cout << "\n";

    //Создание динамического массива 
    DailyTime* time_arr2 = new DailyTime[5]; //< Конструктор 5 раз
    for (std::size_t i = 0; i < 5; i++){
        time_arr2[i].set_hour( i*3 );
        std::cout << time_arr2[i].to_string() << "\n";
    }
    delete[] time_arr2;
    std::cout << "\n";

    //Создание массива из указателей
    DailyTime* time_arr3[5];
    for (std::size_t i = 0; i < 5; i++){
        time_arr3[i] = new DailyTime(i+1, i*10, 10+i); //< Конструктор 
        std::cout << time_arr3[i]->to_string() << "\n";
        delete time_arr3[i];
    }
    std::cout << "\n";

    time1.to_bin_file("test.bin");
    DailyTime timebin;
    timebin.from_bin_file("test.bin");
    std::cout << timebin.to_string();


    DailyTime tm(20);
    tm.add_hour(5);
    tm.add_second(36361);
    assert( tm.to_string() == "11:06:01" );

    // tm.set_hour(23);
    // tm.set_minute(52);
    // tm.set_second(22);
    // std::cout << tm.to_string() << "\n";
    
    // DailyTime tm2(03, 54, 22);
    // tm += tm2;
    // std::cout << tm.to_string() << "\n";

}