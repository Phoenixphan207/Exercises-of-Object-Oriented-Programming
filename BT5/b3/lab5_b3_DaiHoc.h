#pragma once

#include "lab5_b3_SinhVien.h"

class DaiHoc : public SinhVien {
private: 
    string luan_van;
    float lv;
public: 
    void nhap() override;
    void xuat() override;
    float get_lv() {
        return lv;
    }
    int loai_sinh_vien() override {
        return 2;
    }
    bool tot_nghiep() override;
};