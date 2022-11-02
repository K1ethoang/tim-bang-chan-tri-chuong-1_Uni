#pragma once
#include <iostream>
#include "./lib-of-kiet/generate.hpp"
#include "./lib-of-kiet/print.hpp"
#include "./lib-of-kiet/math.hpp"
#include "./lib-of-kiet/data.hpp"
using namespace std;

inline void program();
vector<string> input();
void chooseCommand(vector<string> &data);
void readMe();
void inputCol(int &a);
void inputCol(int &a, int &b);

inline void program()
{
    readMe();
    vector<string> vSign = input();
    int n = vSign.size();
    generateClauseTable(n);
    chooseCommand(vSign);
}

vector<string> input()
{
    int n;
    vector<string> vSign;
    do
    {
        system("cls");
        cout << "\n+ ------------- SO LUONG BIEN ------------- +";
        cout << "\n| Vi du 1 \"(a v a) v a -> la 1 bien\"        |";
        cout << "\n| Vi du 2 \"(a v b) v a -> la 2 bien\"        |";
        cout << "\n| Vi du 3 \"(a v b) v c -> la 3 bien\"        |";
        cout << "\n| ...                                       |";
        cout << "\n+ ----------------------------------------- +";
        cout << "\n  -> Nhap so luong bien: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\n\tSo luong bien phai >= 1 !\n\a";
            system("pause");
        }
        else
        {

            system("cls");
            cout << "\n+ ------------ TEN BIEN ------------ +";
            cout << "\n| Vi du 1 \"(a v a) ^ a -> a\"         |";
            cout << "\n| Vi du 2 \"(a v b) ^ a -> a b\"       |";
            cout << "\n| Vi du 3 \"(a v b) ^ c -> a b c\"     |";
            cout << "\n| ...                                |";
            cout << "\n+ ---------------------------------- +";
            cout << "\n  -> Nhap ten bien (cach nhau bang khoang cach \" \"): ";
            for (int i = 0; i < n; i++)
            {
                cout << "\nNhap ten bien thu " << i + 1 << " -> ";
                char c;
                cin >> c;
                string s;
                s.append(1, c);
                vSign.push_back(s);
            }
        }
    } while (n <= 0);
    writeHeader(vSign);
    cout << endl;
    return vSign;
}

void chooseCommand(vector<string> &data)
{
    int choose;
    bool isExit = false;
    do
    {
        system("cls");
        printClauseTable(data);
        cout << "\n+ ---------- PHEP TOAN ---------- +";
        cout << "\n| 1. Phep phu dinh                | Hoang Gia Kiet";
        cout << "\n| 2. Phep hoi                     | 6251xxxxxx";
        cout << "\n| 3. Phep tuyen                   | CNTT - K62";
        cout << "\n| 4. Phep keo theo                | Github: K1ethoang";
        cout << "\n| 5. Phep keo theo 2 chieu        | Facebook: K1ethoang";
        cout << "\n| 9. Bang quy doi ki hieu         | LinkedIn: K1ethoang";
        cout << "\n| 0. Ket thuc viec tinh toan      |";
        cout << "\n+ ------------------------------- +";
        cout << "\n\n -> Nhap lua chon: ";
        cin >> choose;
        switch (choose)
        {
        case 0:
            isExit = true;
            system("cls");
            break;
        case 1:
        {
            int a;
            cout << "\n\tPhep phu dinh";
            inputCol(a);
            PhuDinh(a);
            break;
        }
        case 2:
        {
            int a, b;
            cout << "\n\tPhep hoi";
            inputCol(a, b);
            hoi(a, b);
            break;
        }
        case 3:
        {
            int a, b;
            cout << "\n\tPhep tuyen";
            inputCol(a, b);
            tuyen(a, b);
            break;
        }
        case 4:
        {
            int a, b;
            cout << "\n\tPhep keo theo";
            inputCol(a, b);
            keoTheo(a, b);
            break;
        }
        case 5:
        {
            int a, b;
            cout << "\n\tPhep keo theo 2 chieu";
            inputCol(a, b);
            keoTheoHaiChieu(a, b);
            break;
        }
        case 9:
        {
            cout << "\n+ ---------- BANG QUY DOI ---------- +";
            cout << "\n| Phu dinh               |     !     |";
            cout << "\n| Hoi                    |     ^     |";
            cout << "\n| Tuyen                  |     v     |";
            cout << "\n| Keo theo               |     ->    |";
            cout << "\n| Keo theo 2 chieu       |    <->    |";
            cout << "\n+ ---------------------------------- +";
            cout << endl;
            system("pause");
            break;
        }
        default:
            cout << "\n\tKhong hop le! Nhap lai\b";
            break;
        }
    } while (!isExit);
}

void readMe()
{
    system("cls");
    cout << "\n----------------------------- DOC TOI ------------------------------\n";
    cout << "\n1. CT Giup cac ban giai bai tap mon Toan Roi Rac\n\ttrong viec tim bang chan tri cho menh de logic";
    cout << "\n\n2. Truoc mat thi cac ban phai tinh thu cong bang viec tu chon phep tinh de co the giai ra bai toan";
    cout << "\n\n3. Ban khong can phai nhap menh de cho cac bien (vd: 010, 001, 111...)\n\tCT se lam viec do thay cac ban, ban chi can chon phep tinh va chon cot can tinh";
    cout << "\n\n4. Neu ban da doc den dong nay thi thong cam vi minh khong viet dau duoc hehe :>";
    cout << "\n\n5. Chuong trinh nay do chinh minh viet, khong sao chep duoi moi hinh thuc\n\n";
    system("pause");
}

void inputCol(int &a)
{
    cout << "\n -> Nhap so cua cot (chi 1 cot): ";
    cin >> a;
}

void inputCol(int &a, int &b)
{
    cout << "\n -> Nhap so cua cot (chi 2 cot): ";
    cout << "\nNhap so cua cot 1 -> ";
    cin >> a;
    cout
        << "\nNhap so cua cot 2 -> ";
    cin >> b;
}