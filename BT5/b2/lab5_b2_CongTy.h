#include "lab5_b2_GiaoDich.h"
#include "lab5_b2_Dat.h"
#include "lab5_b2_ChungCu.h"
#include "lab5_b2_Nha.h"

#include <iostream>
#include <vector>
#include <unordered_map>

#define ESP 1e-9
using namespace std;

class Cty {
private: 
    vector<GiaoDich*> danhSach;
    double thanh_tien;
public: 
    ~Cty();

    void nhap_cty();
    void xuat_cty();
    void tong_so_luong_tung_loai();
    double average_tien_chung_cu();
    double gd_nha_max();
    void gd_t12_2024();
};