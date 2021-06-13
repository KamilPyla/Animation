#include "ReadInstructions.h"
#include <algorithm>
#include <iterator>




template <class Container>
void split(const std::string& str, Container& cont,
	const std::string& delims = " ")
{
	std::size_t current, previous = 0;
	current = str.find_first_of(delims);
	while (current != std::string::npos) {
		cont.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find_first_of(delims, previous);
	}
	cont.push_back(str.substr(previous, current - previous));
}

void ReadInstructions::Read()
{

	string line;
	ifstream instructions(_file);

	while (getline(instructions, line)) 
	{
		_instructions.push_back(line);
	}
	instructions.close();
}

void ReadInstructions::Draw(bool s){
	_save = s;
	vector<string> ins;
	split(_instructions[0], ins);
	SetWinSize(stoi(ins[0]), stoi(ins[1]));
	ins.clear();
	_instructions.erase(_instructions.begin());
	for (auto el : _instructions) {
		split(el, ins);
		if (ChooseFunction(ins) && !stop)
			ins.clear();
		else break;
	}
}



void ReadInstructions::SetWinSize(int x, int y) 
{
	width = x;
	height = y;
}

void ReadInstructions::SetTimeAndNumber(int n, int t) 
{
	bitMap = wxBitmap(width, height);
	memdc.SelectObject(bitMap);
	_time = t;
	FileName = to_string(n) + "_BitMap.bmp";
}

void ReadInstructions::DrawElipse(int x1, int y1, int x2, int y2, int flag) 
{
	if (!flag) {
		memdc.SetBrush(wxColor(0, 0, 0));
	}
	memdc.DrawEllipse(x1, y1, x2, y2);
}

void ReadInstructions::DrawRectangle(int x1, int y1, int x2, int y2, int flag) {
	if (!flag)
	{
		memdc.SetBrush(wxColor(0, 0, 0));
	}
	memdc.DrawRectangle(x1, y1, x2, y2);
}

void ReadInstructions::DrawLine(int x1, int y1, int x2, int y2)
{
	memdc.DrawLine(x1, y1, x2, y2);
}

void ReadInstructions::DrawPunkt(int x, int y)
{
	memdc.DrawPoint(x, y);
}

void ReadInstructions::SetPenSize(int d)
{
	_PenSize = d;
}

void ReadInstructions::SetPenColour(int r, int g, int b) 
{
	memdc.SetPen(wxPen(wxColor(r, g, b), _PenSize));
}

void ReadInstructions::SetFillColor(int r, int g, int b)
{
	memdc.SetBrush(wxColor(r, g, b));
}

void ReadInstructions::SaveBitMap() 
{
	memdc.SelectObject(wxNullBitmap);
	if (_save)
		bitMap.SaveFile(FileName, wxBITMAP_TYPE_BMP);
	else 
		DisplayBitMap();
}


void ReadInstructions::DisplayBitMap() const 
{
	dc->DrawBitmap(bitMap, 0, 0, false);
	Sleep(_time);
	wxYield();
}

bool ReadInstructions::ChooseFunction(const vector<std::string>& ins)
{
	std::string s = ins[0];

	if (ins.size() == 2 && s != "RP" && s != "rozmiar_piora") 
	{
		SetTimeAndNumber(stoi(ins[0]), stoi(ins[1]));
		return true;
	}

	else if (s == "punkt" || s == "PT" && ins.size() == 3 ) 
	{
		DrawPunkt(stoi(ins[1]), stoi(ins[2]));
		return true;
	}

	else if (s == "elipsa" || s == "EL" && ins.size() == 6) 
	{
		DrawElipse(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]), stoi(ins[4]), stoi(ins[5]));
		return true;
	}
	else if (s == "prostokat" || s == "PR" && ins.size() == 6) 
	{
		DrawRectangle(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]), stoi(ins[4]), stoi(ins[5]));
		return true;
	}

	else if ("linia" == s || "LN" == s && ins.size() == 5) 
	{
		DrawLine(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]), stoi(ins[4]));
		return true;
	}
	else if ("rozmiar_piora" == s || "RP" == s && ins.size() == 2) 
	{
		SetPenSize(stoi(ins[1]));
		return true;
	}
	else if ("kolor_piora" == s || "KP" == s && ins.size() == 4) 
	{
		SetPenColour(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]));
		return true;
	}
	else if ("kolor_wypelnienia" == s || "KW" == s && ins.size() == 4) 
	{
		SetFillColor(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]));
		return true;
	}
	else if ("stop" == s || "ST" == s) 
	{
		cout << "zapis klatki" << endl;
		SaveBitMap();
		return true;
	}
	else {
		wxMessageBox(wxT("Niepoprawny plik"), wxT("B³¹d pliku"), wxICON_ERROR);
		return false;
	}

}