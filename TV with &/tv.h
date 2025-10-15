#pragma once

class TV {
public:
    inline static const int MIN_CHANNEL = 1;
    inline static const int MAX_CHANNEL = 99;

    // �������� ���������.
    void TurnOn();

    // ��������� ���������.
    void TurnOff();

    // ���������� true, ���� ��������� �������, � false, ���� ��������� ��������.
    bool IsTurnedOn() const;

    // ���������� ����� �������� ������ ���� 0, ���� ��������� ��������.
    // ��������� ��� ���������� ���������� ����� �������� ������,
    // � ��� ��������� � ��������������� ���.
    // ��� ������ ��������� ��������� ���������� ����� � 1.
    int GetCurrentChannel() const;

    // �������� ����� � ��������� �������. ����� ������
    // ������ ���� � ��������� [1..99].
    // ���� ������ ������������ ����� ������ ���� ���������
    // ��������, ���������� false � �� ������
    // ������� �����. � ��������� ������ ���������� true.
    bool SelectChannel(int channel);

private:
    bool is_turned_on_ = false;
    int current_channel_ = 1;
};
