#pragma once
#include <vector>
#include <iostream>
#include "print.hpp"
#include "data.hpp"
using namespace std;

void generateClauseTable(const int &n);

void generateClauseTable(const int &n)
{
    int i;
    ofstream fileOut(BODY_FILE_PATH, ios::out);
    vector<string>
        vData(n, "0");
    fileOut << n;
    do
    {
        writeARow(fileOut, vData);
        // printClauseTable(vData, n);
        i = n - 1; // vị trí phần tử cuối
        while (i >= 0 && vData[i].compare("1") == 0)
            i--;
        if (i >= 0)
        {
            vData[i] = "1";
            for (int j = i + 1; j < n; j++)
                vData[j] = "0";
        }
    } while (i >= 0);
    fileOut.close();
}
