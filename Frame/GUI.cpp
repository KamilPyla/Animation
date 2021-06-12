///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	window_print = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	window_print->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	
	bSizer9->Add( window_print, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer8->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	

	choose_file = new wxButton( this, wxID_ANY, wxT("Wybierz plik"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( choose_file, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	save_frame = new wxCheckBox( this, wxID_ANY, wxT("Zapisz klatki"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( save_frame, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );	
	
	start = new wxButton( this, wxID_ANY, wxT("Wyœwietl Animacjê"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( start, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer8->Add( bSizer10, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer8 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	window_print->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::changed_size_window ), NULL, this );
	choose_file->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::choose_file_ins ), NULL, this );
	start->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::start_animation ), NULL, this );
	save_frame->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::touch ), NULL, this );

}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	window_print->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::changed_size_window ), NULL, this );
	save_frame->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::touch ), NULL, this );
	save_frame->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::touch ), NULL, this );

	
}
