#ifndef MYTASKBARICON_H
#define MYTASKBARICON_H
#include <wx/taskbar.h>


//#include "taskbarosx.h" // Base class: wxTaskBarIcon

class MyTaskBarIcon : public wxTaskBarIcon
{
public:
    MyTaskBarIcon(wxTaskBarIconType iconType=wxTBI_DEFAULT_TYPE);
    ~MyTaskBarIcon();
    
protected:
    virtual wxMenu* CreatePopupMenu();

};

#endif // MYTASKBARICON_H
