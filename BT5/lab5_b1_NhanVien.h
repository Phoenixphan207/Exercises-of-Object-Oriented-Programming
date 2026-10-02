#pragma once
#include "lab5_b1_cdate.h"
#include <string>
#include <iostream>

using namespace std;

class NhanVien {
protected: 
    string name;
    CDate ntn;
    double luong;

public: 
    NhanVien();
    virtual ~NhanVien() = default;
    virtual void Nhap();
    virtual void Xuat();
    double luong_chinh();
    long so_ngay_tu1900();

};