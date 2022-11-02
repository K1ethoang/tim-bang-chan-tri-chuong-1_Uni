#pragma once
#include "data.hpp"

#define PHU_DINH "!"
#define HOI " ^ "
#define TUYEN " v "
#define KEO_THEO " -> "
#define KEO_THEO_2_CHIEU " <-> "

inline bool phepPhuDinh(const bool &a);
inline bool phepHoi(const bool &a, const bool &b);
inline bool phepTuyen(const bool &a, const bool &b);
inline bool phepKeoTheo(const bool &a, const bool &b);
inline bool phepKeoTheoHaiChieu(const bool &a, const bool &b);
void PhuDinh(const int &col);
void hoi(const int &col1, const int &col2);
void tuyen(const int &col1, const int &col2);
void keoTheo(const int &col1, const int &col2);
void keoTheoHaiChieu(const int &col1, const int &col2);

inline bool phepPhuDinh(const bool &a)
{
    return !a;
}

inline bool phepHoi(const bool &a, const bool &b)
{
    return a && b;
}

inline bool phepTuyen(const bool &a, const bool &b)
{
    return a || b;
}

inline bool phepKeoTheo(const bool &a, const bool &b)
{
    if (a == 0 && b == 0)
        return 1;
    return b;
}

inline bool phepKeoTheoHaiChieu(const bool &a, const bool &b)
{
    if (a == 0 && b == 0)
        return 1;
    else if (a == 1 && b == 1)
        return 1;
    return 0;
}

void PhuDinh(const int &col)
{
    vector<string> header = readHeader();
    string s = PHU_DINH + header[col - 1];
    header.push_back(s);
    writeHeader(header);
    vector<bool> body = readAColBody(col);
    for (int i = 0; i < body.size(); i++)
        body[i] = phepPhuDinh(body[i]);
    writeACol(body);
}

void hoi(const int &col1, const int &col2)
{
    vector<string> header = readHeader();
    string s = "(" + header[col1 - 1] + HOI + header[col2 - 1] + ")";
    header.push_back(s);
    writeHeader(header);
    vector<bool> body1 = readAColBody(col1);
    vector<bool> body2 = readAColBody(col2);
    vector<bool> body;
    for (int i = 0; i < body1.size(); i++)
        body.push_back(phepHoi(body1[i], body2[i]));
    writeACol(body);
}
void tuyen(const int &col1, const int &col2)
{
    vector<string> header = readHeader();
    string s = "(" + header[col1 - 1] + TUYEN + header[col2 - 1] + ")";
    header.push_back(s);
    writeHeader(header);
    vector<bool> body1 = readAColBody(col1);
    vector<bool> body2 = readAColBody(col2);
    vector<bool> body;
    for (int i = 0; i < body1.size(); i++)
        body.push_back(phepTuyen(body1[i], body2[i]));
    writeACol(body);
}
void keoTheo(const int &col1, const int &col2)
{
    vector<string> header = readHeader();
    string s = "(" + header[col1 - 1] + KEO_THEO + header[col2 - 1] + ")";
    header.push_back(s);
    writeHeader(header);
    vector<bool> body1 = readAColBody(col1);
    vector<bool> body2 = readAColBody(col2);
    vector<bool> body;
    for (int i = 0; i < body1.size(); i++)
        body.push_back(phepKeoTheo(body1[i], body2[i]));
    writeACol(body);
}
void keoTheoHaiChieu(const int &col1, const int &col2)
{
    vector<string> header = readHeader();
    string s = "(" + header[col1 - 1] + KEO_THEO_2_CHIEU + header[col2 - 1] + ")";
    header.push_back(s);
    writeHeader(header);
    vector<bool> body1 = readAColBody(col1);
    vector<bool> body2 = readAColBody(col2);
    vector<bool> body;
    for (int i = 0; i < body1.size(); i++)
        body.push_back(phepKeoTheoHaiChieu(body1[i], body2[i]));
    writeACol(body);
}