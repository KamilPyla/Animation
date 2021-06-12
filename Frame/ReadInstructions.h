#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <wx/wxprec.h>
#include "windows.h"

using namespace std;

class ReadInstructions {
public:
	ReadInstructions(string file);
	
	ReadInstructions(string file, wxDC* d) :_file(file), dc(d) {}

	void Draw(bool s = false);

	void SetWinSize(int x, int y);

	void SetTimeAndNumber(int n, float t);

	void DrawPunkt(int x, int y);

	void DrawElipse(int x1, int y1, int x2, int y2, int flag);

	void DrawRectangle(int x1, int y1, int x2, int y2, int flag);

	void DrawLine(int x1, int y1, int x2, int y2);

	void SetPenSize(int d);

	void SetPenColour(int r, int g, int b);

	void ChooseFunction(const vector<string>& ins);

	void SetFillColor(int r, int g, int b);

	void SaveBitMap();

	wxBitmap BitMap();
	
	void DisplayBitMap() const;


private:

	bool _save = false;

	bool _flag;

	int _time;

	int _PenSize = 1;

	int width;

	int height;

	int _num = 0;

	int nrKlatki = 0;

	string _file;

	wxBitmap bitMap;

	std::vector<wxBitmap> _klatki;

	wxMemoryDC memdc;

	string FileName;

	wxDC* dc;


};
