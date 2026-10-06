#include "lab5_b2_CongTy.h"

using namespace std;

int main() {
    Cty a;
    a.nhap_cty();
    a.xuat_cty();
    cout << "Average tien chung cu: " << a.average_tien_chung_cu() << '\n';
    cout << "Giao dich nha max: " << a.gd_nha_max() << '\n';
    a.gd_t12_2024();
    a.tong_so_luong_tung_loai();
}