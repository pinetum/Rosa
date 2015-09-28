#include "MyTaskBarIcon.h"
#include <wx/menu.h>
#include "MainFrame.h"


MyTaskBarIcon::MyTaskBarIcon(wxTaskBarIconType iconType):wxTaskBarIcon(iconType)
{
}

MyTaskBarIcon::~MyTaskBarIcon()
{
}
wxMenu* MyTaskBarIcon::CreatePopupMenu()
{
    wxMenu* mMenu = NULL;
    mMenu = new wxMenu(0);
    //mMenu->Append(new wxMenuItem(mMenu, wxID_OPEN, _("OpenFile\tCtrl+O"), wxT(""), wxITEM_NORMAL));
    
    return mMenu;
}
