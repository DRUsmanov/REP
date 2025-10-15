#pragma once
#include "tv.h"

class TVControl {
public:
    TVControl(TV& tv);
    //  онструктор TVControl должен прин€ть ссылку
    // на телевизор и сохранить еЄ в поле класса.
    // ќпределите его с списком инициализации в tv_control.cpp

    // «амените метод ReadAndApplyCommand, чтобы он стал нестатическим.
    // bool ReadAndApplyCommand() const;
    bool ReadAndApplyCommand() const;

private:
    /* ѕриватные методы класса должны стать нестатическими и не принимать ссылку на tv. */
    void Info() const;
    void TurnOn() const;
    void TurnOff() const;
    bool SelectChannel() const;
    TV& tv_;
};
