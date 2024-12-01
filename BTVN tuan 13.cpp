//Coi nhu 1 phien lam viec cua thu ngan chi thanh toan cho 10 thang
#include<iostream>
#include<string>
using namespace std;

struct Sanpham { //Thong tin cua moi san pham
    string ID; //Ten san pham
    int so_luong; //So luong san pham tuong ung
    int cost; //Gia tien
};

struct Gio_hang { //1 gio hang thi se co 1 so loai san pham nhat dinh
    Sanpham* products;
    int num_products;
    int sum_money;
};

struct Node {
    Gio_hang KH; //1 khach hang dung doi tuong ung voi 1 gio hang
    Node* next;
};

struct Queue {
    Node* R; //Cuoi hang doi
    Node* F; //Dau hang doi
    const int Max_GH = 10; //Gioi han 1 hang chi co 10 khach hang dung doi
};

//Khoi tao hang doi
void Init(Queue* q) {
    q->R = nullptr;
    q->F = nullptr;
}

//Kiem tra hang rong
int Isempty(Queue* q) {
    return (q->R == nullptr);
}

//Kiem tra hang doi day
int Isfull(Queue* q) {
    int count = 0;
    Node* temp = q->F;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return (count >= q->Max_GH ? 1 : 0);
}

//Them khach doi
void EnQueue(Queue* q, Gio_hang khach) {
    if (Isfull(q)) {
        cout << "Hang da day. Cac khach hang dung sau khach hang thu 10 vui long cho toi phien lam viec sau!" << endl;
        return;
    }
    Node* newnode = new Node;
    newnode->KH = khach;
    newnode->next = nullptr;

    if (Isempty(q)) {
        q->R = newnode;
        q->F = newnode;
    }
    else {
        q->R->next = newnode; //De F luon tro vao khach dau tien
        q->R = newnode;
    }
}

//Xoa khach doi
void DeQueue(Queue* q) {
    if (Isempty(q)) {
        cout << "Khong con khach hang nao dang doi thanh toan!" << endl;
        return;
    }
    Node* temp = q->F;
    q->F = q->F->next; //Luc nay F = F + 1

    if (q->F == nullptr) {
        q->R = nullptr; //reset hang doi
    }

    delete temp;
}

//Hien thi so tien phai thanh toan cua 1 khach hang
int Pay(Node* GH) {

    GH->KH.sum_money = 0;
    for (int i = 0; i < GH->KH.num_products; i++) {
        GH->KH.sum_money += GH->KH.products[i].so_luong * GH->KH.products[i].cost;
    }
    return GH->KH.sum_money;
}

//Hien thi hoa don cua 1 khach hang 
void DisplayQueue(Node* GH) {
    cout << "\tHOA DON" << endl;
    int tien = 0;
    for (int i = 0; i < GH->KH.num_products; i++) {
        tien += GH->KH.products[i].cost * GH->KH.products[i].so_luong;
        cout << GH->KH.products[i].ID << "\t"
             << GH->KH.products[i].so_luong << "\t"
             << GH->KH.products[i].cost << "\t"
             << GH->KH.products[i].cost * GH->KH.products[i].so_luong << endl;
    }
    cout << "THANH TIEN\t" << tien << " VND" << endl;
}

//Hien thi tong so tien sau khi ket ca
void Payment(Queue* q) {
    int tong_tien = 0;
    Node* temp = q->F; //Do F cua em luon tro vao vi tri hien tai
    if (Isempty(q)) {
        cout << tong_tien << endl;
    }
    while (temp != nullptr) {
        tong_tien += Pay(temp);
        temp = temp->next;
    }
    cout << "Tong so tien thu duoc sau khi ket ca la: " << tong_tien << " VND" << endl;
}

//Kiem tra da ban duoc bao nhieu san pham A
int check(Queue* q, string masanpham) {
    int dem = 0;
    Node* temp = q->F;  
    while (temp != nullptr) {
        for (int i = 0; i < temp->KH.num_products; i++) {
            if (temp->KH.products[i].ID == masanpham) {
                dem += temp->KH.products[i].so_luong;
            }
        }
        temp = temp->next;
    }
    return dem;
}

