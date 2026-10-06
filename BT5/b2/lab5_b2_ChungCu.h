#pragma once

#include "lab5_b2_GiaoDich.h"
#include <iostream>

using namespace std;

class ChungCu : public GiaoDich {
private:
    string ma_can;
    int tang;
    float s;
public:
    void nhap_gd() override;
    void xuat_gd() override;
    double thanh_tien_gd() override;
    int get_loai() override {
        return 3;
    }
};