#include <iostream>

using namespace std;

class GioPhutGiay {
private:
    int iGio;
    int iPhut;
    int iGiay;

    bool valid_info() {
        if (iGiay < 0 || iGio < 0 || iPhut < 0 || iGiay >= 60 || iPhut >= 60 || iGio > 24 )
            return false;
        return true;
    }
public:
    GioPhutGiay(): iGio(0) , iGiay(0) , iPhut(0) {};

    void Nhap() {
        cout << "Nhap gio phut giay: " ;
        cin >> iGio >> iPhut >> iGiay;

        while (!valid_info()) {
            cout << "Nhap lai : ";
            cin >> iGio >> iPhut >> iGiay;
        }
    }
    
    void TinhCongThemMotGiay() {
        if (iGiay == 59) {
            if (iPhut == 59) {
                iPhut = 0;
                iGiay = 0;       

                if (iGio == 23) {
                    iGio = 0 ;
                }
                else if (iGio == 24) {
                    iGio = 1;
                }
                else {
                    iGio += 1;
                }
            }
            else {
                iGiay = 0;
                iPhut ++;
            }
        }
        else {
            iGiay ++;
        }
    }

    void Xuat() {
        cout << iGio << "h-" << iPhut << "p-" << iGiay <<"s";
    }
};

int main() {
    GioPhutGiay a;
    a.Nhap();
    a.TinhCongThemMotGiay();
    a.Xuat();
}