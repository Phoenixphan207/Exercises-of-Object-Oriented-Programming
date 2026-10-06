#include "lab5_b2_CongTy.h"

void Cty::nhap_cty() {
    int n = 0;
    cout << "Nhap so luong giao dich: ";
    cin >> n;

    for (int i = 0 ; i < n ; i ++) { 
        int s = 0;
        cout << "Nhap loai giao dich: (1: dat, 2: nha pho, 3: chung cu): ";
        cin >>  s;

        GiaoDich *a = nullptr;
        if (s == 1) {
            a = new Dat();
        }
        else if (s == 2) {
            a = new Nha();
        }
        else {
            a = new ChungCu();
        }
        
        a->nhap_gd();
        danhSach.push_back(a);
        cout << "**** Da nhan don hang thanh cong ****" << '\n'; 
    }
}

void Cty::xuat_cty() {
    for (GiaoDich* i : danhSach) {
        i->xuat_gd();
        cout << '\n';
    }
}

void Cty::tong_so_luong_tung_loai() {
    if (danhSach.empty() == true) {
        cout << "Khong co giao dich";
        return;
    }

    int dat = 0;
    int cc = 0;
    int nha = 0;

    for (GiaoDich* i : danhSach) {
        if (i->get_loai() == 1) dat++;
        else if (i->get_loai() == 2) nha ++;
        else if (i->get_loai() == 3) cc ++;
    }

    cout << "So giao dich Dat: " << dat << '\n';
    cout << "So giao dich Chung cu: " << cc << '\n';
    cout << "So giao dich Nha o: " << nha;
}

double Cty::average_tien_chung_cu() {
    if (danhSach.empty()) return 0;

    double a = 0.0;
    int sl = 0;

    for (GiaoDich *i : danhSach) {
        if (i->get_loai() == 3) {
            sl ++;
            a += i->thanh_tien_gd();
        }
    }
    if (sl == 0) return 0;

    return a / sl;
}

double Cty::gd_nha_max() {
    double maxfar = 0.0;

    for (GiaoDich* i : danhSach) {
        if (i->get_loai() == 2) {
            if ((maxfar - i->thanh_tien_gd()) < ESP){
                maxfar = i->thanh_tien_gd();
            }
        }       
    }
    
    return maxfar;

}

void Cty::gd_t12_2024() {
    if (danhSach.empty()) return;

    for (GiaoDich* i : danhSach) {
        if (i->get_month() == 12 && i->get_year() == 2024) {
            i->xuat_gd();
            cout << '\n';
        }
    }
}


Cty::~Cty() {
    for (GiaoDich* gd : danhSach) {
        delete gd;
    }
    danhSach.clear();
}