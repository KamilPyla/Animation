#include "GUIMyFrame1.h"
#include "ReadInstructions.h"
#include <wx/sizer.h>
#include <wx/wx.h>
#include <wx/timer.h>
#include <wx/wfstream.h>





GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}


void GUIMyFrame1::choose_file_ins(wxCommandEvent& event) {
	wxFileDialog
		openFileDialog(this, _("Open TXT file"), "", "",
			"TXT files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() == wxID_CANCEL) {
		return;
	}

	_filename = std::string(openFileDialog.GetPath().mb_str());
	wxFileInputStream input_stream(openFileDialog.GetPath());
	if (!input_stream.IsOk())
	{
		wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
		return;
	}
}


void GUIMyFrame1::start_animation(wxCommandEvent& event)
{
	Show_animation(false);
}
void GUIMyFrame1::save_bitmap(wxCommandEvent& event)
{
	Show_animation(true);
}

void GUIMyFrame1::Show_animation(bool save) 
{
	wxClientDC dc(window_print);
	if (_filename == "") 
	{
		wxMessageBox(wxT("Wybierz plik!"), wxT("Nie wybrano pliku"), wxICON_INFORMATION);
	}
	else 
	{
		if (read)
			delete read;

		read = new ReadInstructions(_filename, &dc);
			read->Draw(save);

		if (save)
			wxMessageBox(wxT("Zapisano!\n  "), wxT("Koniec zapisu"), wxICON_INFORMATION);
		
		wxMessageBox(wxT("Wybierz nowy plik, otwórz ponownie lub zapisz seriê BITMAP"), wxT("Koniec Akcji"), wxICON_INFORMATION);

	}
}

void GUIMyFrame1::stop_animation(wxCommandEvent& event) {
	read->stop = true;
}

GUIMyFrame1::~GUIMyFrame1() {
	if (read)
		delete read;
}