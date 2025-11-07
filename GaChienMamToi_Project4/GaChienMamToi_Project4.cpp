#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class NguoiDung {
protected:
	string strTenDangNhap;
	string strMatKhau;
public:
	NguoiDung() : strTenDangNhap(""), strMatKhau("") {}
	NguoiDung(string ten, string mk) : strTenDangNhap(ten), strMatKhau(mk) {}
	NguoiDung(const NguoiDung& other) : strTenDangNhap(other.strTenDangNhap), strMatKhau(other.strMatKhau) {}
	string getTenDangNhap() const {
		return this->strMatKhau;
	}
	bool ktMatKhau(string strMatKhau, string strTenDangNhap);
	virtual void hienThiMenu() = 0;
	virtual ~NguoiDung() {}
};
bool NguoiDung::ktMatKhau(string strTenNhap, string strMKnhap) {
    return (this->strTenDangNhap == strTenNhap && this->strMatKhau == strMKnhap);
}
class QuanLy : public NguoiDung {
public:
	QuanLy() : NguoiDung() {}
	QuanLy(string ten, string mk) : NguoiDung(ten, mk) {}
	virtual void hienThiMenu() override {
		cout << "\n--- MENU QUAN LY (" << strTenDangNhap << ") ---\n";
		cout << "1. Quan Ly San Pham\n";
		cout << "2. Xu Ly Don Hang\n";
		cout << "3. Quan Ly Nhan Vien\n";
		cout << "ESC. Dang xuat\n";
	}
	void themNhanVien() {}
	void xoaNhanVien() {}
	void xuLyDon() {}
};
class NhanVien : public NguoiDung {
public:
	NhanVien() : NguoiDung() {}
	NhanVien(string ten, string mk) : NguoiDung(ten, mk) {}
	NhanVien(const NhanVien& other) : NguoiDung(other) {}
	void hienThiMenu() override {
		cout << "\n--- MENU NHAN VIEN (" << strTenDangNhap << ") ---\n";
		cout << "1. Xu Ly Don Hang\n";
		cout << "2. Cap Nhat Kho Hang\n";
		cout << "ESC. Dang xuat\n";
	}
	void xuLyDon() { cout << "Dang xu ly don hang...\n"; }
};
class KhachHang : public NguoiDung {
private:
	string strDiaChi;
	string strSDT;

public:
	KhachHang() : NguoiDung(), strDiaChi(""), strSDT("") {}
	KhachHang(string ten, string mk, string dc, string sdt)
		: NguoiDung(ten, mk), strDiaChi(dc), strSDT(sdt) {
	}
	KhachHang(const KhachHang& other)
		: NguoiDung(other), strDiaChi(other.strDiaChi), strSDT(other.strSDT) {
	}
	void hienThiMenu() override {
		cout << "\n--- MENU KHACH HANG (" << strTenDangNhap << ") ---\n";
		cout << "1. Xem San Pham\n";
		cout << "2. Dat Hang\n";
		cout << "3. Xem Don Hang Cua Toi\n";
		cout << "ESC. Dang xuat\n";
	}
	string getDiaChi() const { return strDiaChi; }
	string getSDT() const { return strSDT; }
};

//LOP SAN PHAM
class SanPham {
private:
	string maSP;
	string tenSP;
	double gia;
	string chiTietSP;
	string hangSP;

public:
	string getMa() const { return maSP; }
	string getHang() const { return hangSP; }
	double getGia() const { return gia; }
	string getTen() const { return tenSP; }

	SanPham(string ma, string ten, double g, string ct, string hang) {
		maSP = ma;
		tenSP = ten;
		gia = g;
		chiTietSP = ct;
		hangSP = hang;
	}

	static void TieuDe() {
		cout << left
			<< setw(12) << "MÃ"
			<< setw(43) << "TÊN SẢN PHẨM"
			<< setw(12) << "GIÁ"
			<< setw(40) << "CHI TIẾT" << endl;
		cout << string(102, '-') << endl;
	}

	void hienThi() const {
		cout << left
			<< setw(12) << maSP
			<< setw(35) << tenSP
			<< setw(15) << fixed << setprecision(0) << gia
			<< setw(40) << chiTietSP << endl;
	}

