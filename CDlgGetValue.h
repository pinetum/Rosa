#ifndef CDLGGETVALUE_H
#define CDLGGETVALUE_H
#include "wxcrafter.h"

class CDlgGetValue : public CDlgGetValueBase
{
public:
				CDlgGetValue(wxWindow* parent);
	virtual 	~CDlgGetValue();
	void 		setItemTitle(wxString title);
	void 		setDefaultValue(wxString value);
	void		setLimitValue(int maxValue, int minValue);
	
	wxString 	getStringValue();
	int 		getIntValue();
	double 		getDoubleValue();
	float 		getFloatValue();
	
	
	bool		m_b_limitValue;
	int			m_n_maxValue;
	int			m_n_minValue;
protected:
    virtual void OnButtonSubmit(wxCommandEvent& event);
};
#endif // CDLGGETVALUE_H