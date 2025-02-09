#include "tv_control.h"

#include <iostream>

using namespace std::literals;

bool TVControl::TurnOn(TV& tv) {
    tv.TurnOn();
    std::cout << "Turning on" << std::endl;
    return true;
}

bool TVControl::TurnOff(TV& tv) {
    tv.TurnOff();
    std::cout << "TV is turned off" << std::endl;
    return true;
}

bool TVControl::SelectChannel(TV& tv) {
    int chanel;
    if (!(std::cin >> chanel)) {
        std::cout << "Invalid argument" << std::endl;
        return false;
    }
    if (!(tv.IsTurnedOn())) {
        std::cout << "TV is not turned on" << std::endl;
        return true;
    }
    if (tv.SelectChannel(chanel)) {
        std::cout << "Channel selected" << std::endl;
        return true;
    }
    std::cout << "Invalid channel" << std::endl;
    return true;
}

bool TVControl::ReadAndApplyCommand(TV& tv) {
    std::string action;

    // —начала считываем команду до первого пробела, 
    // табул€ции или конца строки.
    if (!(std::cin >> action)) {
        std::cout << "Invalid command"s << std::endl;
        return false;
    }
    if (action == "Info"s) {
        Info(tv);
        return true;
    }
    if (action == "Exit"s) {
        return false;
    }
    if (action == "TurnOn"s) {
        return TVControl::TurnOn(tv);
    }
    if (action == "TurnOff"s) {
        return TVControl::TurnOff(tv);
    }
    if (action == "SelectChannel"s) {
        return TVControl::SelectChannel(tv);
    }

    // –еализуйте обработку остальных команд.
    // ......................................

    std::cout << "Unknown command"s << std::endl;
    return false;
}

void TVControl::Info(TV& tv) {
    if (!tv.IsTurnedOn()) {
        std::cout << "TV is turned off"s << std::endl;
        return;
    }
    std::cout << "TV is turned on. Channel is "s
        << tv.GetCurrentChannel() << std::endl;
    return;
}