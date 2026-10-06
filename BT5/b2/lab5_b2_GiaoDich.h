#pragma once 
#include "lab5_b2_date.h"
#include <iostream>

using namespace std;

class GiaoDich{
protected: 
    string ma_gd;
    Date ngay_gd;
    double gia;
public: 
    GiaoDich();
    int get_month() const ;
    int get_year() const;

    virtual ~GiaoDich() = default;
    virtual int get_loai() = 0; // 1: Dat; 2: Nha; 3: Chung cu
    virtual void nhap_gd();
    virtual void xuat_gd();
    virtual double thanh_tien_gd() = 0; // khai báo thuần ảo để khỏi define hàm này trong .cpp mà define sau trong các class con 
};