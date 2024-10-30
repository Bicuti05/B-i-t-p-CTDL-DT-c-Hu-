#include <iostream>
using namespace std;

// Cau truc cua mot don thuc (term)
struct DT {
    int heso;   // he so cua da thuc
    int somu;   // bac cua bien
    DT* next;   // con tro den nut tiep theo

    DT(int hs, int sm) : heso(hs), somu(sm), next(nullptr) {}
};

// Lop dai dien cho da thuc
class dathuc {
private:
    DT* head;  // con tro den phan dau cua danh sach lien ket don dai dien da thuc

public:
    // Khoi tao da thuc rong
    dathuc() : head(nullptr) {}

    // Giai phong bo nho da cap phat
    ~dathuc() {
        while (head != nullptr) {
            DT* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Them hang tu vao da thuc
    void addTerm(int sm, int hs) {
        if (hs == 0) return;  // Neu he so = 0 thi bo qua

        DT* newDT = new DT(hs, sm);  // Tao nut moi

        // Neu danh sach rong hoac bac cao nhat thi chen vao dau
        if (!head || head->somu < sm) {
            newDT->next = head;
            head = newDT;
        }
        else {
            DT* current = head;
            DT* previous = nullptr;

            // Tim vi tri de chen
            while (current && current->somu > sm) {
                previous = current;
                current = current->next;
            }

            if (current && current->somu == sm) {
                // Neu da co bac nay thi cong he so vao
                current->heso += hs;
                delete newDT;  // Giai phong bo nho cho nut moi
                if (current->heso == 0) {
                    // Neu he so moi = 0 thi xoa nut
                    if (previous) {
                        previous->next = current->next;
                    }
                    else {
                        head = current->next;
                    }
                    delete current;
                }
            }
            else {
                // Chen vao giua danh sach
                newDT->next = current;
                if (previous) {
                    previous->next = newDT;
                }
            }
        }
    }

    // Ham nhap da thuc
    void nhapDT() {
        int sm, hs;
        cout << "Nhap da thuc (bac va he so tuong ung, nhap 0 0 de dung):" << endl;
        while (true) {
            cin >> sm >> hs;
            if (sm == 0 && hs == 0) break;
            addTerm(sm, hs);
        }
    }

    // Ham in da thuc
    void inDT() const {
        if (!head) {
            cout << "0" << endl;
            return;
        }

        DT* current = head;
        while (current) {
            cout << current->heso << "x^" << current->somu;
            if (current->next && current->next->heso > 0) {
                cout << " + ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Cong hai da thuc va tra ve ket qua
    dathuc add(const dathuc& other) const {
        dathuc result;
        DT* current1 = head;
        DT* current2 = other.head;

        while (current1 || current2) {
            if (current1 && (!current2 || current1->somu > current2->somu)) {
                result.addTerm(current1->somu, current1->heso);
                current1 = current1->next;
            }
            else if (current2 && (!current1 || current2->somu > current1->somu)) {
                result.addTerm(current2->somu, current2->heso);
                current2 = current2->next;
            }
            else {
                result.addTerm(current1->somu, current1->heso + current2->heso);
                current1 = current1->next;
                current2 = current2->next;
            }
        }

        return result;
    }
};

int main() {
    dathuc f, g; // Khai bao hai da thuc f va g

    // Nhap da thuc f
    cout << "Nhap da thuc f:" << endl;
    f.nhapDT();

    // Nhap da thuc g
    cout << "\nNhap da thuc g:" << endl;
    g.nhapDT();

    //In da thuc f va g
    cout << "\nDa thuc f(x) = ";
    f.inDT();
    cout << "Da thuc g(x) = ";
    g.inDT();

    // Tinh tong cua hai da thuc va in ra ket qua
    dathuc sum = f.add(g);

    cout << "Tong cua f(x) va g(x) = ";
    sum.inDT();

    return 0;
}