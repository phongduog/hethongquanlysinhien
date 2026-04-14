#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Nguoi {
protected:
    string hoTen;
    int tuoi;

public:
    Nguoi() : hoTen(""), tuoi(0) {}

    virtual void nhapThongTin() {
        cout << "Nhap Ho Ten: ";
        getline(cin, hoTen);
        cout << "Nhap Tuoi: ";
        cin >> tuoi;
        while (cin.fail() || tuoi <= 0 || tuoi > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Tuoi khong hop le. Nhap lai: ";
            cin >> tuoi;
        }
        cin.ignore();
    }

    virtual void hienThi() const {
        cout << left << setw(25) << hoTen << " | " << setw(5) << tuoi;
    }

    string getHoTen() const { return hoTen; }
    virtual ~Nguoi() {}
};

class SinhVien : public Nguoi {
protected:
    string maSo;
    string khoaHoc;

public:
    SinhVien() : Nguoi(), maSo(""), khoaHoc("") {}

    void nhapThongTin() override {
        cout << "Nhap Ma So SV: ";
        getline(cin, maSo);
        Nguoi::nhapThongTin();
        cout << "Nhap Khoa hoc: ";
        getline(cin, khoaHoc);
    }

    void hienThi() const override {
        cout << left << setw(15) << maSo << " | ";
        Nguoi::hienThi();
        cout << " | " << setw(15) << khoaHoc << endl;
    }

    string getMaSo() const { return maSo; }
};
void themMoi(vector<SinhVien*>& danhSach) {
    SinhVien* sv = new SinhVien();
    sv->nhapThongTin();
    danhSach.push_back(sv);
    cout << "\n=> Them sinh vien thanh cong!\n";
}

void hienThiTatCa(const vector<SinhVien*>& danhSach) {
    if (danhSach.empty()) {
        cout << "\n=> Danh sach trong!\n";
        return;
    }
    cout << "\n" << setfill('=') << setw(70) << "" << endl;
    cout << left << setw(15) << "MSV" << " | " << setw(25) << "Ho Ten" << " | " << setw(5) << "Tuoi" << " | " << setw(15) << "Khoa Hoc" << endl;
    cout << setfill('-') << setw(70) << "" << setfill(' ') << endl;
    for (const auto& sv : danhSach) {
        sv->hienThi();
    }
}

void timKiemMaSo(const vector<SinhVien*>& danhSach) {
    string ms;
    cout << "Nhap Ma So SV can tim: ";
    getline(cin, ms);
    bool timThay = false;
    for (const auto& sv : danhSach) {
        if (sv->getMaSo() == ms) {
            sv->hienThi();
            timThay = true;
        }
    }
    if (!timThay) cout << "=> Khong tim thay sinh vien co MSV: " << ms << endl;
}

void timKiemTen(const vector<SinhVien*>& danhSach) {
    string ten;
    cout << "Nhap Ten can tim: ";
    getline(cin, ten);
    bool timThay = false;
    for (const auto& sv : danhSach) {
        if (sv->getHoTen().find(ten) != string::npos) {
            sv->hienThi();
            timThay = true;
        }
    }
    if (!timThay) cout << "=> Khong tim thay sinh vien co ten: " << ten << endl;
}

int main() {
    vector<SinhVien*> danhSach;
    int luaChon;

    do {
        cout << "\n========= MENU QUAN LY SINH VIEN =========" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Hien thi danh sach" << endl;
        cout << "3. Tim kiem theo Ma So" << endl;
        cout << "4. Tim kiem theo Ten" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon chuc nang: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
            case 1: themMoi(danhSach); break;
            case 2: hienThiTatCa(danhSach); break;
            case 3: timKiemMaSo(danhSach); break;
            case 4: timKiemTen(danhSach); break;
        }
    } while (luaChon != 0);

    for (auto sv : danhSach) delete sv;

    return 0;
}
