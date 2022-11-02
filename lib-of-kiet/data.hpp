#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string HEADER_FILE_PATH = "./file/header.txt";
const string BODY_FILE_PATH = "./file/body.txt";
const string BODY_TEMP_FILE_PATH = "./file/bodyT.txt";

vector<string> getFHeader();
vector<string> getBody();

int readNumberOfCol(ifstream &fileIn);
void copyData(const vector<bool> &data);
vector<string> readARowBody(ifstream &fileIn, const int &n);
vector<bool> readAColBody(const int &col);
vector<string> readHeader();
void writeHeader(ofstream &fileOut, const vector<string> &data);
void writeARow(ofstream &fileOut, const vector<string> &data);
void writeACol(const vector<bool> &data);

vector<string> getFHeader()
{
    ifstream fileIn(HEADER_FILE_PATH, ios::in);
    vector<string> data;
    while (!fileIn.eof())
    {
        string value;
        getline(fileIn, value);
        data.push_back(value);
    }
    fileIn.close();
    return data;
}

int readNumberOfCol(ifstream &fileIn)
{
    int n;
    fileIn >> n;
    string c;
    getline(fileIn, c);
    return n;
}

void copyData(const vector<bool> &data)
{
    ifstream InbodyF(BODY_FILE_PATH, ios::in);
    ofstream OutbodyTempF(BODY_TEMP_FILE_PATH, ios::out);
    int numberOfCol = readNumberOfCol(InbodyF);
    for (int i = 0; i < data.size(); i++)
    {
        vector<string> row = readARowBody(InbodyF, numberOfCol);
        row.push_back((data[i] ? "1" : "0"));
        if (i == 0)
            OutbodyTempF << numberOfCol + 1;
        writeARow(OutbodyTempF, row);
    }
    InbodyF.close();
    OutbodyTempF.close();
}

vector<string> readARowBody(ifstream &fileIn, const int &n)
{
    vector<string> data;
    for (int i = 0; i < n; i++)
    {
        string value;
        getline(fileIn, value);
        data.push_back(value);
    }
    return data;
}

vector<bool> readAColBody(const int &col)
{
    ifstream fileIn(BODY_FILE_PATH, ios::in);
    int n = readNumberOfCol(fileIn);
    vector<bool> data;
    while (!fileIn.eof())
    {
        vector<string> row;
        row = readARowBody(fileIn, n);
        bool value;
        if (row[col - 1].compare("1") == 0)
            value = 1;
        else
            value = 0;
        data.push_back(value);
    }
    fileIn.close();
    return data;
}

vector<string> readHeader()
{
    vector<string> header;
    ifstream fileIn(HEADER_FILE_PATH, ios::in);
    int n = readNumberOfCol(fileIn);
    for (int i = 0; i < n; i++)
    {
        string value;
        getline(fileIn, value);
        header.push_back(value);
    }
    fileIn.close();
    return header;
}

void writeHeader(const vector<string> &data)
{
    ofstream fileOut(HEADER_FILE_PATH, ios::out);
    fileOut << data.size() << endl;
    for (int i = 0; i < data.size(); i++)
        fileOut << data[i] << endl;
    fileOut.close();
}

void writeARow(ofstream &fileOut, const vector<string> &data)
{
    for (int i = 0; i < data.size(); i++)
        fileOut << "\n"
                << data[i];
}

void writeACol(const vector<bool> &data)
{
    copyData(data);
    ifstream InbodyTempF(BODY_TEMP_FILE_PATH, ios::in);
    ofstream OutbodyF(BODY_FILE_PATH, ios::out);
    int numberOfCol = readNumberOfCol(InbodyTempF);
    for (int i = 0; i < data.size(); i++)
    {
        vector<string> row = readARowBody(InbodyTempF, numberOfCol);
        if (i == 0)
            OutbodyF << numberOfCol;
        writeARow(OutbodyF, row);
    }
    OutbodyF.close();
    InbodyTempF.close();
}