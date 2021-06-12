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

ReadInstructions::ReadInstructions(string file):_file(file) {
	Draw();
}

void ReadInstructions::Draw(bool s) {
	_save = s;

	string line;
	ifstream instructions(_file);

	vector<string> inst;

	//wczytanie pierwszej lini
	if (getline(instructions, line)) {
		split(line, inst);
		SetWinSize(stoi(inst[0]), stoi(inst[1]));
		inst.clear();
	}

	while (getline(instructions, line)) {
		split(line, inst);
		ChooseFunction(inst);
		inst.clear();
	}
	instructions.close();

	
}

void ReadInstructions::SetWinSize(int x, int y) {
	cout << " SetWinSize!" << x << y << endl;
	width = x;
	height = y;

}

void ReadInstructions::SetTimeAndNumber(int n, float t) {
	bitMap = wxBitmap(width, height);
	memdc.SelectObject(bitMap);
	_time = static_cast<int>(10 * t);
	_num = n;
	FileName = to_string(n) + "_BitMap.bmp";
	memdc.SetBackground(*wxWHITE_BRUSH);

}

void ReadInstructions::DrawElipse(int x1, int y1, int x2, int y2, int flag) {
	if (!flag) {
		memdc.SetBrush(wxColor(0, 0, 0));
	}
	memdc.DrawEllipse(x1, y1, x2, y2);
}

void ReadInstructions::DrawRectangle(int x1, int y1, int x2, int y2, int flag) {
	if (!flag) {
		memdc.SetBrush(wxColor(0, 0, 0));
	}
	memdc.DrawRectangle(x1, y1, x2, y2);
}

void ReadInstructions::DrawLine(int x1, int y1, int x2, int y2) {
	memdc.DrawLine(x1, y1, x2, y2);
}

void ReadInstructions::DrawPunkt(int x, int y) {
	memdc.DrawPoint(x, y);
}

void ReadInstructions::SetPenSize(int d) {
	_PenSize = d;

}

void ReadInstructions::SetPenColour(int r, int g, int b) {
	memdc.SetPen(wxPen(wxColor(r, g, b), _PenSize));

}

void ReadInstructions::SetFillColor(int r, int g, int b) {
	memdc.SetBrush(wxColor(r, g, b));


}

void ReadInstructions::SaveBitMap() {
	memdc.SelectObject(wxNullBitmap);
	if (_save)
		bitMap.SaveFile("./Klatki/"+FileName, wxBITMAP_TYPE_BMP);
	_klatki.push_back(bitMap);
	DisplayBitMap();
}


void ReadInstructions::DisplayBitMap() const {
	dc->DrawBitmap(bitMap, 0, 0, false);
	//zatrzymanie programu
	Sleep(_time);
}

wxBitmap ReadInstructions::BitMap() {
	nrKlatki += 1;
	if (nrKlatki < _num)
		return _klatki[nrKlatki - 1];
	else return wxBitmap(width, height);
}

void ReadInstructions::ChooseFunction(const vector<std::string>& ins) {
	std::string s = ins[0];

	if (ins.size() == 2 and s != "RP" and s != "rozmiar_piora") {
		SetTimeAndNumber(stoi(ins[0]), stof(ins[1]));
	}

	else if (s == "punkt" or s == "PT") {
		DrawPunkt(stoi(ins[1]), stoi(ins[2]));
	}

	else if (s == "elipsa" or s == "EL") {
		DrawElipse(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]), stoi(ins[4]), stoi(ins[5]));
	}
	else if (s == "prostokat" or s == "PR") {
		DrawRectangle(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]), stoi(ins[4]), stoi(ins[5]));
	}

	else if ("linia" == s or "LN" == s) {
		DrawLine(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]), stoi(ins[4]));
	}
	else if ("rozmiar_piora" == s or "RP" == s) {
		SetPenSize(stoi(ins[1]));
	}
	else if ("kolor_piora" == s or "KP" == s) {
		SetPenColour(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]));
	}
	else if ("kolor_wypelnienia" == s or "KW" == s) {
		SetFillColor(stoi(ins[1]), stoi(ins[2]), stoi(ins[3]));
	}
	else if ("stop" == s or "ST" == s) {
		cout << "zapis klatki" << endl;
		SaveBitMap();
	}

}