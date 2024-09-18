#ifndef TIMEMETHODS_H
#define TIMEMETHODS_H

#include <iostream>
#include <ctime>
#include <string>
#include <mutex>
using namespace std;

// TimeMethods singleton class
class TimeMethods {
    private:
        // singleton pointer
        static TimeMethods* instancePtr;

        // mutex to ensure thread safety
        static mutex mtx;

        TimeMethods() {}

    public:
        // delete copy constructor
        TimeMethods(const TimeMethods& obj) = delete;

        // static method to get the singleton instance
        static TimeMethods* getInstance() {
            if (instancePtr = nullptr) {
                lock_guard<mutex> lock(mtx);
                if (instancePtr = nullptr) {
                    instancePtr = new TimeMethods();
                }
            }
            return instancePtr;
        }

        // return current timestamp as a string
        time_t getCurrentTimestamp() {
            time_t timestamp;

            // write timestamp to memory location
            time(&timestamp);
            return timestamp;
        }

        // create timestamp
        time_t createTimestamp(int year, int month, int day, int hour, int minute, int second) {
            struct tm datetime;
            time_t timestamp;

            datetime.tm_year = year - 1900; // Number of years since 1900
            datetime.tm_mon = month - 1; // Number of months since January
            datetime.tm_mday = day;
            datetime.tm_hour = hour;
            datetime.tm_min = minute;
            datetime.tm_sec = second;

            // Daylight Savings must be specified
            // -1 uses the computer's timezone setting
            datetime.tm_isdst = -1;

            timestamp = mktime(&datetime);
            return timestamp;
        }

        void printTimestamp(time_t timestamp) {
            cout << ctime(&timestamp);
        }

        string getWeekday(time_t timestamp) {
            struct tm datetime = *localtime(&timestamp);

            string weekdays[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
            return weekdays[datetime.tm_wday];
        }

};

// initialize static members
TimeMethods* TimeMethods::instancePtr = nullptr;
mutex TimeMethods::mtx;

TimeMethods* t = TimeMethods::getInstance();

#endif