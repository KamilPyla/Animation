#include <wx/wxprec.h>
#include"GUIMyFrame1.h"
class MyApp : public wxApp
{
public:
	virtual bool OnInit();
	virtual int OnExit() { return 0; };
};


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	GUIMyFrame1* frame = new GUIMyFrame1(NULL);
	frame->Show(true);

	SetTopWindow(frame);
	return true;
}

