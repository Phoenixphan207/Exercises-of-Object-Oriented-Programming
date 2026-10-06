#pragma once

#include "lab5_b2_GiaoDich.h"
#include <iostream>

using namespace std;

class Nha : public GiaoDich {
private: 
    string loai_nha;
    string address;
    float s;
public:
    void nhap_gd() override;
    void xuat_gd() override;
    int get_loai() override {
        return 2;
    } 
    double thanh_tien_gd() override;
};