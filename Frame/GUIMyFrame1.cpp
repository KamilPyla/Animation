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


void GUIMyFrame1::changed_size_window( wxUpdateUIEvent& event )
{
	update_view();
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
	Show_animation();
}

void GUIMyFrame1::Show_animation() 
{
	wxClientDC dc(window_print);
	int x, y;
	dc.GetSize(&x, &y);
	wxBitmap b(x, y);
	wxBufferedDC fill(&dc, b);
	fill.Clear();
	if (_filename == "") 
	{
		wxMessageBox(wxT("Wybierz plik!"), wxT("Nie wybrano pliku"), wxICON_INFORMATION);
	}
	else 
	{

		ReadInstructions read (_filename, &dc);
		if (save_frame->IsChecked())
		{
			read.Draw(true);
		}
		else
		{
			read.Draw(false);
		}

	}
}

void GUIMyFrame1::touch( wxCommandEvent& event )
{
	if (save_frame->IsChecked())
	{
	update_view();
	}
}

void GUIMyFrame1::update_view()
{
	wxClientDC dc(window_print);
	int x, y;
	dc.GetSize(&x, &y);
	wxBitmap b(x, y);
	wxBufferedDC fill(&dc, b);

	fill.Clear();

}
