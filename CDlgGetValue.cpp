#include "CDlgGetValue.h"
#include <wx/log.h> 
CDlgGetValue::CDlgGetValue(wxWindow* parent)
    : CDlgGetValueBase(parent)
{
	SetAffirmativeId(wxID_Submit);
	m_b_limitValue = false;
}

CDlgGetValue::~CDlgGetValue()
{
}

void CDlgGetValue::OnButtonSubmit(wxCommandEvent& event)
{
	if(!m_b_limitValue)
		CDlgGetValue::EndModal(1001);
	else if (m_n_minValue < getIntValue() && getIntValue() < m_n_maxValue)
		CDlgGetValue::EndModal(1001);
	else
		wxLogMessage("value not in correct Range");
}
void CDlgGetValue::setItemTitle(wxString title){
	m_staticTextTitle->SetLabel(title);
}
wxString CDlgGetValue::getStringValue(){
	return m_textValue->GetValue();
}
int CDlgGetValue::getIntValue(){
	wxString value = m_textValue->GetValue();
	double  dv ;
	
	value.ToCDouble(&dv);
	
	return (int)dv;
}
double CDlgGetValue::getDoubleValue(){
	wxString value = m_textValue->GetValue();
	double  dv ;
	
	value.ToCDouble(&dv);
	
	return dv;
	
}
float CDlgGetValue::getFloatValue(){
	wxString value = m_textValue->GetValue();
	double  dv ;
	
	value.ToCDouble(&dv);
	
	return (float)dv;
	
}
void CDlgGetValue::setDefaultValue(wxString value){
	
	m_textValue->SetValue(value);
}
void CDlgGetValue::setLimitValue(int maxValue, int minValue){
	m_b_limitValue = true;
	m_n_maxValue   = maxValue;
	m_n_minValue   = minValue;
	
}