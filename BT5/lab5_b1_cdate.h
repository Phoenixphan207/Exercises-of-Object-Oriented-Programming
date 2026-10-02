#pragma once 

#include <iostream>

class CDate {
private: 
    int ngay;
    int thang;
    int nam;

public:
    CDate();
    bool is_leap_year();
    bool check_valid_ntn();
    void nhap_ngay_thang_nam();
    void xuat_ngay_thang_nam();
    long tong_so_ngay_tu_1900();
};