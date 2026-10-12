#include "lab5_b3_Truong.h"

void Truong::nhap_danh_sach() {
    int n = 0;
    cout << "Nhap vao so luong sinh vien: ";
    cin >> n;

    for (int i = 0 ; i < n ; i++) {
        cout << "Chon loai sinh vien: (1: Cao dang; 2: Dai hoc): ";
        int t = 0;
        cin >> t;

        SinhVien* tmp = nullptr;
        if (t == 1) {
            tmp = new CaoDang();
        }
        else {
            tmp = new DaiHoc();
        }

        tmp->nhap();
        danhSach.push_back(tmp);
    }
    
}