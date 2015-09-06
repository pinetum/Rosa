#include "MyTaskBarIcon.h"
#include <wx/menu.h>



MyTaskBarIcon::MyTaskBarIcon(wxTaskBarIconType iconType):wxTaskBarIcon(iconType)
{
}

MyTaskBarIcon::~MyTaskBarIcon()
{
}
void MyTaskBarIcon::setPopUpMenu(wxMenu* menu)
{
    m_menu_popUp = menu;
}
wxMenu* MyTaskBarIcon::CreatePopupMenu()
{
    wxMenu* mMenu = NULL;
    mMenu = new wxMenu(0);
    for(int i =0; i< m_menu_popUp->GetMenuItemCount(); i++)
    {
        mMenu->Append(m_menu_popUp->FindItemByPosition(i));
    }
    
    return mMenu;
}
