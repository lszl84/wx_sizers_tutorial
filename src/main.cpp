#include <wx/wx.h>
#include <wx/splitter.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
};

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Hello World", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    wxSplitterWindow *splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                                      wxSP_BORDER | wxSP_LIVE_UPDATE);

    wxPanel *left = new wxPanel(splitter);
    wxPanel *right = new wxPanel(splitter);

    left->SetBackgroundColour(wxColor(200, 100, 100));
    right->SetBackgroundColour(wxColor(100, 200, 100));

    splitter->SetMinimumPaneSize(200);

    splitter->SplitVertically(left, right);
}
