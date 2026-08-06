#include <iostream>

using namespace std;

class NgayThangNam {
private:
    int ngay;
    int thang;
    int nam;

    bool laNamNhuan() {
        return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
    }
    bool valid_info() {
        if (ngay * thang * nam <= 0 || ngay > 31 || thang > 12)
            return false;
        if (thang == 2 && ngay > 29) 
            return false;
        if (thang == 4|| thang == 6 || thang == 9 || thang == 11) {
            if (ngay > 30) return false;
        }
        if (!laNamNhuan() && ngay == 29 && thang == 2) return false;

        return true;
    }
    
public:
    NgayThangNam() : ngay(1) , thang(1), nam(1) {};

    void Nhap() {
        cout << "Nhap ngay, thang ,nam: ";
        cin >> ngay >> thang >> nam;
        while (!valid_info()) {
            cout << "Nhap lai ngay thang nam hop le: ";
            cin >> ngay >> thang >> nam;
        }
    }
    void Xuat() {
        cout << ngay << "/" << thang << "/" << nam;
    }

    void NgayThangNamTiepTheo() {
        switch (thang)
        {
        case 1:
            if (ngay == 31) {
                ngay = 1;
                thang ++;
            }
            else {
                ngay ++;
            }
           
            break;
        case 3:
            if (ngay == 31) {
                ngay = 1;
                thang ++;
            }
            else {
                ngay ++;
            }
            
            break;
        case 5:
            if (ngay == 31) {
                ngay = 1;
                thang ++;
            }
            else {
                ngay ++;
            }
            break;
        case 7:
            if (ngay == 31) {
                ngay = 1;
                thang ++;

            }
            else {
                ngay ++;
            }
            break;
        case 8:
            if (ngay == 31) {
                ngay = 1;
                thang ++;

            }
            else {
                ngay ++;
            }
            
            break;
        case 10:
            if (ngay == 31) {
                ngay = 1;
                thang ++;
            }
            else {
                ngay ++;
            }
            break;
        case 12:
            if (ngay == 31) {
                ngay = 1;
                thang = 1;
                nam += 1;
            }
            else {
                ngay ++;
            }
            break;
        case 4:
            if (ngay == 30) {
                ngay = 1;
                thang ++;
            }
            else ngay ++;
            
            break;
        case 6:
            if (ngay == 30) {
                ngay = 1;
                thang ++;
            }
            else ngay ++;
            break;
        case 9: 
            if (ngay == 30) {
                ngay = 1;
                thang ++;
            }
            else ngay ++;
            break;
        case 11: 
            if (ngay == 30) {
                ngay = 1;
                thang ++;
            }
            else ngay ++;
            break;
        case 2:
            if (laNamNhuan()) {
                if (ngay == 29) {
                    ngay = 1;
                    thang ++;
                }
                else {
                    ngay ++;
                }
            }
            else {
                if (ngay == 28) {
                    ngay = 1;
                    thang ++;
                }
                else ngay ++ ;

            }
        default:
            break;
        }
    }
};

int main() {
    NgayThangNam a;
    a.Nhap();
    a.NgayThangNamTiepTheo();
    a.Xuat();
}