int main() {
    Queue Nguyet;
    Init(&Nguyet);

    //Gia su moi khach hang lay toi da 10 san pham
    Gio_hang KH1;
    KH1.products = new Sanpham[10];
    KH1.num_products = 0;
    KH1.products[KH1.num_products++] = { "SPA", 2, 500 };
    KH1.products[KH1.num_products++] = { "SPB", 3, 300 };

    Gio_hang KH2;
    KH2.products = new Sanpham[10];
    KH2.num_products = 0;
    KH2.products[KH2.num_products++] = { "SPC", 1, 100 };
    KH2.products[KH2.num_products++] = { "SPA", 5, 200 };

    /*Gio_hang KH3;
    KH3.products = new Sanpham[10];
    KH3.num_products = 0;
    KH3.products[KH3.num_products++] = { "SPA", 2, 500 };
    KH3.products[KH3.num_products++] = { "SPB", 3, 300 };

    Gio_hang KH4;
    KH4.products = new Sanpham[10];
    KH4.num_products = 0;
    KH4.products[KH4.num_products++] = { "SPA", 2, 500 };
    KH4.products[KH4.num_products++] = { "SPB", 3, 300 };

    Gio_hang KH5;
    KH5.products = new Sanpham[10];
    KH5.num_products = 0;
    KH5.products[KH5.num_products++] = { "SPA", 2, 500 };
    KH5.products[KH5.num_products++] = { "SPB", 3, 300 };

    Gio_hang KH6;
    KH6.products = new Sanpham[10];
    KH6.num_products = 0;
    KH6.products[KH6.num_products++] = { "SPA", 2, 500 };
    KH6.products[KH6.num_products++] = { "SPB", 3, 300 };

    Gio_hang KH7;
    KH7.products = new Sanpham[10];
    KH7.num_products = 0;
    KH7.products[KH7.num_products++] = { "SPA", 2, 500 };
    KH7.products[KH7.num_products++] = { "SPB", 3, 300 };

    Gio_hang KH8;
    KH8.products = new Sanpham[10];
    KH8.num_products = 0;
    KH8.products[KH8.num_products++] = { "SPA", 2, 500 };
    KH8.products[KH8.num_products++] = { "SPB", 3, 300 };

    Gio_hang KH9;
    KH9.products = new Sanpham[10];
    KH9.num_products = 0;
    KH9.products[KH9.num_products++] = { "SPA", 2, 500 };
    KH9.products[KH9.num_products++] = { "SPB", 3, 300 };

    Gio_hang KH10;
    KH10.products = new Sanpham[10];
    KH10.num_products = 0;
    KH10.products[KH10.num_products++] = { "SPA", 2, 500 };
    KH10.products[KH10.num_products++] = { "SPB", 3, 300 };

    Gio_hang KH11;
    KH11.products = new Sanpham[10];
    KH11.num_products = 0;
    KH11.products[KH11.num_products++] = { "SPA", 2, 500 };
    KH11.products[KH11.num_products++] = { "SPB", 3, 300 };*/
        
    //Them khach hang cho thanh toan vao hang (2 - 11 khach hang)
    EnQueue(&Nguyet, KH1);
    EnQueue(&Nguyet, KH2);
    /*EnQueue(&Nguyet, KH3);
    EnQueue(&Nguyet, KH4);
    EnQueue(&Nguyet, KH5);
    EnQueue(&Nguyet, KH6);
    EnQueue(&Nguyet, KH7);
    EnQueue(&Nguyet, KH8);
    EnQueue(&Nguyet, KH9);
    EnQueue(&Nguyet, KH10);
    EnQueue(&Nguyet, KH11);*/

    //In hoa don khach khang
    Node* current = Nguyet.F;
        while (current != nullptr) {
            DisplayQueue(current);
            current = current->next;
    }

    //Thu ngan ket ca
    Payment(&Nguyet);

    //Kiem tra ban duoc bao nhieu san pham A
    int d = check(&Nguyet, "SPA");
    cout << "So luong san pham A da ban duoc la: " << d;

    return 0;
}

