#pragma once

#include "lab5_b2_GiaoDich.h"
#include <iostream>

using namespace std;

class Dat : public GiaoDich{
private:
    char loai_dat;
    float s;
public:
    void nhap_gd() override;
    void xuat_gd() override;
    double thanh_tien_gd() override;
    int get_loai() override {
        return 1;
    }
};