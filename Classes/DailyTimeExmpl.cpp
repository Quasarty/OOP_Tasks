#include <stdexcept>
#include <format>
#include <string>
#include <fstream>
#include "DailyTime.hpp"

#include <assert.h>
#include <iostream>

void DailyTime_test(){
    //Тесты
    DailyTime tm1(20);
    tm1.add_hour(5);
    tm1.add_second(36361);
    assert( tm1.to_string() == "11:06:01" );
    
    DailyTime tm2(5, 8, 2);
    tm2 += tm1;
    assert( tm2.to_string() == "16:14:03" );

    DailyTime tm3(tm1+tm2);
    assert( tm3.to_string() == "03:20:04" );

    DailyTime tm4;
    tm4.set_hour(23);
    tm4.set_minute(52);
    tm4.set_second(22);
    assert( tm4.to_string() == "23:52:22" );

    DailyTime tm5(22, 13, 7);
    assert( tm5.to_string() == "22:13:07");

    DailyTime tm6(13, 7);
    assert( tm6.to_string() == "13:07:00");

    try{
        tm6.set_hour(32);
        assert(false); //< если тест не пройден
    }
    catch(const std::invalid_argument& e){
        // Тест пройден
    }
    
    try{
        tm6.set_minute(999);
        assert(false); //< если тест не пройден
    }
    catch(const std::invalid_argument& e){
        // Тест пройден
    }}

int main(){
    DailyTime_test();

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

    //Работа с файлами
    time2->to_bin_file("test.bin");
    DailyTime timebin;
    timebin.from_bin_file("test.bin");
    std::cout << timebin.to_string();

}