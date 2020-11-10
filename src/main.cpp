#include <wx/wx.h>

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
    wxPanel *panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
    panel_top->SetBackgroundColour(wxColor(100, 100, 200));

    wxPanel *panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
    panel_bottom->SetBackgroundColour(wxColor(100, 200, 100));

    wxPanel *panel_bottom_right = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
    panel_bottom_right->SetBackgroundColour(wxColor(200, 200, 100));

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(panel_top, 1, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);

    wxSizer *sizer_bottom = new wxBoxSizer(wxHORIZONTAL);
    sizer_bottom->Add(panel_bottom, 1, wxEXPAND | wxRIGHT, 10);
    sizer_bottom->Add(panel_bottom_right, 1, wxEXPAND, 0);

    sizer->Add(sizer_bottom, 2, wxEXPAND | wxALL, 10);

    this->SetSizerAndFit(sizer);
}
