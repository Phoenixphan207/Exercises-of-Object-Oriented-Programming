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
        cout << "**** NHAP THANH CONG ****" << '\n';
    }
    
}

void Truong::xuat_danh_sach() {
    for (SinhVien* i : danhSach) {
        i->xuat();
        cout << '\n';
    }
}

void Truong::sinh_vien_tn() {
    for (SinhVien* i : danhSach) {
        if (i->tot_nghiep()) {
            i->xuat();
            cout << endl;
        }
    }
}

void Truong::sinh_vien_ko_tn() {
    for (SinhVien* i : danhSach) {
        if (!i->tot_nghiep()) {
            i->xuat();
            cout << endl;
        }
    }
}

SinhVien* Truong::dai_hoc_diem_max() {
    SinhVien * tmp = danhSach[0];
    float res = 0.0;

    for (SinhVien* i : danhSach) {
        if (i->loai_sinh_vien() == 2) {
            if (i->get_gpa() > res) {
                res = i->get_gpa();
                tmp = i;
            }
        }
    }

    return tmp;
}

SinhVien* Truong::cao_dang_diem_max() {
    SinhVien * tmp = danhSach[0];
    float res = 0.0;

    for (SinhVien* i : danhSach) {
        if (i->loai_sinh_vien() == 1) {
            if (i->get_gpa() > res) {
                res = i->get_gpa();
                tmp = i;
            }
        }
    }

    return tmp;
}

void Truong::sinh_vien_ko_tn_moi_loai() {
    int cd = 0;
    int dh = 0;

    for (SinhVien* i : danhSach) {
        if (!i->tot_nghiep()) {
            if (i->loai_sinh_vien() == 1) cd ++;
            else dh ++;
        }
    }

    cout << "Dai hoc: " << dh << '\n';
    cout << "Cao dang: " << cd << '\n';

}


Truong::~Truong() {
    for (SinhVien* i : danhSach) {
        delete i;
    }
    danhSach.clear();
}