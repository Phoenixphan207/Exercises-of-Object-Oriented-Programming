#pragma once

#include <iostream>
using namespace std;

class Date {
private: 
    int ngay;
    int thang;
    int nam;
public:
    Date();
    int get_thang() const;
    int get_nam() const;
    void nhap_ntn();
    void xuat_ntn();
    bool check_valid_ntn();
};