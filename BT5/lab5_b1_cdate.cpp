#include "lab5_b1_cdate.h"

using namespace std;

CDate::CDate() {
    ngay = thang = nam = 0;
}
 
bool is_leap_year(int y) {
    return (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);
}
bool CDate::check_valid_ntn() {
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

void CDate::nhap_ngay_thang_nam() {
    cin >> ngay >> thang >> nam;

    while (check_valid_ntn() == false) {
        cout << "nhap lai ngay tahng nam hop le: ";
        cin >> ngay >> thang >> nam;
    }
}

void CDate::xuat_ngay_thang_nam() {
    cout << ngay << "/" << thang << "/" << nam;
}

long CDate::tong_so_ngay_tu_1900() {
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long tongNgay = 0;
    // 1. Cộng số ngày của các năm trọn vẹn từ năm 1900 đến năm ngay trước
    // năm hiện tại (this->nam - 1)
    for (int y = 1900; y < this->nam; y++) {
        if (is_leap_year(y)) {
            tongNgay += 366;
        } else {
            tongNgay += 365;
        }
    }
    // 2. Cộng số ngày của các tháng trọn vẹn từ tháng 1 đến tháng ngay
    // trước tháng hiện tại (this->thang - 1)
    for (int m = 0; m < this->thang - 1; m++) {
    tongNgay += monthDays[m];
    }
    // 3. Nếu năm hiện tại là năm nhuận và đã qua tháng 2 (tức là từ tháng 3
    // trở đi) thì cộng thêm 1 ngày nhuận (ngày 29/2)
    if (this->thang > 2 && is_leap_year(this->nam)) {
        tongNgay += 1;
    }
    // 4. Cộng thêm số ngày lẻ của tháng hiện tại (trừ đi 1 ngày vì ngày bắt
    // đầu là 01/01/1900)
    tongNgay += (this->ngay - 1);

    return tongNgay;
}