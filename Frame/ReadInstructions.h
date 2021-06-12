#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <wx/wxprec.h>
#include "windows.h"

using namespace std;

class ReadInstructions {
public:
	
	ReadInstructions(string file, wxDC* d) :_file(file), dc(d) {}

	void Draw(bool s = false);

	void SetWinSize(int x, int y);

	void SetTimeAndNumber(int n, int t);

	void DrawPunkt(int x, int y);

	void DrawElipse(int x1, int y1, int x2, int y2, int flag);

	void DrawRectangle(int x1, int y1, int x2, int y2, int flag);

	void DrawLine(int x1, int y1, int x2, int y2);

	void SetPenSize(int d);

	void SetPenColour(int r, int g, int b);

	void ChooseFunction(const vector<string>& ins);

	void SetFillColor(int r, int g, int b);

	void SaveBitMap();
	
	void DisplayBitMap() const;


private:

	bool _save = false;

	bool _flag = false;

	int _time = 1;

	int _PenSize = 1;

	int width;

	int height;

	string _file;

	wxBitmap bitMap;

	wxMemoryDC memdc;

	string FileName;

	wxDC* dc;


};
