#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Log {

    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    string key;
    string ipKey;

    Log() : year(""), month(""), day(""), time(""), ip(""), message(""), key(""), ipKey("") {}

    Log(string year, string month, string day, string time, string ip, string message);

    bool operator<(const Log& log) const;
    bool operator>(const Log& log) const;
    bool operator<=(const Log& log) const;
    bool operator>=(const Log& log) const;

    friend ostream& operator<<(ostream& os, const Log& log);

    string getKey() const;
    string getIpKey() const;
    string getYear() const;
    string getMonth() const;
    string getDay() const;
    string getMessage() const;
    string getTime() const;
    void replaceIpDotsWithZero();
};

Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;

    string aux;
    if (month == "Jan") {
        aux = "01";
    } else if (month == "Feb") {
        aux = "02";
    } else if (month == "Mar") {
        aux = "03";
    } else if (month == "Apr") {
        aux = "04";
    } else if (month == "May") {
        aux = "05";
    } else if (month == "Jun") {
        aux = "06";
    } else if (month == "Jul") {
        aux = "07";
    } else if (month == "Aug") {
        aux = "08";
    } else if (month == "Sep") {
        aux = "09";
    } else if (month == "Oct") {
        aux = "10";
    } else if (month == "Nov") {
        aux = "11";
    } else {
        aux = "12";
    }
    string hour = time.substr(0, 2);
    string min = time.substr(3, 2);
    string sec = time.substr(6, 2);
    key = year + aux + day + hour + min + sec;

    // Calcular la clave basada en la dirección IP
    ipKey = ip;
}

void Log::replaceIpDotsWithZero() {
    for (char &c : ip) {
        if (c == '.') {
            c = '0';
        }
    }
}

bool Log::operator<(const Log& log) const {
    return this->key < log.key;
}

bool Log::operator>(const Log& log) const {
    return this->key > log.key;
}

bool Log::operator<=(const Log& log) const {
    return this->key <= log.key;
}

bool Log::operator>=(const Log& log) const {
    return this->key >= log.key;
}

ostream& operator<<(ostream& os, const Log& log) {
    os << "Log: " << log.month << " " << log.day << " " << log.year << " " << log.time << " " << log.ip << " " << log.message << endl;
    return os;
}

string Log::getKey() const {
    return key;
}

string Log::getIpKey() const {
    return ipKey;
}

string Log::getYear() const {
    return year;
}

string Log::getMonth() const {
    return month;
}

string Log::getDay() const {
    return day;
}

string Log::getMessage() const {
    return message;
}

string Log::getTime() const {
    return time;
}