#include "lab5_b2_date.h"

Date::Date() : ngay(0), thang(0) , nam(0) {};

bool is_leap_year(int y) {
    return (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);
}

bool Date::check_valid_ntn() {
    if (nam <= 0) return false;          // Năm phải dương
    if (thang < 1 || thang > 12) return false; // Tháng từ 1 đến 12

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Nếu là năm nhuận thì tháng 2 có 29 ngày
    if (is_leap_year(this->nam)) {
        daysInMonth[1] = 29;
    }

    if (ngay < 1 || ngay > daysInMonth[thang - 1]) return false;

    return true;
}

void Date::nhap_ntn(){
    cin >> ngay >> thang >> nam;

    while (check_valid_ntn() == false) {
        cout << "nhap lai ngay thang nam hop le: ";
        cin >> ngay >> thang >> nam;
    }
}

void Date::xuat_ntn() {
    cout << ngay <<"/" << thang << "/" << nam;
}

int Date::get_thang() const {
    return thang;
}

int Date::get_nam() const {
    return nam;
}