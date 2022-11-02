#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include "data.hpp"
using namespace std;

const int LENGTH_OF_COLUMN = 1;

void printSeperatorCell(const int &lengthOfCell);
void printSeperatorLineByCell(const vector<string> &data);
// void printSeperatorLine(const int &numberOfCol, const int &colLength = LENGTH_OF_COLUMN);
void printCell(const int &lengthOfCell, const string &value);
void printRow(vector<string> data, const int &colLength);
void printHeader();
void printBody(const vector<string> &header);
void printNumberOfCol(const vector<string> &data);
void printClauseTable(const vector<string> &data);
int countDigit(int n);

void printSeperatorCell(const int &lengthOfCell)
{
    cout << " ";
    cout << setfill('-');
    cout << setw(lengthOfCell) << "-";
    cout << " ";
}

void printSeperatorLineByCell(const vector<string> &data)
{
    cout << "+";
    for (int i = 0; i < data.size(); i++)
    {
        printSeperatorCell(data[i].length());
        cout << "+";
    }
    cout << endl;
}

// void printSeperatorLine(const int &numberOfCol, const int &colLength)
// {
//     int length = (numberOfCol * colLength) + numberOfCol;
//     cout << "+";
//     do
//     {
//         printSeperatorCell(colLength);
//         length -= colLength;
//         cout << "+";
//         length -= 1;
//     } while (length != 0);
//     cout << setfill(' ') << endl;
// }

void printCell(const int &lengthOfCell, const string &value)
{
    cout << " ";
    cout << setw(lengthOfCell) << left << value;
    cout << " ";
}

void printRow(const vector<string> &data)
{
    cout << "|";
    for (int i = 0; i < data.size(); i++)
    {
        printCell(data[i].length(), data[i]);
        cout << "|";
    }
    cout << endl;
}

void printHeader()
{
    vector<string> header = readHeader();
    printNumberOfCol(header);
    printSeperatorLineByCell(header);
    printRow(header);
    printSeperatorLineByCell(header);
}

void printBody(const vector<string> &header)
{
    ifstream fileIn(BODY_FILE_PATH, ios::in);
    int n = readNumberOfCol(fileIn);
    while (!fileIn.eof())
    {
        vector<string> row = readARowBody(fileIn, n);
        printRow(row);
    }
    fileIn.close();
}

void printNumberOfCol(const vector<string> &data)
{
    int length = data.size();
    vector<string> data2(length);
    for (int i = 0; i < length; i++)
    {
        string s;
        s.assign(data[i].length() - countDigit(i + 1), ' ');
        data2[i] = to_string(i + 1);
        data2[i] += s;
    }
    printSeperatorLineByCell(data2);
    printRow(data2);
}

void printClauseTable(const vector<string> &data)
{
    printHeader();
    printBody(data);
}

int countDigit(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}