	void hienThiChiTiet() const {
		cout << "\n=== CHI TIẾT SẢN PHẨM ===\n";
		cout << "Hãng: " << hangSP << endl;
		cout << "Mã: " << maSP << endl;
		cout << "Tên sản phẩm: " << tenSP << endl;
		cout << "Giá: " << fixed << setprecision(0) << gia << " VND\n";
		cout << "Chi tiết: " << chiTietSP << endl;
	}
};
int main() {
    // Tài khoản mẫu
    QuanLy ql("admin", "123");
    NhanVien nv("nhanvien", "111");
    KhachHang kh("khach", "000", "P4.Q5", "0123");

    string ten, mk;
    cout << "===== ĐĂNG NHẬP HỆ THỐNG =====\n";
    cout << "Tên đăng nhập: ";
    getline(cin, ten);
    cout << "Mật khẩu: ";
    getline(cin, mk);

    // Xác định loại người dùng
    if (ql.ktMatKhau(ten, mk)) {
        ql.hienThiMenu();
    }
    else if (nv.ktMatKhau(ten, mk)) {
        nv.hienThiMenu();
    }
    else if (kh.ktMatKhau(ten, mk)) {
        kh.hienThiMenu();
        cout << "\n✅ Đăng nhập thành công với tư cách KHÁCH HÀNG!\n";

        // === PHẦN CODE SẢN PHẨM GIỮ NGUYÊN ===
        vector<SanPham> dsSP = {
            {"101", "Nike Air Jordan 1 high OG", 5000000, "Thời trang, năng động", "Nike"},
            {"102", "Nike Air Max", 2000000, "Thích hợp chạy bộ", "Nike"},
            {"201", "Adidas Ultraboost", 5000000, "Đế đàn hồi cao", "Adidas"},
            {"202", "Adistar 4", 3500000, "Thiết kế nhẹ, thông thoáng", "Adidas"},
            {"301", "Bitis Hunter Jogging", 800000, "Thích hợp chạy đường dài", "Bitis Hunter"},
            {"302", "Bitis Hunter Running", 1000000, "Đệm êm, thích hợp chạy bền", "Bitis Hunter"}
        };

        int luaChon, soLuongGioHang = 0;
        string maNhap;

        while (true) {
            cout << "\n===== SẢN PHẨM =====\n";
            cout << "1. Nike\n";
            cout << "2. Adidas\n";
            cout << "3. Biti's Hunter\n";
            cout << "0. Thoát\n";
            cout << "Nhập lựa chọn: ";
            cin >> luaChon;
            cin.ignore();

            if (luaChon == 0) break;

            string hang;
            switch (luaChon) {
            case 1: hang = "Nike"; break;
            case 2: hang = "Adidas"; break;
            case 3: hang = "Bitis Hunter"; break;
            default:
                cout << "Lựa chọn không hợp lệ!\n";
                continue;
            }

            cout << "\n============================== DANH SÁCH SẢN PHẨM " << hang << " ==============================\n";
            SanPham::TieuDe();
            for (const auto& sp : dsSP)
                if (sp.getHang() == hang)
                    sp.hienThi();

            cout << "\nNhập mã sản phẩm để xem chi tiết (hoặc 0 để quay lại): ";
            getline(cin, maNhap);
            if (maNhap == "0") continue;

            bool timThay = false;
            for (const auto& sp : dsSP) {
                if (sp.getMa() == maNhap && sp.getHang() == hang) {
                    timThay = true;
                    sp.hienThiChiTiet();

                    cout << "\n1. Thanh toán\n2. Thêm vào giỏ hàng\n0. Quay lại\n Lựa chọn: ";
                    int chon;
                    cin >> chon;
                    cin.ignore();

                    if (chon == 1) {
                        string tenKH, sdt, diaChi, thanhToan;
                        cout << "\n=== NHẬP THÔNG TIN KHÁCH HÀNG ===\n";
                        cout << "Tên khách hàng: ";
                        getline(cin, tenKH);
                        cout << "Số điện thoại: ";
                        getline(cin, sdt);
                        cout << "Địa chỉ: ";
                        getline(cin, diaChi);
                        cout << "Cách thanh toán (ngân hàng/ tiền mặt): ";
                        getline(cin, thanhToan);

                        cout << "\nĐơn hàng của bạn đã được thanh toán thành công!\n";
                        cout << "Khách hàng: " << tenKH << endl;
                        cout << "Sản phẩm: " << sp.getTen() << " (" << sp.getMa() << ")\n";
                        cout << "Tổng tiền: " << fixed << setprecision(0) << sp.getGia() << " VND\n";
                        cout << "Phương Thức: " << thanhToan << endl;
                    }
                    else if (chon == 2) {
                        soLuongGioHang++;
                        cout << "\nĐã thêm vào giỏ hàng!\n";
                        cout << "Giỏ hàng: " << soLuongGioHang << " sản phẩm\n";
                    }
                    break;
                }
            }

            if (!timThay) cout << "Không tìm thấy mã sản phẩm!\n";
        }
    }
    else {
        cout << "❌ Sai tên đăng nhập hoặc mật khẩu!\n";
    }
	return 0;
}