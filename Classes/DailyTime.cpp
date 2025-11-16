#include <stdexcept>
// #include <exception>
class DailyTime{
    unsigned short hour;
    unsigned short minute;
    unsigned short second;

public:
    DailyTime(){
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
    DailyTime(unsigned short hour){
        this->hour = hour;
        this->minute = 0;
        this->second = 0;
    }
    DailyTime(unsigned short hour, unsigned short minute){
        this->hour = hour;
        this->minute = minute;
        this->second = 0;
    }
    DailyTime(unsigned short hour, unsigned short minute, unsigned short second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    unsigned short get_hour() const{
        return this->hour;
    } 
    unsigned short get_minute() const{
        return this->minute;
    } 
    unsigned short get_second() const{
        return this->second;
    } 
    void set_hour(unsigned short hour){
        if (hour > 23)
            throw std::invalid_argument("0 <= hour <= 23");
        this->hour = hour;
    }
    void set_minute(unsigned short minute){
        if (minute > 23)
            throw std::invalid_argument("0 <= minute <= 59");
        this->minute = minute;
    }
    void set_second(unsigned short second){
        if (second > 23)
            throw std::invalid_argument("0 <= second <= 23");
        this->hour = second;
    }
};