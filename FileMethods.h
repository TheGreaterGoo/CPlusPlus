// guards
#ifndef FILEMETHODS_H
#define FILEMETHODS_H

#include <iostream>
#include <string>
#include <fstream>
#include <mutex>
using namespace std;

// FileMethods singleton class
class FileMethods {
    private:
        // singleton pointer
        static FileMethods* instancePtr;

        // mutex to ensure thread safety
        static mutex mtx;

        FileMethods() {}

    public:
        // deleting the copy constructor
        FileMethods(const FileMethods& obj) = delete;

        // static method to get the singleton instance
        static FileMethods* getInstance() {
            if (instancePtr == nullptr) {
                lock_guard<mutex> lock(mtx);
                if (instancePtr == nullptr) {
                    instancePtr = new FileMethods();
                }
            }
            return instancePtr;
        }

        // write to file with parameter
        void write(string text, ofstream &myFile) {
            myFile << text;
            myFile.close();
        };

        // write to file with console input
        void writeInput(ofstream &myFile) {
            string text;
            getline(cin, text);
            myFile << text;
            myFile.close();
        };

        // read file
        void read(ifstream &myFile) {
            string text;
            while (getline(myFile, text)) {
                cout << text;
            }
            myFile.close();
        };
};

// Initialize static members
FileMethods* FileMethods::instancePtr = nullptr;
mutex FileMethods::mtx;

FileMethods* file = FileMethods::getInstance();

#endif