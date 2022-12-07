//
// Created by Calin on 23/05/2022.
//

#ifndef PROIECT_FINAL_TIME_H
#define PROIECT_FINAL_TIME_H


class Time {
private:
    int hours, minutes;
public:
    Time() = default;
    Time(int hours, int minutes) : hours(hours), minutes(minutes) {};

    int getHours() const {
        return hours;
    }

    int getMinutes() const {
        return minutes;
    }

    void setHours(int hours) {
        Time::hours = hours;
    }

    void setMinutes(int minutes) {
        Time::minutes = minutes;
    }

    bool operator<(const Time &rhs) const {
        if (hours < rhs.hours)
            return true;
        if (rhs.hours < hours)
            return false;
        return minutes < rhs.minutes;
    }

    bool operator>(const Time &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Time &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Time &rhs) const {
        return !(*this < rhs);
    }

    Time& operator=(const Time &time){
        if(this != &time){
            this->hours = time.hours;
            this->minutes = time.minutes;
        }
        return *this;
    }

    bool operator==(const Time &rhs) const {
        return hours == rhs.hours &&
               minutes == rhs.minutes;
    }

    ~Time() = default;
};


#endif //PROIECT_FINAL_TIME_H
