#pragma once
#include "tv.h"

class TVControl {
public:
    TVControl(TV& tv);
    // ����������� TVControl ������ ������� ������
    // �� ��������� � ��������� � � ���� ������.
    // ���������� ��� � ������� ������������� � tv_control.cpp

    // �������� ����� ReadAndApplyCommand, ����� �� ���� �������������.
    // bool ReadAndApplyCommand() const;
    bool ReadAndApplyCommand() const;

private:
    /* ��������� ������ ������ ������ ����� �������������� � �� ��������� ������ �� tv. */
    void Info() const;
    void TurnOn() const;
    void TurnOff() const;
    bool SelectChannel() const;
    TV& tv_;
};
