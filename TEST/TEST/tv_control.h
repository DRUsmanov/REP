#pragma once

#include <string>

#include "tv.h"

class TVControl {
public:
    // ��������� �� ������������ ������ ����� ������� ���������� �����������
    // � ��������� ��� �������, ��������� ��������� tv.
    // ���������� true � ������ ������.
    // ���������� false, ���� ��������� ������ ������� ������� ��� ���� ������� ������� Exit.
    static bool ReadAndApplyCommand(TV& tv);


private:
    static void Info(TV& tv);
    static bool TurnOn(TV& tv);
    static bool TurnOff(TV& tv);
    static bool SelectChannel(TV& tv);
};
