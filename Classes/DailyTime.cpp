#include <stdexcept>
#include <format>
#include <string>

#include <assert.h>
#include <iostream>
// #include <exception>


//todo: комментарии, больше тестов + примеры исп.

class DailyTime{
    unsigned short hour;
    unsigned short minute;
    unsigned short second;

public:

    DailyTime() : hour(0), minute(0), second(0) {}
    DailyTime(unsigned short hour) : minute(0), second(0) {
        set_hour(hour);
    }
    DailyTime(unsigned short hour, unsigned short minute) : second(0) {
        set_hour(hour);
        set_minute(minute);
    }
    DailyTime(unsigned short hour, unsigned short minute, unsigned short second) {
        set_hour(hour);
        set_minute(minute);
        set_second(second);
    }

    unsigned short get_hour() const{
        return hour;
    } 
    unsigned short get_minute() const{
        return minute;
    } 
    unsigned short get_second() const{
        return second;
    } 
    
    void set_hour(unsigned short new_hour){
        if (new_hour > 23)
            throw std::invalid_argument("0 <= hour <= 23");
        hour = new_hour;
    }
    void set_minute(unsigned short new_minute){
        if (new_minute > 59)
            throw std::invalid_argument("0 <= minute <= 59");
        minute = new_minute;
    }
    void set_second(unsigned short new_second){
        if (new_second > 59)
            throw std::invalid_argument("0 <= second <= 59");
        second = new_second;
    }

    void add_hour(unsigned short new_hour){
        hour = (hour + new_hour) % 24;
    }
    void add_minute(unsigned short new_minute){
        add_hour((minute + new_minute) / 60);
        minute = (minute + new_minute) % 60;
    }
    void add_second(unsigned short new_second){
        add_minute((second + new_second) / 60);
        second = (second + new_second) % 60;
    }

    std::string to_string() const {
        return std::format("{:02d}:{:02d}:{:02d}", hour, minute, second);
    }

    DailyTime& operator +=(const DailyTime& add_time){
        add_hour( add_time.get_hour() );
        add_minute( add_time.get_minute() );
        add_second( add_time.get_second() );
        return *this;
    }
};

DailyTime operator+(const DailyTime& time1, const DailyTime& time2){
    DailyTime new_time = time1;
    new_time += time2;
    return new_time;
}

int main(){
    DailyTime tm(20);
    tm.add_hour(5);
    tm.add_second(36361);
    assert( tm.to_string() == "11:06:01" );
    std::cout << tm.to_string() << "\n";

    tm.set_hour(23);
    tm.set_minute(52);
    tm.set_second(22);
    std::cout << tm.to_string() << "\n";
    
    DailyTime tm2(03, 54, 22);
    tm += tm2;
    std::cout << tm.to_string() << "\n";

}